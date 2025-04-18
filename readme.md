## Используемые технологии и библиотеки

- **Язык программирования**: C++ (стандарт C++17).  
- **Система сборки**: CMake.  
- **Библиотеки**:  
  - **Стандартная библиотека C++ (STL)**:  
    - `<fstream>` — для чтения и записи файлов.  
    - `<stdexcept>` — для обработки исключений.  
    - `<vector>` — для хранения данных изображения.  
    - `<algorithm>` — для операций над данными.  
    - `<cmath>` — для математических вычислений.  
  - Сторонние библиотеки для работы с изображениями **не используются**.  

---

## Архитектура проекта

Проект представляет собой консольное приложение для обработки изображений в формате BMP. Основные компоненты:

1. **Pixel** — структура, представляющая цвет пикселя в формате RGB.  
2. **Image** — класс, представляющий изображение как одномерный массив пикселей.  
3. **Filter** — абстрактный базовый класс для фильтров обработки изображений.  
4. **BMP** — функции для чтения и записи 24-битных BMP-файлов.  
5. **Filters** — конкретные реализации фильтров (Crop, Grayscale, Negative, Sharpening, Edge Detection, Gaussian Blur, Pixelate).  
6. **ImageProcessorMain** — главная функция, управляющая процессом: парсинг аргументов, чтение файла, применение фильтров, запись результата.  

---

## Описание основных компонентов

### 1. Pixel

- **Назначение**:  
  Структура для представления цвета одного пикселя в формате RGB. Используется для хранения и манипуляции цветовыми значениями.  

- **Атрибуты**:  
  - `float r` — красная компонента.  
  - `float g` — зелёная компонента.  
  - `float b` — синяя компонента.  

- **Методы**:  
  - **`Pixel()`**:  
    Конструктор по умолчанию. Инициализирует пиксель чёрным цветом (`r = 0.0`, `g = 0.0`, `b = 0.0`).  
  - **`Pixel(float r, float g, float b)`**:  
    Конструктор с параметрами. Принимает значения для `r`, `g`, `b` **без ограничения диапазона** (могут быть любыми `float`).  
  - **`bool operator==(const Pixel& other) const`**:  
    Оператор сравнения. Возвращает `true`, если все компоненты (`r`, `g`, `b`) равны с учётом точности `float`.  

- **Особенности**:  
  - Значения компонент не ограничены диапазоном [0.0, 1.0], что может привести к некорректным цветам при записи в BMP.  
  - Предполагается нормализованное представление (0.0–1.0) для упрощения вычислений, но это не enforced в коде.  

---

### 2. Image

- **Назначение**:  
  Класс для представления изображения как одномерного массива пикселей. Обеспечивает доступ и модификацию пикселей по координатам.  

- **Атрибуты**:  
  - `size_t width_` — ширина изображения.  
  - `size_t height_` — высота изображения.  
  - `std::vector<Pixel> pixels_` — одномерный массив пикселей.  

- **Методы**:  
  - **`Image(size_t width, size_t height)`**:  
    Конструктор. Создаёт изображение заданных размеров, все пиксели инициализируются чёрным цветом (`Pixel{0.0, 0.0, 0.0}`).  
  - **`size_t GetWidth() const`**:  
    Возвращает ширину изображения.  
  - **`size_t GetHeight() const`**:  
    Возвращает высоту изображения.  
  - **`Pixel GetPixel(int x, int y) const`**:  
    Возвращает пиксель по координатам `(x, y)`. Если координаты вне границ, используется **краевой эффект** (возвращается ближайший существующий пиксель).  
  - **`void SetPixel(size_t x, size_t y, const Pixel& p)`**:  
    Устанавливает значение пикселя по координатам `(x, y)`. Игнорирует запросы, если `(x, y)` вне границ изображения.  

- **Особенности**:  
  - Хранение в виде одномерного массива `pixels_`. Индекс пикселя `(x, y)` вычисляется как `y * width_ + x`.  
  - Краевой эффект реализован для упрощения работы фильтров на границах изображения.  

---

### 3. Filter

- **Назначение**:  
  Абстрактный базовый класс для всех фильтров обработки изображений. Определяет интерфейс для их применения.  

- **Методы**:  
  - **`virtual Image Apply(const Image& image) const = 0`**:  
    Чисто виртуальный метод. Применяет фильтр к изображению и возвращает результат.  
  - **`virtual ~Filter() = default`**:  
    Виртуальный деструктор для корректного освобождения памяти при наследовании.  

- **Особенности**:  
  - Использует полиморфизм, позволяя добавлять новые фильтры через наследование.  

---

### 4. BMP

- **Назначение**:  
  Набор функций для работы с 24-битными BMP-файлами без сжатия.  

- **Методы**:  
  - **`Image ReadBMP(const std::string& filename)`**:  
    Читает BMP-файл и возвращает объект `Image`. Выбрасывает `std::runtime_error` при ошибках (например, неверный формат файла).  
  - **`void WriteBMP(const std::string& filename, const Image& image)`**:  
    Записывает объект `Image` в BMP-файл с учётом заголовков и padding’а.  

- **Особенности**:  
  - Поддерживает только 24-битные BMP-файлы с заголовком `BITMAPINFOHEADER`.  
  - Проверяет:  
    - Сигнатуру `BM`.  
    - Глубину цвета (24 бита).  
    - Отсутствие сжатия.  
  - Учитывает padding (выравнивание строк по 4 байта).  
  - Порядок компонент в файле: BGR (синий, зелёный, красный).  

---

### 5. Filters

- **Назначение**:  
  Конкретные реализации фильтров, наследующиеся от `Filter`. Каждый выполняет определённую операцию над изображением.  

- **Реализованные фильтры**:  
  1. **`CropFilter` (`-crop width height`)**:  
     - Обрезает изображение до заданных `width` и `height`, извлекая верхнюю левую часть.  
     - Учитывает перевёрнутую ориентацию BMP (снизу вверх).  
  2. **`GrayscaleFilter` (`-gs`)**:  
     - Преобразует изображение в оттенки серого по формуле:  
       `gray = 0.299R + 0.587G + 0.114B`.  
  3. **`NegativeFilter` (`-neg`)**:  
     - Преобразует изображение в негатив:  
       `R' = 1 - R`, `G' = 1 - G`, `B' = 1 - B`.  
  4. **`SharpeningFilter` (`-sharp`)**:  
     - Повышает резкость с использованием матрицы:  
       ```
       [ 0 -1  0 ]
       [-1  5 -1 ]
       [ 0 -1  0 ]
       ```  
     - Ограничивает результат диапазоном [0.0, 1.0].  
  5. **`EdgeDetectionFilter` (`-edge threshold`)**:  
     - Выделяет границы:  
       - Преобразует изображение в серый.  
       - Применяет матрицу:  
         ```
         [ 0 -1  0 ]
         [-1  4 -1 ]
         [ 0 -1  0 ]
         ```  
       - Пиксели с результатом > `threshold` становятся белыми (1.0), иначе — чёрными (0.0).  
  6. **`GaussianBlurFilter` (`-blur sigma`)**:  
     - Применяет гауссово размытие с параметром `sigma`.  
     - Размер ядра: `2 * ceil(3 * sigma) + 1`.  
     - Реализовано через два прохода: горизонтальный и вертикальный.  
  7. **`PixelateFilter` (`-pixelate block_size`)**:  
     - Разбивает изображение на блоки `block_size x block_size`.  
     - Заменяет пиксели в каждом блоке средним цветом блока.  

- **Общие особенности**:  
  - Фильтры применяются **последовательно** в порядке указания в командной строке.  
  - Матричные фильтры (Sharpening, Edge Detection, Gaussian Blur) используют краевой эффект для обработки границ.  

---

### 6. ImageProcessorMain

- **Назначение**:  
  Главная функция, управляющая процессом обработки изображения: парсинг аргументов, чтение файла, применение фильтров, запись результата.  

- **Формат аргументов**:  
  ```
  ./image_processor {input.bmp} {output.bmp} [-filter1 [param1] ...] [-filter2 ...] ...
  ```  
  - `{input.bmp}` — путь к входному файлу.  
  - `{output.bmp}` — путь к выходному файлу.  
  - `[-filter1 [param1] ...]` — опциональные фильтры с параметрами.  

- **Поведение**:  
  - Если аргументов меньше 3, выводит справку и завершается с кодом 1.  
  - Парсит фильтры и их параметры, создаёт объекты `Filter`.  
  - Читает изображение из `input.bmp` с помощью `ReadBMP`.  
  - Применяет фильтры последовательно.  
  - Записывает результат в `output.bmp` с помощью `WriteBMP`.  
  - При ошибках (неверный формат файла, некорректные параметры) выводит сообщение и завершается с кодом 1.  

- **Особенности**:  
  - Использует `std::unique_ptr<Filter>` для управления памятью фильтров.  
  - Поддерживает все реализованные фильтры.  

---

## Тесты в проекте (которые я сделал. test_image_processor.py тоже работает и корректно отображает работу фильтров)

- **Содержимое**:  
  - **`BMPTest.cpp`**: Проверяет функции чтения и записи BMP-файлов.  
  - **`FilterTest.cpp`**: Тестирует фильтры: Crop, Grayscale, Negative, Gaussian Blur, Pixelate.  
  - **`ImageTest.cpp`**: Проверяет методы класса `Image`.  
  - **`MainTest.cpp`**: Сценарные тесты для `ImageProcessorMain`.  
  - **`PixelTest.cpp`**: Проверяет структуру `Pixel`.  

- **Запуск тестов**:  
  - Собираются через CMake.  
  - Запускаются через `ctest` или исполняемый файл `runTests`.  

- **Необходимые библиотеки**:  
  - `googletests` (находится через `find_package(GTest REQUIRED)`).  
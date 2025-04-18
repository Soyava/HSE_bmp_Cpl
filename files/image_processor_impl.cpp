#include "image_processor.h"
#include <iostream>

int ImageProcessorMain(int argc, const char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: image_processor input.bmp output.bmp [-filter1 [params]] [-filter2 [params]] ...\n";
        std::cout << "Available filters:\n";
        std::cout << "  -crop width height\n  -gs\n  -neg\n  -sharp\n  -edge threshold\n  -blur sigma\n  -pixelate "
                     "block_size\n";
        return 1;
    }
    try {
        Image image = ReadBMP(argv[1]);
        std::vector<std::unique_ptr<Filter>> filters;
        for (int i = 3; i < argc; ++i) {
            std::string arg = argv[i];
            if (arg == "-crop") {
                if (i + 2 >= argc) {
                    throw std::runtime_error("Not enough arguments for -crop");
                }
                size_t width = std::stoi(argv[i + 1]);
                size_t height = std::stoi(argv[i + 2]);
                filters.push_back(std::make_unique<CropFilter>(width, height));
                i += 2;
            } else if (arg == "-gs") {
                filters.push_back(std::make_unique<GrayscaleFilter>());
            } else if (arg == "-neg") {
                filters.push_back(std::make_unique<NegativeFilter>());
            } else if (arg == "-sharp") {
                filters.push_back(std::make_unique<SharpeningFilter>());
            } else if (arg == "-edge") {
                if (i + 1 >= argc) {
                    throw std::runtime_error("Not enough arguments for -edge");
                }
                float threshold = std::stof(argv[i + 1]);
                filters.push_back(std::make_unique<EdgeDetectionFilter>(threshold));
                i += 1;
            } else if (arg == "-blur") {
                if (i + 1 >= argc) {
                    throw std::runtime_error("Not enough arguments for -blur");
                }
                float sigma = std::stof(argv[i + 1]);
                filters.push_back(std::make_unique<GaussianBlurFilter>(sigma));
                i += 1;
            } else if (arg == "-pixelate") {
                if (i + 1 >= argc) {
                    throw std::runtime_error("Not enough arguments for -pixelate");
                }
                size_t block_size = std::stoi(argv[i + 1]);
                filters.push_back(std::make_unique<PixelateFilter>(block_size));
                i += 1;
            } else {
                throw std::runtime_error("Unknown filter: " + arg);
            }
        }
        for (const auto& filter : filters) {
            image = filter->Apply(image);
        }
        WriteBMP(argv[2], image);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
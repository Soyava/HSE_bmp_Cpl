cmake_minimum_required(VERSION 3.14)

project(image_processor)

if (CMAKE_COMPILER_IS_GNUCC AND 
    CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 9.3)
    set(CMAKE_CXX_STANDARD 20)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND 
       CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 10.0)
    set(CMAKE_CXX_STANDARD 20)
else()
    set(CMAKE_CXX_STANDARD 17)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message("C++ version: ${CMAKE_CXX_STANDARD}")

include_directories(files)
include_directories(/opt/homebrew/include)

set(CMAKE_CXX_FLAGS "-Wall -Werror -Wimplicit-fallthrough -g")

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address,undefined -fno-sanitize-recover=all"
    CACHE STRING "Compiler flags in asan build"
    FORCE)

set(SOURCES
    files/BMP.cpp
    files/Filters.cpp
    files/Image.cpp
    files/Pixel.cpp
    files/image_processor_impl.cpp
)

set(MAIN_SOURCE
    files/image_processor.cpp
)

add_executable(image_processor ${SOURCES} ${MAIN_SOURCE})

enable_testing()

include(FetchContent)

find_package(GTest QUIET)

if(NOT GTest_FOUND)
    message(STATUS "GTest не найден. Загружаем GTest из исходников...")
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
    )
    FetchContent_MakeAvailable(googletest)
else()
    message(STATUS "GTest найден.")
endif()

set(TEST_SOURCES
    tests/ImageTest.cpp
    tests/PixelTest.cpp
    tests/FilterTest.cpp
    tests/BMPTest.cpp
    tests/MainTest.cpp
)

add_executable(runTests ${TEST_SOURCES} ${SOURCES})
target_link_libraries(runTests GTest::gtest_main)
add_test(NAME UnitTests COMMAND runTests)
#include "BMP.h"
#include <fstream>
#include <stdexcept>
#include <vector>
#include <algorithm>

constexpr uint16_t KBmpSignature = 0x4D42;
constexpr uint32_t KHeaderSize = 40;
constexpr uint16_t KBitsPerPixel = 24;
constexpr uint32_t KOffset = 54;
constexpr float KMaxColorValue = 255.0f;

Image ReadBMP(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    BMPFileHeader file_header;
    BMPInfoHeader info_header;
    file.read(reinterpret_cast<char*>(&file_header), sizeof(file_header));
    file.read(reinterpret_cast<char*>(&info_header), sizeof(info_header));

    if (file_header.signature != KBmpSignature) {
        throw std::runtime_error("Not a BMP file: " + filename);
    }
    if (info_header.header_size != KHeaderSize) {
        throw std::runtime_error("Unsupported BMP header: " + filename);
    }
    if (info_header.bits_per_pixel != KBitsPerPixel) {
        throw std::runtime_error("Not a 24-bit BMP: " + filename);
    }
    if (info_header.compression != 0) {
        throw std::runtime_error("Compressed BMP not supported: " + filename);
    }

    size_t width = static_cast<size_t>(std::abs(info_header.width));
    size_t height = static_cast<size_t>(std::abs(info_header.height));
    Image image(width, height);

    file.seekg(file_header.offset, std::ios::beg);
    size_t padding = (4 - (width * 3) % 4) % 4;
    std::vector<unsigned char> pixel_data(width * 3);
    for (size_t y = 0; y < height; ++y) {
        file.read(reinterpret_cast<char*>(pixel_data.data()), static_cast<std::streamsize>(width * 3));
        file.seekg(static_cast<std::streamoff>(padding), std::ios::cur);
        for (size_t x = 0; x < width; ++x) {
            size_t offset = x * 3;
            unsigned char b = pixel_data[offset];
            unsigned char g = pixel_data[offset + 1];
            unsigned char r = pixel_data[offset + 2];
            image.SetPixel(x, y,
                           Pixel(static_cast<float>(r) / KMaxColorValue, static_cast<float>(g) / KMaxColorValue,
                                 static_cast<float>(b) / KMaxColorValue));
        }
    }
    return image;
}

void WriteBMP(const std::string& filename, const Image& image) {
    size_t width = image.GetWidth();
    size_t height = image.GetHeight();
    size_t padding = (4 - (width * 3) % 4) % 4;
    size_t pixel_data_size = (width * 3 + padding) * height;
    size_t file_size = KOffset + pixel_data_size;

    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Cannot create file: " + filename);
    }
    BMPFileHeader file_header = {KBmpSignature, static_cast<uint32_t>(file_size), 0, 0, KOffset};
    BMPInfoHeader info_header = {
        KHeaderSize, static_cast<int32_t>(width), static_cast<int32_t>(height), 1, KBitsPerPixel, 0, 0, 0, 0, 0, 0};
    file.write(reinterpret_cast<const char*>(&file_header), sizeof(file_header));
    file.write(reinterpret_cast<const char*>(&info_header), sizeof(info_header));

    std::vector<unsigned char> pixel_data(pixel_data_size, 0);
    for (size_t y = 0; y < height; ++y) {
        size_t offset = y * (width * 3 + padding);
        for (size_t x = 0; x < width; ++x) {
            Pixel p = image.GetPixel(static_cast<int>(x), static_cast<int>(y));
            pixel_data[offset + x * 3] =
                static_cast<unsigned char>(std::clamp(p.b * KMaxColorValue, 0.0f, KMaxColorValue));
            pixel_data[offset + x * 3 + 1] =
                static_cast<unsigned char>(std::clamp(p.g * KMaxColorValue, 0.0f, KMaxColorValue));
            pixel_data[offset + x * 3 + 2] =
                static_cast<unsigned char>(std::clamp(p.r * KMaxColorValue, 0.0f, KMaxColorValue));
        }
    }
    file.write(reinterpret_cast<const char*>(pixel_data.data()), static_cast<std::streamsize>(pixel_data_size));
}
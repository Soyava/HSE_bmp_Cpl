#include "Image.h"
#include <algorithm>

Image::Image(size_t width, size_t height) : width_(width), height_(height), pixels_(width * height) {
}

size_t Image::GetWidth() const {
    return width_;
}

size_t Image::GetHeight() const {
    return height_;
}

Pixel Image::GetPixel(int x, int y) const {
    x = std::max(0, std::min(static_cast<int>(width_) - 1, x));
    y = std::max(0, std::min(static_cast<int>(height_) - 1, y));
    return pixels_[y * width_ + x];
}

void Image::SetPixel(size_t x, size_t y, const Pixel& pixel) {
    if (x < width_ && y < height_) {
        pixels_[y * width_ + x] = pixel;
    }
}
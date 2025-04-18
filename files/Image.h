#pragma once

#include <vector>
#include "Pixel.h"

class Image {
public:
    Image(size_t width, size_t height);

    size_t GetWidth() const;
    size_t GetHeight() const;
    Pixel GetPixel(int x, int y) const;
    void SetPixel(size_t x, size_t y, const Pixel& p);

private:
    size_t width_;
    size_t height_;
    std::vector<Pixel> pixels_;
};
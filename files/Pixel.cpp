#include "Pixel.h"

Pixel::Pixel() : r(0), g(0), b(0) {
}
Pixel::Pixel(float r, float g, float b) : r(r), g(g), b(b) {
}

bool Pixel::operator==(const Pixel& other) const {
    return r == other.r && g == other.g && b == other.b;
}
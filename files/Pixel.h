#ifndef PIXEL_H
#define PIXEL_H

struct Pixel {
    float r, g, b;
    Pixel();
    Pixel(float r, float g, float b);
    bool operator==(const Pixel& other) const;
};

#endif
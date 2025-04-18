#include "Image.h"
#include <gtest/gtest.h>
#include "Constants.h"

TEST(ImageTest, ConstructorValid) {
    Image img(constants::ImageTestSize, constants::ImageTestSize);
    EXPECT_EQ(img.GetWidth(), constants::ImageTestSize);
    EXPECT_EQ(img.GetHeight(), constants::ImageTestSize);
}

TEST(ImageTest, ConstructorZero) {
    Image img(0, 0);
    EXPECT_EQ(img.GetWidth(), 0);
    EXPECT_EQ(img.GetHeight(), 0);
}

TEST(ImageTest, GetPixelInBounds) {
    Image img(constants::ImageTestSize, constants::ImageTestSize);
    img.SetPixel(1, 1, Pixel(constants::HalfIntensity, constants::HalfIntensity, constants::HalfIntensity));
    EXPECT_EQ(img.GetPixel(1, 1), Pixel(constants::HalfIntensity, constants::HalfIntensity, constants::HalfIntensity));
}

TEST(ImageTest, GetPixelOutOfBounds) {
    Image img(constants::ImageTestSize, constants::ImageTestSize);
    img.SetPixel(0, 0, Pixel(constants::NoIntensity, constants::NoIntensity, constants::NoIntensity));
    img.SetPixel(2, 2, Pixel(constants::FullIntensity, constants::FullIntensity, constants::FullIntensity));
    EXPECT_EQ(img.GetPixel(-1, 1), img.GetPixel(0, 1));
    EXPECT_EQ(img.GetPixel(3, 1), img.GetPixel(2, 1));
    EXPECT_EQ(img.GetPixel(1, -1), img.GetPixel(1, 0));
    EXPECT_EQ(img.GetPixel(1, 3), img.GetPixel(1, 2));
}

TEST(ImageTest, SetPixelOutOfBounds) {
    Image img(constants::ImageTestSize, constants::ImageTestSize);
    img.SetPixel(3, 1, Pixel(constants::FullIntensity, constants::FullIntensity, constants::FullIntensity));
    img.SetPixel(1, 3, Pixel(constants::FullIntensity, constants::FullIntensity, constants::FullIntensity));
    for (size_t y = 0; y < constants::ImageTestSize; ++y) {
        for (size_t x = 0; x < constants::ImageTestSize; ++x) {
            EXPECT_EQ(img.GetPixel(static_cast<int>(x), static_cast<int>(y)),
                      Pixel(constants::NoIntensity, constants::NoIntensity, constants::NoIntensity));
        }
    }
}
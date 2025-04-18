#include "Pixel.h"
#include <gtest/gtest.h>
#include "Constants.h"

TEST(PixelTest, DefaultConstructor) {
    Pixel p;
    EXPECT_EQ(p.r, constants::NoIntensity);
    EXPECT_EQ(p.g, constants::NoIntensity);
    EXPECT_EQ(p.b, constants::NoIntensity);
}

TEST(PixelTest, ParameterizedConstructor) {
    Pixel p(constants::LowIntensity, constants::SlightlyAboveMedium, constants::AboveHalfIntensity);
    EXPECT_EQ(p.r, constants::LowIntensity);
    EXPECT_EQ(p.g, constants::SlightlyAboveMedium);
    EXPECT_EQ(p.b, constants::AboveHalfIntensity);
}
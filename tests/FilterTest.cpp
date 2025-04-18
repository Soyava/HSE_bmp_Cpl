#include "Filters.h"
#include <gtest/gtest.h>
#include "Constants.h"

TEST(CropFilterTest, CropSmaller) {
    Image img(constants::ImageTestSize, constants::ImageTestSize);
    img.SetPixel(0, 0, Pixel(constants::NoIntensity, constants::NoIntensity, constants::NoIntensity));
    img.SetPixel(1, 0, Pixel(constants::VeryLowIntensity, constants::VeryLowIntensity, constants::VeryLowIntensity));
    img.SetPixel(2, 0, Pixel(constants::LowIntensity, constants::LowIntensity, constants::LowIntensity));
    img.SetPixel(0, 1, Pixel(constants::MediumIntensity, constants::MediumIntensity, constants::MediumIntensity));
    img.SetPixel(1, 1,
                 Pixel(constants::SlightlyAboveMedium, constants::SlightlyAboveMedium, constants::SlightlyAboveMedium));
    img.SetPixel(2, 1, Pixel(constants::HalfIntensity, constants::HalfIntensity, constants::HalfIntensity));
    img.SetPixel(0, 2,
                 Pixel(constants::AboveHalfIntensity, constants::AboveHalfIntensity, constants::AboveHalfIntensity));
    img.SetPixel(1, 2, Pixel(constants::HighIntensity, constants::HighIntensity, constants::HighIntensity));
    img.SetPixel(2, 2, Pixel(constants::VeryHighIntensity, constants::VeryHighIntensity, constants::VeryHighIntensity));
    CropFilter filter(constants::CropTestWidth, constants::CropTestHeight);
    Image cropped = filter.Apply(img);
    EXPECT_EQ(cropped.GetWidth(), constants::CropTestWidth);
    EXPECT_EQ(cropped.GetHeight(), constants::CropTestHeight);
    EXPECT_FLOAT_EQ(cropped.GetPixel(0, 0).r, constants::MediumIntensity);
    EXPECT_FLOAT_EQ(cropped.GetPixel(1, 0).r, constants::SlightlyAboveMedium);
    EXPECT_FLOAT_EQ(cropped.GetPixel(0, 1).r, constants::AboveHalfIntensity);
    EXPECT_FLOAT_EQ(cropped.GetPixel(1, 1).r, constants::HighIntensity);
}

TEST(CropFilterTest, EmptyImage) {
    Image img(0, 0);
    CropFilter filter(constants::CropTestWidth, constants::CropTestHeight);
    Image cropped = filter.Apply(img);
    EXPECT_EQ(cropped.GetWidth(), 0);
    EXPECT_EQ(cropped.GetHeight(), 0);
}

TEST(GrayscaleFilterTest, Apply) {
    Image img(1, 1);
    img.SetPixel(0, 0, Pixel(constants::LowIntensity, constants::SlightlyAboveMedium, constants::AboveHalfIntensity));
    GrayscaleFilter filter;
    Image gray = filter.Apply(img);
    float expected = constants::LowIntensity * KGrayscaleRedWeight +
                     constants::SlightlyAboveMedium * KGrayscaleGreenWeight +
                     constants::AboveHalfIntensity * KGrayscaleBlueWeight;
    EXPECT_FLOAT_EQ(gray.GetPixel(0, 0).r, expected);
    EXPECT_FLOAT_EQ(gray.GetPixel(0, 0).g, expected);
    EXPECT_FLOAT_EQ(gray.GetPixel(0, 0).b, expected);
}

TEST(NegativeFilterTest, Apply) {
    Image img(1, 1);
    img.SetPixel(0, 0, Pixel(constants::LowIntensity, constants::SlightlyAboveMedium, constants::AboveHalfIntensity));
    NegativeFilter filter;
    Image neg = filter.Apply(img);
    EXPECT_FLOAT_EQ(neg.GetPixel(0, 0).r, constants::FullIntensity - constants::LowIntensity);
    EXPECT_FLOAT_EQ(neg.GetPixel(0, 0).g, constants::FullIntensity - constants::SlightlyAboveMedium);
    EXPECT_FLOAT_EQ(neg.GetPixel(0, 0).b, constants::FullIntensity - constants::AboveHalfIntensity);
}

TEST(GaussianBlurFilterTest, InvalidSigma) {
    EXPECT_THROW(GaussianBlurFilter(0.0f), std::invalid_argument);
    EXPECT_THROW(GaussianBlurFilter(-1.0f), std::invalid_argument);
}

TEST(PixelateFilterTest, InvalidBlockSize) {
    EXPECT_THROW(PixelateFilter(0), std::invalid_argument);
}
#include "BMP.h"
#include <gtest/gtest.h>
#include <fstream>
#include "Constants.h"

TEST(BMPTest, ReadWrite) {
    Image original(constants::CropTestWidth, constants::CropTestHeight);
    original.SetPixel(0, 0, Pixel(constants::NoIntensity, constants::NoIntensity, constants::NoIntensity));
    original.SetPixel(1, 0, Pixel(constants::FullIntensity, constants::FullIntensity, constants::FullIntensity));
    original.SetPixel(0, 1, Pixel(constants::HalfIntensity, constants::HalfIntensity, constants::HalfIntensity));
    original.SetPixel(1, 1, Pixel(constants::LowIntensity, constants::MediumIntensity, constants::SlightlyAboveMedium));
    std::string temp_file = testing::TempDir() + "test.bmp";
    WriteBMP(temp_file, original);
    Image read_back = ReadBMP(temp_file);
    EXPECT_EQ(read_back.GetWidth(), constants::CropTestWidth);
    EXPECT_EQ(read_back.GetHeight(), constants::CropTestHeight);
    EXPECT_NEAR(read_back.GetPixel(0, 0).r, constants::NoIntensity, constants::FullIntensity / 255);
    EXPECT_NEAR(read_back.GetPixel(1, 0).r, constants::FullIntensity, constants::FullIntensity / 255);
    EXPECT_NEAR(read_back.GetPixel(0, 1).r, constants::HalfIntensity, constants::FullIntensity / 255);
    EXPECT_NEAR(read_back.GetPixel(1, 1).r, constants::LowIntensity, constants::FullIntensity / 255);
}

TEST(BMPTest, ReadInvalid) {
    std::string invalid_file = "non_existent.bmp";
    EXPECT_THROW(ReadBMP(invalid_file), std::runtime_error);
    std::string temp_file = testing::TempDir() + "invalid.bmp";
    std::ofstream f(temp_file, std::ios::binary);
    f.write("INVALID", constants::InvalidStringLength);
    f.close();
    EXPECT_THROW(ReadBMP(temp_file), std::runtime_error);
}
#include "image_processor.h"
#include <gtest/gtest.h>
#include <sstream>
#include "Constants.h"

int RunMain(int argc, const char* argv[]) {
    return ImageProcessorMain(argc, argv);
}

TEST(MainTest, InsufficientArgs) {
    std::ostringstream oss;
    std::streambuf* old_cout = std::cout.rdbuf(oss.rdbuf());
    const char* argv[] = {"image_processor"};
    int argc = 1;
    EXPECT_EQ(RunMain(argc, argv), 1);
    std::cout.rdbuf(old_cout);
}

TEST(MainTest, UnknownFilter) {
    const char* argv[] = {"image_processor", "input.bmp", "output.bmp", "-unknown"};
    int argc = 4;
    EXPECT_EQ(RunMain(argc, argv), 1);
}

TEST(MainTest, InvalidCropArgs) {
    const char* argv[] = {"image_processor", "input.bmp", "output.bmp", "-crop", "abc", "200"};
    int argc = constants::ArgCountInvalidCrop;
    EXPECT_EQ(RunMain(argc, argv), 1);
}

TEST(MainTest, InputFileNotFound) {
    const char* argv[] = {"image_processor", "non_existent.bmp", "output.bmp"};
    int argc = 3;
    EXPECT_EQ(RunMain(argc, argv), 1);
}
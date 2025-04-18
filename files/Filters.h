#ifndef FILTERS_H
#define FILTERS_H

#include "Filter.h"
#include <vector>

constexpr float KGrayscaleRedWeight = 0.299f;
constexpr float KGrayscaleGreenWeight = 0.587f;
constexpr float KGrayscaleBlueWeight = 0.114f;

class CropFilter : public Filter {
public:
    CropFilter(size_t width, size_t height);
    Image Apply(const Image& input) const override;

private:
    size_t width_, height_;
};

class GrayscaleFilter : public Filter {
public:
    Image Apply(const Image& input) const override;
};

class NegativeFilter : public Filter {
public:
    Image Apply(const Image& input) const override;
};

class SharpeningFilter : public Filter {
public:
    Image Apply(const Image& input) const override;

private:
    Image ApplyMatrix(const Image& input, const std::vector<std::vector<float>>& matrix) const;
};

class EdgeDetectionFilter : public Filter {
public:
    explicit EdgeDetectionFilter(float threshold);
    Image Apply(const Image& input) const override;

private:
    float threshold_;
    Image ApplyMatrix(const Image& input, const std::vector<std::vector<float>>& matrix) const;
};

class GaussianBlurFilter : public Filter {
public:
    explicit GaussianBlurFilter(float sigma);
    Image Apply(const Image& input) const override;

private:
    float sigma_;
    Image ApplyKernelHorizontal(const Image& input, const std::vector<float>& kernel, int radius) const;
    Image ApplyKernelVertical(const Image& input, const std::vector<float>& kernel, int radius) const;
};

class PixelateFilter : public Filter {
public:
    explicit PixelateFilter(size_t block_size);
    Image Apply(const Image& input) const override;

private:
    size_t block_size_;
};

#endif
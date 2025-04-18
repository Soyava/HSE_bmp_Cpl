#include "Filters.h"
#include <algorithm>
#include <cmath>
#include <vector>
#include <stdexcept>

constexpr float KSharpeningCenterWeight = 5.0f;

CropFilter::CropFilter(size_t width, size_t height) : width_(width), height_(height) {
}

Image CropFilter::Apply(const Image& input) const {
    size_t out_width = std::min(width_, input.GetWidth());
    size_t out_height = std::min(height_, input.GetHeight());
    Image output(out_width, out_height);
    size_t input_height = input.GetHeight();
    for (size_t y = 0; y < out_height; ++y) {
        for (size_t x = 0; x < out_width; ++x) {
            output.SetPixel(x, y, input.GetPixel(static_cast<int>(x), static_cast<int>(input_height - out_height + y)));
        }
    }
    return output;
}

Image GrayscaleFilter::Apply(const Image& input) const {
    Image output(input.GetWidth(), input.GetHeight());
    for (size_t y = 0; y < input.GetHeight(); ++y) {
        for (size_t x = 0; x < input.GetWidth(); ++x) {
            Pixel p = input.GetPixel(static_cast<int>(x), static_cast<int>(y));
            float gray = KGrayscaleRedWeight * p.r + KGrayscaleGreenWeight * p.g + KGrayscaleBlueWeight * p.b;
            output.SetPixel(x, y, Pixel(gray, gray, gray));
        }
    }
    return output;
}

Image NegativeFilter::Apply(const Image& input) const {
    Image output(input.GetWidth(), input.GetHeight());
    for (size_t y = 0; y < input.GetHeight(); ++y) {
        for (size_t x = 0; x < input.GetWidth(); ++x) {
            Pixel p = input.GetPixel(static_cast<int>(x), static_cast<int>(y));
            output.SetPixel(x, y, Pixel(1.0f - p.r, 1.0f - p.g, 1.0f - p.b));
        }
    }
    return output;
}

Image SharpeningFilter::Apply(const Image& input) const {
    std::vector<std::vector<float>> matrix = {{0, -1, 0}, {-1, KSharpeningCenterWeight, -1}, {0, -1, 0}};
    return ApplyMatrix(input, matrix);
}

Image SharpeningFilter::ApplyMatrix(const Image& input, const std::vector<std::vector<float>>& matrix) const {
    Image output(input.GetWidth(), input.GetHeight());
    int radius = 1;
    for (size_t y = 0; y < input.GetHeight(); ++y) {
        for (size_t x = 0; x < input.GetWidth(); ++x) {
            float r_sum = 0.0f;
            float g_sum = 0.0f;
            float b_sum = 0.0f;
            for (int dy = -radius; dy <= radius; ++dy) {
                for (int dx = -radius; dx <= radius; ++dx) {
                    Pixel p = input.GetPixel(static_cast<int>(x) + dx, static_cast<int>(y) + dy);
                    float weight = matrix[radius + dy][radius + dx];
                    r_sum += weight * p.r;
                    g_sum += weight * p.g;
                    b_sum += weight * p.b;
                }
            }
            r_sum = std::min(1.0f, std::max(0.0f, r_sum));
            g_sum = std::min(1.0f, std::max(0.0f, g_sum));
            b_sum = std::min(1.0f, std::max(0.0f, b_sum));
            output.SetPixel(x, y, Pixel(r_sum, g_sum, b_sum));
        }
    }
    return output;
}

EdgeDetectionFilter::EdgeDetectionFilter(float threshold) : threshold_(threshold) {
}

Image EdgeDetectionFilter::Apply(const Image& input) const {
    GrayscaleFilter gs;
    Image gray = gs.Apply(input);
    std::vector<std::vector<float>> matrix = {{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}};
    Image output = ApplyMatrix(gray, matrix);
    for (size_t y = 0; y < output.GetHeight(); ++y) {
        for (size_t x = 0; x < output.GetWidth(); ++x) {
            Pixel p = output.GetPixel(static_cast<int>(x), static_cast<int>(y));
            if (p.r > threshold_) {
                output.SetPixel(x, y, Pixel(1, 1, 1));
            } else {
                output.SetPixel(x, y, Pixel(0, 0, 0));
            }
        }
    }
    return output;
}

Image EdgeDetectionFilter::ApplyMatrix(const Image& input, const std::vector<std::vector<float>>& matrix) const {
    Image output(input.GetWidth(), input.GetHeight());
    int radius = 1;
    for (size_t y = 0; y < input.GetHeight(); ++y) {
        for (size_t x = 0; x < input.GetWidth(); ++x) {
            float sum = 0.0f;
            for (int dy = -radius; dy <= radius; ++dy) {
                for (int dx = -radius; dx <= radius; ++dx) {
                    Pixel p = input.GetPixel(static_cast<int>(x) + dx, static_cast<int>(y) + dy);
                    float weight = matrix[radius + dy][radius + dx];
                    sum += weight * p.r;
                }
            }
            sum = std::min(1.0f, std::max(0.0f, sum));
            output.SetPixel(x, y, Pixel(sum, sum, sum));
        }
    }
    return output;
}

GaussianBlurFilter::GaussianBlurFilter(float sigma) : sigma_(sigma) {
    if (sigma <= 0) {
        throw std::invalid_argument("Sigma must be positive");
    }
}

Image GaussianBlurFilter::Apply(const Image& input) const {
    int radius = static_cast<int>(std::ceil(3 * sigma_));
    std::vector<float> kernel(2 * radius + 1);
    float sum = 0.0f;
    for (int i = -radius; i <= radius; ++i) {
        kernel[i + radius] = std::exp(-static_cast<float>(i * i) / (2 * sigma_ * sigma_));
        sum += kernel[i + radius];
    }
    for (auto& val : kernel) {
        val /= sum;
    }
    Image temp = ApplyKernelHorizontal(input, kernel, radius);
    return ApplyKernelVertical(temp, kernel, radius);
}

Image GaussianBlurFilter::ApplyKernelHorizontal(const Image& input, const std::vector<float>& kernel,
                                                int radius) const {
    Image output(input.GetWidth(), input.GetHeight());
    for (size_t y = 0; y < input.GetHeight(); ++y) {
        for (size_t x = 0; x < input.GetWidth(); ++x) {
            float r_sum = 0.0f;
            float g_sum = 0.0f;
            float b_sum = 0.0f;
            for (int dx = -radius; dx <= radius; ++dx) {
                Pixel p = input.GetPixel(static_cast<int>(x) + dx, static_cast<int>(y));
                float weight = kernel[radius + dx];
                r_sum += weight * p.r;
                g_sum += weight * p.g;
                b_sum += weight * p.b;
            }
            output.SetPixel(x, y, Pixel(r_sum, g_sum, b_sum));
        }
    }
    return output;
}

Image GaussianBlurFilter::ApplyKernelVertical(const Image& input, const std::vector<float>& kernel, int radius) const {
    Image output(input.GetWidth(), input.GetHeight());
    for (size_t x = 0; x < input.GetWidth(); ++x) {
        for (size_t y = 0; y < input.GetHeight(); ++y) {
            float r_sum = 0.0f;
            float g_sum = 0.0f;
            float b_sum = 0.0f;
            for (int dy = -radius; dy <= radius; ++dy) {
                Pixel p = input.GetPixel(static_cast<int>(x), static_cast<int>(y) + dy);
                float weight = kernel[radius + dy];
                r_sum += weight * p.r;
                g_sum += weight * p.g;
                b_sum += weight * p.b;
            }
            output.SetPixel(x, y, Pixel(r_sum, g_sum, b_sum));
        }
    }
    return output;
}

PixelateFilter::PixelateFilter(size_t block_size) : block_size_(block_size) {
    if (block_size == 0) {
        throw std::invalid_argument("Block size must be positive");
    }
}

Image PixelateFilter::Apply(const Image& input) const {
    Image output(input.GetWidth(), input.GetHeight());
    for (size_t y_start = 0; y_start < input.GetHeight(); y_start += block_size_) {
        for (size_t x_start = 0; x_start < input.GetWidth(); x_start += block_size_) {
            float r_sum = 0.0f;
            float g_sum = 0.0f;
            float b_sum = 0.0f;
            size_t count = 0;
            for (size_t y = y_start; y < std::min(y_start + block_size_, input.GetHeight()); ++y) {
                for (size_t x = x_start; x < std::min(x_start + block_size_, input.GetWidth()); ++x) {
                    Pixel p = input.GetPixel(static_cast<int>(x), static_cast<int>(y));
                    r_sum += p.r;
                    g_sum += p.g;
                    b_sum += p.b;
                    ++count;
                }
            }
            if (count > 0) {
                Pixel avg(r_sum / static_cast<float>(count), g_sum / static_cast<float>(count),
                          b_sum / static_cast<float>(count));
                for (size_t y = y_start; y < std::min(y_start + block_size_, input.GetHeight()); ++y) {
                    for (size_t x = x_start; x < std::min(x_start + block_size_, input.GetWidth()); ++x) {
                        output.SetPixel(x, y, avg);
                    }
                }
            }
        }
    }
    return output;
}
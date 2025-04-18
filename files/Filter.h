#ifndef FILTER_H
#define FILTER_H

#include "Image.h"

class Filter {
public:
    virtual Image Apply(const Image& input) const = 0;
    virtual ~Filter() = default;
};

#endif

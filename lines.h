#ifndef LINES_H
#define LINES_H

#include "constants.h"
#include <cstdint>

class Lines
{
public:
    Lines() = default;
    Lines(unsigned int row, unsigned int column);
    bool intersects(Lines l);
    bool equals(Lines l);
    void add(Lines l);
    uint64_t solutions();
    uint64_t cnt = 0;

private:
    // bit masks representing the lines
    uint64_t row = 0;
    uint64_t column = 0;
    uint64_t ddiag = 0;
    uint64_t udiag = 0;
};

#endif // LINES_H

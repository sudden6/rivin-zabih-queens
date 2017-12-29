#ifndef LINES_H
#define LINES_H

#include "constants.h"
#include <cstdint>

class Lines
{
public:
    Lines() = default;
    Lines(unsigned int row, unsigned int column, unsigned int board_size);
    bool intersects(Lines l);
    bool equals(Lines l);
    Lines add(Lines l);
    bool has_row(unsigned int row) const;
    bool solution(unsigned int board_size) const;
    bool operator<(const Lines& other) const;

private:
    // bit masks representing the lines
    uint32_t row = 0;
    uint32_t column = 0;
    uint64_t ddiag = 0;
    uint64_t udiag = 0;
};

#endif // LINES_H

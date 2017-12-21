#include "lines.h"

// down diagonal: going from the top left to the bottom right
// up diagonal  : going from the bottom left to the top right
// row index starts at 0 with the top row
// column index starts at 0 with the left column
// up diagonal index starts at 0 with the top left corner
// down diagonal index starts at 0 with the bottom left corner

Lines::Lines(unsigned int row, unsigned int column)
{
    this->row = 1 << row;
    this->column = 1 << column;
    this->udiag = 1 << (row + column);
    this->ddiag = 1 << (N - 1 + column - row);
}

bool Lines::intersects(Lines l)
{
    return (row & l.row) &&
           (column & l.column) &&
           (udiag & l.udiag) &&
           (ddiag & l.ddiag);
}

bool Lines::equals(Lines l)
{
    return (row == l.row) &&
           (column == l.column) &&
           (udiag == l.udiag) &&
           (ddiag == l.ddiag);
}

void Lines::add(Lines l)
{
    row |= l.row;
    column |= l.column;
    udiag |= l.udiag;
    ddiag |= l.ddiag;
}

uint64_t Lines::solutions()
{
    // mask for all columns/rows
    uint64_t mask = (1 << N) - 1;
    if((row == mask) && (column == mask))
    {
        return cnt;
    }
    else
    {
        return  0;
    }
}



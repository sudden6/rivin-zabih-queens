#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cstdint>

constexpr uint8_t N = 7;        // board size
constexpr uint8_t MAXN = 32;    // maximum board size

// expected results from https://oeis.org/A000170
constexpr uint64_t results[27] = {  1ULL,
                                    0ULL,
                                    0ULL,
                                    2ULL,
                                    10ULL,
                                    4ULL,
                                    40ULL,
                                    92ULL,
                                    352ULL,
                                    724ULL,
                                    2680ULL,
                                    14200ULL,
                                    73712ULL,
                                    365596ULL,
                                    2279184ULL,
                                    14772512ULL,
                                    95815104ULL,
                                    666090624ULL,
                                    4968057848ULL,
                                    39029188884ULL,
                                    314666222712ULL,
                                    2691008701644ULL,
                                    24233937684440ULL,
                                    227514171973736ULL,
                                    2207893435808352ULL,
                                    22317699616364044ULL,
                                    234907967154122528ULL};


#endif // CONSTANTS_H

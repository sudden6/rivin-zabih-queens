#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "lines.h"

using namespace std;

uint64_t nqueens(unsigned int N)
{
    map<Lines, uint64_t> q;
    // Initialization
    q.emplace(Lines{}, 1);

    for(unsigned int row = 0; row < N; row++)
    {
        for(unsigned int col = 0; col < N; col++)
        {
            // square selection
            Lines square(row, col, N);

            cout << "square " << row*N+col << " of " << N*N << " queue size " << q.size() << endl;

            // iteration
            for(auto s: q)
            {
                if(square.intersects(s.first))
                {
                    continue;
                }
                Lines u = square.add(s.first);
                uint64_t i = s.second;
                //u.cnt = i;

                auto it = q.find(u);

                if(it != q.end())
                {
                    // compaction
                    it->second += i;
                }
                else
                {   // creation
                    q.insert(std::pair<Lines, uint64_t>(u, i));
                }
            }
        }
        auto iter = q.begin();
        auto end = q.end();
        for(; iter != end; )
        {
            if (!iter->first.has_row(row))
            {
                q.erase(iter++);
            }
            else
            {
                ++iter;
            }
        }

    }

    uint64_t solutions = 0;

    for(auto s = q.begin(); s != q.end(); ++s)
    {
        if(s->first.solution(N))
        {
            solutions += s->second;
        }
    }
    return solutions;
}

#define TESTSUITE

int main(int argc, char **argv) {

#ifdef TESTSUITE
  int i = 2;
#else
  int i = N;
#endif
  if (argc == 2) {
    i = atoi(argv[1]);
    if (i < 1 || i > MAXN) {
      printf("n must be between 2 and %d!\n", MAXN);
    }
  }

  for (; i <= N; i++) {
    //time_start = get_time();
    uint64_t result = nqueens(i);
    //time_diff = (get_time() - time_start); // calculating time difference
    result == results[i - 1] ? cout << "PASS " : cout << "FAIL ";
    cout << "N " << i << ", Solutions " << result << ", Expected " << results[i - 1] << endl;
  }
  return 0;
}


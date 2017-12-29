#include <iostream>
#include <map>
#include <vector>
#include "lines.h"

using namespace std;

uint64_t nqueens(unsigned int N)
{
    auto q = new vector<Lines>();
    // Initialization
    q->emplace_back(Lines{});
    q->at(0).cnt = 1;

    for(unsigned int row = 0; row < N; row++)
    {
        for(unsigned int col = 0; col < N; col++)
        {
            // square selection
            Lines square(row, col, N);

            // cout << "square " << row*N+col << " of " << N*N << " queue size " << q->size() << endl;

            // iteration
            for(size_t idx = 0; idx < q->size(); ++idx)
            {
                if(square.intersects(q->at(idx)))
                {
                    continue;
                }
                Lines u = square.add(q->at(idx));
                uint64_t i = q->at(idx).cnt;
                u.cnt = i;
                size_t jdx = 0;
                for(; jdx < q->size(); ++jdx)
                {
                    Lines& cur = q->at(jdx);
                    if(cur.equals(u))
                    {
                        // compaction
                        cur.cnt += i;
                        break;
                    }
                }
                if(jdx == q->size())
                {
                    // creation
                    q->push_back(u);
                }
            }
        }
    }

    uint64_t solutions = 0;

    for(auto s = q->begin(); s != q->end(); ++s)
    {
        if(s->solution(N))
        {
            solutions += s->cnt;
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


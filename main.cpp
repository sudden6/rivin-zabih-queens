#include <iostream>
#include <map>
#include "lines.h"

using namespace std;

int main()
{
    auto q = new map<Lines, uint64_t>();
    // Initialization
    q->emplace(Lines{}, 1);

    for(unsigned int row = 0; row < N; row++)
    {
        for(unsigned int col = 0; col < N; col++)
        {
            // square selection
            Lines t(row, col);
            // iteration
            for(auto s = q->begin(); s != q->end(); ++s)
            {
                if(t.intersects(s->first))
                {
                    continue;
                }
                t.add(s->first);
                uint64_t i = s->second;
                auto f = q->find(t);
                if(f == q->end())
                {
                    // creation
                    q->insert(std::pair<Lines, uint64_t>(t, i));
                }
                else
                {
                    // compaction
                    f->second += i;
                }
            }
        }
    }

    uint64_t solutions = 0;

    for(auto s = q->begin(); s != q->end(); ++s)
    {
        if(s->first.solution())
        {
            solutions += s->second;
        }
    }

    cout << "DONE" << std::endl;
    cout << "Solutions: " << solutions << std::endl;
}

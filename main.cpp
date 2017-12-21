#include <iostream>
#include <forward_list>
#include "lines.h"

using namespace std;

int main()
{
    forward_list<Lines>* q = new forward_list<Lines>();
    // Initialization
    Lines zero_element{};
    zero_element.cnt = 1;
    q->push_front(zero_element);

    for(unsigned int row = 0; row < N; row++)
    {
        for(unsigned int col = 0; col < N; col++)
        {
            // square selection
            Lines t(row, col);
            // iteration
            for(auto s = q->begin(); s != q->end(); ++s)
            {
                if(t.intersects(*s))
                {
                    continue;
                }
                t.add(*s);
                bool found = false;
                uint64_t i = (*s).cnt;
                for(auto c = q->begin(); c != q->end(); ++c)
                {
                    // compaction
                    if((*c).equals(t))
                    {
                        (*c).cnt += i;
                        found = true;
                    }
                }

                // creation
                if(!found)
                {
                    t.cnt = i;
                    q->insert_after(s, t);
                }
            }
        }
    }

    uint64_t solutions = 0;

    for(auto s = q->begin(); s != q->end(); ++s)
    {
        solutions += (*s).solutions();
    }

    cout << "DONE" << std::endl;
    cout << "Solutions: " << solutions << std::endl;
}

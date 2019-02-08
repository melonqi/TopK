#include <iostream>
#include "TopK.h"

//max-heap
bool max_heap_compare(const int &t1, const int &t2)
{
    return t1 > t2;
}
//min-heap
bool min_heap_compare(const int &t1, const int &t2)
{
    return t1 < t2;
}

int main()
{
    int array[] = {4, 5, 1, 9, 8, 0, 3, 2};
    int array_len = sizeof(array) / sizeof(array[0]);
    TopK<int> top_k(3, min_heap_compare);
    for (int i = 0; i < array_len; i++)
    {
        top_k.push(array[i]);
        std::vector<int> result = top_k.get();
        for (int i = 0; i < result.size(); i++)
        {
            std::cout << result[i] << " ";
        }
        std::cout << std::endl;
    }

    
    return 0;
}

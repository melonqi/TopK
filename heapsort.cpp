#include <iostream>

void build_heap(int array[], int array_len, int root)
{
    int left = root * 2 + 1;
    int right = root * 2 + 2;
    int largest = root;
    if (left < array_len && array[left] > array[largest])
    {
        largest = left;
    }

    if (right < array_len && array[right] > array[largest])
    {
        largest = right;
    }

    if (largest != root)
    {
        std::swap(array[largest], array[root]);
        build_heap(array, array_len, largest);
    }
}

void heap_sort(int array[], int array_len)
{
    //first build heap， make sure the tree is a heap
    for (int i = (array_len - 1) / 2; i >= 0; i--)
    {
        build_heap(array, array_len, i);
    }

    for (int i = array_len - 1; i >= 0; i--)
    {
        //put the max value to the last index
        std::swap(array[0], array[i]);
        build_heap(array, i, 0);
    }
}

void print_array(int array[], int array_len)
{
    for (int i = 0; i < array_len; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int array[] = {6, 9, 8, 1, 4, 2, 3, 5, 7};
    int array_len = sizeof(array) / sizeof(array[0]);
    heap_sort(array, array_len);
    print_array(array, array_len);
    return 0;
}
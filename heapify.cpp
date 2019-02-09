#include <vector>
#include <iostream>
using namespace std;

void build_heap(vector<int> &nums, int parent)
{
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    int largest = parent;
    int array_size = nums.size();
    //max-heap
    if (left < array_size && nums[left] > nums[largest])
    {
        largest = left;
    }
    if (right < array_size && nums[right] > nums[largest])
    {
        largest = right;
    }
    if (largest != parent)
    {
        std::swap(nums[largest], nums[parent]);
        build_heap(nums, largest);
    }
}

void heapify(vector<int> &nums)
{
    int array_size = nums.size();
    for (int i = (array_size - 1) / 2; i >= 0; i--)
    {
        build_heap(nums, i);
    }
}

int main()
{
    int array[] = {4, 9, 5, 7, 6, 8};
    vector<int> nums(array, array + sizeof(array)/sizeof(int));
    heapify(nums);
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << "\t";
    }
    cout << endl;
    return 0;
}

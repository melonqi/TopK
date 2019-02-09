//
// Created by melonqi on 2019/1/9.
//

#ifndef TOPK_H
#define TOPK_H

#include <vector>

template <typename T>

class TopK
{
  public:
	TopK(int k, bool (*compare_func)(const T &t1, const T &t2))
	{
		k_ = k;
		compare_ = compare_func;
		array_.reserve(k_);
	}

	bool push(const T &value);

	void heapify(int array_size);

	std::vector<T> get()
	{
		return array_;
	}

	void build_heap(int array_size, int root);

  private:
	int k_;
	std::vector<T> array_;
	bool (*compare_)(const T &t1, const T &t2);
};

template <typename T>
void TopK<T>::heapify(int array_size)
{
	for (int i = (array_size - 1) / 2; i >= 0; i--)
	{
		build_heap(array_size, i);
	}
}

template <typename T>
bool TopK<T>::push(const T &value)
{
	if (array_.size() < k_)
	{
		//array has less than k_ elements
		array_.push_back(value);
		heapify(array_.size());
		return true;
	}

	//array has k_ elements
	//user define compare func
	if (compare_ == NULL)
		return false;
	//if heap is min-heap, compare is less func, that is array[0] < value
	//if heap is max-heap, compare is greater func, that is array[0] > value
	if (compare_(array_[0], value))
	{
		//the value need to insert heap
		array_[0] = value;
		heapify(k_);
	}
	return true;
}

template <typename T>
void TopK<T>::build_heap(int array_size, int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	int target = root;
	if (left < array_size && compare_(array_[left], array_[target]))
	{
		target = left;
	}
	if (right < array_size && compare_(array_[right], array_[target]))
	{
		target = right;
	}
	if (target != root)
	{
		std::swap(array_[target], array_[root]);
		build_heap(array_size, target);
	}
}

#endif //TOPK_H

#include <iostream>
#include <random>


template<typename It>
It Partition(It beg, It end) {
	It pivot = end - 1;
	//int key = *pivot;
	auto first = beg;
	for (auto it = beg; it != end - 1; ++it) {
		if (*it <= *pivot) {
			std::swap(*first, *it);
			++first;
		}
	}
	//bug fixed: 2017/6/23 
	//ԭ��swap(*first, key)����������ɵ���������ǰ��Ѱַʱ����������Ϊ�����д�������������Ľ�����firstָ���ֵ��
	//pivotָ���ֵ��û�иı䡣
	std::swap(*first, *pivot);
	return first;
}

template<typename It>
It RandomPartition(It beg, It end) {
	static std::default_random_engine e;
	static std::uniform_int_distribution<unsigned> u(0, 9);
	auto range = end - beg;
	It pivot = beg + u(e) * range / 10;
	std::swap(*pivot, *(end - 1));
	return Partition(beg, end);
}


template<typename It>
void RandomQuickSort(It beg, It end) {
	if (end - beg > 1) {
		auto pivot = RandomPartition(beg, end);
		RandomQuickSort(beg, pivot);
		RandomQuickSort(pivot + 1, end);
	}
}
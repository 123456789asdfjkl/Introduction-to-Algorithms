#include <iostream>

//version A
template<typename It>
It PartitionA(It beg, It end) {
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
void QuickSort(It beg, It end) {
	if (end - beg > 1) {
		auto pivot = PartitionA(beg, end);
		QuickSort(beg, pivot);
		QuickSort(pivot + 1, end);
	}
}



//version B
template<typename It>
It PartitionB(It beg, It end) {
	It pivot = beg;
	int key = *beg;
	auto first = beg, last = end - 1;
	while (first < last) {
		while (first < last && *last > *pivot)
			--last;
		std::swap(*last, *pivot);
		pivot = last;
		while (first < last && *first <= *pivot)
			++first;
		
		std::swap(*first, *pivot);
		pivot = first;
	}
	return first;
}


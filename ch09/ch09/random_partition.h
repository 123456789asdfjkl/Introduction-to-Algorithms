#include <iostream>
#include <random>


template<typename It>
inline It Partition(It beg, It end) {
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
inline It RandomPartition(It beg, It end) {
	static std::default_random_engine e;
	static std::uniform_int_distribution<unsigned> u(0, 9);
	auto range = end - beg;
	It pivot = beg + u(e) * range / 10;
	std::swap(*pivot, *(end - 1));
	return Partition(beg, end);
}
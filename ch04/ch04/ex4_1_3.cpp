#include <iostream>
#include <tuple>



template<typename Continer>
std::tuple<Continer, int> FindMaxCrossingSubArr(Continer arr) {
	int leftsum = 0, rightsum = 0;
	auto sum = 0;
	auto mid = arr.begin() + arr.size() / 2;
	auto releft = arr.begin(), reright = arr.end();
	//auto end = arr.rend();
	auto times = mid - arr.begin() + 1;
	auto it = mid;
	
	while (times--) {
		sum += *it;
		if (sum > leftsum) {
			leftsum = sum;
			releft = it;
		}
		if (it != arr.begin())
			it--;
	}
	for (auto it = mid + 1; it != arr.end(); ++it) {
		sum += *it;
		if (sum > rightsum) {
			rightsum = sum;
			//modify 2017/6/9/22:08: �нᣬ��Ϊ������c++������ʵ�֣���������ұ߽磬��������һ��ʱָ��βԪ�ص���һ��Ԫ�ء�
			reright = it + 1;
		}
	}
	std::tuple<Continer, int> ret(Continer(releft, reright), leftsum + rightsum);
	return ret;
}



template<typename Continer>
std::tuple<Continer, int> FindMaxSubArr(Continer arr) {
	//modify 2017/6/9/22:06: ���߽������ĳ�<=2ʱ������if�����ʱarr�Ĵ�С������������Ԫ�أ������Ϳ��Ա���ݹ���������ʱarr��sizeΪ0�����⡣
	//������ԭ�ȵ�<=1,����������ʱarr��ֻ����һ��Ԫ�ء���Ȼ�ڡ��㷨���ۡ����е�����ʱֻ����һ��Ԫ�صı߽����������ǣ���ʱ����
	//��Ҫ����c++�����ԣ�����������ʵ�֡����ԣ�Ϊ�˱���ݹ�ʱ����arr��sizeΪ0�����⣬�����ô˷���ʵ�֡�

	//modify 2017/6/9/22:40: �����Է��֣�������ʵ���ڵ�arr��sizeΪ0ʱ��������tuple�е�Ԫ���ǽ�������õ��ģ�����ֻҪ�Ƚ�arr.begin()�Ƿ����
	//arr.end()�����������ʾarr��sizeΪ0������û��Ԫ�أ��ɽ�������tuple�е�sum��Ϊ0.
	if (arr.size() <= 1)
		return std::make_tuple(Continer(arr.begin(), arr.end()), arr.begin() == arr.end() ? 0 : *arr.begin());
	else {
		auto mid = arr.begin() + arr.size() / 2;
		auto left = FindMaxSubArr(Continer(arr.begin(), mid));
		auto right = FindMaxSubArr(Continer(mid + 1, arr.end()));
		auto cross = FindMaxCrossingSubArr(arr);		
		if (std::get<1>(left) >= std::get<1>(right) && std::get<1>(left) >= std::get<1>(cross))
			return left;
		else if (std::get<1>(right) >= std::get<1>(left) && std::get<1>(right) >= std::get<1>(cross))
			return right;
		else
			return cross;
	}
}
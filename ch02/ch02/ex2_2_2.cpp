#include <iostream>



//notice: ע����ѭ����i�ķ�Χ��[0, len-1),��Ϊ����i���Ͻ�Ϊlenʱ�����һ��ѭ����i����ȡlen-1, �ڲ�ѭ����j��Ϊlen.
//��j��С��len���ʲ�����뵽�ڲ�ѭ��������i�ķ�ΧΪ[0,len-1)ʱ���Ѿ��㹻���������������е�Ԫ�ء�
template<typename Continer>
void SelectSort(Continer &arr) {
	int len = arr.size();
	for (int i = 0; i < len - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < len; ++j) {
			if (arr[j] < arr[min])
				min = j;
		}
		if (min != i) {
			auto tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}	
	}
}
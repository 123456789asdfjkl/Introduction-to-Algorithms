#include <iostream>

#define NIL -1


//notice: �˴��趨������ģ�����������Ϊ����һ������Ҫ������Ǹ����飬���ڶ�����Ҫ����
//����Ϊ��������ĳ��ֵ��
template<typename T, typename N>
int FindValue(T arr, N v, int len) {
	for (int i = 0; i < len; ++i) {
		if (arr[i] == v)
			return i;
	}
	return NIL;
}
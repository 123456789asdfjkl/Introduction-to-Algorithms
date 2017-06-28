#include <iostream>



template<typename Continer>
inline Continer CountingSort(Continer A, int k) {
	Continer C(k + 1, 0), B(A.size(), 0);
	for (int i = 0; i < A.size(); ++i)
		C[A[i]]++;
	for (int i = 1; i <= k; ++i)
		C[i] = C[i - 1] + C[i];
	for (int j = A.size() - 1; j > 0; --j) {
		//�����Ǵ�0��ʼ����Ҫ������C��ӦԪ����ΪB���±���������ݣ���Ҫ��һ��
		B[C[A[j]] - 1] = A[j];
		C[A[j]]--;
	}
	return Continer(B.begin() + 1, B.end());
}





#include <iostream>
#include <vector>
#include "randomized_select.h"



int main() {
	std::vector<int> v1{ 5, 3, 8, 2, 1, 6 };
	int i = 1;
	int key = RandomizedSelect(v1, i);
	std::cout << "��" << i << "С��Ԫ����: " << key << std::endl;
	system("pause");
	return 0;
}
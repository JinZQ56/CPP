#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

// since c++20

void fun0()
{
	// ranges可以使用容器而非迭代器作为输入
	std::vector<int> x{ 1,2,3,4,5 };
	auto it1 = std::find(x.begin(), x.end(), 3);
	std::cout << "find: " << *it1 << std::endl;
	auto it2 = std::ranges::find(x, 3);
	std::cout << "ranges::find: " << *it2 << std::endl;
}




#include <iostream>
#include <vector>
#include <typeinfo>

void fun0()
{
	// Iterator
	std::vector<int> x{ 1,2,3 };
	auto b = x.begin(); //cbegin, c代表constant，是只读的
	std::cout << typeid(b).name() << "\n";
	auto e = x.end();
	for (auto ptr = b; ptr < e; ++ptr) 
	{
		std::cout << *ptr << " ";
		// *ptr = *ptr + 1
	}
}

int main()
{
	fun0();
}
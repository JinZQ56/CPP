#include <iostream>
#include <string>

int fun1(int x, int y)
{
	return x + y;
}

int fun1(int x, int y, int z)
{
	return x + y + z;
}

int fun2(int x)
{
	return x + 1;
}

double fun2(double x)
{
	return x + 1;
}

void fun3()
{
	std::cout << "限定名称查找，全局域" << '\n';
}

void fun4()
{
	std::cout << "global" << '\n';
}

namespace myns
{
	void fun3()
	{
		std::cout << "限定名称查找，myns域" << '\n';
	}

	void fun5()
	{
		fun3();
		fun4();
	}

	struct str {};

	void fun6(str x)
	{
		std::cout << "Argument Dependent Lookup:ADL" << '\n';
	}
}

void fun7(int)
{
	std::cout << "int" << '\n';
}

/*
void fun7(const int)
{
	std::cout << "const int" << '\n';
}
*/ 

void fun7(std::string)
{
	std::cout << "string" << '\n';
}

void fun7(bool, float)
{
	std::cout << "bool and float" << '\n';
}
void fun7(int,double)
{
	std::cout << "int and double" << '\n';
}

int main()
{
	std::cout << fun1(1, 2) << '\n';
	std::cout << fun1(1, 2, 3) << '\n';
	std::cout << fun2(3) << '\n';
	std::cout << fun2(3.5) << '\n';

	::fun3(); //qualified lookup
	myns::fun3();

	myns::fun5(); //unqualified lookup
	//逐级查找

	myns::str val;
	fun6(val); //实参依赖查找

	fun7(3);
	fun7(1, 1.1);
}
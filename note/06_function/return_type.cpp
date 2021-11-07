#include <iostream>

//函数详解--返回类型
int fun1(int a, int b)
{
	return a + b;
}

//返回类型的书写方式
//经典方法:位于函数头的前部

//c++11 引入方式：位于函数头后部
//泛型函数和类中有用
auto fun2(int a, int b) -> int
{
	return a - b;
}

//C++14 引入的方式：返回类型的自动推导
auto fun3(int a, int b)
{
	if (a > b)
	{
		return 1;
	}
	else
	{
		//return 0.1;
		return -1; //return后表达式类型应该相同
	}
}

decltype(auto) fun4()
{
	int x=10;
	return x;
}

constexpr bool value = true; //编译期常量
auto fun5()
{
	if constexpr (value)
	{
		return 1;
	}
	else
	{
		return 1.0;
	}
}
//运行期返回类型唯一


//返回类型与结构化绑定
struct str 
{
	int x;
	int y;
};

str fun6()
{
	str x = { 1,2 };
	return x;
}

//[[noiscard]]属性 （c++17）
[[nodiscard]]int fun7(int a, int b)
{
	return a + b;
}

int main()
{
	//类型自动推导，c++11
	auto x = 3;
	decltype(3) y = 4;

	//c++14
	decltype(auto) z = 5;

	auto [res1, res2] = fun6();
	std::cout << res1 << ' ' << res2 << '\n';

	fun7(2, 3);
}
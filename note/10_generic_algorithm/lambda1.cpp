#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <memory>
#include <string>

void fun0()
{
	// lambda表达式构造了一个对象
	auto l = [](int val) {return val > 3; };
	std::cout << l(5) << std::endl;

	// 显示指定返回类型
	auto l1 = [](int val) -> float {return 1; };
	std::cout << l1(5) << std::endl;

	// 捕获：针对函数体中使用的局部自动对象进行捕获
	// static int y = 10; //static 时不需要捕获y
	int y = 10;
	auto l2 = [y](int val) { return val > y; };
	std::cout << l2(11) << std::endl;

	// 值捕获
	auto l3 = [y](int val) mutable {++y; return val > y; };
	std::cout << y << std::endl;
	std::cout << l3(11) << std::endl;

	// 引用捕获
	auto l4 = [&y](int val) {++y; return val > y; };
	std::cout << y << std::endl;
	std::cout << l4(11) << std::endl;

	// 混合捕获
	int z = 5;
	auto l5 = [&y, z](int val) {++y; return val > z; };
	std::cout << y << std::endl;
	std::cout << l5(11) << std::endl;

	// =可以自动进行值捕获
	auto l6 = [=](int val) { return val > z; };
	// &自动进行引用捕获
	auto l7 = [&](int val) { ++y; return val > z; };
	// 仅对z进行值捕获 
	auto l8 = [&, z](int val) { ++y; return val > z; };
}

// this 关键字
// 指向结构体
struct str
{
	auto fun()
	{
		int val = 3;
		auto l = [val, this]() {return val > x; };
		return l();
	}
	auto fun1()
	{
		int val = 3;
		// *this 为this的解引用，对象会被复制到lambda表达式的内部，不再保存指针
		auto l = [val, *this]() {return val + x; };
		return l;
	}
	int x=3;
};

// 初始化捕获 since c++14
void fun1()
{
	int x = 10;
	auto l = [y = x](int val) {return val > y; };
	std::cout << l(11) << std::endl;

	//可以定义更复杂的逻辑
	std::string s = "hello";
	auto l1 = [y = std::move(s)](){std::cout << y << std::endl; };
	l1();
	std::cout << "after move: " << s << std::endl;
}

// *this 捕获 since c++17
auto wrapper()
{
	str s;
	return s.fun1();
}

// 说明符
void fun2()
{
	// multable
	// 取消constant
	int y = 3;
	auto l = [y](int val) mutable {++y;  return val > y; };

	// constexpr
	// 在编译期可以进行调用
	auto l1 = [](int val) constexpr { return val + 1; };
	constexpr int val = l1(100);
	std::cout << val << std::endl;
}

// 模板形参 since c++20
void fun3()
{
	auto l = []<typename T>(T val) { return val + 1; };
}


int main()
{
	// fun0();
	/*
	str s;
	s.x = 2;
	std::cout << s.fun() << std::endl;
	*/
	//fun1();
	//auto l = wrapper();
	//std::cout << l() << std::endl;
	fun2();
}
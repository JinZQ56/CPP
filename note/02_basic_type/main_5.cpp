#include <iostream>
#include <type_traits>

//类型别名与类型的自动推导

typedef int myint; //引入类型别名
using Myint = int; //C++11种引入类型别名的方式

//using引入类型别名更友好
typedef char mychararr[4];
using MyCharArr = char[4]; //使用using定义更加清晰

void fun_0()
{
	myint x = 3;
	Myint y = 4;
	size_t z = 5;
}

//类型别名与指针、引用的关系

using IntPtr = int*; 

//不能通过类型别名定义引用的引用
using RefInt = int&;
using RefRefInt = RefInt&;

void fun_1()
{
	int x = 3;
	const IntPtr ptr = &x;
	//此处不等价于 const int* ptr = &x;
	//此处等价于 int* const ptr = &x;
	//可以理解为const修饰IntPtr，而不是修饰int

	std::cout << std::is_same_v<RefInt, RefRefInt> << std::endl;
	std::cout << std::is_same_v<RefInt, int&> << std::endl;
	std::cout << std::is_same_v<int&, RefRefInt> << std::endl;
}

//类型的自动推导

void fun_2()
{
	int x = 3.5 + 15l;
	std::cout << x << '\n';

	auto y = 3.5 + 15l; //y的类型不是显示定义的，由编译器定义
	std::cout << y << '\n'; 
	std::cout << sizeof(y) << '\n';
	std::cout << sizeof(float) << '\n';
	std::cout << sizeof(double) << '\n';

	long double z = 10.8888;
	std::cout << sizeof(z) << '\n';
}

void fun_3()
{
	//自动推导的常见形式

	auto x1 = 6; //auto可能会出现类型退化
	
	int& x2 = x1;
	int x3 = x2; //int& 退化为int
	auto x4 = x2; //x4的类型是int，而不是int&

	const auto x5 = 3;  //x5类型为const int
	constexpr auto x6 = 4; //x6类型为const int
	const auto& x7 = 3; //x7类型const int&

	const int x8 = 5;
	const auto x9 = x8; //x9类型为const int
	auto x10 = x8; //x10的类型为int，因为const int作为等式右值时产生退化

	auto& x11 = x8; //x11类型为const int&，因为auto&不会引起等式右侧的类型退化
	const int& x12 = 6;
	auto& x13 = x12; //x13类型为const int&
}

void fun_4()
{
	//decltype关键字,不会产生类型退化
	//decltype(exp) 返回exp表达式的类型
	//decltype(val) 返回val的类型 

	auto x1 = 3.5 + 15l;
	decltype(3.5 + 15l) x2 = 3.5 + 15l;

	int x3 = 3;
	int& x4 = x3;
	auto x5 = x4; //由于类型退化，x5类型为int
	decltype(x4) X6 = x4; //x6类型为int&，不产生类型退化

	int x7 = 3;
	int* ptr = &x7;
	//decltype(exp) 左值加引用
	/*
	ptr -> int*
	*ptr -> int
	decltype(*ptr) -> int&
	*/
	//因为*ptr是带操作符的表达式，表达式且是左值时带引用
	//变量名词，或表达式为右值时(如 3.5+15l)，不带引用
	decltype(x7); //类型为int
	decltype((x7)); //类型为int& 

	//decltype(auto) 由C++14引入，简化decltype的使用
	decltype(auto) x = 3.5 + 15l;

	//concept auto 由C++20开始支持，表示一系列类型
}

int main()
{
	fun_2();
	int x = 3;
	int* y = &x;
	x = *y + 2;
	std::cout << x << std::endl;
	std::cout << *y << std::endl;
}
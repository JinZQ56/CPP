#include <iostream>
#include <vector>
#include <string>

//数值模板参数
//template <typename T, T x>
//template <auto x> since c++17
template<int x>
void fun1(int y)
{
	std::cout << x + y << std::endl;
}

// 模板模板参数
// 参数一般为类模板
// template<template<typename> class C>
// template<template<typename> typename T>
template<template<typename T> class C>
void fun2()
{
	std::cout << "too hard for me" << std::endl;
}

template <typename T>
class cla{};

// 别名模板
template <typename T>
using pointer = T*;

// 变长行模板
// type... Args
template <int... x>
void fun3() {};
// typename|class...Args
template <typename... T>
void fun4(T... args) { std::cout << sizeof...(T) << std::endl; };
// template < parameter-list > typename(C++17)|class ... Args
template <template<typename>class... C>
void fun5() {};

// 包展开
void fun6()
{

}

template <typename U, typename... T>
void fun6(U u, T... args)
{
	// &args... 为包展开
	// &args 为模式
	std::cout << u << std::endl;
	fun6(args...);
}

// 折叠表达式 c++17
template <typename... T>
void fun7(T... args)
{
	((std::cout << args << std::endl), ...);
}

template <typename... Args>
void sum(Args... args)
{
	// 先从最右端结合
	std::cout << (args + ...) << std::endl;
	// 先从最左端结合
	std::cout << (... + args) << std::endl;
}

int main()
{
	// A 数值模板参数
	// 模板可以接收（编译器常量）数值作为模板参数
	// template <int x> class cla
	// template <typename T, T x> class cla 控制数值的类型
 	// template <auto x> since c++ 17 auto 可以是数值 int bool char等
	// 接收字面值类对象与浮点数作为模板参数 since c++ 20
	fun1<3>(5);

	// B 模板模板参数
	// template<template<typename T>class C> class cla
	// template<template<typename T>typename C> class cla since c++ 17
	fun2<cla>();

	// C 别名模板
	// 使用using引入别名模板
	// 为模板本身引入别名
	// 为类模板的成员引入别名
	pointer<int> x = nullptr;

	// D 变长模板
	// variadic template
	// 通过形参包实现 parameter pack
	// 模板形参和函数形参都可以使用参数包
	// 变长模板参数可以是数值，类型或模板

	// D.1 type...Args
	fun3<1, 2, 3>();
	// D.2 typename... Args
	fun4<int, bool, char>(1, true, 'c');
	// D.3 template < parameter-list > typename(C++17)|class ... Args
	fun5<cla, cla, cla>();

	// 参数包最好是最后一个参数
	// sizeof...() 可以获取参数包中参数的个数

	// E 包展开
	// 通过包展开计数操作边长模板参数
	// 参考 cppreference
	fun6(1, 2, "hello", 'c');

	// F 折叠表达式
	// since c++ 17
	// 基于逗号的折叠表达式应用
	// 折叠表达式用于表达式求值，无法处理输入（输出）是类型与模板的情形
	// c++ reference fold expression
	fun7(1, 2, "hello", 'c');
	sum(1, 2, 3, 4, 5);


	std::cout << "complied successfully" << std::endl;
	

}
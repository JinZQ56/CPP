#include <iostream>
#include <vector>
#include <string>
// #include "header.h"

// 模板的声明
template <typename T>
void fun(T x);

// 模板的定义
template <typename T>
void fun(T x)
{
	std::cout << "template: " << x << std::endl;
}

// 对模板进行显式实例化
template void fun<int>(int x);
// 编译器可以推导时，可以省略模板参数
// template void fun(std::string x);

// 模板的特化
template <>
void fun<std::string>(std::string x)
{
	std::cout << "specialization of template: " << x << std::endl;
}

int main()
{
	// A 函数模板的实例化控制
	// 显式实例化定义 将模板显式实例化成函数，但是并不调用
	// template void fun<int>(int x)
	// template void fun(int x)

	int x = 3;
	fun<int>(x);
	// 此时编译器会直接调用显式实例化的函数

	// 显式实例化声明 表明可能会使用到此函数，但不是在当前单元定义的
	// extern template void fun_h<int>(int x)
	// extern template void fun_h(int x)
	// 可以不需要重复显式实例化定义 减轻编译器负担和链接的负担

	// B 函数模板的（完全）特化
	// 完全特化的完全表示 必须同时给出函数模板的所有形参
	// 并不引入新的名称，只是为某个模板针对特定模板参数进行优化
	// 本质上就是一个函数模板的实例（与类的特化有区别，类有完全特殊，此时是实例，有部分特化，此时不引入实例）
	// template<> void fun<int>/int x)
	// template<> void fun(int x)
	std::string s = "abc";
	fun<std::string>(s);

	// 与重载的区别
	// 重载：引入新的同名名称
	// 特化：不引入新的同名名称

	// C 避免使用函数模板的特化
	// 通常可以用重载代替特化
	// 不便于重载的情况：无法建立模板形参与函数形参的关联
		// 用 if constexpr(std::is_sam_v<x, int>)
		// 引入辅助函数形参
		// 通过类的模板特化解决 

	// D 函数模板的简化形式：使用auto定义模板参数的类型
	// since C++ 20
	
	// void fun(auto x) {}
	// void fun(auto& x) {}
	// void fun(auto&& x) {}
	// 缺点：需要在函数内部间接获取参数类型信息

}
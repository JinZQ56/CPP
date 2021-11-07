#include <iostream>
#include <vector>
#include <string>

// 类模板定义
template<typename T1, typename T2>
class cla
{
public:
	void fun() { std::cout << "normal" << std::endl; }
};

// 实例化类模板
template class cla<int, int>;
// 实例化类模板的成员函数
template void cla<double, double>::fun();

// 完全特化类模板
template <>
class cla<std::string, std::string>
{	
public:
	// 可以完全不同 例如 void fun2() {}
	void fun() { std::cout << "full specialization" << std::endl; }
};

// 部分特化类模板
template <typename T2>
class cla<float, T2>
{
public:
	void fun() { std::cout << "part specialization" << std::endl; }
};


int main()
{
	// A 类模板的实例化
	// 实例化整个类
	// 实例化某个成员函数
	
	// B 类模板的完全特化/部分特化（偏特化）
	// 特化版本和基础版本可以有完全不同的实现
	cla<int, int> c1;
	c1.fun();

	cla<std::string, std::string> c2; // 完全特化
	c2.fun();

	cla<float, int> c3; // 部分特化
	c3.fun();
	
	// C 类模板的实参推导（since C++ 17）
	// 基于构造函数的实参推导
	// 用户自定义的推导指引 cpp-reference
	
}
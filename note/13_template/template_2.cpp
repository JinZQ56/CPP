#include <iostream>
#include <vector>
#include <string>
#include <utility>

// 完美转发
void f(int&)
{
	std::cout << "l.value" << std::endl;
}

void f(int&&)
{
	std::cout << "r.value" << std::endl;
}

template <typename T>
void fun(T&& input) // T&&万能引用
{
	std::cout << "Hello world" << std::endl;
	f(std::forward<T>(input)); // 根据T的类型 将input转换为左值或右值
}

// 消除歧义
class cla
{
public:
	using internal = int;

	template <typename T>
	static void fun()
	{

	}
};

template <typename T>
void fun2()
{
	typename T::internal* p = nullptr;
	// 可以理解为p指针
	// 也可以理解为两个数相乘
	// 此处使用template表示一个依赖名称是类型而不是静态数据成员

	T::template fun<int>();
	// 可以理解为类中的函数
	// 也可以理解为比较大小
	// 此处使用template表示一个依赖名称是模板

	T obj;
	obj.template fun<int>();
}

// 变量模板
template <typename T>
T pi = (T)3.1415926;

template <typename T>
unsigned Mysize = sizeof(T);

int main()
{
	// A 完美转发
	// std::forward<>()
	// 通常与万能引用相结合
	// 同时处理传入参数是左值和右值的情形

	int x = 3;
	f(x); // 左值
	f(3); // 右值

	fun(x);
	fun(3);

	// B lambda表达式模板
	// since C++ 20

	// C 消除歧义
	// 使用typename和template
	// 使用typename表示一个依赖名称是类型而非静态数据成员
	// 使用template表示一个依赖名称是模板
	// template与成员函数模板调用

	fun2<cla>();
	
	// D 变量模板
	// since C++ 14
	// template <typename T> T pi=(T)3.1415926;
	// 其它形式
	std::cout << pi<int> << std::endl;
	std::cout << pi<float> << std::endl;
	std::cout << pi<double> << std::endl;
}
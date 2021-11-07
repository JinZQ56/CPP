#include <iostream>
#include <vector>
#include <string>
#include <functional>

class cla
{
public:
	cla() = default;
	cla(int val, const std::string& str)
		: x(val)
		, y(2*val)
		, s(str)
	{}

	void print(int val)
	{
		std::cout << val << std::endl;
	}

public:
	int x = 0;
	int y = 1;
	std::string s;

};

int main()
{
	// A 成员指针
	// 成员变量指针类型 int cla::*
	// 成员函数指针类型 int(cla::*)(double)
	// 成员指针对象赋值 auto ptr = &cla::x
	// 域操作符的子表达式不能加小括号 &(cla::x) 这种写法是错的 因为符号优先级的原因

	// 成员变量指针
	int cla::*ptr; // *ptr 是一个指针，指向cla域中的成员变量，类型为int
	// ptr 的类型为int cla::*
	std::cout << std::is_same_v<int cla::*, decltype(ptr)> << std::endl;

	// 成员函数指针
	void (cla:: * ptr_fun)(int); //*ptr_fun是一个指针，指向cla域中的函数，类型为void，接收0个参数

	// 指针初始化
	int cla::* p1 = &cla::x;
	int cla::* p2 = &cla::y;
	void (cla:: * p3)(int) = &cla::print;

	// 成员指针的使用
	// 对象.*成员指针 c.*ptr
	// 对象指针->*成员指针
	// .* -> 也可以理解为 pointer-to-member 操作符
	cla c(3, "abc");
	cla* p_c = &c;
	std::cout << c.*p1 << std::endl; // .是成员操作符 操作p1指向的成员
	std::cout << p_c->*p1 << std::endl; // p_c是指向对象的指针 此时使用 ->*
	(c.*p3)(100);
	
	// B 与bind交互
	auto pri = std::bind(p3, c, 100); // 引入类的对象作为第二个参数传入bind
	pri();

	// 可以使用bind构建基于数据成员的可调用对象
	auto x = std::bind(p1, c);
	std::cout << x() << std::endl;
 



}
#include <iostream>
#include <vector>

struct str
{
	int x;
	int y;

	// 成员函数（方法）
	void print() // 隐式内联
	{
		std::cout << x << " " << y << std::endl;
		// std::cout << this->x << " " this->y << sthd::endl;
		std::cout << this << std::endl; // this指针引用当前对象
	}
};

struct str1
{
	int x;
	int y;
	// 成员函数（方法）
	void print(); // 类内声明，类外定义
};

struct str2
{
	int x;
	int y;
	using MyRes = int;
	// 成员函数（方法）
	MyRes get(); // 类内声明，类外定义
};

// str2::MyRes str2::get() 
auto str2::get() -> MyRes //trail returning type
{
	return x;
}

void str1::print() // 此时不是内联，需要加inline
{
	std::cout << x << " " << y << std::endl;
}

class cla
{
public:
	int x;
	int y;
	// 成员函数（方法）
	void print() // 隐式内联
	{
		std::cout << x << " " << y << std::endl;
	}
};

void fun0()
{
	str s{ 1,2 };
	s.print();

	cla c{ 1,2 };
	c.print();

	str1 s1{ 1,2 };
	s1.print();

	str2 s2{ 1,2 };
	std::cout << s2.get() << std::endl;
}

struct str3
{
	// const str3* const this //表示指针和指针的指向都不可以修改
	void fun(int x) const // const表示函数不能对内部成员进行修改
	{
		std::cout << x << std::endl;
		std::cout << this->x << std::endl;
	}
	// str3* const this // this指针是const 不可修改
	void fun(int x) // 函数可以重载
	{
		std::cout << x << std::endl;
		std::cout << this->x << std::endl;
	}
	void fun1(int x);
	int x;
};

int x;

inline void str3::fun1(int x)
{
	x; //函数形参x
	this->x; //类内成员x
	str3::x; //类内成员x
	::x; //全局域x
}

void fun1()
{
	// 成员函数与this指针
	str s1{ 1,2 };
	std::cout << "s1: " << std::endl;
	s1.print();
	std::cout << &(s1) << std::endl;
	str s2{ 3,4 };
	std::cout << "s2: " << std::endl;
	s2.print();
	std::cout << &(s2) << std::endl;
}

struct str4
{
	static int fun() //静态成员函数，被所有对象共享
	{
		// 不能在静态成员函数中使用非静态的成员
		return x;
	}
	static int x; 

	static auto& fun1()
	{
		inline static std::vector<int> x; //仅当被使用的适合才会被构造 
		return x;
	}
	
	// 模式设计中的典型单例模式
	static auto& instance()
	{
		static int x;
		return x;
	}
	
};

int str4::x;

void fun2()
{
	str4 s1;
	str4 s2;
	std::cout << str4::fun() << std::endl;
	//静态成员函数的调用
}

int main()
{
	// fun0();
	// fun1();
	fun2();
} 
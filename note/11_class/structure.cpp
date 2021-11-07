// 结构体和对象聚合
#include <iostream>
#include <vector>
#include "header.h"

struct str; // 结构体的声明

struct str // 结构体定义
{
	int x;
	int y;
};
//结构体内部包含数据成员打的声明

struct str1
{
	decltype(3) x; //能用decltype，不能用auto
	int y = 3; //类内成员可以初始化
	const int z = 6;
};

struct str2
{
	// mutable 可更改的
	mutable int x = 0;
	mutable int y = 1;
};

struct str3
{
	// 静态数据成员
	static int x;
	int y = 1;
};

int str3::x; // 静态成员类内声明，类外定义

extern int x; //声明
int x; // 变量的定义



void fun0()
{
	str s;
	s.x = 3;
	s.y = 5;
	std::cout << s.x << " " << s.y << std::endl;

	// 聚合初始化
	str1 ss{ 1, 2, 3 };
	// const 在ss被定义时才被关联到3，如果不赋值则关联到6
	// const之后不能修改
	// since c++ 20 ： 指派初始化器
	// str1 sss{.x = 1, .y =2, .z = 3}
	// 防止结构体调整后初始化错误
	std::cout << ss.x << " " << ss.y << " " << ss.z << std::endl;

	// mutable
	// 声明时加mutable 可以更改const的struct对象
	// 例如需要在类或结构体内定义计数器
	const str2 s1;
	s1.x = 5;
	s1.y = 6;
	std::cout << s1.x << " " << s1.y << std::endl;
}

void fun1()
{
	// 静态数据成员
	str3 s1;
	str3 s2;
	s1.x = 100;
	std::cout << s2.x << std::endl;

	str4 s3;
	std::cout << &(s3.array_size) << std::endl;

	str5 s4;
	std::cout << &(s4.array_size) << std::endl;
}

void fun2()
{
	// 静态数据成员的访问
	str3 s3;
	s3.x = 80;
	str3* p3 = &s3;
	std::cout << str3::x << std::endl; // 域操作符，仅用于静态数据成员
	std::cout << s3.x << std::endl;
	std::cout << p3->x << std::endl;

	str4 s4;
	str4* p4 = &s4;
	std::cout << str4::array_size << std::endl;
	std::cout << s4.array_size << std::endl;
	std::cout << p4->array_size << std::endl;

}

// 在类的内部声明相同类型的静态数据成员
struct str6
{
	static str6 s; //静态数据成员被所有对象共享，不属于单独某个对象
	// inline static str6 s; // 此种方法不好使
};

// str6 str6::s;
inline str6 str6::s;

void fun3()
{
	str6 s1;
	str6 s2;
	//s1.s = s2;
	std::cout << &(s1.s) << std::endl;
}

int main()
{
	// fun0();
	// fun1();
	// fun2();
	fun3();
}
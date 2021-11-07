#include <iostream>
#include "function.h"
#include <initializer_list>

void fun1(void)  //void可以显示的表示函数不包含任何参数
{
}

void fun2(int) //形参可以不赋予名称，用在需要预留接口的情况下
{
	//形参名称的不同不会引入函数版本的不同
}

struct str
{
	str() = default;
	str(const str&)
	{
		std::cout << "Copy constructor is called.\n";
	}
};

void fun3(str)
{
	//c++17强制省略复制临时对象
}

void fun4(int par)  //传值
{
	++par;
}

void fun5(int* par) //传址
{
	++(*par);
}

void fun6(int& par)
{
	++par;
}

void fun7(int* ptr) //函数传参过程中的类型退化
{
}

void fun8(int (*ptr)[4])
{
}

void fun9(std::initializer_list<int> par) //可变参数数量
{
	//使用initiallizer_list 
}

//如果某个形参具有缺省实参，那么它右侧的形参都必须具有缺省实参

//void fun10(int x, int y, int z = 3);
//void fun10(int x, int y = 2, int z); 
void fun10(int x, int y = 2, int z)
{
	std::cout << x + y + z << '\n';
}

int main(int argc, char* argv[])
{
	/*
	std::cout << add(3, 2) << '\n';
	std::cout << sub(3, 2) << '\n';
	*/
	 
	/*
	str val;
	fun3(val);
	fun3(str{});
	*/

	int arg = 3;
	fun4(arg);
	std::cout << "传值：" << arg << '\n';
	fun5(&arg);
	std::cout << "传址：" << arg << '\n';
	fun6(arg);
	std::cout << "传引用： " << arg << '\n';

	int a[3];
	fun7(a); //数组传入函数后退化为指针
	//使用引用可以防止退化  void fun(int (&par)[3])
	//此时，数组长度也必须对应

	int b[3][4];
	fun8(b);

	fun9({ 1,2,3,4,5 });

	fun10(1);
}

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}
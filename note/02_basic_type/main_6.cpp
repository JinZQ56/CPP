#include <iostream>

//域与对象的生命周期

//global scope 全局域 定义全局对象
int x = 3;

//名字空间域
namespace MyNS
{
	int x = 5;
}

void fun_0()
{
	//block scope 块域 定义局部对象
	int x = 4;
	std::cout << x << std::endl;  //系统会 选择局部域中的x，在局部域中把全局域隐藏了
	{
		int x = 6;
		std::cout << x << std::endl;
	}
}


int main()
{
	fun_0();

	std::cout << x << std::endl;

	int x = 7;  //此处x的生命周期起始于此处
	std::cout << x << std::endl;
}
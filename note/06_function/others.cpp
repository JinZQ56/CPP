#include <iostream>

//递归函数
//用于描述复杂的迭代过程 

//内联函数
//由编译器决定是否复制
void fun1()
{
	std::cout << "Hello World!" << '\n';
}

inline void fun2()
{
	std::cout << "Hello World!" << '\n';
}


//constexpr函数(c++11)
//既可以在编译期被调用，又可以在运行期被调用
//函数内部代码必须能够在编译期内执行 
constexpr int fun3(int x)
{
	return x;
}

//consteval函数(c++20)
//只能在编译期被调用
/*
consteval int fun4(int x)
{
	return x;
}
*/

//函数指针
//函数类型和函数指针类型
int fun5(int val)  // int(int)
{
	return val + 1;
}

int add(int val)
{
	return val + 1;
}

int sub(int val)
{
	return val - 1;
}

using F = int(int);
F fun6;  //函数声明，fun6是一个int(int)类型的函数
F* fun7; //函数指针

int fun8(F* subfun, int val)
{
	auto tmp = (*subfun)(val);
	return tmp * tmp; 
}

int fun9(F f, int val)
{
	return f(val);
}

//函数的返回类型不能是函数
//可以返回函数指针
F* fun10(bool val)
{
	if (val) { return add; }
	else { return sub; }
}

using f = void(void);

void fun11()
{
	std::cout << "test" << '\n';
}

void fun12(f fun)
{
	fun();
}



//函数指针与重载

int main()
{
	fun2(); //将函数内容直接复制到main函数中 

	constexpr int x = fun3(1);
	std::cout << "编译期：" << x << '\n';
	int y;
	std::cin >> y;
	std::cout << "运行期：" << fun3(y) << '\n';

	std::cout << "函数指针" << '\n';
	fun7 = &add;
	std::cout << fun7(2) << '\n';
	fun7 = &sub;
	std::cout << fun7(2) << '\n';

	std::cout << "函数指针作为函数参数" << '\n';
	std::cout << fun8(&add, 2) << '\n';
	std::cout << fun8(&sub, 2) << '\n';

	std::cout << fun8(add, 2) << '\n';
	std::cout << fun9(sub, 2) << '\n';

	std::cout << fun10(true)(2) << '\n';
	std::cout << fun10(false)(2) << '\n';

	std::cout << add(sub(3)) << '\n';
}
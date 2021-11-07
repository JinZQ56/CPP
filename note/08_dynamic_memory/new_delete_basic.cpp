#include <iostream>
#include <new>

void fun0()
{
	//栈内存
	int x = 1;
	std::cout << x << '\n';

	//堆内存
	//new创建大小为int的堆内存，并将2保存到指针y中
	//new返回内存对应的地址
	int* y = new int(2);
	std::cout << *y << '\n';
	delete y;
}

int* fun1()
{
	int res = 1;
	return &res;
	//代码非常危险，指向了临时对象
}

int* fun2()
{
	int* res = new int(2);
	return res;
}

void fun3()
{
	int* x = new int[5];
	//创建连续5个int大小的内存，将首地址返回给x
	delete[] x;
	//中括号表示要删除数组

	int* y = new int[5]{ 1,2,3,4,5 };
}

void fun4()
{
	//nothrow new
	int* y = new (std::nothrow) int[5]{};
	if(y==nullptr)
	{//... 
	}
	//分配内存失败不会导致进入异常处理，而是返回nullptr

	//placement new
	char ch[sizeof(int)];
	int* z = new (ch) int(4);
	std::cout << *z << '\n';
	//使用ch开辟的内存将4构造出来

	//new auto
	//根据表达式类型自动推导
	int* x = new auto(3);
}

struct alignas(256) Str{};
//地址对齐，256的整数倍

void fun5()
{
	//placement delete

	//delete nullptr
	int* x = 0;
	if (x==0)
	{
		x = new int(3);
	}
	delete x;

	//不能delete一个非new返回的内存
	//int x;
	//delete& x;

	//delete删除内存但不删除ptr
	//ptr为栈中的对象，指向堆中的内存
	int* ptr = new int(3);
	std::cout << "before delete:" << ptr << '\n';
	delete ptr;
	std::cout << "after delete:" << ptr << '\n';

	//不能删除非new返回的内存
	int* pt = new int[5];
	int* pt2 = (pt + 1);
	delete[] pt2;
}

int main()
{
	//fun0();

	//int* x = fun1();
	//std::cout << *x << '\n';

	//int* y = fun2();
	//std::cout << *y << '\n';

	//int x[5];
	//std::cout << x[0] << '\n';
	//int* y = new int[5];
	//std::cout << y[0] << '\n';

	//fun4();

	//Str* s = new Str();
	//std::cout << s << '\n';

	//fun5();

	//int* ptr = new int(3);
	//std::cout << "before delete:" << ptr << '\n';
	//delete ptr;
	//ptr = nullptr;
	//std::cout << "after delete:" << ptr << '\n';
	//delete ptr;

	//int* pt = new int[5];
	//int* pt2 = (pt + 1);
	//delete[] pt2;

	//调整系统自身的new/delete行为
	//不要轻易使用

}  

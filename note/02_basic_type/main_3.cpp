#include <iostream>

void fun_0()
{
	//指针可以指向不同的对象
	int x = 1;
	int y = 2;
	int* p = &x; //也可以写为int *p
	p = &y;
	std::cout << y << std::endl;
	std::cout << (&y) << std::endl;
	std::cout << *p << std::endl;
	std::cout << p << std::endl;

	//指针具有相同的尺寸
	int i = 1;
	char c = 'a';
	int* p1 = &i;
	char *p2 = &c;
	std::cout << sizeof(p1) << std::endl;
	std::cout << &i << std::endl;
	std::cout << p1 << std::endl;
	std::cout << sizeof(p2) << std::endl;
	//std::cout << &c << std::endl;
	//std::cout << p2 << std::endl;

	//int* p3;
	//std::cout << p3 << std::endl;
	//指针初始化 使用零指针
	int* p4 = 0; //int* p4=NULL;
	int* p5 = nullptr; //C++11新特性，nullptr（类型是nullptr_t）是一个特殊的对象，表示空指针，可以转换为任意类型的指针
	std::cout << p4 << std::endl;
	std::cout << p5 << std::endl;

	//指针与bool的隐式转换
	//非空指针转换为true，空指针转换为false

	//指针的操作
	std::cout << *p << std::endl; //解引用
	std::cout << p << std::endl;
	std::cout << p+1 << std::endl; //增加，指向下一个int的地址
	std::cout << p-1 << std::endl; //减少，指向上一个int的地址
	std::cout << (p == p1) << std::endl; //指针判等
}

void fun_1(int* p)
{
	std::cout << p+1 << std::endl;
}

void fun_2()
{
	int x = 1;
	int* p = &x;
	std::cout << p << std::endl;
	std::cout << p+1 << std::endl;
	fun_1(p);
}

void fun_3(int par)
{
	par = par + 1;
}

void fun_4(int* par)
{
	*par = *par + 1;
}

void fun_5() //函数传值与传址
{
	int x = 1;
	int* p = &x;
	fun_3(x);
	std::cout << x << std::endl;
	fun_4(p);
	std::cout << x << std::endl;
}

void fun_6() //引用
{
	int x = 3;
	int& ref = x; //引用
	int* ptr = &ref; //指针

	std::cout << x << std::endl;
	std::cout << ref << std::endl;
	std::cout << *ptr << std::endl;
	ref = ref + 1;
	std::cout << x << std::endl;
	std::cout << ref << std::endl;
	std::cout << *ptr << std::endl;
}

void fun_7() //指针的引用
{
	int x = 8;
	int* ptr = &x;
	int*& ref = ptr;

	std::cout << x << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ptr << std::endl;
	std::cout << *ref << std::endl;
	std::cout << ref << std::endl;

	*ref = *ref + 1;

	std::cout << x << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ptr << std::endl;
	std::cout << *ref << std::endl;
	std::cout << ref << std::endl;

}

int main()
{
	//fun_0();
	//fun_2();
	//fun_5();
	//fun_6();
	fun_7();
}
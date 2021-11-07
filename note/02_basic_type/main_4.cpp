#include <iostream>
#include <type_traits>


void fun_0() //常量和常量指针
{
	const int x = 4; //常量只能读，不能写。初始化化后不能被赋值。
	std::cout << x << std::endl;

	int y = 5;
	int z = 6;
	const int* ptr1 = &z; //指针指向常量 //指向常量的指针也可以指向变量
	z = z + 1;
	std::cout << z << std::endl;

	//int* ptr3 = &x;  //报错 指向变量的指针不能指向常量

    // *ptr1 = 6; //时报错
	int* const ptr2 = &y; //指针是常量
	// ptr2 = &z; //时报错
	*ptr2 = z;
	std::cout << y << std::endl;

}

void fun_1() //常量和常量引用
{
	int x = 3;
	const int& ref1 = x; //常量指针可以绑定变量
	//ref1 = ref1 + 1; //报错，不可写

	int& ref2 = x;
	ref2 = ref2 + 1;
	
	const int y = 4;
	//int& ref3 = y; //变量引用不可以绑定常量

	//int& ref4 = 3; //非法， 不能绑定字面值
	const int& ref4 = 3; //合法，可以绑定字面值
}

void fun_2(int x)
{
	x = x + 1;
}
void fun_3(int* x)
{
	*x = *x + 1;
}
void fun_4(int& x)
{
	x = x + 1;
}

//适用于传递大的数据类型，用于int没有必要 
void fun_5(const int& x) //函数内x的值无法进行修改
{
	//x = x + 1;
}

void fun_6()
{
	int x;
	std::cin >> x;

	const int y1 = x;
	constexpr int y2 = 3; //更明确的表示y2是编译期常量
	//y2的类型依然为const int

	//常量表达式指针
	constexpr const char* ptr = "123";//constexpr修饰ptr，ptr的类型为const char* const
	std::cout << std::is_same_v<decltype(ptr), const char* const> << std::endl;
}

int main()
{
	//fun_0();

	int x = 1;
	fun_2(x);
	std::cout << x << std::endl;
	fun_3(&x);
	std::cout << x << std::endl;
	fun_4(x);
	std::cout << x << std::endl;

	fun_6();
	
}
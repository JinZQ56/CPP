#include <iostream>
#include <cstring>
#include <type_traits>

void fun0()  //C字符串
{
	char str[] = "Hello";  //char[6] null-terminated string
	auto ptr = str; //char* 被隐式的转换为指针
	std::cout << strlen(str) << std::endl;
	std::cout << strlen(ptr) << std::endl;

	char str1[] = { 'H','e','l','l','o' }; //char[5]
	auto ptr1 = str1;
	std::cout << strlen(str1) << std::endl; //strlen会遍历数组直到找到\0
	std::cout << strlen(ptr1) << std::endl;

	char str2[] = { 'H','e','l','l','o','\0' }; //char[6]
	auto ptr2 = str2;
	std::cout << strlen(str2) << std::endl; //strlen会遍历数组直到找到\0
	std::cout << strlen(ptr2) << std::endl;

	//strcmp 字符串比较
	std::cout << strcmp(str1, str) << std::endl;
	std::cout << strcmp(str, str2) << std::endl;
}

void fun1() //多维数组
{
	//多维数组缺省初始化
	int x1[3];
	std::cout << x1[0] << std::endl;
	std::cout << sizeof(int) << std::endl;
	std::cout << sizeof(x1[0]) << std::endl;
	int x2[3][4];  //x2包含三个元素，每个元素是int[4]
	std::cout << sizeof(x2[0]) << std::endl;
	std::cout << std::is_same_v<decltype(x2[0]),int[4]> << std::endl;  //x2[0]是表达式，是l-value，decltype会返回引用
	std::cout << std::is_same_v<decltype(x2[0]), int(&)[4]> << std::endl;
	int x3[3][4][5]; //x3包含3个元素，每个元素是int[4][5]
	std::cout << sizeof(x3[0]) << std::endl;
	std::cout << std::is_same_v<decltype(x3[0]), int[4][5]> << std::endl;
	std::cout << std::is_same_v<decltype(x3[0]), int(&)[4][5]> << std::endl;

	//多维数组聚合初始化
	int x4[3][4] = { 1,2,3,4,5 };
	//{int, int, int, int},{int, int, int, int},{int, int, int, int}
	//前五个元素赋值，其余为0

	int x5[3][4] = { {1,2,3,4},{5,6,7,8} }; //其余为0
	int x6[3][4] = { {1,2,3,4},{5,6,7} }; //其余为0
	int x7[3][4] = { {1,2,3},{4,5,6,7} }; //其余为0
	std::cout << x6[1][0] << " " << x6[1][3] << std::endl;
	std::cout << x7[1][0] << " " << x7[0][3] << std::endl;
	std::cout << x6[0] << " " << x6[2] << std::endl;

	int x8[][2] = { 1,2,3,4 }; //编译器自动推导第0维
	std::cout << sizeof(x8) << std::endl;
	int x9[][3] = { 1,2,3,4 }; 
	std::cout << sizeof(x9) << std::endl;
	std::cout << std::is_same_v<decltype(x9), int[2][3]> << std::endl;

	int x10[][4] = { {1,2,3},{2,3,4,5} };
	std::cout << std::is_same_v<decltype(x10), int[2][4]> << std::endl;

	int x11[][4][5] = { {{1,2,3},{4,5,6}} }; //仅能省略第0维，但是不推荐
	std::cout << sizeof(x11) << std::endl;
}

using A = int[4];

void fun2() //多维数组的索引与遍历
{
	int x1[3][4] = { {1,2},{3,4},{5,6} };
	
	//range based for
	for (auto& p : x1)
	{
		for (auto q : p)
		{
			std::cout << q << '\n';
		}
	}

	/*
	int x2[3][4][5] = { 1,2,3 };
	for (auto& r : x2)
	{
		for (auto& p : r)
		{
			for (auto& q : p)
			{
				std::cout << q << '\n';
			}
		}
	}
	*/

	size_t index0 = 0;
	size_t index1 = 0;
	while (index0 < std::size(x1))
	{
		index1 = 0;
		while (index1 < std::size(x1[index0]))
		{
			std::cout << x1[index0][index1] << ' ';
			if (index1 == 3)
			{
				std::cout << '\n';
			}
			index1 = index1 + 1;
		}
		index0 = index0 + 1;
	}

	int x3[3][4] = {1,2,3,4,5,6,7,8};
	auto ptr3 = x3; //ptr为指针但仅丢失最高位信息，保留其它维度的信息
	std::cout << std::is_same_v<decltype(ptr3), int(*)[4]> << std::endl;
	std::cout << ptr3[0] << '\n';
	std::cout << ptr3[1][0] << '\n';

    /*
	std::cout << *ptr3 << '\n';
	std::cout << ptr3 << '\n';
	std::cout << ptr3[0] << '\n';
	std::cout << *(ptr3+1) << '\n'; 
	std::cout << ptr3 + 1 << '\n';
	std::cout << ptr3[1] << '\n';
	*/

	auto ptr4 = x3[0];
	std::cout << std::is_same_v<decltype(ptr4), int*> << std::endl;
	auto ptr5 = ptr3[0];
	std::cout << std::is_same_v<decltype(ptr5), int*> << std::endl;

	//使用类型别名简化多维数组指针的声明
	A* ptr6 = x3; //转换为指针时，第0维度丢失
	std::cout << std::is_same_v<decltype(ptr6), int(*)[4]> << std::endl;

	A x4[3] = { 3,4,5,6,7,8 };
	std::cout << std::is_same_v<decltype(x4), int[3][4]> << std::endl; //true
	std::cout << std::is_same_v<decltype(x4), int[4][3]> << std::endl; //false

    //使用指针来遍历多维数组
	auto ptr7 = x4; //or auto ptr7 = std::begin(x4)
	while (ptr7 != std::end(x4))
	{
		auto ptr8 = std::begin(*ptr7);
		while (ptr8 != std::end(*ptr7))
		{
			std::cout << *ptr8 << std::endl;
			ptr8 = ptr8 + 1;
		}
		ptr7 = ptr7 + 1;
	}
}


int main()
{
	//fun0();
	//fun1();
	fun2();
}
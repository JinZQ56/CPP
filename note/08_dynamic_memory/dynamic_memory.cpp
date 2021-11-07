#include <iostream>
#include <new>
#include <memory>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

void fun0()
{
	//sizeof不会返回动态分配的内存大小
	//sizeof返回指针的大小
	int* ptr = new int(5);
	std::cout << sizeof(ptr) << std::endl;

	int* ptr1 = new int[5];
	std::cout << sizeof(ptr) << std::endl;

	std::cout << sizeof(std::vector<int>) << std::endl;
	std::vector<int> x;
	x.push_back(10);
	std::cout << sizeof(x) << std::endl;
}

void fun1()
{
	//使用分配器(allocator)来分配内存
	std::allocator<int> al;
	//分配三个int大小的内存，地址保存到ptr
	//仅分配内存，不调用构造函数 
	int* ptr = al.allocate(3);

	//回收
	al.deallocate(ptr, 3);
}

void fun2(void)
{
	//malloc和free
	//new既分配内存又构造对象
	//malloc继承自C语言，只分配内存，不构造对象
    void* p1 = malloc(4 * sizeof(int));
	void* p2 = malloc(sizeof(int[4]));
	//int* p3 = malloc(4 * sizeof  *p3);
	//不知道为什么会报错

	free(p1);
	free(p2);
	//free(p3);

	//aligned_alloc分配对齐内存
	void* p4 = malloc(1024 * sizeof(int));
	printf("default-aligned addr: %p\n", (void*)p4);
	free(p4);

	//void* p5 = alligned_alloc(1024, 1024 * sizeof(int));
	void* p5 = _aligned_malloc(1024, 1024 * sizeof(int));
	printf("1024-byte-aligned addr: %p\n", (void*)p5);
	_aligned_free(p5);
}

int main()
{ 
	//fun0();
	//fun1();
	fun2();
}
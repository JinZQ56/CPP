#include <iostream>
#include <new>
#include <memory>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

void fun0()
{
	//sizeof���᷵�ض�̬������ڴ��С
	//sizeof����ָ��Ĵ�С
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
	//ʹ�÷�����(allocator)�������ڴ�
	std::allocator<int> al;
	//��������int��С���ڴ棬��ַ���浽ptr
	//�������ڴ棬�����ù��캯�� 
	int* ptr = al.allocate(3);

	//����
	al.deallocate(ptr, 3);
}

void fun2(void)
{
	//malloc��free
	//new�ȷ����ڴ��ֹ������
	//malloc�̳���C���ԣ�ֻ�����ڴ棬���������
    void* p1 = malloc(4 * sizeof(int));
	void* p2 = malloc(sizeof(int[4]));
	//int* p3 = malloc(4 * sizeof  *p3);
	//��֪��Ϊʲô�ᱨ��

	free(p1);
	free(p2);
	//free(p3);

	//aligned_alloc��������ڴ�
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
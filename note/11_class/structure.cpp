// �ṹ��Ͷ���ۺ�
#include <iostream>
#include <vector>
#include "header.h"

struct str; // �ṹ�������

struct str // �ṹ�嶨��
{
	int x;
	int y;
};
//�ṹ���ڲ��������ݳ�Ա�������

struct str1
{
	decltype(3) x; //����decltype��������auto
	int y = 3; //���ڳ�Ա���Գ�ʼ��
	const int z = 6;
};

struct str2
{
	// mutable �ɸ��ĵ�
	mutable int x = 0;
	mutable int y = 1;
};

struct str3
{
	// ��̬���ݳ�Ա
	static int x;
	int y = 1;
};

int str3::x; // ��̬��Ա�������������ⶨ��

extern int x; //����
int x; // �����Ķ���



void fun0()
{
	str s;
	s.x = 3;
	s.y = 5;
	std::cout << s.x << " " << s.y << std::endl;

	// �ۺϳ�ʼ��
	str1 ss{ 1, 2, 3 };
	// const ��ss������ʱ�ű�������3���������ֵ�������6
	// const֮�����޸�
	// since c++ 20 �� ָ�ɳ�ʼ����
	// str1 sss{.x = 1, .y =2, .z = 3}
	// ��ֹ�ṹ��������ʼ������
	std::cout << ss.x << " " << ss.y << " " << ss.z << std::endl;

	// mutable
	// ����ʱ��mutable ���Ը���const��struct����
	// ������Ҫ�����ṹ���ڶ��������
	const str2 s1;
	s1.x = 5;
	s1.y = 6;
	std::cout << s1.x << " " << s1.y << std::endl;
}

void fun1()
{
	// ��̬���ݳ�Ա
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
	// ��̬���ݳ�Ա�ķ���
	str3 s3;
	s3.x = 80;
	str3* p3 = &s3;
	std::cout << str3::x << std::endl; // ��������������ھ�̬���ݳ�Ա
	std::cout << s3.x << std::endl;
	std::cout << p3->x << std::endl;

	str4 s4;
	str4* p4 = &s4;
	std::cout << str4::array_size << std::endl;
	std::cout << s4.array_size << std::endl;
	std::cout << p4->array_size << std::endl;

}

// ������ڲ�������ͬ���͵ľ�̬���ݳ�Ա
struct str6
{
	static str6 s; //��̬���ݳ�Ա�����ж����������ڵ���ĳ������
	// inline static str6 s; // ���ַ�������ʹ
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
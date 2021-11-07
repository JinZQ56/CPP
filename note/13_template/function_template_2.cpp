#include <iostream>
#include <vector>
#include <string>
// #include "header.h"

// ģ�������
template <typename T>
void fun(T x);

// ģ��Ķ���
template <typename T>
void fun(T x)
{
	std::cout << "template: " << x << std::endl;
}

// ��ģ�������ʽʵ����
template void fun<int>(int x);
// �����������Ƶ�ʱ������ʡ��ģ�����
// template void fun(std::string x);

// ģ����ػ�
template <>
void fun<std::string>(std::string x)
{
	std::cout << "specialization of template: " << x << std::endl;
}

int main()
{
	// A ����ģ���ʵ��������
	// ��ʽʵ�������� ��ģ����ʽʵ�����ɺ��������ǲ�������
	// template void fun<int>(int x)
	// template void fun(int x)

	int x = 3;
	fun<int>(x);
	// ��ʱ��������ֱ�ӵ�����ʽʵ�����ĺ���

	// ��ʽʵ�������� �������ܻ�ʹ�õ��˺������������ڵ�ǰ��Ԫ�����
	// extern template void fun_h<int>(int x)
	// extern template void fun_h(int x)
	// ���Բ���Ҫ�ظ���ʽʵ�������� ������������������ӵĸ���

	// B ����ģ��ģ���ȫ���ػ�
	// ��ȫ�ػ�����ȫ��ʾ ����ͬʱ��������ģ��������β�
	// ���������µ����ƣ�ֻ��Ϊĳ��ģ������ض�ģ����������Ż�
	// �����Ͼ���һ������ģ���ʵ����������ػ�������������ȫ���⣬��ʱ��ʵ�����в����ػ�����ʱ������ʵ����
	// template<> void fun<int>/int x)
	// template<> void fun(int x)
	std::string s = "abc";
	fun<std::string>(s);

	// �����ص�����
	// ���أ������µ�ͬ������
	// �ػ����������µ�ͬ������

	// C ����ʹ�ú���ģ����ػ�
	// ͨ�����������ش����ػ�
	// ���������ص�������޷�����ģ���β��뺯���βεĹ���
		// �� if constexpr(std::is_sam_v<x, int>)
		// ���븨�������β�
		// ͨ�����ģ���ػ���� 

	// D ����ģ��ļ���ʽ��ʹ��auto����ģ�����������
	// since C++ 20
	
	// void fun(auto x) {}
	// void fun(auto& x) {}
	// void fun(auto&& x) {}
	// ȱ�㣺��Ҫ�ں����ڲ���ӻ�ȡ����������Ϣ

}
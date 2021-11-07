#include <iostream>
#include <vector>
#include <string>

//��ֵģ�����
//template <typename T, T x>
//template <auto x> since c++17
template<int x>
void fun1(int y)
{
	std::cout << x + y << std::endl;
}

// ģ��ģ�����
// ����һ��Ϊ��ģ��
// template<template<typename> class C>
// template<template<typename> typename T>
template<template<typename T> class C>
void fun2()
{
	std::cout << "too hard for me" << std::endl;
}

template <typename T>
class cla{};

// ����ģ��
template <typename T>
using pointer = T*;

// �䳤��ģ��
// type... Args
template <int... x>
void fun3() {};
// typename|class...Args
template <typename... T>
void fun4(T... args) { std::cout << sizeof...(T) << std::endl; };
// template < parameter-list > typename(C++17)|class ... Args
template <template<typename>class... C>
void fun5() {};

// ��չ��
void fun6()
{

}

template <typename U, typename... T>
void fun6(U u, T... args)
{
	// &args... Ϊ��չ��
	// &args Ϊģʽ
	std::cout << u << std::endl;
	fun6(args...);
}

// �۵����ʽ c++17
template <typename... T>
void fun7(T... args)
{
	((std::cout << args << std::endl), ...);
}

template <typename... Args>
void sum(Args... args)
{
	// �ȴ����Ҷ˽��
	std::cout << (args + ...) << std::endl;
	// �ȴ�����˽��
	std::cout << (... + args) << std::endl;
}

int main()
{
	// A ��ֵģ�����
	// ģ����Խ��գ���������������ֵ��Ϊģ�����
	// template <int x> class cla
	// template <typename T, T x> class cla ������ֵ������
 	// template <auto x> since c++ 17 auto ��������ֵ int bool char��
	// ��������ֵ������븡������Ϊģ����� since c++ 20
	fun1<3>(5);

	// B ģ��ģ�����
	// template<template<typename T>class C> class cla
	// template<template<typename T>typename C> class cla since c++ 17
	fun2<cla>();

	// C ����ģ��
	// ʹ��using�������ģ��
	// Ϊģ�屾���������
	// Ϊ��ģ��ĳ�Ա�������
	pointer<int> x = nullptr;

	// D �䳤ģ��
	// variadic template
	// ͨ���βΰ�ʵ�� parameter pack
	// ģ���βκͺ����βζ�����ʹ�ò�����
	// �䳤ģ�������������ֵ�����ͻ�ģ��

	// D.1 type...Args
	fun3<1, 2, 3>();
	// D.2 typename... Args
	fun4<int, bool, char>(1, true, 'c');
	// D.3 template < parameter-list > typename(C++17)|class ... Args
	fun5<cla, cla, cla>();

	// ��������������һ������
	// sizeof...() ���Ի�ȡ�������в����ĸ���

	// E ��չ��
	// ͨ����չ�����������߳�ģ�����
	// �ο� cppreference
	fun6(1, 2, "hello", 'c');

	// F �۵����ʽ
	// since c++ 17
	// ���ڶ��ŵ��۵����ʽӦ��
	// �۵����ʽ���ڱ��ʽ��ֵ���޷��������루�������������ģ�������
	// c++ reference fold expression
	fun7(1, 2, "hello", 'c');
	sum(1, 2, 3, 4, 5);


	std::cout << "complied successfully" << std::endl;
	

}
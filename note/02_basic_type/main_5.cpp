#include <iostream>
#include <type_traits>

//���ͱ��������͵��Զ��Ƶ�

typedef int myint; //�������ͱ���
using Myint = int; //C++11���������ͱ����ķ�ʽ

//using�������ͱ������Ѻ�
typedef char mychararr[4];
using MyCharArr = char[4]; //ʹ��using�����������

void fun_0()
{
	myint x = 3;
	Myint y = 4;
	size_t z = 5;
}

//���ͱ�����ָ�롢���õĹ�ϵ

using IntPtr = int*; 

//����ͨ�����ͱ����������õ�����
using RefInt = int&;
using RefRefInt = RefInt&;

void fun_1()
{
	int x = 3;
	const IntPtr ptr = &x;
	//�˴����ȼ��� const int* ptr = &x;
	//�˴��ȼ��� int* const ptr = &x;
	//�������Ϊconst����IntPtr������������int

	std::cout << std::is_same_v<RefInt, RefRefInt> << std::endl;
	std::cout << std::is_same_v<RefInt, int&> << std::endl;
	std::cout << std::is_same_v<int&, RefRefInt> << std::endl;
}

//���͵��Զ��Ƶ�

void fun_2()
{
	int x = 3.5 + 15l;
	std::cout << x << '\n';

	auto y = 3.5 + 15l; //y�����Ͳ�����ʾ����ģ��ɱ���������
	std::cout << y << '\n'; 
	std::cout << sizeof(y) << '\n';
	std::cout << sizeof(float) << '\n';
	std::cout << sizeof(double) << '\n';

	long double z = 10.8888;
	std::cout << sizeof(z) << '\n';
}

void fun_3()
{
	//�Զ��Ƶ��ĳ�����ʽ

	auto x1 = 6; //auto���ܻ���������˻�
	
	int& x2 = x1;
	int x3 = x2; //int& �˻�Ϊint
	auto x4 = x2; //x4��������int��������int&

	const auto x5 = 3;  //x5����Ϊconst int
	constexpr auto x6 = 4; //x6����Ϊconst int
	const auto& x7 = 3; //x7����const int&

	const int x8 = 5;
	const auto x9 = x8; //x9����Ϊconst int
	auto x10 = x8; //x10������Ϊint����Ϊconst int��Ϊ��ʽ��ֵʱ�����˻�

	auto& x11 = x8; //x11����Ϊconst int&����Ϊauto&���������ʽ�Ҳ�������˻�
	const int& x12 = 6;
	auto& x13 = x12; //x13����Ϊconst int&
}

void fun_4()
{
	//decltype�ؼ���,������������˻�
	//decltype(exp) ����exp���ʽ������
	//decltype(val) ����val������ 

	auto x1 = 3.5 + 15l;
	decltype(3.5 + 15l) x2 = 3.5 + 15l;

	int x3 = 3;
	int& x4 = x3;
	auto x5 = x4; //���������˻���x5����Ϊint
	decltype(x4) X6 = x4; //x6����Ϊint&�������������˻�

	int x7 = 3;
	int* ptr = &x7;
	//decltype(exp) ��ֵ������
	/*
	ptr -> int*
	*ptr -> int
	decltype(*ptr) -> int&
	*/
	//��Ϊ*ptr�Ǵ��������ı��ʽ�����ʽ������ֵʱ������
	//�������ʣ�����ʽΪ��ֵʱ(�� 3.5+15l)����������
	decltype(x7); //����Ϊint
	decltype((x7)); //����Ϊint& 

	//decltype(auto) ��C++14���룬��decltype��ʹ��
	decltype(auto) x = 3.5 + 15l;

	//concept auto ��C++20��ʼ֧�֣���ʾһϵ������
}

int main()
{
	fun_2();
	int x = 3;
	int* y = &x;
	x = *y + 2;
	std::cout << x << std::endl;
	std::cout << *y << std::endl;
}
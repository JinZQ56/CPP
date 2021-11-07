#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <memory>
#include <string>

void fun0()
{
	// lambda���ʽ������һ������
	auto l = [](int val) {return val > 3; };
	std::cout << l(5) << std::endl;

	// ��ʾָ����������
	auto l1 = [](int val) -> float {return 1; };
	std::cout << l1(5) << std::endl;

	// ������Ժ�������ʹ�õľֲ��Զ�������в���
	// static int y = 10; //static ʱ����Ҫ����y
	int y = 10;
	auto l2 = [y](int val) { return val > y; };
	std::cout << l2(11) << std::endl;

	// ֵ����
	auto l3 = [y](int val) mutable {++y; return val > y; };
	std::cout << y << std::endl;
	std::cout << l3(11) << std::endl;

	// ���ò���
	auto l4 = [&y](int val) {++y; return val > y; };
	std::cout << y << std::endl;
	std::cout << l4(11) << std::endl;

	// ��ϲ���
	int z = 5;
	auto l5 = [&y, z](int val) {++y; return val > z; };
	std::cout << y << std::endl;
	std::cout << l5(11) << std::endl;

	// =�����Զ�����ֵ����
	auto l6 = [=](int val) { return val > z; };
	// &�Զ��������ò���
	auto l7 = [&](int val) { ++y; return val > z; };
	// ����z����ֵ���� 
	auto l8 = [&, z](int val) { ++y; return val > z; };
}

// this �ؼ���
// ָ��ṹ��
struct str
{
	auto fun()
	{
		int val = 3;
		auto l = [val, this]() {return val > x; };
		return l();
	}
	auto fun1()
	{
		int val = 3;
		// *this Ϊthis�Ľ����ã�����ᱻ���Ƶ�lambda���ʽ���ڲ������ٱ���ָ��
		auto l = [val, *this]() {return val + x; };
		return l;
	}
	int x=3;
};

// ��ʼ������ since c++14
void fun1()
{
	int x = 10;
	auto l = [y = x](int val) {return val > y; };
	std::cout << l(11) << std::endl;

	//���Զ�������ӵ��߼�
	std::string s = "hello";
	auto l1 = [y = std::move(s)](){std::cout << y << std::endl; };
	l1();
	std::cout << "after move: " << s << std::endl;
}

// *this ���� since c++17
auto wrapper()
{
	str s;
	return s.fun1();
}

// ˵����
void fun2()
{
	// multable
	// ȡ��constant
	int y = 3;
	auto l = [y](int val) mutable {++y;  return val > y; };

	// constexpr
	// �ڱ����ڿ��Խ��е���
	auto l1 = [](int val) constexpr { return val + 1; };
	constexpr int val = l1(100);
	std::cout << val << std::endl;
}

// ģ���β� since c++20
void fun3()
{
	auto l = []<typename T>(T val) { return val + 1; };
}


int main()
{
	// fun0();
	/*
	str s;
	s.x = 2;
	std::cout << s.fun() << std::endl;
	*/
	//fun1();
	//auto l = wrapper();
	//std::cout << l() << std::endl;
	fun2();
}
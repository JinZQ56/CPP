#include <iostream>
#include <vector>
#include <string>
#include <functional>

class cla
{
public:
	cla() = default;
	cla(int val, const std::string& str)
		: x(val)
		, y(2*val)
		, s(str)
	{}

	void print(int val)
	{
		std::cout << val << std::endl;
	}

public:
	int x = 0;
	int y = 1;
	std::string s;

};

int main()
{
	// A ��Աָ��
	// ��Ա����ָ������ int cla::*
	// ��Ա����ָ������ int(cla::*)(double)
	// ��Աָ�����ֵ auto ptr = &cla::x
	// ����������ӱ��ʽ���ܼ�С���� &(cla::x) ����д���Ǵ�� ��Ϊ�������ȼ���ԭ��

	// ��Ա����ָ��
	int cla::*ptr; // *ptr ��һ��ָ�룬ָ��cla���еĳ�Ա����������Ϊint
	// ptr ������Ϊint cla::*
	std::cout << std::is_same_v<int cla::*, decltype(ptr)> << std::endl;

	// ��Ա����ָ��
	void (cla:: * ptr_fun)(int); //*ptr_fun��һ��ָ�룬ָ��cla���еĺ���������Ϊvoid������0������

	// ָ���ʼ��
	int cla::* p1 = &cla::x;
	int cla::* p2 = &cla::y;
	void (cla:: * p3)(int) = &cla::print;

	// ��Աָ���ʹ��
	// ����.*��Աָ�� c.*ptr
	// ����ָ��->*��Աָ��
	// .* -> Ҳ�������Ϊ pointer-to-member ������
	cla c(3, "abc");
	cla* p_c = &c;
	std::cout << c.*p1 << std::endl; // .�ǳ�Ա������ ����p1ָ��ĳ�Ա
	std::cout << p_c->*p1 << std::endl; // p_c��ָ������ָ�� ��ʱʹ�� ->*
	(c.*p3)(100);
	
	// B ��bind����
	auto pri = std::bind(p3, c, 100); // ������Ķ�����Ϊ�ڶ�����������bind
	pri();

	// ����ʹ��bind�����������ݳ�Ա�Ŀɵ��ö���
	auto x = std::bind(p1, c);
	std::cout << x() << std::endl;
 



}
#include <iostream>
#include <vector>
#include <string>

class cla
{
public:
	// ����ʹ�ùؼ��� explicit ������ʽת��
	// explicit cla(int x): val(x) {} 
	cla(int x) : val(x) {}

	void print()
	{
		std::cout << val << std::endl;
	}
private:
	int val;
};

void fun(cla c)
{
	c.print();
}

class cla1
{
public:
	// ȱʡ���캯��
	cla1() = default;
	// ����ʹ��default�ṩ�������캯��
	// cla1(const cla1&) = default; 
	// ����ʹ��default�ṩ�ƶ����캯��
	// cla1(cla1&&) = default
	cla1(int x) : val(x) 
	{
		std::cout << "constructor1 is called" << std::endl;
	};
	cla1(int x, const std::string& str) : val(x), s(str)
	{
		std::cout << "constructor2 is called" << std::endl;
	};
	// �������캯��
	// �β�һ��Ҫ������
	cla1(const cla1& c)
		: val(c.val)
		, s(c.s)
	{
		std::cout << "copy constructor is called" << std::endl;
	}
	// �ƶ����캯��
	// �β�����ֵ���ã��Ҳ�������Ϊconst
	cla1(cla1&& c) noexcept
		: val(c.val)
		, s(std::move(c.s))
	{
		std::cout << "move constructor is called" << std::endl;
	}
	
	void print()
	{
		std::cout << val << std::endl;
		std::cout << s << std::endl;
	}
private:
	int val=0;
	std::string s="a";
};

class cla2
{
public:
	cla2() = default;
	cla2(const cla2& c)
	{
		std::cout << "cla2's copy constructor is called" << std::endl;
	}
	// cla2(cla2&& c)
	// {
	// 	std::cout << "cla2's move consteuctor is called" << std::endl;
	// }
};

class cla3
{
public:
	cla3() = default;
	cla3(const cla3&) = default;
	cla3(cla3&&) noexcept = default;
private:
	cla2 c;

};

int main()
{
	// A ���캯���ͳ�ʼ���б�
	// B ȱʡ���캯�� 
	
	// C ��һ�������캯��
	// ��һ�������캯��������Ϊ����ת������
	cla c = 3;
	fun(4);
	// ʹ��static_cast��������ת���������ڵ�һ��������
	cla c1 = static_cast<cla>(5);

	// D �������캯��
	// ���ܵ�ǰ�����Ĺ��캯�����Ӷ������µĶ���
	cla1 c2(6);
	cla1 c3(c2); // cla1 c3{c2}; // cla c3=c2;
	c3.print();
	// ��δ��ʾ�ṩ�����������Զ��ϳ�
	c1 = c;
	c1.print();

	// E �ƶ����캯��
	// ���ܵ�ǰ����ֵ���ö���Ĺ��캯��
	// ���Դ����������͵����Դ��ֻҪȷ����������ںϷ�״̬����
	std::string ori_s{ "abc" };
	// ��ori����new����ʹ��ori
	std::string new_s = std::move(ori_s); // �ƶ���oriΪ��
	std::cout << ori_s << std::endl;
	std::cout << new_s << std::endl;

	cla1 c_ori{ 1,"abc" };
	c_ori.print();
	cla1 c_new1{ c_ori }; // cla1 c_new = std::move(c_ori);
	c_ori.print();
	c_new1.print();
	cla1 c_new2{ std::move(c_ori) }; // cla1 c_new = std::move(c_ori);
	c_ori.print();
	c_new2.print();

	// ���ṩ�˿������캯���󣬱����������Զ��ϳ��ƶ����캯����ͨ��Ҳ�����׳��쳣
	// ��û���ƶ����캯��ʱ������ÿ������캯�� c++11 �Ժ�
	cla3 c3_ori;
	cla3 c3_new(std::move(c3_ori));
}
#include <iostream>
#include <vector>
#include <string>
class cla1
{
public:
	cla1() = default;
	cla1():cla1("abc",3,x) // �����캯��
	{
		std::cout << "Constructor is called" << std::endl;
	}
	cla1(int input):cla1("abc", 3, x)
	{
		std::cout << "constructor 2" << std::endl;
		x = input;
	}
	cla1(const std::string& str):cla1("abc", 3, x)
	{
		// ��ʱs�Ѿ������죬ʹ��ȱʡ��ʼ��
		std::cout << "Pre" << s << std::endl;
		s = str;
		std::cout << "Post" << s << std::endl;
	}
	// Ϊ���ⲻ��Ҫ�ò����������ʹ�ó�ʼ���б�
	cla1(const std::string& str, int i, int& val) 
		:s(str)
		,x(i)
		,ref(val) // ���ñ���ʹ�ó�ʼ���б�
		// Ԫ�صĳ�ʼ��˳�����ʼ���б��޹أ���Ԫ�ص�����˳���й�
	{
		// ��ʱs����ʹ��ȱʡ��ʼ��
		std::cout << "int" << x << std::endl;
		std::cout << "string" << s << std::endl;
		ref = 9;
	}
private:
	int x;
	std::string s;
	// int& ref; //������ʱ����һ�����ܱ�ȱʡ��ʼ��
	int ref;
	
public:
	void print()
	{
		std::cout << x << std::endl;
	}

};

int main()
{
	cla1 c1;
	cla1 c2(5);
	c1.print();
	c2.print();

	cla1 c3("abc");
	int val;
	cla1 c4("def", 7, val);
	std::cout << val << std::endl;
}
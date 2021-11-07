#include <iostream>
#include <vector>

struct str
{
	int x;
	int y;

	// ��Ա������������
	void print() // ��ʽ����
	{
		std::cout << x << " " << y << std::endl;
		// std::cout << this->x << " " this->y << sthd::endl;
		std::cout << this << std::endl; // thisָ�����õ�ǰ����
	}
};

struct str1
{
	int x;
	int y;
	// ��Ա������������
	void print(); // �������������ⶨ��
};

struct str2
{
	int x;
	int y;
	using MyRes = int;
	// ��Ա������������
	MyRes get(); // �������������ⶨ��
};

// str2::MyRes str2::get() 
auto str2::get() -> MyRes //trail returning type
{
	return x;
}

void str1::print() // ��ʱ������������Ҫ��inline
{
	std::cout << x << " " << y << std::endl;
}

class cla
{
public:
	int x;
	int y;
	// ��Ա������������
	void print() // ��ʽ����
	{
		std::cout << x << " " << y << std::endl;
	}
};

void fun0()
{
	str s{ 1,2 };
	s.print();

	cla c{ 1,2 };
	c.print();

	str1 s1{ 1,2 };
	s1.print();

	str2 s2{ 1,2 };
	std::cout << s2.get() << std::endl;
}

struct str3
{
	// const str3* const this //��ʾָ���ָ���ָ�򶼲������޸�
	void fun(int x) const // const��ʾ�������ܶ��ڲ���Ա�����޸�
	{
		std::cout << x << std::endl;
		std::cout << this->x << std::endl;
	}
	// str3* const this // thisָ����const �����޸�
	void fun(int x) // ������������
	{
		std::cout << x << std::endl;
		std::cout << this->x << std::endl;
	}
	void fun1(int x);
	int x;
};

int x;

inline void str3::fun1(int x)
{
	x; //�����β�x
	this->x; //���ڳ�Աx
	str3::x; //���ڳ�Աx
	::x; //ȫ����x
}

void fun1()
{
	// ��Ա������thisָ��
	str s1{ 1,2 };
	std::cout << "s1: " << std::endl;
	s1.print();
	std::cout << &(s1) << std::endl;
	str s2{ 3,4 };
	std::cout << "s2: " << std::endl;
	s2.print();
	std::cout << &(s2) << std::endl;
}

struct str4
{
	static int fun() //��̬��Ա�����������ж�����
	{
		// �����ھ�̬��Ա������ʹ�÷Ǿ�̬�ĳ�Ա
		return x;
	}
	static int x; 

	static auto& fun1()
	{
		inline static std::vector<int> x; //������ʹ�õ��ʺϲŻᱻ���� 
		return x;
	}
	
	// ģʽ����еĵ��͵���ģʽ
	static auto& instance()
	{
		static int x;
		return x;
	}
	
};

int str4::x;

void fun2()
{
	str4 s1;
	str4 s2;
	std::cout << str4::fun() << std::endl;
	//��̬��Ա�����ĵ���
}

int main()
{
	// fun0();
	// fun1();
	fun2();
} 
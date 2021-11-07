#include <iostream>
#include <vector>
#include <string>

// ��ģ�������
template <typename T>
class cla;

// ��ģ�������
template <typename T>
class cla
{
public:
	// ��Ա����ֻ���ڵ���ʱ�Żᱻʵ����
	void fun(T input)
	{
		std::cout << "class template: " << input <<std::endl;
	}

	// ������ģ�����ƿ��Լ�д
	void fun1()
	{
		return cla{}; // �Զ���Ϊ cla<T>{};
	}
	
	// ��ģ���Ա�����Ķ��壨����+���⣩
	// ��������
	void fun2(T input);
};

template <typename T>
void cla<T>::fun2(T input)
{
	std::cout << "member function is defined outside of the class template: " << input << std::endl;
}

// ��ĳ�Ա����ģ��
class cla1
{
public:
	// ���ڶ���
	template <typename T>
	void fun_in(T input)
	{
		std::cout << "inside definition: " << input << std::endl;
	}

	// �������������ⶨ��
	template <typename T>
	void fun_out(T input);
};

template <typename T>
void cla1::fun_out(T input)
{
	std::cout << "outside definition: " << input << std::endl;
}

// ��ģ��ĳ�Ա����ģ��
template <typename T_cla>
class cla2
{
public:
	// ���ڶ���
	template <typename T_fun>
	void fun_in(T_cla x, T_fun s)
	{
		std::cout << "member function template of class template" << std::endl;
		std::cout << "inside definition: " << x << " " << s << std::endl;
	}

	// �������������ⶨ��
	template <typename T_fun>
	void fun_out(T_cla x, T_fun s);
};

template <typename T_cla>
template <typename T_fun>
void cla2<T_cla>::fun_out(T_cla x, T_fun s)
{
	std::cout << "member function template of class template" << std::endl;
	std::cout << "outside definition: " << x << " " << s << std::endl;
}

// ��Ԫ����ģ��
template <typename T_cla>
class cla3
{
public:
	// ��Ԫ������������
	template <typename T_fun>
	friend void fun(T_fun x);

	void set_t(T_cla x)
	{
		t = x;
	}
private:
	T_cla t;
};

template <typename T_fun>
void fun(T_fun x)
{
	cla3<int> c3;
	c3.set_t(1);
	std::cout << x << " " << c3.t << std::endl;

	cla3<std::string> s3;
	s3.set_t("abc");
	std::cout << x << " " << s3.t << std::endl;
}

int main()
{
	// A ��ģ��
	// ���뵥Ԫ�����һ������ԭ��
	// ��Ա����ֻ���ڵ���ʱ�Żᱻʵ����
	// ������ģ������Ƽ�д ������ cla{} �ᱻ�Զ���Ϊ cla<T>{}

	cla<int> c;
	c.fun(3);

	cla<std::string> s;
	s.fun2("abc");

	// B ��Ա����ģ��
	// B.1 ��ĳ�Ԫ����ģ��
	cla1 c1;
	c1.fun_in<int>(3);
	c1.fun_out<int>(5);
	c1.fun_out<std::string>("abc");

	// B.2 ��ģ��ĳ�Ա����ģ��
	cla2<int> c2;
	c2.fun_in<int>(1, 2);
	cla2<std::string> s2;
	s2.fun_out<std::string>("abc", "asd");

	// C ��Ԫ������ģ�壩
	// ��������һ������ģ��Ϊĳ���ࣨģ�壩����Ԫ
	// C++11��֧������ģ�����Ϊ��Ԫ
	fun<int>(123);
	fun<std::string>("abc");
}
#include <iostream>
#include <vector>
#include <string>

// 类模板的声明
template <typename T>
class cla;

// 类模板的声明
template <typename T>
class cla
{
public:
	// 成员函数只有在调用时才会被实例化
	void fun(T input)
	{
		std::cout << "class template: " << input <<std::endl;
	}

	// 类内类模板名称可以简写
	void fun1()
	{
		return cla{}; // 自动视为 cla<T>{};
	}
	
	// 类模板成员函数的定义（类内+类外）
	// 类内声明
	void fun2(T input);
};

template <typename T>
void cla<T>::fun2(T input)
{
	std::cout << "member function is defined outside of the class template: " << input << std::endl;
}

// 类的成员函数模板
class cla1
{
public:
	// 类内定义
	template <typename T>
	void fun_in(T input)
	{
		std::cout << "inside definition: " << input << std::endl;
	}

	// 类内声明，类外定义
	template <typename T>
	void fun_out(T input);
};

template <typename T>
void cla1::fun_out(T input)
{
	std::cout << "outside definition: " << input << std::endl;
}

// 类模板的成员函数模板
template <typename T_cla>
class cla2
{
public:
	// 类内定义
	template <typename T_fun>
	void fun_in(T_cla x, T_fun s)
	{
		std::cout << "member function template of class template" << std::endl;
		std::cout << "inside definition: " << x << " " << s << std::endl;
	}

	// 类内声明，类外定义
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

// 友元函数模板
template <typename T_cla>
class cla3
{
public:
	// 友元函数类内声明
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
	// A 类模板
	// 翻译单元级别的一处定义原则
	// 成员函数只有在调用时才会被实例化
	// 类内类模板的名称简写 在类内 cla{} 会被自动视为 cla<T>{}

	cla<int> c;
	c.fun(3);

	cla<std::string> s;
	s.fun2("abc");

	// B 成员函数模板
	// B.1 类的成元函数模板
	cla1 c1;
	c1.fun_in<int>(3);
	c1.fun_out<int>(5);
	c1.fun_out<std::string>("abc");

	// B.2 类模板的成员函数模板
	cla2<int> c2;
	c2.fun_in<int>(1, 2);
	cla2<std::string> s2;
	s2.fun_out<std::string>("abc", "asd");

	// C 友元函数（模板）
	// 可以声明一个函数模板为某个类（模板）的友元
	// C++11后支持声明模板参数为友元
	fun<int>(123);
	fun<std::string>("abc");
}
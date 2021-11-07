#include <iostream>
#include <vector>
#include <string>

class cla
{
public:
	// 可以使用关键字 explicit 避免隐式转换
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
	// 缺省构造函数
	cla1() = default;
	// 可以使用default提供拷贝构造函数
	// cla1(const cla1&) = default; 
	// 可以使用default提供移动构造函数
	// cla1(cla1&&) = default
	cla1(int x) : val(x) 
	{
		std::cout << "constructor1 is called" << std::endl;
	};
	cla1(int x, const std::string& str) : val(x), s(str)
	{
		std::cout << "constructor2 is called" << std::endl;
	};
	// 拷贝构造函数
	// 形参一定要传引用
	cla1(const cla1& c)
		: val(c.val)
		, s(c.s)
	{
		std::cout << "copy constructor is called" << std::endl;
	}
	// 移动构造函数
	// 形参是右值引用，且不能声明为const
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
	// A 构造函数和初始化列表
	// B 缺省构造函数 
	
	// C 单一参数构造函数
	// 单一参数构造函数可以视为类型转换函数
	cla c = 3;
	fun(4);
	// 使用static_cast进行类型转换，适用于单一参数的类
	cla c1 = static_cast<cla>(5);

	// D 拷贝构造函数
	// 接受当前类对象的构造函数，从而构造新的对象
	cla1 c2(6);
	cla1 c3(c2); // cla1 c3{c2}; // cla c3=c2;
	c3.print();
	// 若未显示提供，编译器会自动合成
	c1 = c;
	c1.print();

	// E 移动构造函数
	// 接受当前类右值引用对象的构造函数
	// 可以从输入对象中偷窃资源，只要确保传入对象处于合法状态即可
	std::string ori_s{ "abc" };
	// 将ori赋给new后不再使用ori
	std::string new_s = std::move(ori_s); // 移动后ori为空
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

	// 当提供了拷贝构造函数后，编译器不会自动合成移动构造函数，通常也不会抛出异常
	// 当没有移动构造函数时，会调用拷贝构造函数 c++11 以后
	cla3 c3_ori;
	cla3 c3_new(std::move(c3_ori));
}
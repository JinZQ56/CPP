#include <iostream>
#include <vector>
#include <string>

class cla
{
public:
	// 编译期构造函数
	// constexpr 既可以编译期常量 也可以运行期变量
	// consteval (since c++ 20) 仅能编译期常量
	constexpr cla(int val)
		: x(val)
	{}

	// 平凡的析构函数
	~cla() = default;
	// ~cla() {}; 此种定义不平凡

	// 编译期成员函数
	// constexpr/consteval
	// c++ 11 之前 const为缺省值
	// c++ 14 以后 constexpr缺省为非const
	constexpr int fun() const // const修饰成员函数，此时类中的值不能在函数中被修改
	{
		return x + 1;
	}

	// since c++ 14 可以定义constexpr成员函数且函数可以修改字面值类
	// 此时不能加const关键字
	constexpr void inc()
	{
		x = x + 1;
	}
private:
	int x = 3;

};

constexpr cla c(3);

int result()
{
	cla c(0);
	c.inc();
	c.inc();
	c.inc();
	return c.fun();
}

int main()
{
	// A 字面值类
	// 可以构造编译期常量的类型
	// 其数据成员需要是字面值类型
	// 使用平凡的析构函数
	// 构造函数 constexpr/consteval
	// 成员函数 constexpr/consteval
	// 从c++14起， constexpr/consteval成员函数非const成员函数


	// 编译期常量 内建数据类型
	constexpr int a = 3;

	std::cout << c.fun() << std::endl;

	cla c1(5);
	std::cout << c1.fun() << std::endl;

	// 关于const关键字
	std::cout << result() << std::endl;
}
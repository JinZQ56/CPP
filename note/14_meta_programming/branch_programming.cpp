#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

// 基于 if constexpr
template <int x>
int fun_if() // 在运行期的函数中引入了编译期的分支
{
	if constexpr (x > 3)
	{
		return x * 2;
	}
	else
	{
		return x * 4;
	}
}

// 基于偏特化引入分支
template <int x>
class fun_cla
{
public:
	constexpr static int value = x * 1;
	using type = int;
};

template <>
class fun_cla<5>
{
public:
	const static int value = 5 * 3;
	using type = double;
};

template <int x>
requires (x<=3)
class fun_cla<x>
{
public:
	constexpr static int value = x * 2;
	using type = int;
};

template <int x>
requires (x>3)
class fun_cla<x>
{
public:
	constexpr static int value = x * 4;
	using type = int;
};

// 基于conditional引入分支
// 第一个参数为true则返回第1个了类型，否则返回第2个类型
typedef std::conditional<true, int, double>::type ty1;
typedef std::conditional<false, int, double>::type ty2;

// 基于 SFINAE 引入分支
// 函数模板
template <int x, std::enable_if_t<(x <= 3)>* = nullptr> // void*
constexpr auto fun_sfinae()
{
	return x * 2;
}
	
template <int x, std::enable_if_t<(x > 3)>* = nullptr>
constexpr auto fun_sfinae()
{
	return x * 4;
}

// 类模板
template<int x, typename = void*>
class cla_sfinae
{
public:
	constexpr static int value = x * 2;
};

template<int x>
class cla_sfinae<x, std::enable_if_t<(x<=3)>*>
{
public:
	constexpr static int value = x * 2;
};

template<int x>
class cla_sfinae<x, std::enable_if_t<(x>3)>*>
{
public:
	constexpr static int value = x * 4;
};

// 基于三元运算符引入分支
// 数值版本
template<int x>
constexpr auto fun_to = (x < 3) ? x * 2 : x * 4;


int main()
{
	// 分支代码
	// A 基于 if constexpr 的分支
	// 只能处理数值问题，同时要小心引入运行期计算
	int x1 = fun_if<5>(); // 形成了函数
	// 如果用constexpr函数+if，则无法形成函数

	// B 基于（偏）特化引入分支
	// 常见的分支引入方式，但是编写复杂
	using x = fun_cla<5>::type;
	std::cout << std::is_same_v<x, double> << std::endl;

	std::cout << fun_cla<2>::value << std::endl;
	std::cout << fun_cla<5>::value << std::endl;
	std::cout << fun_cla<8>::value << std::endl;


	// C 基于 std::conditional 引入分支
	// std::conditional<bool b, T, U>
	// b为true返回T，b为false返回U
	// 语法简单但应用场景受限
	std::cout << typeid(ty1).name() << std::endl;
	std::cout << typeid(ty2).name() << std::endl;

	// D 基于 SFINAE 引入分支
	// 基于std::enable_if引入分支，语法复杂但功能强大，注意用做省缺模板实参不能引入分支
	// 基于std::void_t引入分支，C++17，通过“无效语句”触发分支
	std::cout << fun_sfinae<2>() << std::endl;
	std::cout << fun_sfinae<8>() << std::endl;

	std::cout << cla_sfinae<2>::value << std::endl;
	std::cout << cla_sfinae<8>::value << std::endl; 

	// E 基于concept引入分支
	// since C++ 20，可用于替换enable_if

	// F 基于三元运算符引入分支
	// std::conditional的数值版本

}
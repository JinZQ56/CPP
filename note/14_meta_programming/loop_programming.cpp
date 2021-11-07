#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

// A 计算二进制中包含1的个数
template <int x>
constexpr auto fun = (x % 2) + fun<x / 2>;
// % 是取余
// / 相当于向左移位

template <>
constexpr auto fun<0> = 0;

constexpr auto x = fun<99>;

// B 循环处理数组
// 定义输入模板和输入
template <typename...> class arr;
using input = arr<int, char, double, bool, void, float>;
// 模板声明
template <typename res, typename rem> // res代表返回值，rem为输入待处理数据
struct imp;
// 特化1
template <typename... processed, typename T1, typename T2, typename... Trem>
struct imp<arr<processed...>, arr<T1, T2, Trem...>> // rem大于等于两个元素
{
	using t1 = arr<processed..., T1>; // 将T1放进结果
	using t = typename imp<t1, arr<Trem...>>::t;
};
// 特化2
template <typename... processed, typename T1>
struct imp<arr<processed...>, arr<T1>> // rem只有一个元素时的特化
{
	using t = arr<processed..., T1>;
};
// 特化3
template <typename... processed>
struct imp<arr<processed...>, arr<>>
{
	using t = arr<processed...>; // rem为空时的特化
};
// 定义输出
using output = imp<arr<>, input>::t;

// C 获取数组中最后的三个元素
// 模板声明
template <typename res, typename rem>
struct imp1;
// 特化1 输出含有3个元素
template <typename U1, typename U2, typename U3, typename T, typename... Trem>
struct imp1<arr<U1, U2, U3>, arr<T, Trem...>>
{
	using t1 = arr<U2, U3, T>;
	using t = typename imp1<t1, arr<Trem...>>::t;
};
// 特化2 输出含有2个元素
template <typename U1, typename U2, typename T, typename... Trem>
struct imp1<arr<U1, U2>, arr<T, Trem...>>
{
	using t1 = arr<U1, U2, T>;
	using t = typename imp1<t1, arr<Trem...>>::t;
};
// 特化3 输出含有1个元素
template <typename U1, typename T, typename... Trem>
struct imp1<arr<U1>, arr<T, Trem...>>
{
	using t1 = arr<U1, T>;
	using t = typename imp1<t1, arr<Trem...>>::t;
};
// 特化4 输出为空
template <typename T, typename... Trem>
struct imp1<arr<>, arr<T, Trem...>>
{
	using t1 = arr<T>;
	using t = typename imp1<t1, arr<Trem...>>::t;
};
// 特化5 输入为空
template <typename... T>
struct imp1<arr<T...>, arr<>>
{
	using t = arr<T...>;
};
// 输出
using output2 = imp1<arr<>, input>::t;

int main()
{
	// 循环代码

	// A 简单示例：计算二进制中包含1的个数
	std::cout << x << std::endl;

	// B 使用递归实现循环

	// C 任何一种分支代码的编写方式都对应相应的循环代码编写方式

	// D 使用循环处理数组：获取数组中id=0，2，4，6...的元素
	std::cout << std::is_same_v<output, arr<int, double, void>> << std::endl;
	std::cout << "大受震撼！！！" << std::endl;

	// E 相对复杂的示例：获取数组中最后三个元素
	std::cout << std::is_same_v<output2, arr<bool, void, float>> << std::endl;
}
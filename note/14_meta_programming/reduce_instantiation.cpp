#include <iostream>
#include <vector>
#include <type_traits>

// case 1
template <size_t A>
struct Wrap_ {
	template <size_t ID, typename TDummy=void>
	struct imp
	{
		constexpr static size_t value = ID + imp<ID - 1>::value;
	};

	template <typename TDummy> // 嵌套的类模板不允许使用完全特化，引入TDummy可以辅助完成部分特化
	struct imp<0, TDummy>
	{
		constexpr static size_t value = 0;
	};

	template <size_t ID>
	constexpr static size_t value = imp<A + ID>::value;
};

// case 2
using res1 = std::conditional_t<false,
	std::remove_reference_t<int&>,
	std::remove_reference_t<double&>>; // 建立实例较多

// using res = std::remove_reference_t<std::conditional_t<false, int&, double&>>;
using res2 = std::conditional_t<false,
	std::remove_reference<int&>,
	std::remove_reference<double&>>::type; // 建立实例较少
// std::remove_reference<double&> 没有访问任何数据成员，所以不会建立实例化

// case 3
template <typename T>
struct Identity
{
	using type = T;
};

using res3 = std::conditional_t<true,
	Identity<double&>,
	std::remove_reference<double&>>::type; // 建立实例较少

// case 4
template <typename T>
constexpr bool intordouble1 = std::is_same_v<T, int> || std::is_same_v<T, double>;
// 元编程时，无论第一个值得结果，与和或都会对两侧都求值

// 可以使用 std::conjuction (logical and) std::disjunction (logical or) 减少实例化
template <typename T>
constexpr bool intordouble2 = std::disjunction_v<std::is_same<T, int>, std::is_same<T, double>>;

// case 5
template <typename... T> class arr;

template <typename T, unsigned id>
struct at;

template <typename Tcur, typename... T, unsigned id>
struct at<arr<Tcur, T...>, id>
{
	using type = typename at<arr<T...>, id - 1>::type;
};

template <typename Tcur, typename... T>
struct at<arr<Tcur, T...>, 0>
{
	using type = Tcur;
};

using res = at<arr<double, float, int, bool>, 2>::type;

int main()
{
	// 减少实例化的技巧

	// A 减少实例化的原因
	// 提升编译速度，减少编译所需内存
	std::vector<int> a;
	std::vector<int> b; // 第二次构造所需要的资源少于第一次构造
	
    // 但这不适合元编程
	// 嵌套的类模板外围的模板时不同的
	std::cout << Wrap_<3>::value<2> << std::endl;
	std::cout << Wrap_<10>::value<2> << std::endl;

	// B 相关技巧
	// 提取重复逻辑以较少实例个数
	// conditional使用时避免实例化
	// 使用std::conjunction/std::disjunction引入短路逻辑
	std::cout << std::is_same_v<res1, double> << std::endl;
	std::cout << std::is_same_v<res2, double> << std::endl;
	std::cout << std::is_same_v<res3, double&> << std::endl;

	std::cout << intordouble1<int> << std::endl;
	std::cout << intordouble2<int> << std::endl;

	// C 其它技巧
	// 减少分摊复杂度的数组元素访问操作
	std::cout << std::is_same_v<res, int> << std::endl;
}
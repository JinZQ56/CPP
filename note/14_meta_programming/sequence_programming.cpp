#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

// 元编程
// ex1 为输入类型去掉引用并添加const
template <typename T>
struct str1
{
	using re_ref = typename std::remove_reference<T>::type;
	using con_type = typename std::add_const<re_ref>::type;
};

// ex2 判断输入的类型去掉引用后尺寸是否于输入参数相等
// 引入限定符防止误用
template <typename T, unsigned U>
struct str2
{
private:
	using re_ref = typename std::remove_reference<T>::type;

public:
	constexpr static bool value = (sizeof(re_ref) == U);
};

// 引入别名模板简化调用方式
template <typename T, unsigned U>
constexpr auto str2_v = str2<T, U>::value;

int main()
{
	// 顺序代码的编写方式

	// A 类型转换示例：为输入类型去掉引用并添加const
	str1<int&>::con_type x = 3; // const int x = 3;

	// B 代码无需至于函数中
	// 通常至于模板中，以头文件的形式提供

	// C 复杂示例
	// 以数值，类型，模板作为输入
	// 以数值，类型，模板作为输出
	constexpr bool res = str2<int&, 4>::value;
	std::cout << res << std::endl;

	// D 引入限定符防止误用

	// E 通过别名模板简化调用方式
	std::cout << str2_v<int&, 4> << std::endl;
}
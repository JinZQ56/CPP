#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

// 模板元程序
template <int x>
struct str
{
	constexpr static int val = x + 1;
};

// constexpr函数
constexpr int fun(int x)
{
	return x + 1;
}

// 编译期数组
// 采用变长模板
template <unsigned... T> struct arr; // 数值数组
template <auto... T> struct arr2;
template <typename... T> struct arr3;
template <template<typename> class... T> struct arr4; // 模板数组

// 编译期常量，可以作为元程序的输入或输出
constexpr int c = 3;

int main()
{
	// A 元编程
	// 引入操纵程序的程序
	// 编译期计算

	// B 元程序的形式
	// 模板，constexpr函数，其它编译期可使用的函数（如 sizeof）
	// 通常以函数为单位，也被称为函数式编程
	str<3>::val;
	constexpr int x = fun(3);
	int y = sizeof(int);

	// C 元数据
	// 编译期函数能够接收和产生的元数据
	// 基本元数据：数值，类型，模板
	// 数组

	// D 元程序的性质
	// 输入输出均为“常量”，在运行期无法被改变，和变量做对比
	// 函数编译期可以被调用
	// 函数无副作用，对于相同的输入有相同的输出

	// E type_traits元编程库
	// since C++ 11
}
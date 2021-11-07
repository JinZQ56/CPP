#include <iostream>
#include <vector>
#include <string>


// 函数模板的声明
template <typename T>
void fun(T input);

// 函数模板的定义
template <typename T = int>
void fun(T input)
{
	std::cout << input << std::endl;
}

// 函数模板的重载
template <typename T> 
void fun(T* input)
{
	std::cout << *input << std::endl;
}

// 函数模板重载
template <typename T1, typename T2>
void fun(T1 input1, T2 input2)
{
	std::cout << input1 << " " << input2 << std::endl;
}


int main()
{
	// A 函数模板
	// template<typename T>void fun(T){...}
	// template<class C>void fun(C){...} 
	// template可以被class替换，含义相同，但是不能用struct
	// 函数模板中包含了两对参数：函数形参/实参；模板形参/实参
	// T是模板形参 input是函数形参
	// int是模板实参 x是函数实参
	// 模板形参需要在编译期赋予相应的模板实参
	// 函数形参主要在运行期调用
	
	int x = 1;
	std::string s = "abc";

	// B 函数模板实例化
	// 函数模板不是函数，不能被调用
	// 实例化会使得编译器产生相应的函数模板的实例，可以被调用
	// 有<int>时为显式实例化
	fun<int>(x);
	fun<std::string>(s);

	// C 函数模板的一处定义原则
    // 函数模板在实例化时必须可见，因此C++放松了对模板一处定义原则的限制
	// 函数是程序级别的一处定义原则，若定义在头文件，需要写明inline
	// 函数模板是翻译单元级别的一处定义原则，可直接写进头文件
	// 函数模板中的函数也可以加inline变为内联函数，但是含义与普通的内联函数有区别，会在定义处被展开(不是很懂）

	// D 函数模板的重载
	fun<int>(x);
	fun<std::string>(&s);
	fun<int, std::string>(x, s);

	// E 模板实参的类型推导
	// 如果函数模板在实例化时没有显式指定模板实参，那么系统会尝试推导
	// 推导是基于函数实参确定模板实参的过程，基本原则与auto类型推导相似
	// 1 函数形参是左值引用/指针 T&/T*
	// 2 函数形参是万能引用 T&&
	// 3 函数形参不包含引用 T

	// 隐式实例化
	fun(x);
	fun(s);

	// 第一个const为底层const 表示ptr指向的内容不会被修改
	// 第二个const为顶层const 表示ptr不会被修改
	const int* const ptr = &x;

	// 数组不能被复制

	// 同时使用显式实例化和隐式实例化
	// 第一个模板参数为int，第二个为自动推导
	fun<int>(3, 5.0);

	// F 模板实参并非总能推导得到
	// 模板形参与函数形参无关时，无法推导
	// 推导成功后可能存在歧义 // void fun(unsigned input = sizeof(T))

	// G 可以为模板形参设置缺省实参
	// 可以为任意位置的的模板形参指定缺省实参，此点与函数缺省实参有区别
	// 正确 <typename T1, typename T2=int, typename T3>
	// 错误 (int x1, int x2=1, int x3)

	// H 显示指定部分模板实参
	// 显示指定的模板实参必须从最左边开始，依次指定
	// 模板形参的声明顺序会影响调用的灵活性，将需要显式指定的模板形参放在最前面

	// I 其它
	// SFINAE
	// 模板与非模板同时匹配，匹配等级相同，此时选择非模板版本
	//多个模板同时匹配，此时采用偏序关系确定选择最”特殊“的版本
}
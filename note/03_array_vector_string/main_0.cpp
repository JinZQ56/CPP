#include <iostream>
#include <type_traits>
#include <typeinfo>

void fun0()
{
	int a;  //int
	int b[10];  //int[10]

	std::cout << std::is_same_v<decltype(b), int[10]> << std::endl;

}

void fun1()
{
	int x;
	std::cin >> x;

	//int b[x];  //标准C++不支持
	//int b[];  //不合法，编译器无法推导b的类型

	constexpr short y = 3;
	int b[y];  //合法，y是常量表达式
}

void fun2()
{
	int a;    //int
	int b[1]; //int[1]与int类型完全不同
}

int a[3]; //全局域中缺省会被初始化为0
int a1[3] = {}; //同样初始化为0

void fun3()  //数组初始化
{
	int b[3]; //缺省初始化，三个元素均按照缺省的方式初始化
	
	int c[3] = { 1,2,3 }; //聚合初始化
	int d[3] = { 1,2 }; //聚合初始化变体1，前两个元素初始化为1和2，第三个初始化为0
	int e[3] = {}; //初始化为0
	int f[] = { 1,2,3 }; //编译器自动推导类型为int[3]
	std::cout << std::is_same_v<decltype(f), int[3]> << std::endl;
	//int g[2] = { 1,2,3 }; //编译报错

	//auto不能用于推导数组类型
	auto h = { 1,2,3 };  //auto推导为类模板所实例化出的类型
	std::cout << std::is_same_v<decltype(h), int[3]> << std::endl;
	std::cout << std::is_same_v<decltype(h), std::initializer_list<int>> << std::endl;
	std::cout << typeid(h).name() << std::endl;
	
	//int i[3] = b;   //报错，数组初始化不支持复制
	auto j = b;  //数组作为右值时被退化为指针 
	auto& k = b; //引用防止类型退化
	std::cout << std::is_same_v<decltype(j), int*> << std::endl;
	std::cout << std::is_same_v<decltype(k), int(&)[3]> << std::endl;
}

void fun4() //字符串数组
{
	char str[] = "Hello";  //简化写法  char[6]  隐式的加入了0，表示字符串的结束
	std::cout << std::is_same_v<decltype(str), char[6]> << std::endl;
	char str1[] = { 'H','e','l','l','o' };  //char[5]	
	char str2[] = { 'H','e','l','l','o','\0' };  //char[5]
	std::cout << std::is_same_v<decltype(str1), char[5] > << std::endl;
	std::cout << std::is_same_v<decltype(str), decltype(str2) > << std::endl;

}

void fun5() //数组的复杂声明
{
	int x1;
	int x2;
	int x3;
	int* a[3] = {&x1, &x2, &x3}; //指针数组，数组中的元素都为指针
	std::cout << std::is_same_v<decltype(a), int* [3]> << std::endl;

	//int& a1[3] = { x1,x2,x3 };  //报错，无法定义引用数组
	//实现上引用是指针，概念上引用是对象的别名，数组应包含的是对象

	int b[3];  //数组的指针
	int(*c)[3]=&b;  //数组的指针
	std::cout << std::is_same_v<decltype(c), int(*)[3]> << std::endl;

	int(&d)[3] = b;  //数组的引用
	std::cout << std::is_same_v<decltype(d), int(&)[3]> << std::endl;

	int e[3] = { 1,2,3 };  //数组访问，第一个下标为0；
	e[1] = 4;
	std::cout << e[0] << e[1] << e[2] << std::endl;

	auto f = e;
	std::cout << std::is_same_v<decltype(f), int*> << std::endl;
	std::cout << std::is_same_v<decltype(f), int(*)[3]> << std::endl;
	std::cout << *f << std::endl;
	std::cout << f << std::endl;
	std::cout << &(e[0]) << std::endl;

	std::cout << f[0] << f[1] << f[2] << std::endl;  //中括号并不是数组专用的，可以用于指针
	std::cout << *(f + 0) << *(f + 1) << *(f + 2) << std::endl;
	std::cout << 0[f] << 1[f] << 2[f] << std::endl;

	//注意访问溢出
	//*(a-1)不合法
	//std::cout << a[-1] << ' ' << *(a - 1) << std::endl;  //合法，但不能这样使用


}

//extern int array[4]; //定义处数组长度的改变，声明处也应该改变
extern int array1[];
extern int* array;  //数组在一定情况下会转换为指针，但不可以这样声明 

void fun6()
{
	int a[3] = { 1,2,3 };
	auto b = a; // int*
	std::cout << std::is_same_v<decltype(b), int*> << std::endl;
	auto& c = a; // int(&)[3]
	std::cout << std::is_same_v<decltype(c), int(&)[3]> << std::endl;

	int array[4] = { 1,2,3,4 };  //数组的定义，而非数组的声明

}

void fun7();

void fun8()
{
	int a[3] = { 1,2,3 };
	
	std::cout << a  << ' ' << &(a[0]) << ' ' << std::cbegin(a) << std::endl;
	// 指向数组结尾的指针 &(a[3]) 或 a+3
	std::cout << a + 3 << ' ' << &(a[3]) << ' ' << std::cend(a) << std::endl;

    // std::begin(a) -> int* 可以进行读写
	// std::cbegin(a) -> const int* 只能进行读
}

void fun9()  //指针算数
{
	int a[3] = { 1,2,3 };
	auto ptr = a;
	std::cout << *ptr << std::endl;

	//增减
	ptr = ptr + 2;
	std::cout << *ptr << std::endl;

	//比较
	auto ptr1 = a + 1;
	std::cout << (ptr == ptr1) << '\n';
	std::cout << (ptr != ptr1) << '\n';
	std::cout << (ptr >= ptr1) << '\n';
	std::cout << (ptr <= ptr1) << '\n';

	//求距离
	std::cout << ptr - ptr1 << std::endl; //返回两个指针间包含的元素个数
	std::cout << ptr1 - ptr << std::endl;

	//解引用
	//指针索引，即正确使用中括号
	std::cout << *ptr << ' ' << ptr[-1] << ' ' << ptr1[1] << std::endl;
}

void fun10()  //数组其它操作
{
	int a[3] = { 1,2,3 };
	
	//求元素个数
	std::cout << sizeof(a) << std::endl;  //sizeof为c语言中的常用方法
	std::cout << sizeof(int) << std::endl;  //sizeof求元素所占的空间
	std::cout << sizeof(a) / sizeof(int) << std::endl;

	std::cout << std::size(a) << std::endl;  //C++标准库中的函数，较为推荐

	std::cout << std::end(a) - std::begin(a) << std::endl;  //end指针错后一位
	std::cout << std::cend(a) - std::cbegin(a) << std::endl;  //在运行期获取，可能消耗更多的时间

	//元素遍历
	size_t index = 0;
	while (index < std::size(a))
	{
		std::cout << a[index] << std::endl;
		index = index + 1;
	}

	auto ptr = std::cbegin(a);
	while (ptr != std::cend(a))
	{
		std::cout << *ptr << std::endl;
		ptr = ptr + 1;
	}

	for (int x : a)  //基于 range-based for 循环，C++11中引入的语法糖
	{
		std::cout << x << std::endl;
	}

}

int main()
{
	//fun0();
	//fun3();
	//fun4();
	fun5();
	//fun6();
	//std::cout << array[0] << array[2] << std::endl;

	/*
	std::cout << array << std::endl;
	std::cout << array1 << std::endl;
	fun7();
	*/

	//fun8();

	//fun9();

	//fun10();
}
#include <iostream>

// 基本（内建）类型
// 数值类型：字符类型，整数类型，浮点类型
// void

void fun_0()
{
	char c; //8位，1个字节，256种，ASCII码
	wchar_t wc; //宽字符类型，无准确定义
	//char8_t c8 = 'a';
	char16_t c16; //可引入于C++11
	char32_t c32; //扩展位4个字节，处理Unicode编码

	std::cout << sizeof(c) << std::endl;
	std::cout << sizeof(wc) << std::endl;
	//std::cout << sizeof(char8_t) << std::endl;
	std::cout << sizeof(c16) << std::endl;
	std::cout << sizeof(c32) << std::endl;

	//char是否有符号
	char ch1='a';
	signed char ch2='s'; //有符号的char
	unsigned char ch3='s'; //无符号的char
}

void fun_1() //整数类型
{
	//不同整数类型的尺寸不同，C++标准种仅规定了每种类型的最小尺寸，在不同的环境种不同
	//带符号
	short s; //占2个字节
	int i; //占4个字节
	long l=10;
	long long ll=10;

	std::cout << sizeof(s) << std::endl;
	std::cout << sizeof(i) << std::endl;
	std::cout << sizeof(long) << std::endl;
	std::cout << sizeof(long long) << std::endl;

	//无符号
	unsigned short us=10;
	unsigned int ui=10; // unsigned 等价于 unsigned int
	unsigned long ul=10;
	unsigned long long ull=10;

	//固定宽度的整数类型
	//增加代码可移植性
	int32_t i32 = 888;
	std::cout << sizeof(int32_t) << std::endl;
}

void fun_2() //浮点类型
{
	float f = 3.14; //单精度
	double d = 3.0; //双精度
	long double ld = 3.14; //宽度更宽

	std::cout << f << std::endl;
	std::cout << sizeof(f) << std::endl;
	std::cout << std::numeric_limits<float>::max() << std::endl;
	std::cout << std::numeric_limits<float>::min() << std::endl;
	std::cout << sizeof(d) << std::endl;
	std::cout << std::numeric_limits<double>::max() << std::endl;
	std::cout << std::numeric_limits<double>::min() << std::endl;
	std::cout << sizeof(ld) << std::endl;

}

void fun_3() //字面值类型
{
	//1.3一般为double型，可以通过添加后缀转换为float（1.3f）
	float f = 1.3f;
	unsigned long long ull = 2ULL; 	 
}

int operator "" _ddd(long double x) //自定义数据类型
{
	return (int)x * 2;
}

extern int g_x; //变量的声明，该变量来源于外部
//当在此赋值时，有引用转变为定义，可能出现重复定义的问题

int sq_x;

void fun_4()
{
	std::cout << "全部变量初始话省缺" << sq_x << std::endl;
	int sq_y=1;
	std::cout << "函数内部初始话省缺" << sq_y << std::endl;
	std::cout << "函数内部初始化省缺时报错" << std::endl;

	//直接初始化
	int zj_x(10); 
	int zj_y{10}; //也可以使用大括号
	//拷贝初始化
	int kb_x = 10;

	std::cout << zj_x << zj_y << kb_x << std::endl;

}

int main()
{
	std::cout << "字符类型" << std::endl;
	fun_0();
	std::cout << "整数类型" << std::endl;
	fun_1();
	/*
	int x = 10;
	int y;
	std::cout << sizeof(x) << std::endl;
	std::cout << sizeof(y) << std::endl;
	*/
	std::cout << "浮点类型" << std::endl;
	fun_2();

	std::cout << sizeof(nullptr_t) << std::endl;

	int x = 3.14_ddd;
	std::cout << x << std::endl;

	//int g_x = 2;
	std::cout << "变量的声明于定义" << g_x << std::endl;

	//变量的初始化
	//函数内部初始化缺省时，变量值随机的，未知的
	//int f_x=1;
	//std::cout << "函数内部声明变量初始化省缺" << f_x << std::endl;
	//全局变量初始化缺省时，变量被赋值为0
	std::cout << "变量初始化" << std::endl;
	fun_4();
}
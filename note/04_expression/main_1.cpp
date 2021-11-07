#include<iostream>
#include<compare>

void fun0()  //算术操作符
{
	int x = 3;
	int y = 5; 
	
	//优先级
	//一元 + -
	std::cout << +x << '\n';
	std::cout << -y << '\n';

	//* / % 乘初求余
	std::cout << y % x << '\n';

	//二元 + -
	std::cout << x + y << '\n';

	//均为左结合
	//结果为算数类型的右值
	
	//+ - 和 一元+可以接收指针
	int a[3] = { 1,2,3 };
	int* ptr = a;
	ptr = ptr + 1;
	std::cout << *ptr << '\n';


	//求余特性
	// (m/n)*n + m%n == m
	std::cout << (5 / 2) * 2 + 5 % 2 << '\n';
}

void fun1() //逻辑与关系操作符
{
	int* ptr = nullptr;
	if(ptr && (*ptr==3))  //逻辑与和逻辑或的短路特性
	{ }

    /* 逻辑与优先级大于逻辑或
	a && b || c
	a || b && c
	*/

	int a = 3;
	int b = 4;
	int c = 5;
	std::cout << (c > b > a) << '\n';
	std::cout << (c > b) && (b > a) << '\n';

	//three way comprasion operator <=>
	//大于 等于 小于 返回 1 0 -1
	//auto res = (a <=> b);  //由c++20引入，支持 <=> 不好
	//std::cout << res << '\n';
}

void fun2() //位操作符
{
	//按位取反 ~
	signed char x = 3; //00000011
	std::cout << x << '\n';
	std::cout << ~x << '\n'; //11111100

	//与& 或| 异或^
	signed char y = 5; //00000101
	std::cout << (x & y) << '\n'; //00000001
	std::cout << (x | y) << '\n'; //00000111
	std::cout << (x ^ y) << '\n'; //00000110

	//整型提升
	auto z = x & y;
	std::cout << z << '\n';
	std::cout << std::is_same_v<decltype(z), int> << '\n';


	//没有短路逻辑

	//移位操作
	std::cout << (x << 1) << '\n'; //00000110
	std::cout << (x >> 1) << '\n'; //00000001

	unsigned char x1 = 0xff; //11111111
	//00000...11111111
	//11111...00000000
	auto y1 = ~x1;  //首先对x1做整数的提升
	std::cout << y1 << std::endl; 

	signed char x2 = 0xff;
	//补1，因为有符号位，提升前后数值应相等
	//1111...11111111
	//0000...00000000
	auto y2 = ~x2;
	std::cout << y2 << '\n';

	//char时结果因为编译器不同可能不同
	char x3 = 0xff;
	auto y3 = ~x3;
	std::cout << y3 << '\n';

	//右移可以保持符号，左移不一定
	int x4 = 0x80000000;
	std::cout << x4 << '\n';
	std::cout << (x4 >> 1) << '\n';
	std::cout << (x4 << 1) << '\n';

	int x5 = -1;
	std::cout << x5 << '\n';
	std::cout << (x5 >> 1) << '\n';
	std::cout << (x5 << 1) << '\n';
}

void fun3() //赋值操作符
{
	//赋值操作符为右结合
	int x;
	int y;

	x = y = 3;
	
	//{}防止收缩转换
	short z;
	z = 0x80000003;
	std::cout << z << '\n';

	z = { 3 };
	
	constexpr int z1 = 4;
	z = { z1 };

	//复合赋值运算符
	int x1 = 2;
	x1 = x1 + 2;

	x1 += 2; // x=x+2
	x1 *= 2; // x=x*2
    
	x = 2;
	y = 3;
	x ^= y ^= x ^= y;
	std::cout << x << '\n';
	std::cout << y << '\n';
}

void fun4() //自增自减运算符
{
	int x = 3;
	x = x + 1;
	x += 1;
	x++; //返回prvalue，可以视为临时变量
	++x; //返回左值，返回更新之后的值
	std::cout << x << '\n';

	int y = 1;
	int z;
	z = y++;
	std::cout << y << '\n';
	std::cout << z << '\n';
	z = ++y;
	std::cout << y << '\n';
	std::cout << z << '\n';
}

struct Str
{
	int x;
};

namespace ABC
{
	int x；
}

void fun5() //其它操作符
{
	//成员访问操作符 . and ->
	Str a;
	a.x;

	Str* ptr = &a;
	(*ptr).x;
	ptr->x; //替代指针写法

	int y = 3;

	decltype(a.x) y1;
	std::cout << std::is_same_v<decltype(y1), int> << '\n';
	decltype((a.x)) y2 = y;
	std::cout << std::is_same_v<decltype(y2), int&> << '\n';
	decltype((Str().x)) y3 = 3;
	std::cout << std::is_same_v<decltype(y3), int&&> << '\n';
	decltype((ptr->x)) y4 = y; //箭头操作数返回左值
	std::cout << std::is_same_v<decltype(y4), int&> << '\n';

	//条件操作符， 唯一的三元操作数 由？和：组成
	std::cout << (true ? 5 : 3) << '\n';
	std::cout << (false ? 3 : 5) << '\n';

	int x1 = 1;
	int x2 = 3;
	std::cout << (true ? ++x1 : ++x2) << '\n';
	std::cout << x1 << '\n';
	std::cout << x2 << '\n';

	//当两个表达式都是左值时则返回左值，否则返回右值
	(false ? x1 : x2) = 12;
	std::cout << x2 << '\n';

	//右结合
	int score = -100;
	int res = (score > 0) ? 1 : (score == 0) ? 0 : -1;
	std::cout << res << '\n';

	//逗号操作符,从左向右求值
	std::cout << (2, 3) << '\n';

	//sizeof操作符
	//sizeof(type) sizeof expression
	int x = 56;
	std::cout << sizeof(int) << sizeof(x) << sizeof x << '\n';

	//sizeof不会实际求值，二十返回相应的尺寸
	int* ptr = nullptr;
	std::cout << sizeof(*ptr) << '\n';

	//域解析操作符::
	ABC::x；

}

int main()
{
	//fun0();

	//fun1();

	//fun2();

	//fun3();

	//fun4();

	fun5();
}
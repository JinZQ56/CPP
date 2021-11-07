#include<iostream>
#include<vector>

void fun0()
{
	//表达式语句
	//对表达式求值后丢弃，可能产生副作用
	int x;
	x = 2 + 3;
	std::cout << x << '\n';
	//空语句
	;

	//复合语句（语句体）
	if (x < 10)
	{
		++x;
	}
	std::cout << x << '\n';

	//复合语句形成独立的语句域
	int y = 56;
	std::cout << y << '\n';
	{
		int y = 65;
		std::cout << y << '\n';
	}

	//顺序语句
	//非顺序语句
	int z = 3;
	if (z) goto label;
	++z;
	std::cout << z << '\n';
label:
	std::cout << "label" << '\n';
}

void fun1()
{
	//分支语句
	int x = 5;
	//if语句
	if (x > 2)
		std::cout << "x > 2" << '\n';
	else
		std::cout << "x < 2" << '\n';
	//语句块
	if (x > 2)
	{
		int y = 56;
		std::cout << y << '\n';
	}
	else
	{
		x = x * 2;
		std::cout << x << '\n';
	}
	//多分支
	if (x > 2)
	{
		std::cout << "x>2" << '\n';
	}
	else if (x > 0)
	{
		std::cout << "x>0" << '\n';
	}
	else
	{
		std::cout << "x<0" << '\n';
	}

	//else与最近的if匹配，不能通过缩进或换行控制匹配
	int grade = 65;
	if (grade > 60)
		if (grade > 80)
		{
			std::cout << "Excellent\n";
		}
	else
		std::cout << "bad\n";

	//通过大括号控制匹配
	if (grade > 60)
	{
		if (grade > 80)
		{
			std::cout << "Excellent\n";
		}
	}
	else
		std::cout << "bad\n";


	//constexpr if
	constexpr int gra = 80;
	if constexpr (gra < 60)  //条件应为常量表达式
	{
		std::cout << "fail\n";
	}
	else
	{
		std::cout << "pass\n";
	}

	//带初始化语句的if（from C++ 17）
	/*
	int y = 3;
	if (int z = y * 3; z > 5)
	{
		std::cout << z << '\n';
	}
	*/

}

void fun2()
{
	//switch语句
	//fallthrough 属性
	//若不加break，case会执行后面的全部语句
	//from C++17 条件可以包含初始化语句
	int x;
	std::cin >> x;
	switch (x)
	{
	case 1:
		std::cout << "Hello\n"; [[fallthrough]];//from  C++17
	case 2:
		std::cout << "Bye\n"; break;
	case 3:
		{
		int y = 3;
		std::cout << y << '\n'; break;
		}
	case 4:
	case 5:
		std::cout << "double\n";  
	default:
		std::cout << "Hi\n"; break;
	}

	//在case和default中定义对象要加大括号
}

void fun3()
{
	//循环语句
	//while语句
	int x = 3;
	while (x < 10)
	{
		std::cout << x << '\n';
		++x;
	}
	

	//do-while语句
	do
	{
		std::cout << x << '\n';
		--x;
	} while (x>2);
}

void fun4()
{
	//for循环语句
	for (int x = 0; x < 5; ++x)
	{
		std::cout << x << '\n';
	}

	//初始化语句，条件，迭代表达式都可以为空 
	//for (;;)
	//	;

	//基于范围的for循环
	//语法糖，编译器会转换为传统for循环的调用
	std::vector<int> arr{ 1,2,3,4,5 };
	for (int v : arr)
	{
		std::cout << v << '\n';
	}

	std::vector<std::string> str{ "h","e","l" };
	for (const std::string& v : str)
	{
		std::cout << v << '\n';
	}

	//使用万能引用（universal reference）修改元素
	for (auto&& v : arr)
	{
		v = v + 1;
	}
	for (const int& v : arr)
	{
		std::cout << v << '\n';
	}
	
}

void fun5()
{
	//break
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 5; ++j)  //break仅终止内循环
		{
			if (j == 2) break;
			std::cout << i << ' ' << j << '\n';
		}
	}

	//continue
	//用于跳过循环体的剩余部分，但不终止循环
	for (int i = 0; i < 10; i++)
	{
		if (i == 5) continue;
		std::cout << i << '\n';
	}

	//goto
	//可以用于跳出多重嵌套循环
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 5; ++j)  //break仅终止内循环
		{
			if (j == 2) goto label;
			std::cout << i << ' ' << j << '\n';
		}
	}

	label:std::cout << "stop" << '\n';
}

void fun6()
{
	//达夫设备
	constexpr size_t buffer_count = 10000;
	std::vector<size_t> buffer(buffer_count);
	for (size_t i = 0; i < buffer_count; ++i)
	{
		buffer[i] = i;
	}

	size_t max_value = buffer[0];
	for (size_t i = 0; i < buffer_count; ++i)
	{
		max_value = (max_value > buffer[i]) ? max_value : buffer[i];
	}

	std::cout << max_value << '\n';

	max_value = buffer[0];
	for (size_t i = 0; i < buffer_count; i += 8)
	{
		max_value = (max_value > buffer[i]) ? max_value : buffer[i];
		max_value = (max_value > buffer[i + 1]) ? max_value : buffer[i + 1];
		max_value = (max_value > buffer[i + 2]) ? max_value : buffer[i + 2];
		max_value = (max_value > buffer[i + 3]) ? max_value : buffer[i + 3];
		max_value = (max_value > buffer[i + 4]) ? max_value : buffer[i + 4];
		max_value = (max_value > buffer[i + 5]) ? max_value : buffer[i + 5];
		max_value = (max_value > buffer[i + 6]) ? max_value : buffer[i + 6];
		max_value = (max_value > buffer[i + 7]) ? max_value : buffer[i + 7];

	}

	std::cout << max_value << '\n';

	max_value = buffer[0];
	for (size_t i = 0; i + 7 < buffer_count; i += 8)
	{
		max_value = (max_value > buffer[i]) ? max_value : buffer[i];
		max_value = (max_value > buffer[i + 1]) ? max_value : buffer[i + 1];
		max_value = (max_value > buffer[i + 2]) ? max_value : buffer[i + 2];
		max_value = (max_value > buffer[i + 3]) ? max_value : buffer[i + 3];
		max_value = (max_value > buffer[i + 4]) ? max_value : buffer[i + 4];
		max_value = (max_value > buffer[i + 5]) ? max_value : buffer[i + 5];
		max_value = (max_value > buffer[i + 6]) ? max_value : buffer[i + 6];
		max_value = (max_value > buffer[i + 7]) ? max_value : buffer[i + 7];

	}

	for (size_t i = (buffer_count / 8) * 8 ; i < buffer_count; ++i)
	{
		max_value = (max_value > buffer[i]) ? max_value : buffer[i];
	}


	std::cout << max_value << '\n';
}

void fun7()
{
	constexpr size_t buffer_count = 10004;
	std::vector<size_t> buffer(buffer_count);
	auto ptr = buffer.begin();
	size_t max_value = buffer[0];
	for (size_t i = 0; i < buffer_count; ++i)
	{
		buffer[i] = i;
	}

	for (size_t i = 0; i + 7 < buffer_count; i += 8)
	{
		max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
	}

	switch (buffer_count % 8)
	{
	case 7: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
	case 6: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
	case 5: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
	case 4: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
	case 3: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
	case 2: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
	case 1: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
	case 0: break;
	}

	std::cout << max_value << '\n';
}

void fun8()
{
	constexpr size_t buffer_count = 10003;
	std::vector<size_t> buffer(buffer_count);
	auto ptr = buffer.begin();
	size_t max_value = buffer[0];
	for (size_t i = 0; i < buffer_count; ++i)
	{
		buffer[i] = i;
	}

	size_t i = 0;
	switch (buffer_count % 8)
		for (; i < (buffer_count + 7) / 8; ++i)
		{
		case 0: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		case 7: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		case 6: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		case 5: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		case 4: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		case 3: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		case 2: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		case 1: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		}

	std::cout << max_value << '\n';
}

int main()
{
	//fun0();

	//fun1();

	//fun2();

	//fun3();

	//fun4();

	//fun5();

	fun6();

	fun7();

	fun8();
}


#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

void fun0()
{
	std::ostringstream obj1;
	obj1 << 12;
	//obj1 << std::setw(10) <<std::setfill('.') <<"1234";
	std::string res = obj1.str();
	std::cout << res << '\n';

	std::istringstream obj2(res);
	int x;
	obj2 >> x;
	std::cout << x << '\n';


}

void fun1()
{

	//基于字符串流的字符串拼接与释放
	std::string str1="Hello ";
	str1 += "Hello ";
	str1 += "Hello ";
	str1 += "Hello!";
	//内存重复开辟与释放，不利于程序运行
	std::cout << str1 << '\n';

	std::ostringstream ostr;
	ostr << "World ";
	ostr << "World ";
	ostr << "World ";
	ostr << "World!";
	//通过缓冲区避免内存重复开辟与释放
	std::string str2 = ostr.str();
	std::cout << str2 << '\n';

}

int main()
{
	//fun0();
	fun1();
}
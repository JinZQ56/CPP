#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

void fun0()
{
	//流的定位

	//获取流位置
	std::ostringstream s;
	std::cout << s.tellp() << '\n';
	s << 'H';
	std::cout << s.tellp() << '\n';
	s << "ello world!";
	std::cout << s.tellp() << '\n';

	//设置流位置
	std::string str = "Hello world!";
	std::istringstream in(str);
	std::string str1, str2, str3, str4;
	in >> str1;
	in >> str2;
	std::cout << str1 << " " << str2 << '\n';

	in.seekg(3);
	in >> str3;
	in.seekg(8);
	in >> str4;
	std::cout << str3 << " " << str4 << '\n';
}

void fun1()
{
	//流的同步

	//基于flush()/sync()/unitbuf的同步
	std::cout << "What's your name?" << std::flush;
	//std::cout << std::unitbuf << "What's your name?";
	//std::cout.flush();
	std::string name;
	std::cin >> name;

	//基于绑定(tie)的同步
	std::ofstream out("test.txt");
	std::ifstream in("test.txt");
	std::string str = "0";

	out << "test";
	in >> str;

	std::cout << "Before tie: " << str << '\n';

	in.clear();
	in.tie(&out);
	in >> str;

	std::cout << "After tie: " << str << '\n';

	//与C语言标准IO库同步
	std::ios::sync_with_stdio(false);
	std::cout << "a\n";
	printf("b\n");
	std::cout << "c\n";
}

void fun2()
{
	//流的状态
	std::ofstream outF;
	outF << 10; //badbit
	std::cout << outF.good() << ' '
		<< outF.fail() << ' '
		<< outF.bad() << ' '
		<< outF.eof() << ' '
		<< static_cast<bool>(outF) << '\n';


	int x;
	//failbit:输入输出操作失败
	//需要整数却输入字符串
	std::cin >> x;
	std::cout << std::cin.good() << ' '
		<< std::cin.fail() << ' '
		<< std::cin.bad() << ' '
		<< std::cin.eof() << ' '
		<< static_cast<bool>(std::cin) << '\n';
}

int main()
{
	//fun0();
	//fun1();
	fun2();
}
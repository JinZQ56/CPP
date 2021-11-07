#include <iostream>
#include <iomanip>
#include <string>

void fun0()
{
	int x = 100;
	std::cout.setf(std::ios_base::showpos);
	std::cout.width(10);
	std::cout.fill('.');
	std::cout << x << std::endl;
	char a = '0';
	int aa = static_cast<char>(a);
	std::cout << a << '\n';
	std::cout << aa << '\n';

	std::cout << std::showpos << std::setw(10) << std::setfill('.')
		<< x << std::setw(10) << std::setfill('.') << '\n';
}

void fun1()
{
	int x;
	std::cin.read(reinterpret_cast<char*>(&x), sizeof(x));
	std::cout << x << '\n';
}

void fun2()
{
	int x;
	std::cin >> x;
	std::cout << x << '\n';

	std::string s;
	std::cin >> s;
	std::cout << s << '\n';
	
	char c[5] = {};//聚合初始化，初始为0
	std::cin >> std::setw(5) >> c; //读5-1个字符
	std::cout << c << '\n';
}

int main()
{
	//fun0();
	//fun1();
	fun2();
}
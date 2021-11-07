#include <iostream>
#include <cstdio>

void fun0(const char* pInfo, int pValue)
{
	std::cout << pInfo << std::endl;
	std::cout << pValue << std::endl;
}

void fun1(const char* pInfo, int /* pValue */)
{
	std::cout << pInfo << std::endl;
}

void fun2()
{
	fun0("Hello World!", 00);
	fun0("Hello China!", 01);
	fun1("Hello World!", 02);
	fun1("Hello China! ", 03);
}

void fun3()
{
	int x;
	std::cout << "How old are you?" << std::endl;
	std::cin >> x;
	std::cout << "You are " << x; //<< std::endl;
}

void fun4()
{
	std::cout << "output from cout";
	std::cerr << "output from cerr";
	std::clog << "output from clog";
}

void fun5()
{
	std::cout << "output from cout\n";
	std::cerr << "output from cerr\n";
	std::clog << "output from clog\n";
}

namespace NameSpace1
{
	void fun5()
	{
		std::cout << "output from cout\n";
		std::cerr << "output from cerr\n";
		std::clog << "output from clog\n";
	}

	void fun6()
	{
		std::cout << "output from cout\n";
		std::cerr << "output from cerr\n";
		std::clog << "output from clog\n";
	}
}

void fun7()
{
	std::cout << "Hello World\n"; // <iostream>
	printf("Hello World\n"); // <cstdio>

	int x = 10;
	std::cout << "I have " << x << " pens.\n";
	printf("I have %d pens.\n", x);
}

void fun8()
{
	int x = 42;

	std::cout << "Please input a numer: \n";

	int y = 0;
	std::cin >> y;
	if (y == x)
	{
		std::cout << "You are right!\n";
	}
	else
	{
		std::cout << "You are wrong!\n";
	}
}

void fun9()
{
	int x = 42;
	int y = 0;
	while (y != x)
	{
		std::cout << "Please input a number: \n";
		std::cin >> y;
		if(y<x)
		{
			std::cout << "Your number is samll.\n";
		}
		else if(y>x)
		{
			std::cout << "Your number is big.\n";
		}
		else
		{
			std::cout << "Your number is right.\n";
		}
	}
}

struct point
{
	int x;
	int y;

	void inc_x()
	{
		x = x + 1;
	}
};

point fun10(point p)
{
	p.x = p.x + 1;
	p.y = p.y + 1;
	return p;
}

int main()  //int main(int argc, char* argv[])
{
	//using namespace NameSpace1; fun6();
	//namespace sp1 = NameSpace1; sp1::fun6();
	//NameSpace1::fun6();

	point p;
	p.x = 1;
	p.y = 2;
	std::cout << p.x + p.y <<"\n";

	p = fun10(p);
	std::cout << p.x << " " << p.y << "\n";

	p.inc_x();
	std::cout << p.x << " " << p.y << "\n";

	point p1 = { 4,4 };
	std::cout << p1.x << " " << p1.y << "\n";
}


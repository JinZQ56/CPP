#include <iostream>
#include <fstream>
#include <string>

void fun0(std::string s)
{
	std::ofstream outFile("demo");
	outFile << s;
	std::cout << outFile.is_open() << '\n';
	outFile.close();
	std::cout << outFile.is_open() << '\n';
}

void fun1()
{
	std::ifstream inFile("demo");
	std::cout << inFile.is_open() << '\n';
	std::string x;
	inFile >> x;
	std::cout << x << '\n';

	std::ifstream inFile2;
	inFile2.open("demo");
	std::cout << inFile2.is_open() << '\n';
	inFile2.close();
	std::cout << inFile2.is_open() << '\n';
}

void fun2(std::string s,int mode=1)
{
	if(mode == 0)
	{
		std::ofstream outFile("demo", std::ios_base::out);
		outFile << s;
		//outFile.close();  //对象脱离生命周期后会自动关闭
	}
	else
	{
		std::ofstream outFile("demo", std::ios_base::out | std::ios_base::app);
		outFile << s;
		//outFile.close();  //对象脱离生命周期后会自动关闭
	}
}

void fun3()
{
	std::ifstream inFile("demo", std::ios_base::in);
	std::string s;
	inFile >> s;
	std::cout << s << '\n';
	//inFile.close();  //对象脱离生命周期后会自动关闭
}

int main()
{
	//fun0("Hello");
	//fun1();
	fun2("Hello",0);
	fun2("World");
	fun3();
}
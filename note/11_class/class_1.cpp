#include <iostream>
#include <vector>
#include <string>
class cla1
{
public:
	cla1() = default;
	cla1():cla1("abc",3,x) // 代理构造函数
	{
		std::cout << "Constructor is called" << std::endl;
	}
	cla1(int input):cla1("abc", 3, x)
	{
		std::cout << "constructor 2" << std::endl;
		x = input;
	}
	cla1(const std::string& str):cla1("abc", 3, x)
	{
		// 此时s已经被构造，使用缺省初始化
		std::cout << "Pre" << s << std::endl;
		s = str;
		std::cout << "Post" << s << std::endl;
	}
	// 为避免不必要得参数构造可以使用初始化列表
	cla1(const std::string& str, int i, int& val) 
		:s(str)
		,x(i)
		,ref(val) // 引用必须使用初始化列表
		// 元素的初始化顺序与初始化列表无关，与元素的声明顺序有关
	{
		// 此时s不再使用缺省初始化
		std::cout << "int" << x << std::endl;
		std::cout << "string" << s << std::endl;
		ref = 9;
	}
private:
	int x;
	std::string s;
	// int& ref; //有引用时，类一定不能被缺省初始化
	int ref;
	
public:
	void print()
	{
		std::cout << x << std::endl;
	}

};

int main()
{
	cla1 c1;
	cla1 c2(5);
	c1.print();
	c2.print();

	cla1 c3("abc");
	int val;
	cla1 c4("def", 7, val);
	std::cout << val << std::endl;
}
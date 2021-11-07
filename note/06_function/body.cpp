#include <iostream>
#include <vector>

void fun1()
{
	static int x = 0;
	//生命周期：首次调用->程序结束
	//仅在函数内部可见
	//多线程时，只初始化一次 
	++x;
	std::cout << x << '\n';

	return; //无需走到结尾

	++x;
	std::cout << x << '\n';
}

int fun2()
{
	int x = 0;
	return x + 3; //返回表达式
}

std::vector<int> fun3()
{
	return { 1,2,3,4,5 }; //返回初始化列表
	//不建议返回 initializer_list 
	//因为 initializer_list 仅包含两个指针
	//但是返回列表在函数结束后会被销毁
}

int& fun4()
{
	static int y = 3;
	return y;
}

struct str
{
	str() = default;
	str(const str&)
	{
		std::cout << "copy constructor is called." << '\n';
	}
};

str fun5()
{
	str x;
	return x;
}

str fun6()
{
	return str{};
}

int main()
{
	fun1();
	fun1();

	std::vector<int> x;
	x = fun3();
	std::cout << x[2] << '\n';

	int& res = fun4();
	std::cout << res << '\n';

	std::cout << "非临时变量" << '\n';
	str st = fun5();

	std::cout << "临时变量" << '\n';
	str sr = fun6();
}
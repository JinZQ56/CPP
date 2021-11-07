#include <iostream>
#include <functional>
#include <map>

void fun0()
{
	// 捕获时计算
	int x = 3;
	int y = 5;
	auto l1 = [z = x + y](){return z; };
	std::cout << l1() << std::endl;

	//即调用函数表达式 Immediately Ivoked Function Expression
	const auto val = [z = x + y](){return z; }();
	std::cout << val << std::endl;

	// 使用auto避免复制 since c++14
	// 生成模板
	auto l2 = [](auto x) {return x + 1; };
	std::cout << l2(1) << " " << l2(2.3) << std::endl;

	std::map<int, int> m{ {2,3} };
	auto lam = [](const auto& p)
	{
		return p.first + p.second;
	};
	std::cout << lam(*m.begin()) << std::endl; 
}

auto f1(int val)
{
	return val + 1;
}

// 函数重载
auto f1(double val)
{
	return val + 1;
}

void fun1()
{
	// lifting since c++14
	// bind 无法应付函数重载
	//auto b = std::bind(f1, 3);
	//std::cout << b() << std::endl;

	auto l = [](auto x) {return f1(x); };
	std::cout << "int: " << l(3) << " " 
		<< "double: "<< l(3.5) << " " << std::endl;
}

void fun2()
{
	// 递归调用 since c++14
	// 有很多解决方案
	auto f = [](int n)
	{
		// 内层lambda表达式需要给出返回类型
		auto f_imple = [](int n, const auto& impl) -> int
		{
			return n > 1 ? n * impl(n - 1, impl) : 1;
		};
		return f_imple(n, f_imple);
	};
	std::cout << f(5) << std::endl;
}

int main()
{
	// fun0();
	// fun1();
	fun2();
}
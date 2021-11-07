#include <iostream>
#include <new>
#include <memory> //定义智能指针

std::shared_ptr<int> fun0()
{
	std::shared_ptr<int> res(new int(3));

	//shared_ptr中提高的方法 
	std::cout << *res << std::endl;
	//get返回res中保存的地址
	//方便与指针操作进行兼容
	std::cout << *(res.get()) << std::endl;

	std::shared_ptr<int> x = res;
	std::cout << *(x.get()) << std::endl;

	//reset首先判断是否是否已经关联到其它内存，若是则先delete
	//可以不传入任何参数，相当于传入null_ptr
	res.reset(new int(4));
	std::cout << *(res.get()) << std::endl;
	std::cout << *(x.get()) << std::endl;

	return res;
}

void fun1(int* ptr)
{
	//shared_ptr指定销毁逻辑
	std::cout << "Call deleter fun\n";
	delete ptr;
}

void dummy(int*) {}

std::shared_ptr<int> fun2()
{
	static int res = 5;
	return std::shared_ptr<int>(&res, dummy);
}

void fun3()
{
	std::unique_ptr<int> x(new int(3));
	//unique_ptr不可以复制，但可以移动
	//使用将亡值
	std::cout << x.get() << std::endl;
	std::unique_ptr<int> y = std::move(x);
	std::cout << x.get() << std::endl;
	std::cout << y.get() << std::endl;
}

std::unique_ptr<int> fun4()
{
	std::unique_ptr<int> res(new int(5));
	return res;
}

struct str
{
	//std::shared_ptr<str> nei;
	std::weak_ptr<str> nei;
	
	//析构函数
	~str()
	{
		std::cout << "~str is called\n";
	}
};

void fun5()
{
	std::shared_ptr<str> x(new str);
	std::shared_ptr<str> y(new str);
	x->nei = y;
	y->nei = x;
}

void fun6()
{
	std::shared_ptr<str> x(new str);
	{
		std::shared_ptr<str> y(new str);
		x->nei = y;
	}
	auto ptr = x->nei.lock();
	if (ptr)
	{
		std::cout << "ture branch" << std::endl;
	}
	else
	{
		std::cout << "false branch" << std::endl;
	}
}

int main()
{
	std::shared_ptr<int> x(new int(3));
	//对于shared_ptr不需要使用delete
	//对象会在调用后自动销毁
	//有引用计数，判读是否与其它共享指针对象共享相同的内存
	//初始时为1，代表没有其它对象与其共享内存

	std::shared_ptr<int> y = x;
	//x中的引用计数为2
	//y为局部对象，调用结束后会被析构
	//析构时引用计数-1

	//std::make_shared
	std::shared_ptr<int> yy = std::make_shared<int>(3);
	auto yyy = std::make_shared<int>(4);
	//推荐使用make_shared构造智能指针
	//由于内存局部性 
	//使用new_int时，指针的地址与引用计数地址可能相隔很远，不便于析构
	//make_shared可以使保存对象的内存和保存引用计数的内存尽量的近

	//std::shared_ptr<int> z = fun0();
	//std::cout << *(z.get()) << std::endl;

	//为shared_ptr指定删除器
	std::shared_ptr<int> z(new int(3), fun1);

	std::shared_ptr<int> a = fun2();

	//智能指针支持数组
	//C++17 -> shared_ptr<T[]>
	//C++20 -> make_shared分配数组
	std::shared_ptr<int[]> b(new int[5]{ 1,2,3,4,5 });
	//auto c = std::make_shared<int[5]>();
	//auto d = std::make_shared<int[]>(5);

	fun3();
	std::unique_ptr<int> e = fun4();
	std::cout << *(e.get()) << std::endl;

	std::unique_ptr<int, decltype(&fun1)> f(new int(6), fun1);
	std::cout << f << std::endl;

	//std::shared_ptr<str> g(new str);
	fun5();
	fun6();
}
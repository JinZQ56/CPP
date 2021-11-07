#include <iostream>
#include <vector>


void fun0(int p1,int p2)  //操作数求值顺序的不确定性
{
	std::cout << p1 << ' ' << p2 << '\n';
}

void fun1()
{
	std::cout << int{} << '\n'; //临时对象，0；
}

void fun2(std::vector<int>&& vec)
{

}

struct Str
{
	int x;
};

void fun3()
{
	const int x = 3;
	//x是glvalue，且没有即将消亡，所以x是lvalue
	//x是inmutable lvalue，无法放在等号左侧

	int y = int{}; //int{}是构造临时对象，是prvalue，无法定位到内存位置
	Str{} = Str{}; //右值可以放在等号左边
}

void fun4(const int& par) //左值与右值转换
{
	int x = 3;
	int y = 3;
	int z;
	z = x + y; //lvalue to rvalue conversion
	
	//Temporaray Materialization 临时具体化
	//prvalue to xvalue
	Str().x;  //从Str对应的内存中取出x对应的部分，Str()从prvalue转换为xvalue
}

void fun5() //decltype
{
	//prvalue -> type
	decltype(3) x;
	std::cout << std::is_same_v<decltype(x),int> << '\n';

	//lvalue -> type& 引用
	decltype((x)) y = x;
	std::cout << std::is_same_v<decltype(y), int&> << '\n';

	//xvalue -> type&& 右值引用
	decltype(std::move(x)) z = 3;
	std::cout << std::is_same_v<decltype(z), int&&> << '\n';
}

void fun6()  //类型转换
{
	//隐式类型转换
	int x = 1 + 1.5;
	std::cout << x << '\n';

	//显式类型转换
	//static_cast 性能好但不安全
    //dynamic_cast 安全但性能较差
	int y;
	y = static_cast<double>(3) + 0.5;
	std::cout << y << '\n';

	//操作符的操作数都是整数，则结果也是整数
	std::cout << (3 / 4) << '\n';
	std::cout << (3 / 4.0) << '\n';
	int z1 = 3;
	int z2 = 4;
	std::cout << (z1 / z2) << '\n';
	std::cout << (z1 / static_cast<double>(z2)) << '\n'; 

	//const_cast 去除或增加常量性
	//使用较为危险 
	const int* ptr;
	const_cast<int*>(ptr); //去除常量指针的常量性

	int x1 = 3;
	const int& ref = x1;
	int& ref2 = const_cast<int&>(ref);
	ref2 = 4;
	std::cout << x1 << '\n';

	//reinterpret_cast
	int x2 = 3;
	int* ptr2 = &x;
	double* ptr3 = reinterpret_cast<double*>(ptr2);
	float* ptr4 = reinterpret_cast<float*>(ptr2);
	//double y2 = reinterpret_cast<double>(x2);
	std::cout << *ptr3 << '\n';
	std::cout << *ptr4 << '\n';

	//C形式的类型转换
	//C++中不建议使用
	double x3 = (double)3;
	std::cout << x3 << '\n';
}

int main()
{
	//int x = 0;
	//fun0(x = x + 1, x = x + 1);

	//fun1();

	//std::vector<int> x; //glvalue 左值
	//fun2(std::move(x)); //转换为xvalue，代表x中的内容不会做更改，可以再fun中重复利用 

	//fun4(3); //3为prvalue，需要转换为xvalue才能绑定到par(par为引用，所以需要绑定到具体数值）

	//fun5();

	fun6();
}
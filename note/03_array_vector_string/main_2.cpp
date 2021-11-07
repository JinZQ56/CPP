#include <iostream>
#include <vector>
#include <string>

//C++标准库引入的数据结构
//vector 和 string
//更加侧重易用性

void fun0()  
{
	std::vector<int> x;
	std::vector<float> y;
	std::vector<int> x1;
	x1 = x; //vector支持复制，支持运行期动态改变元素个数
}

void fun1()
{
	//缺省初始化，包含0个元素
	std::vector<int> x;
	std::cout << x.empty() << std::endl;

	//聚合初始化，使用{}
	std::vector<int> x1 = { 1,2,3 };
	std::vector<int> x2(3); //包含3个元素且初始化为0
	std::cout << x2.size() << std::endl;
	std::vector<int> x3(3, 1); //包含三个元素，每个元素为1
	std::cout << x3.size() << std::endl;
	std::vector<int> x4{ 3,1 }; //包含两个元素，3和1
	std::cout << x4.size() << std::endl;

	//插入、删除元素
	x.push_back(2);  //在结尾（back）端插入
	std::cout << x.size() << std::endl;
	x.pop_back();  //在结尾弹出（pop）元素
	std::cout << x.size() << std::endl;

	//比较，按照字典顺序的比较
	std::cout << (x1 == x2) << std::endl;
	std::cout << (x1 > x2) << std::endl;

	//元素的索引与遍历
	std::cout << x1[2] <<' '<< x1.at(2) << std::endl;

	auto b = std::begin(x1);
	auto b1 = x1.begin();
	auto c = std::end(x1);
	auto c1 = x1.end();  //不再是获取指针，返回迭代器（iterator），用来模拟指针的行为，是一种特殊的数据类型
	//std::cout << *b1 << ' ' << *c << std::endl;
	while (b != c)
	{
		std::cout << *b << std::endl;
		b = b + 1;
	}

	for (auto val : x1)
	{
		std::cout << val << std::endl;
	}

	auto q = x4.begin();
	auto p = x4.end();
	std::cout << *q << ' ' << *(p - 1) << std::endl;
	/*
	//添加元素导致迭代器失效
	x4.push_back(2);
	std::cout << *q << ' ' << *(p - 1) << std::endl;
	*/

	//多维vector
	std::vector<std::vector<int>> z;
	z.push_back(std::vector<int>());
	z[0].push_back(56);
	std::cout << z[0][0] << std::endl;

	std::vector<std::vector<int>> z1 = { {1,2,3},{3,4,5} };
	std::cout << z1[1][2] << std::endl;
	std::cout << z1[1].size() << std::endl;


	std::vector<std::vector<int>> z2 = { {1,2,3},{4,5} };  //可以建立每一个维度包含元素不一致的vector
	std::cout << z2[1][1] << std::endl;
	std::cout << z2[1].size() << std::endl;

	// . 与 -> 
	std::vector<std::vector<int>>* ptr = &z1;
	std::cout << (*ptr).size() << std::endl;
	std::cout << ptr->size() << std::endl; //C+引入的语法糖，用于操作指向类的指针


}

void fun2()  //string
{
	std::string x = "Hello world"; 
	std::string y = x; //支持复制
	std::string z(x);
	y = y + "!!!";
	z = z + '!';
	std::cout << y << ' ' << z << '\n';

	//构造和初始化
	std::string x1(3, 'a');
	std::cout << x1 << '\n';

	//比较
	std::cout << (y == x) << '\n';
	std::cout << (y > x) << '\n';

	//赋值
	x1 = "ccc";
	std::cout << x1 << '\n';

	//拼接
	x1 = y + z;
	std::cout << x1 << '\n';

	//索引
	std::cout << x[10] << '\n';
	std::cout << x.at(10) << '\n';
	std::cout << x[11] << '\n';
	//std::cout << x[12] << '\n';

	//转换为C字符串
	auto ptr = x.c_str(); //转换为指向\0结尾的与原string相同的指针
	std::cout << ptr << std::endl;
	std::cout << *ptr << std::endl;
}

int main()
{
	//fun0();
	//fun1();
	fun2();
}
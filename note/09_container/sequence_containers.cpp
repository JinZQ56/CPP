#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <deque>
#include <type_traits>

void fun0()
{
	// array
	// 与内建数组相比，支持复制
	std::array<int, 3> a = {};
	std::array<int, 3> b = a;
	std::cout << std::is_same_v<std::array<int, 3>::value_type, int> << "\n";
}

void fun1()
{
	// 元素访问
	std::array<int, 5> a = { 1,2,3,4,5 };
	std::cout << a[3] << '\n';
	std::cout << a.at(3) << '\n'; //超范围不会乱指
	std::cout << a.front() << '\n';
	std::cout << a.back() << '\n';

    auto p = a.data(); //返回指针，指向第一个元素
	std::cout << *p << '\n';

	// 容量相关接口
	std::cout << a.empty() << '\n'; 
	std::cout << a.size() << '\n';
	std::cout << a.max_size() << '\n';

	// 填充与交换
	std::array<int, 5> b;
	b.fill(100);
	std::cout << b[0] << " "
		<< b[1] << " "
		<< b[2] << "\n";
	a.swap(b);
	std::cout << b[0] << " "
		<< b[1] << " "
		<< b[2] << "\n";

	// 比较操作
	// 按照字典顺序比较
	// 比较的两种数据类型相同
	std::cout << (a < b) << '\n';

	// 迭代器 iterator
	std::cout << *(b.begin()) << '\n';
	std::cout << *(b.end() - 1) << '\n';
}

void fun2()
{
	// vector
	// 元素数目可变

	// 容量相关接口
	std::vector<int> v1{ 1,2,3 };
	v1.reserve(1024);
	std::cout << "size: " << v1.size() << '\n';
	std::cout << "max_size: " << v1.max_size() << '\n';
	std::cout << "capacity: " << v1.capacity() << '\n';
	v1.shrink_to_fit();
	std::cout << "after shrink to fit" << '\n';
	std::cout << "size: " << v1.size() << '\n';
	std::cout << "max_size: " << v1.max_size() << '\n';
	std::cout << "capacity: " << v1.capacity() << '\n';

	std::vector<int> v2{ 4,5,6 };
	std::cout << "v1>v2?: " << (v1 < v2) << '\n';
	// vector swap直接交换指针，速度较快

	// 附加元素接口
	std::vector<std::string> vs;
	vs.push_back("Hello");
	vs.emplace_back("World");  //emplace_back少了一次元素的拷贝与移动，性能会提升
	std::cout << vs[0] << ' ' << vs[1] << '\n';

	// 插入元素接口
	auto it = vs.begin();
	vs.insert(it + 1, " ");
	it = vs.begin(); // 插入后指针失效
	it = vs.insert(it + 3, "!");
	std::cout << "new it: " << *it << '\n';
	std::cout << "vs: ";
	for (auto p : vs)
	{
		std::cout << p;
	}
	std::cout << '\n';

	// 元素删除接口
	vs.pop_back();
	it = vs.end();
	std::cout << *(it - 1) << '\n';
	it = vs.begin();
	vs.erase(it + 1);
	std::cout << vs.size() << '\n';
	vs.clear();
	std::cout << vs.size() << '\n'; 
}

std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list)
{
	for (auto& i : list) {
		ostr << " " << i;
	}
	return ostr;
}

std::ostream& operator<<(std::ostream& ostr, const std::forward_list<int>& list)
{
	for (auto& i : list) {
		ostr << " " << i;
	}
	return ostr;
}

void fun3()
{
	// list
	std::list<int> l1{ 1,2,3 };
	for (auto p = l1.begin(); p!=l1.end(); ++p)
	{
		std::cout << *p << '\n';
	}

	std::list<int> l2{ 4,5,6 };
	auto it = l1.begin();
	std::advance(it, 2);
	l1.splice(it, l2);
	std::cout << "list1: " << l1 << '\n';
	std::cout << "list2: " << l2 << '\n';
	std::cout << "new it: " << *it << '\n';

	// forward_list
	// 迭代器只支持递增
	std::forward_list<int> fl1{ 1, 2, 3 };
	auto it1 = fl1.begin();
	fl1.insert_after(it1, 5);
	std::cout << "forward_list1: " << fl1 << '\n';
	fl1.erase_after(it1);
	std::cout << *it1 << '\n';
	std::cout << "forward_list1: " << fl1 << '\n';
}

void fun4()
{
	// deque 
	// 双端队列
	// vector 和 list 的折中
}

void fun5()
{
	// basic_string
	// 提供了数值与字符串的转换函数
	int x = 100;
	std::cout << std::to_string(x) << '\n';
	std::string str = "123";
	std::cout << std::stoi(str) << '\n';
}

int main()
{
	// fun0();
	// fun1();

	// fun2();

	// fun3();

	fun5();
}
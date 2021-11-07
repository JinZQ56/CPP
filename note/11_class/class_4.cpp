#include <iostream>
#include <vector>
#include <string>

class cla
{
public:
	// 构造函数
	cla()
		: p(new int())
	{}

	// 析构函数
	~cla()
	{
		delete p;
	}

	// 拷贝构造
	cla(const cla& c)
		: p(new int())
	{
		*p = *(c.p);
	}

	// 拷贝赋值
	cla& operator= (const cla& c)
	{
		// p = new int();
		// 可以没有new，因为cla在构造时，已经有过new了
		*p = *(c.p);
		return *this;
	}

	// 移动构造
	cla(cla&& c) noexcept
		: p(c.p)
	{
		c.p = nullptr;
	}

	// 移动赋值
	cla& operator= (cla&& c)
	{
		p = c.p;
		c.p = nullptr;
		return *this;
	}

	int& data()
	{
		return *p;
	}

private:
	int* p;
};



int main()
{
	// A 若没有主动定义析构函数，c被删除，指针p被删除，但是指针p指向的内存没有被删除
	cla c1;
	c1.data() = 3;
	std::cout << c1.data() << std::endl;
	
	// B 当没有主动定义拷贝构造函数时，c1和c2中的指针都指向同一块内存，结束时会销毁两次，此时会报错
	// 通常有析构函数时，最好主动定义拷贝构造和移动构造
	// 有拷贝构造函数时，最后主动定义拷贝赋值函数

	// 拷贝构造
	cla c2(c1);
	// 拷贝赋值
	cla c3;
	c3 = c2;

	// 移动构造
	cla c4(std::move(c3));
	// 移动赋值
	cla c5;
	c5 = std::move(c4);

	// C 类中的关键字
	// default 关键字 只对特殊函数有效
	// delete 关键字 对所有函数都有效 表示函数无法被调用
	// 
}
#include <iostream>
#include <vector>

struct str
{
	// 缺省情况为public
	int x;
	
private:
	int y;

public:
	int z;

protected:
	int a;
};

class cla
{
	// 缺省情况为private
	int x;

	// 友元 friend
	// 某个函数是当前类的友元或者某个类是当前类的友元
	friend void fun0();

public:
	int y;

protected:
	int z;
};

void fun0()
{
	cla c;
	c.x = 1;
	std::cout << c.x << std::endl;
}

class cls1
{
	int x;
	friend void cfun() // 隐藏友元
	{
		cls1 c;
		c.x = 100;
		std::cout << c.x << std::endl;
	}

	friend void cfun1(cls1& c)
	{
		c.x = 10;
		std::cout << c.x << std::endl;
	}
};

void cfun();

void fun1()
{
	cfun();

	//实参依赖查找
	cls1 c;
	cfun1(c);
}

int main()
{
	// fun0();
	fun1();
}



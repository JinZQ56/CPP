#include <iostream>
#include <vector>

struct str
{
	// ȱʡ���Ϊpublic
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
	// ȱʡ���Ϊprivate
	int x;

	// ��Ԫ friend
	// ĳ�������ǵ�ǰ�����Ԫ����ĳ�����ǵ�ǰ�����Ԫ
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
	friend void cfun() // ������Ԫ
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

	//ʵ����������
	cls1 c;
	cfun1(c);
}

int main()
{
	// fun0();
	fun1();
}



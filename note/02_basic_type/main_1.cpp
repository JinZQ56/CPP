#include <iostream>
#include <limits>

void fun_0() //�洢�ռ�ߴ�
{
	int x = 10;
	char y = 'a';

	std::cout << sizeof(x) << std::endl;
	std::cout << sizeof(int) << std::endl;
	std::cout << sizeof(y) << std::endl;
	std::cout << sizeof(char) << std::endl;
}

void fun_1() //ȡֵ�ռ�
{
	std::cout << std::numeric_limits<int>::max() << std::endl;
	std::cout << std::numeric_limits<int>::min() << std::endl;

	std::cout << std::numeric_limits<unsigned int>::max() << std::endl;
	std::cout << std::numeric_limits<unsigned int>::min() << std::endl;
}

void fun_2() //��Χ���
{
	unsigned int x = std::numeric_limits<unsigned int>::max();
	x = x + 1;
	std::cout << x << std::endl;

	int y = std::numeric_limits<int>::max();
	y = y + 1;
	std::cout << y << std::endl;

	int z = std::numeric_limits<int>::min();
	z = z - 1;
	std::cout << z << std::endl;
}

struct str
{
	//8000-8003
	int x;
	//8004-8007 ��Ϊ��Ҫ����
	char y;
};

void fun_3() //������Ϣ
{
	int x = 10;

	std::cout << alignof(int) << std::endl;
	std::cout << alignof(char) << std::endl;

	std::cout << alignof(str) << std::endl;
	std::cout << sizeof(str) << std::endl;
}


int main()
{
	
	std::cout << "�洢�ռ�ߴ�" << std::endl;
	fun_0();
	std::cout << "ȡֵ�ռ�" << std::endl;
	fun_1();
	std::cout << "��Χ���" << std::endl;
	fun_2();
	std::cout << "������Ϣ" << std::endl;
	fun_3();
	
}
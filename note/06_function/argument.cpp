#include <iostream>
#include "function.h"
#include <initializer_list>

void fun1(void)  //void������ʾ�ı�ʾ�����������κβ���
{
}

void fun2(int) //�βο��Բ��������ƣ�������ҪԤ���ӿڵ������
{
	//�β����ƵĲ�ͬ�������뺯���汾�Ĳ�ͬ
}

struct str
{
	str() = default;
	str(const str&)
	{
		std::cout << "Copy constructor is called.\n";
	}
};

void fun3(str)
{
	//c++17ǿ��ʡ�Ը�����ʱ����
}

void fun4(int par)  //��ֵ
{
	++par;
}

void fun5(int* par) //��ַ
{
	++(*par);
}

void fun6(int& par)
{
	++par;
}

void fun7(int* ptr) //�������ι����е������˻�
{
}

void fun8(int (*ptr)[4])
{
}

void fun9(std::initializer_list<int> par) //�ɱ��������
{
	//ʹ��initiallizer_list 
}

//���ĳ���βξ���ȱʡʵ�Σ���ô���Ҳ���βζ��������ȱʡʵ��

//void fun10(int x, int y, int z = 3);
//void fun10(int x, int y = 2, int z); 
void fun10(int x, int y = 2, int z)
{
	std::cout << x + y + z << '\n';
}

int main(int argc, char* argv[])
{
	/*
	std::cout << add(3, 2) << '\n';
	std::cout << sub(3, 2) << '\n';
	*/
	 
	/*
	str val;
	fun3(val);
	fun3(str{});
	*/

	int arg = 3;
	fun4(arg);
	std::cout << "��ֵ��" << arg << '\n';
	fun5(&arg);
	std::cout << "��ַ��" << arg << '\n';
	fun6(arg);
	std::cout << "�����ã� " << arg << '\n';

	int a[3];
	fun7(a); //���鴫�뺯�����˻�Ϊָ��
	//ʹ�����ÿ��Է�ֹ�˻�  void fun(int (&par)[3])
	//��ʱ�����鳤��Ҳ�����Ӧ

	int b[3][4];
	fun8(b);

	fun9({ 1,2,3,4,5 });

	fun10(1);
}

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}
#include <iostream>

//����������������

//global scope ȫ���� ����ȫ�ֶ���
int x = 3;

//���ֿռ���
namespace MyNS
{
	int x = 5;
}

void fun_0()
{
	//block scope ���� ����ֲ�����
	int x = 4;
	std::cout << x << std::endl;  //ϵͳ�� ѡ��ֲ����е�x���ھֲ����а�ȫ����������
	{
		int x = 6;
		std::cout << x << std::endl;
	}
}


int main()
{
	fun_0();

	std::cout << x << std::endl;

	int x = 7;  //�˴�x������������ʼ�ڴ˴�
	std::cout << x << std::endl;
}
#include <iostream>
#include <vector>

void fun1()
{
	static int x = 0;
	//�������ڣ��״ε���->�������
	//���ں����ڲ��ɼ�
	//���߳�ʱ��ֻ��ʼ��һ�� 
	++x;
	std::cout << x << '\n';

	return; //�����ߵ���β

	++x;
	std::cout << x << '\n';
}

int fun2()
{
	int x = 0;
	return x + 3; //���ر��ʽ
}

std::vector<int> fun3()
{
	return { 1,2,3,4,5 }; //���س�ʼ���б�
	//�����鷵�� initializer_list 
	//��Ϊ initializer_list ����������ָ��
	//���Ƿ����б��ں���������ᱻ����
}

int& fun4()
{
	static int y = 3;
	return y;
}

struct str
{
	str() = default;
	str(const str&)
	{
		std::cout << "copy constructor is called." << '\n';
	}
};

str fun5()
{
	str x;
	return x;
}

str fun6()
{
	return str{};
}

int main()
{
	fun1();
	fun1();

	std::vector<int> x;
	x = fun3();
	std::cout << x[2] << '\n';

	int& res = fun4();
	std::cout << res << '\n';

	std::cout << "����ʱ����" << '\n';
	str st = fun5();

	std::cout << "��ʱ����" << '\n';
	str sr = fun6();
}
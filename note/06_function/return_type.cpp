#include <iostream>

//�������--��������
int fun1(int a, int b)
{
	return a + b;
}

//�������͵���д��ʽ
//���䷽��:λ�ں���ͷ��ǰ��

//c++11 ���뷽ʽ��λ�ں���ͷ��
//���ͺ�������������
auto fun2(int a, int b) -> int
{
	return a - b;
}

//C++14 ����ķ�ʽ���������͵��Զ��Ƶ�
auto fun3(int a, int b)
{
	if (a > b)
	{
		return 1;
	}
	else
	{
		//return 0.1;
		return -1; //return����ʽ����Ӧ����ͬ
	}
}

decltype(auto) fun4()
{
	int x=10;
	return x;
}

constexpr bool value = true; //�����ڳ���
auto fun5()
{
	if constexpr (value)
	{
		return 1;
	}
	else
	{
		return 1.0;
	}
}
//�����ڷ�������Ψһ


//����������ṹ����
struct str 
{
	int x;
	int y;
};

str fun6()
{
	str x = { 1,2 };
	return x;
}

//[[noiscard]]���� ��c++17��
[[nodiscard]]int fun7(int a, int b)
{
	return a + b;
}

int main()
{
	//�����Զ��Ƶ���c++11
	auto x = 3;
	decltype(3) y = 4;

	//c++14
	decltype(auto) z = 5;

	auto [res1, res2] = fun6();
	std::cout << res1 << ' ' << res2 << '\n';

	fun7(2, 3);
}
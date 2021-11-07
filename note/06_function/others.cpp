#include <iostream>

//�ݹ麯��
//�����������ӵĵ������� 

//��������
//�ɱ����������Ƿ���
void fun1()
{
	std::cout << "Hello World!" << '\n';
}

inline void fun2()
{
	std::cout << "Hello World!" << '\n';
}


//constexpr����(c++11)
//�ȿ����ڱ����ڱ����ã��ֿ����������ڱ�����
//�����ڲ���������ܹ��ڱ�������ִ�� 
constexpr int fun3(int x)
{
	return x;
}

//consteval����(c++20)
//ֻ���ڱ����ڱ�����
/*
consteval int fun4(int x)
{
	return x;
}
*/

//����ָ��
//�������ͺͺ���ָ������
int fun5(int val)  // int(int)
{
	return val + 1;
}

int add(int val)
{
	return val + 1;
}

int sub(int val)
{
	return val - 1;
}

using F = int(int);
F fun6;  //����������fun6��һ��int(int)���͵ĺ���
F* fun7; //����ָ��

int fun8(F* subfun, int val)
{
	auto tmp = (*subfun)(val);
	return tmp * tmp; 
}

int fun9(F f, int val)
{
	return f(val);
}

//�����ķ������Ͳ����Ǻ���
//���Է��غ���ָ��
F* fun10(bool val)
{
	if (val) { return add; }
	else { return sub; }
}

using f = void(void);

void fun11()
{
	std::cout << "test" << '\n';
}

void fun12(f fun)
{
	fun();
}



//����ָ��������

int main()
{
	fun2(); //����������ֱ�Ӹ��Ƶ�main������ 

	constexpr int x = fun3(1);
	std::cout << "�����ڣ�" << x << '\n';
	int y;
	std::cin >> y;
	std::cout << "�����ڣ�" << fun3(y) << '\n';

	std::cout << "����ָ��" << '\n';
	fun7 = &add;
	std::cout << fun7(2) << '\n';
	fun7 = &sub;
	std::cout << fun7(2) << '\n';

	std::cout << "����ָ����Ϊ��������" << '\n';
	std::cout << fun8(&add, 2) << '\n';
	std::cout << fun8(&sub, 2) << '\n';

	std::cout << fun8(add, 2) << '\n';
	std::cout << fun9(sub, 2) << '\n';

	std::cout << fun10(true)(2) << '\n';
	std::cout << fun10(false)(2) << '\n';

	std::cout << add(sub(3)) << '\n';
}
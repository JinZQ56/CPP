#include <iostream>
#include <type_traits>
#include <typeinfo>

void fun0()
{
	int a;  //int
	int b[10];  //int[10]

	std::cout << std::is_same_v<decltype(b), int[10]> << std::endl;

}

void fun1()
{
	int x;
	std::cin >> x;

	//int b[x];  //��׼C++��֧��
	//int b[];  //���Ϸ����������޷��Ƶ�b������

	constexpr short y = 3;
	int b[y];  //�Ϸ���y�ǳ������ʽ
}

void fun2()
{
	int a;    //int
	int b[1]; //int[1]��int������ȫ��ͬ
}

int a[3]; //ȫ������ȱʡ�ᱻ��ʼ��Ϊ0
int a1[3] = {}; //ͬ����ʼ��Ϊ0

void fun3()  //�����ʼ��
{
	int b[3]; //ȱʡ��ʼ��������Ԫ�ؾ�����ȱʡ�ķ�ʽ��ʼ��
	
	int c[3] = { 1,2,3 }; //�ۺϳ�ʼ��
	int d[3] = { 1,2 }; //�ۺϳ�ʼ������1��ǰ����Ԫ�س�ʼ��Ϊ1��2����������ʼ��Ϊ0
	int e[3] = {}; //��ʼ��Ϊ0
	int f[] = { 1,2,3 }; //�������Զ��Ƶ�����Ϊint[3]
	std::cout << std::is_same_v<decltype(f), int[3]> << std::endl;
	//int g[2] = { 1,2,3 }; //���뱨��

	//auto���������Ƶ���������
	auto h = { 1,2,3 };  //auto�Ƶ�Ϊ��ģ����ʵ������������
	std::cout << std::is_same_v<decltype(h), int[3]> << std::endl;
	std::cout << std::is_same_v<decltype(h), std::initializer_list<int>> << std::endl;
	std::cout << typeid(h).name() << std::endl;
	
	//int i[3] = b;   //���������ʼ����֧�ָ���
	auto j = b;  //������Ϊ��ֵʱ���˻�Ϊָ�� 
	auto& k = b; //���÷�ֹ�����˻�
	std::cout << std::is_same_v<decltype(j), int*> << std::endl;
	std::cout << std::is_same_v<decltype(k), int(&)[3]> << std::endl;
}

void fun4() //�ַ�������
{
	char str[] = "Hello";  //��д��  char[6]  ��ʽ�ļ�����0����ʾ�ַ����Ľ���
	std::cout << std::is_same_v<decltype(str), char[6]> << std::endl;
	char str1[] = { 'H','e','l','l','o' };  //char[5]	
	char str2[] = { 'H','e','l','l','o','\0' };  //char[5]
	std::cout << std::is_same_v<decltype(str1), char[5] > << std::endl;
	std::cout << std::is_same_v<decltype(str), decltype(str2) > << std::endl;

}

void fun5() //����ĸ�������
{
	int x1;
	int x2;
	int x3;
	int* a[3] = {&x1, &x2, &x3}; //ָ�����飬�����е�Ԫ�ض�Ϊָ��
	std::cout << std::is_same_v<decltype(a), int* [3]> << std::endl;

	//int& a1[3] = { x1,x2,x3 };  //�����޷�������������
	//ʵ����������ָ�룬�����������Ƕ���ı���������Ӧ�������Ƕ���

	int b[3];  //�����ָ��
	int(*c)[3]=&b;  //�����ָ��
	std::cout << std::is_same_v<decltype(c), int(*)[3]> << std::endl;

	int(&d)[3] = b;  //���������
	std::cout << std::is_same_v<decltype(d), int(&)[3]> << std::endl;

	int e[3] = { 1,2,3 };  //������ʣ���һ���±�Ϊ0��
	e[1] = 4;
	std::cout << e[0] << e[1] << e[2] << std::endl;

	auto f = e;
	std::cout << std::is_same_v<decltype(f), int*> << std::endl;
	std::cout << std::is_same_v<decltype(f), int(*)[3]> << std::endl;
	std::cout << *f << std::endl;
	std::cout << f << std::endl;
	std::cout << &(e[0]) << std::endl;

	std::cout << f[0] << f[1] << f[2] << std::endl;  //�����Ų���������ר�õģ���������ָ��
	std::cout << *(f + 0) << *(f + 1) << *(f + 2) << std::endl;
	std::cout << 0[f] << 1[f] << 2[f] << std::endl;

	//ע��������
	//*(a-1)���Ϸ�
	//std::cout << a[-1] << ' ' << *(a - 1) << std::endl;  //�Ϸ�������������ʹ��


}

//extern int array[4]; //���崦���鳤�ȵĸı䣬������ҲӦ�øı�
extern int array1[];
extern int* array;  //������һ������»�ת��Ϊָ�룬���������������� 

void fun6()
{
	int a[3] = { 1,2,3 };
	auto b = a; // int*
	std::cout << std::is_same_v<decltype(b), int*> << std::endl;
	auto& c = a; // int(&)[3]
	std::cout << std::is_same_v<decltype(c), int(&)[3]> << std::endl;

	int array[4] = { 1,2,3,4 };  //����Ķ��壬�������������

}

void fun7();

void fun8()
{
	int a[3] = { 1,2,3 };
	
	std::cout << a  << ' ' << &(a[0]) << ' ' << std::cbegin(a) << std::endl;
	// ָ�������β��ָ�� &(a[3]) �� a+3
	std::cout << a + 3 << ' ' << &(a[3]) << ' ' << std::cend(a) << std::endl;

    // std::begin(a) -> int* ���Խ��ж�д
	// std::cbegin(a) -> const int* ֻ�ܽ��ж�
}

void fun9()  //ָ������
{
	int a[3] = { 1,2,3 };
	auto ptr = a;
	std::cout << *ptr << std::endl;

	//����
	ptr = ptr + 2;
	std::cout << *ptr << std::endl;

	//�Ƚ�
	auto ptr1 = a + 1;
	std::cout << (ptr == ptr1) << '\n';
	std::cout << (ptr != ptr1) << '\n';
	std::cout << (ptr >= ptr1) << '\n';
	std::cout << (ptr <= ptr1) << '\n';

	//�����
	std::cout << ptr - ptr1 << std::endl; //��������ָ��������Ԫ�ظ���
	std::cout << ptr1 - ptr << std::endl;

	//������
	//ָ������������ȷʹ��������
	std::cout << *ptr << ' ' << ptr[-1] << ' ' << ptr1[1] << std::endl;
}

void fun10()  //������������
{
	int a[3] = { 1,2,3 };
	
	//��Ԫ�ظ���
	std::cout << sizeof(a) << std::endl;  //sizeofΪc�����еĳ��÷���
	std::cout << sizeof(int) << std::endl;  //sizeof��Ԫ����ռ�Ŀռ�
	std::cout << sizeof(a) / sizeof(int) << std::endl;

	std::cout << std::size(a) << std::endl;  //C++��׼���еĺ�������Ϊ�Ƽ�

	std::cout << std::end(a) - std::begin(a) << std::endl;  //endָ����һλ
	std::cout << std::cend(a) - std::cbegin(a) << std::endl;  //�������ڻ�ȡ���������ĸ����ʱ��

	//Ԫ�ر���
	size_t index = 0;
	while (index < std::size(a))
	{
		std::cout << a[index] << std::endl;
		index = index + 1;
	}

	auto ptr = std::cbegin(a);
	while (ptr != std::cend(a))
	{
		std::cout << *ptr << std::endl;
		ptr = ptr + 1;
	}

	for (int x : a)  //���� range-based for ѭ����C++11��������﷨��
	{
		std::cout << x << std::endl;
	}

}

int main()
{
	//fun0();
	//fun3();
	//fun4();
	fun5();
	//fun6();
	//std::cout << array[0] << array[2] << std::endl;

	/*
	std::cout << array << std::endl;
	std::cout << array1 << std::endl;
	fun7();
	*/

	//fun8();

	//fun9();

	//fun10();
}
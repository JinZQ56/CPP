#include <iostream>

void fun_0()
{
	//ָ�����ָ��ͬ�Ķ���
	int x = 1;
	int y = 2;
	int* p = &x; //Ҳ����дΪint *p
	p = &y;
	std::cout << y << std::endl;
	std::cout << (&y) << std::endl;
	std::cout << *p << std::endl;
	std::cout << p << std::endl;

	//ָ�������ͬ�ĳߴ�
	int i = 1;
	char c = 'a';
	int* p1 = &i;
	char *p2 = &c;
	std::cout << sizeof(p1) << std::endl;
	std::cout << &i << std::endl;
	std::cout << p1 << std::endl;
	std::cout << sizeof(p2) << std::endl;
	//std::cout << &c << std::endl;
	//std::cout << p2 << std::endl;

	//int* p3;
	//std::cout << p3 << std::endl;
	//ָ���ʼ�� ʹ����ָ��
	int* p4 = 0; //int* p4=NULL;
	int* p5 = nullptr; //C++11�����ԣ�nullptr��������nullptr_t����һ������Ķ��󣬱�ʾ��ָ�룬����ת��Ϊ�������͵�ָ��
	std::cout << p4 << std::endl;
	std::cout << p5 << std::endl;

	//ָ����bool����ʽת��
	//�ǿ�ָ��ת��Ϊtrue����ָ��ת��Ϊfalse

	//ָ��Ĳ���
	std::cout << *p << std::endl; //������
	std::cout << p << std::endl;
	std::cout << p+1 << std::endl; //���ӣ�ָ����һ��int�ĵ�ַ
	std::cout << p-1 << std::endl; //���٣�ָ����һ��int�ĵ�ַ
	std::cout << (p == p1) << std::endl; //ָ���е�
}

void fun_1(int* p)
{
	std::cout << p+1 << std::endl;
}

void fun_2()
{
	int x = 1;
	int* p = &x;
	std::cout << p << std::endl;
	std::cout << p+1 << std::endl;
	fun_1(p);
}

void fun_3(int par)
{
	par = par + 1;
}

void fun_4(int* par)
{
	*par = *par + 1;
}

void fun_5() //������ֵ�봫ַ
{
	int x = 1;
	int* p = &x;
	fun_3(x);
	std::cout << x << std::endl;
	fun_4(p);
	std::cout << x << std::endl;
}

void fun_6() //����
{
	int x = 3;
	int& ref = x; //����
	int* ptr = &ref; //ָ��

	std::cout << x << std::endl;
	std::cout << ref << std::endl;
	std::cout << *ptr << std::endl;
	ref = ref + 1;
	std::cout << x << std::endl;
	std::cout << ref << std::endl;
	std::cout << *ptr << std::endl;
}

void fun_7() //ָ�������
{
	int x = 8;
	int* ptr = &x;
	int*& ref = ptr;

	std::cout << x << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ptr << std::endl;
	std::cout << *ref << std::endl;
	std::cout << ref << std::endl;

	*ref = *ref + 1;

	std::cout << x << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ptr << std::endl;
	std::cout << *ref << std::endl;
	std::cout << ref << std::endl;

}

int main()
{
	//fun_0();
	//fun_2();
	//fun_5();
	//fun_6();
	fun_7();
}
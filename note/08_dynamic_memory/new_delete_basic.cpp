#include <iostream>
#include <new>

void fun0()
{
	//ջ�ڴ�
	int x = 1;
	std::cout << x << '\n';

	//���ڴ�
	//new������СΪint�Ķ��ڴ棬����2���浽ָ��y��
	//new�����ڴ��Ӧ�ĵ�ַ
	int* y = new int(2);
	std::cout << *y << '\n';
	delete y;
}

int* fun1()
{
	int res = 1;
	return &res;
	//����ǳ�Σ�գ�ָ������ʱ����
}

int* fun2()
{
	int* res = new int(2);
	return res;
}

void fun3()
{
	int* x = new int[5];
	//��������5��int��С���ڴ棬���׵�ַ���ظ�x
	delete[] x;
	//�����ű�ʾҪɾ������

	int* y = new int[5]{ 1,2,3,4,5 };
}

void fun4()
{
	//nothrow new
	int* y = new (std::nothrow) int[5]{};
	if(y==nullptr)
	{//... 
	}
	//�����ڴ�ʧ�ܲ��ᵼ�½����쳣�������Ƿ���nullptr

	//placement new
	char ch[sizeof(int)];
	int* z = new (ch) int(4);
	std::cout << *z << '\n';
	//ʹ��ch���ٵ��ڴ潫4�������

	//new auto
	//���ݱ��ʽ�����Զ��Ƶ�
	int* x = new auto(3);
}

struct alignas(256) Str{};
//��ַ���룬256��������

void fun5()
{
	//placement delete

	//delete nullptr
	int* x = 0;
	if (x==0)
	{
		x = new int(3);
	}
	delete x;

	//����deleteһ����new���ص��ڴ�
	//int x;
	//delete& x;

	//deleteɾ���ڴ浫��ɾ��ptr
	//ptrΪջ�еĶ���ָ����е��ڴ�
	int* ptr = new int(3);
	std::cout << "before delete:" << ptr << '\n';
	delete ptr;
	std::cout << "after delete:" << ptr << '\n';

	//����ɾ����new���ص��ڴ�
	int* pt = new int[5];
	int* pt2 = (pt + 1);
	delete[] pt2;
}

int main()
{
	//fun0();

	//int* x = fun1();
	//std::cout << *x << '\n';

	//int* y = fun2();
	//std::cout << *y << '\n';

	//int x[5];
	//std::cout << x[0] << '\n';
	//int* y = new int[5];
	//std::cout << y[0] << '\n';

	//fun4();

	//Str* s = new Str();
	//std::cout << s << '\n';

	//fun5();

	//int* ptr = new int(3);
	//std::cout << "before delete:" << ptr << '\n';
	//delete ptr;
	//ptr = nullptr;
	//std::cout << "after delete:" << ptr << '\n';
	//delete ptr;

	//int* pt = new int[5];
	//int* pt2 = (pt + 1);
	//delete[] pt2;

	//����ϵͳ�����new/delete��Ϊ
	//��Ҫ����ʹ��

}  

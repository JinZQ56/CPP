#include <iostream>
#include <new>
#include <memory> //��������ָ��

std::shared_ptr<int> fun0()
{
	std::shared_ptr<int> res(new int(3));

	//shared_ptr����ߵķ��� 
	std::cout << *res << std::endl;
	//get����res�б���ĵ�ַ
	//������ָ��������м���
	std::cout << *(res.get()) << std::endl;

	std::shared_ptr<int> x = res;
	std::cout << *(x.get()) << std::endl;

	//reset�����ж��Ƿ��Ƿ��Ѿ������������ڴ棬��������delete
	//���Բ������κβ������൱�ڴ���null_ptr
	res.reset(new int(4));
	std::cout << *(res.get()) << std::endl;
	std::cout << *(x.get()) << std::endl;

	return res;
}

void fun1(int* ptr)
{
	//shared_ptrָ�������߼�
	std::cout << "Call deleter fun\n";
	delete ptr;
}

void dummy(int*) {}

std::shared_ptr<int> fun2()
{
	static int res = 5;
	return std::shared_ptr<int>(&res, dummy);
}

void fun3()
{
	std::unique_ptr<int> x(new int(3));
	//unique_ptr�����Ը��ƣ��������ƶ�
	//ʹ�ý���ֵ
	std::cout << x.get() << std::endl;
	std::unique_ptr<int> y = std::move(x);
	std::cout << x.get() << std::endl;
	std::cout << y.get() << std::endl;
}

std::unique_ptr<int> fun4()
{
	std::unique_ptr<int> res(new int(5));
	return res;
}

struct str
{
	//std::shared_ptr<str> nei;
	std::weak_ptr<str> nei;
	
	//��������
	~str()
	{
		std::cout << "~str is called\n";
	}
};

void fun5()
{
	std::shared_ptr<str> x(new str);
	std::shared_ptr<str> y(new str);
	x->nei = y;
	y->nei = x;
}

void fun6()
{
	std::shared_ptr<str> x(new str);
	{
		std::shared_ptr<str> y(new str);
		x->nei = y;
	}
	auto ptr = x->nei.lock();
	if (ptr)
	{
		std::cout << "ture branch" << std::endl;
	}
	else
	{
		std::cout << "false branch" << std::endl;
	}
}

int main()
{
	std::shared_ptr<int> x(new int(3));
	//����shared_ptr����Ҫʹ��delete
	//������ڵ��ú��Զ�����
	//�����ü������ж��Ƿ�����������ָ���������ͬ���ڴ�
	//��ʼʱΪ1������û�������������乲���ڴ�

	std::shared_ptr<int> y = x;
	//x�е����ü���Ϊ2
	//yΪ�ֲ����󣬵��ý�����ᱻ����
	//����ʱ���ü���-1

	//std::make_shared
	std::shared_ptr<int> yy = std::make_shared<int>(3);
	auto yyy = std::make_shared<int>(4);
	//�Ƽ�ʹ��make_shared��������ָ��
	//�����ڴ�ֲ��� 
	//ʹ��new_intʱ��ָ��ĵ�ַ�����ü�����ַ���������Զ������������
	//make_shared����ʹ���������ڴ�ͱ������ü������ڴ澡���Ľ�

	//std::shared_ptr<int> z = fun0();
	//std::cout << *(z.get()) << std::endl;

	//Ϊshared_ptrָ��ɾ����
	std::shared_ptr<int> z(new int(3), fun1);

	std::shared_ptr<int> a = fun2();

	//����ָ��֧������
	//C++17 -> shared_ptr<T[]>
	//C++20 -> make_shared��������
	std::shared_ptr<int[]> b(new int[5]{ 1,2,3,4,5 });
	//auto c = std::make_shared<int[5]>();
	//auto d = std::make_shared<int[]>(5);

	fun3();
	std::unique_ptr<int> e = fun4();
	std::cout << *(e.get()) << std::endl;

	std::unique_ptr<int, decltype(&fun1)> f(new int(6), fun1);
	std::cout << f << std::endl;

	//std::shared_ptr<str> g(new str);
	fun5();
	fun6();
}
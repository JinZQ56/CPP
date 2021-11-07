#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>

// �����㷨����ͨ���ɵ��ö����Զ�������߼�
// ����������ָ�룬�࣬ bind, lambda
bool MyPredict(int val)
{
	return val > 3;
}

bool MyPredict2(int val1, int val2)
{
	return val1 > val2;
}

bool MyAnd(bool val1, bool val2)
{
	return val1 && val2;
}

void fun0()
{
	std::vector<int> x{ 1,2,3,4,5,6,7,8,9 };
	std::vector<int> y;
	std::copy_if(x.begin(), x.end(), 
		         std::back_inserter<std::vector<int>>(y), 
		         MyPredict);
	for (auto i : y)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;
}

void bind_1st_2nd()
{
	// removed from c++17
	std::vector<int> x{ 1,2,3,4,5,6,7,8,9 };
	std::vector<int> y;
	std::vector<int> z;
	// bind_1st �󶨵�һ������
	std::copy_if(x.begin(), x.end(),
		         std::back_inserter<std::vector<int>>(y),
		         std::bind1st(std::less<int>(), 3));
	for (auto i : y)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	// bind_2nd �󶨵ڶ�������
	std::copy_if(x.begin(), x.end(),
		         std::back_inserter<std::vector<int>>(z), 
		         std::bind2nd(std::greater<int>(), 3));
	for (auto i : z)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;
}

void bind()
{
	using namespace std::placeholders;
	std::vector<int> x{ 1,2,3,4,5,6,7,8,9 };
	std::vector<int> y;
	std::vector<int> z;
	// bind
	std::copy_if(x.begin(), x.end(),
		std::back_inserter<std::vector<int>>(y),
		std::bind(MyPredict2, 3, _1));
	for (auto i : y)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	auto f1 = std::bind(MyPredict2, _1, 1);
	std::cout << f1(50) << std::endl;
	auto f2 = std::bind(MyPredict2, _2, 3);
	std::cout << f2("hello", 50) << std::endl;
	auto f3 = std::bind(MyPredict2, _2, _1);
	std::cout << f2(10, 50) << std::endl;
	auto f4 = std::bind(MyPredict2, 3, _1);
	std::cout << f4(2) << std::endl;
	auto f5 = std::bind(MyAnd, f1, f4);
	std::cout << f5(2) << std::endl;
}

void MyFun(int* val1, int* val2)
{
	
}

void MyFun2(std::shared_ptr<int> ptr1, std::shared_ptr<int> ptr2)
{

}

auto fun1()
{
	using namespace std::placeholders;

	// �з��գ�bind�Ḵ�ƴ���Ĳ���
	int x;
	int y;
	auto f = std::bind(MyFun, &x, &y);

	// ��ȫ
	std::shared_ptr<int> p1(new int());
	std::shared_ptr<int> p2(new int());
	auto f1 = std::bind(MyFun2, p1, p2);

	return f1;
}

// since c++20 bind_front
// ��Ϊ����bind_1st,�󶨵�һ��Ԫ��

void Proc(int& x)
{
	++x;
}

int main()
{
	// fun0();
	// bind_1st_2nd();
	// bind();
	// fun1();
	int x = 0;
	Proc(x);
	std::cout << x << std::endl;
	auto f = std::bind(Proc, x);
	f();
	// ��Ϊx��ͨ�������ķ�ʽ����f�ڣ����Դ�ʱ���ᱻ�޸�
	std::cout << x << std::endl;
	// ͨ��ʹ��std::ref �� std::cref���⸴����Ϊ
	auto f1 = std::bind(Proc, std::ref(x));
	f1();
	std::cout << x << std::endl;
}
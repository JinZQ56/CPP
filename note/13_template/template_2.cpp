#include <iostream>
#include <vector>
#include <string>
#include <utility>

// ����ת��
void f(int&)
{
	std::cout << "l.value" << std::endl;
}

void f(int&&)
{
	std::cout << "r.value" << std::endl;
}

template <typename T>
void fun(T&& input) // T&&��������
{
	std::cout << "Hello world" << std::endl;
	f(std::forward<T>(input)); // ����T������ ��inputת��Ϊ��ֵ����ֵ
}

// ��������
class cla
{
public:
	using internal = int;

	template <typename T>
	static void fun()
	{

	}
};

template <typename T>
void fun2()
{
	typename T::internal* p = nullptr;
	// �������Ϊpָ��
	// Ҳ�������Ϊ���������
	// �˴�ʹ��template��ʾһ���������������Ͷ����Ǿ�̬���ݳ�Ա

	T::template fun<int>();
	// �������Ϊ���еĺ���
	// Ҳ�������Ϊ�Ƚϴ�С
	// �˴�ʹ��template��ʾһ������������ģ��

	T obj;
	obj.template fun<int>();
}

// ����ģ��
template <typename T>
T pi = (T)3.1415926;

template <typename T>
unsigned Mysize = sizeof(T);

int main()
{
	// A ����ת��
	// std::forward<>()
	// ͨ����������������
	// ͬʱ�������������ֵ����ֵ������

	int x = 3;
	f(x); // ��ֵ
	f(3); // ��ֵ

	fun(x);
	fun(3);

	// B lambda���ʽģ��
	// since C++ 20

	// C ��������
	// ʹ��typename��template
	// ʹ��typename��ʾһ���������������Ͷ��Ǿ�̬���ݳ�Ա
	// ʹ��template��ʾһ������������ģ��
	// template���Ա����ģ�����

	fun2<cla>();
	
	// D ����ģ��
	// since C++ 14
	// template <typename T> T pi=(T)3.1415926;
	// ������ʽ
	std::cout << pi<int> << std::endl;
	std::cout << pi<float> << std::endl;
	std::cout << pi<double> << std::endl;
}
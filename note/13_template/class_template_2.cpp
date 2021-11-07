#include <iostream>
#include <vector>
#include <string>

// ��ģ�嶨��
template<typename T1, typename T2>
class cla
{
public:
	void fun() { std::cout << "normal" << std::endl; }
};

// ʵ������ģ��
template class cla<int, int>;
// ʵ������ģ��ĳ�Ա����
template void cla<double, double>::fun();

// ��ȫ�ػ���ģ��
template <>
class cla<std::string, std::string>
{	
public:
	// ������ȫ��ͬ ���� void fun2() {}
	void fun() { std::cout << "full specialization" << std::endl; }
};

// �����ػ���ģ��
template <typename T2>
class cla<float, T2>
{
public:
	void fun() { std::cout << "part specialization" << std::endl; }
};


int main()
{
	// A ��ģ���ʵ����
	// ʵ����������
	// ʵ����ĳ����Ա����
	
	// B ��ģ�����ȫ�ػ�/�����ػ���ƫ�ػ���
	// �ػ��汾�ͻ����汾��������ȫ��ͬ��ʵ��
	cla<int, int> c1;
	c1.fun();

	cla<std::string, std::string> c2; // ��ȫ�ػ�
	c2.fun();

	cla<float, int> c3; // �����ػ�
	c3.fun();
	
	// C ��ģ���ʵ���Ƶ���since C++ 17��
	// ���ڹ��캯����ʵ���Ƶ�
	// �û��Զ�����Ƶ�ָ�� cpp-reference
	
}
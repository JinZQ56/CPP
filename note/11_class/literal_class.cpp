#include <iostream>
#include <vector>
#include <string>

class cla
{
public:
	// �����ڹ��캯��
	// constexpr �ȿ��Ա����ڳ��� Ҳ���������ڱ���
	// consteval (since c++ 20) ���ܱ����ڳ���
	constexpr cla(int val)
		: x(val)
	{}

	// ƽ������������
	~cla() = default;
	// ~cla() {}; ���ֶ��岻ƽ��

	// �����ڳ�Ա����
	// constexpr/consteval
	// c++ 11 ֮ǰ constΪȱʡֵ
	// c++ 14 �Ժ� constexprȱʡΪ��const
	constexpr int fun() const // const���γ�Ա��������ʱ���е�ֵ�����ں����б��޸�
	{
		return x + 1;
	}

	// since c++ 14 ���Զ���constexpr��Ա�����Һ��������޸�����ֵ��
	// ��ʱ���ܼ�const�ؼ���
	constexpr void inc()
	{
		x = x + 1;
	}
private:
	int x = 3;

};

constexpr cla c(3);

int result()
{
	cla c(0);
	c.inc();
	c.inc();
	c.inc();
	return c.fun();
}

int main()
{
	// A ����ֵ��
	// ���Թ�������ڳ���������
	// �����ݳ�Ա��Ҫ������ֵ����
	// ʹ��ƽ������������
	// ���캯�� constexpr/consteval
	// ��Ա���� constexpr/consteval
	// ��c++14�� constexpr/consteval��Ա������const��Ա����


	// �����ڳ��� �ڽ���������
	constexpr int a = 3;

	std::cout << c.fun() << std::endl;

	cla c1(5);
	std::cout << c1.fun() << std::endl;

	// ����const�ؼ���
	std::cout << result() << std::endl;
}
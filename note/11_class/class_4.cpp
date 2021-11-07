#include <iostream>
#include <vector>
#include <string>

class cla
{
public:
	// ���캯��
	cla()
		: p(new int())
	{}

	// ��������
	~cla()
	{
		delete p;
	}

	// ��������
	cla(const cla& c)
		: p(new int())
	{
		*p = *(c.p);
	}

	// ������ֵ
	cla& operator= (const cla& c)
	{
		// p = new int();
		// ����û��new����Ϊcla�ڹ���ʱ���Ѿ��й�new��
		*p = *(c.p);
		return *this;
	}

	// �ƶ�����
	cla(cla&& c) noexcept
		: p(c.p)
	{
		c.p = nullptr;
	}

	// �ƶ���ֵ
	cla& operator= (cla&& c)
	{
		p = c.p;
		c.p = nullptr;
		return *this;
	}

	int& data()
	{
		return *p;
	}

private:
	int* p;
};



int main()
{
	// A ��û��������������������c��ɾ����ָ��p��ɾ��������ָ��pָ����ڴ�û�б�ɾ��
	cla c1;
	c1.data() = 3;
	std::cout << c1.data() << std::endl;
	
	// B ��û���������忽�����캯��ʱ��c1��c2�е�ָ�붼ָ��ͬһ���ڴ棬����ʱ���������Σ���ʱ�ᱨ��
	// ͨ������������ʱ������������忽��������ƶ�����
	// �п������캯��ʱ������������忽����ֵ����

	// ��������
	cla c2(c1);
	// ������ֵ
	cla c3;
	c3 = c2;

	// �ƶ�����
	cla c4(std::move(c3));
	// �ƶ���ֵ
	cla c5;
	c5 = std::move(c4);

	// C ���еĹؼ���
	// default �ؼ��� ֻ�����⺯����Ч
	// delete �ؼ��� �����к�������Ч ��ʾ�����޷�������
	// 
}
#include <iostream>
#include <vector>
#include <string>

class cla
{
public:
	// ȱʡ���캯��
	// cla() = deault;
	cla()
	{
		std::cout << "constructor is called" << std::endl;
 	}
	// �������캯��
	cla(const cla&) = default;
	// �ƶ����캯��
	cla(cla&&) noexcept = default;

	// ���캯��
	cla(int val, const std::string& str)
		: x(val)
		, s(str)
	{}

	// ������ֵ����
	cla& operator= (const cla& c)
	{
		// �ж�����ֵ
		if (&c == this)
		{
			std::cout << "dummy assigment" << std::endl;
			return *this;
		}
		std::cout << "copy assigment is called" << std::endl;
		x = c.x;
		s = c.s;
		return *this;
	}

	// �ƶ���ֵ����
	cla& operator= (cla&& c)
	{
		// �ж�����ֵ����֪����ô�����ƶ���ֵ��
		if (&c == this)
		{
			std::cout << "dummy assigment" << std::endl;
			return *this;
		}

		// �������ָ��ʱ
		// delete ptr�� //ɾ��ԭ�е�ptr
		// ptr = x.ptr;
		// x.ptr = nullptr
		// ���Ϸ���������������ֵ�����

		std::cout << "move assigment is called" << std::endl;
		x = std::move(c.x);
		s = std::move(c.s);
		return *this;
	}
	
	// ��������
	// ~cla() noexcept = default;
	~cla()
	{
		std::cout << "destructor is called" << std::endl;
	}

	// ��Ա����
	void print()
	{
		std::cout << "x=" << x << " " << "s=" << s << std::endl;
	}

private:
	int x = 0;
	std::string s = "abc";
	// int* ptr;

};

class ccla
{
public:
	// ��û�ж����������캯��ʱ�����������Զ��ϳɿ�����ֵ���ƶ���ֵ����
	int x = 0;
	std::string s = "abc";

	void print()
	{
		std::cout << "x=" << x << " " << "s=" << s << std::endl;
	}
};

int main()
{
	// A ������ֵ���ƶ���ֵ����
	// operator= 
	// ʵ��Ϊ���������
	// ��ֵ��������ʹ�ó�ʼ���б�
	// ͨ�����ص�ǰ���͵����� Ϊ�������� c3 = c2 = c1
	std::cout << "--------------------" << std::endl;
	cla c1(1,"asd");
	cla c2;
	c2 = c1;
	c1.print();
	c2.print();

	cla c3;
	c3 = std::move(c2);
	c2.print();
	c3.print();

	c3 = c3;
	c3.print();

	// ϵͳ�Զ��ϳɿ�����ֵ���ƶ���ֵ
	ccla cc1;
	cc1.x = 1;
	cc1.s = "asd";
	ccla cc2;
	cc2 = cc1;
	cc1.print();
	cc2.print();

	// B ��������
	// destructor
	// ~��ǰ���ͣ��޲������޷���ֵ
	// �����ͷ���Դ
	// �ڴ�������ڵ�������������ʱ�Ž���
	// �ڴ���պ������������������� 
	// ������ʽ�������������һ����Զ��ϳɣ����ڲ��߼�ʱƽ����
	// �������������׳��쳣
	// ���������Զ�����ڴ�ķ��������٣������ֶ�����
	std::cout << "--------------------" << std::endl;
	cla* ccc = new cla(); // �ȷ����ڴ��ٵ��ù��캯��
	// ��ʾ���ڴ洴�����������ʾ���ڴ����
	delete ccc; // �ȵ������������ٽ����ڴ����
	// new ��� delete
	// malloc ��� free �������ڴ� û�����ͺʹ�С

}
#include <iostream>
#include <type_traits>


void fun_0() //�����ͳ���ָ��
{
	const int x = 4; //����ֻ�ܶ�������д����ʼ�������ܱ���ֵ��
	std::cout << x << std::endl;

	int y = 5;
	int z = 6;
	const int* ptr1 = &z; //ָ��ָ���� //ָ������ָ��Ҳ����ָ�����
	z = z + 1;
	std::cout << z << std::endl;

	//int* ptr3 = &x;  //���� ָ�������ָ�벻��ָ����

    // *ptr1 = 6; //ʱ����
	int* const ptr2 = &y; //ָ���ǳ���
	// ptr2 = &z; //ʱ����
	*ptr2 = z;
	std::cout << y << std::endl;

}

void fun_1() //�����ͳ�������
{
	int x = 3;
	const int& ref1 = x; //����ָ����԰󶨱���
	//ref1 = ref1 + 1; //��������д

	int& ref2 = x;
	ref2 = ref2 + 1;
	
	const int y = 4;
	//int& ref3 = y; //�������ò����԰󶨳���

	//int& ref4 = 3; //�Ƿ��� ���ܰ�����ֵ
	const int& ref4 = 3; //�Ϸ������԰�����ֵ
}

void fun_2(int x)
{
	x = x + 1;
}
void fun_3(int* x)
{
	*x = *x + 1;
}
void fun_4(int& x)
{
	x = x + 1;
}

//�����ڴ��ݴ���������ͣ�����intû�б�Ҫ 
void fun_5(const int& x) //������x��ֵ�޷������޸�
{
	//x = x + 1;
}

void fun_6()
{
	int x;
	std::cin >> x;

	const int y1 = x;
	constexpr int y2 = 3; //����ȷ�ı�ʾy2�Ǳ����ڳ���
	//y2��������ȻΪconst int

	//�������ʽָ��
	constexpr const char* ptr = "123";//constexpr����ptr��ptr������Ϊconst char* const
	std::cout << std::is_same_v<decltype(ptr), const char* const> << std::endl;
}

int main()
{
	//fun_0();

	int x = 1;
	fun_2(x);
	std::cout << x << std::endl;
	fun_3(&x);
	std::cout << x << std::endl;
	fun_4(x);
	std::cout << x << std::endl;

	fun_6();
	
}
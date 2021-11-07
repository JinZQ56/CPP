#include<iostream>
#include<compare>

void fun0()  //����������
{
	int x = 3;
	int y = 5; 
	
	//���ȼ�
	//һԪ + -
	std::cout << +x << '\n';
	std::cout << -y << '\n';

	//* / % �˳�����
	std::cout << y % x << '\n';

	//��Ԫ + -
	std::cout << x + y << '\n';

	//��Ϊ����
	//���Ϊ�������͵���ֵ
	
	//+ - �� һԪ+���Խ���ָ��
	int a[3] = { 1,2,3 };
	int* ptr = a;
	ptr = ptr + 1;
	std::cout << *ptr << '\n';


	//��������
	// (m/n)*n + m%n == m
	std::cout << (5 / 2) * 2 + 5 % 2 << '\n';
}

void fun1() //�߼����ϵ������
{
	int* ptr = nullptr;
	if(ptr && (*ptr==3))  //�߼�����߼���Ķ�·����
	{ }

    /* �߼������ȼ������߼���
	a && b || c
	a || b && c
	*/

	int a = 3;
	int b = 4;
	int c = 5;
	std::cout << (c > b > a) << '\n';
	std::cout << (c > b) && (b > a) << '\n';

	//three way comprasion operator <=>
	//���� ���� С�� ���� 1 0 -1
	//auto res = (a <=> b);  //��c++20���룬֧�� <=> ����
	//std::cout << res << '\n';
}

void fun2() //λ������
{
	//��λȡ�� ~
	signed char x = 3; //00000011
	std::cout << x << '\n';
	std::cout << ~x << '\n'; //11111100

	//��& ��| ���^
	signed char y = 5; //00000101
	std::cout << (x & y) << '\n'; //00000001
	std::cout << (x | y) << '\n'; //00000111
	std::cout << (x ^ y) << '\n'; //00000110

	//��������
	auto z = x & y;
	std::cout << z << '\n';
	std::cout << std::is_same_v<decltype(z), int> << '\n';


	//û�ж�·�߼�

	//��λ����
	std::cout << (x << 1) << '\n'; //00000110
	std::cout << (x >> 1) << '\n'; //00000001

	unsigned char x1 = 0xff; //11111111
	//00000...11111111
	//11111...00000000
	auto y1 = ~x1;  //���ȶ�x1������������
	std::cout << y1 << std::endl; 

	signed char x2 = 0xff;
	//��1����Ϊ�з���λ������ǰ����ֵӦ���
	//1111...11111111
	//0000...00000000
	auto y2 = ~x2;
	std::cout << y2 << '\n';

	//charʱ�����Ϊ��������ͬ���ܲ�ͬ
	char x3 = 0xff;
	auto y3 = ~x3;
	std::cout << y3 << '\n';

	//���ƿ��Ա��ַ��ţ����Ʋ�һ��
	int x4 = 0x80000000;
	std::cout << x4 << '\n';
	std::cout << (x4 >> 1) << '\n';
	std::cout << (x4 << 1) << '\n';

	int x5 = -1;
	std::cout << x5 << '\n';
	std::cout << (x5 >> 1) << '\n';
	std::cout << (x5 << 1) << '\n';
}

void fun3() //��ֵ������
{
	//��ֵ������Ϊ�ҽ��
	int x;
	int y;

	x = y = 3;
	
	//{}��ֹ����ת��
	short z;
	z = 0x80000003;
	std::cout << z << '\n';

	z = { 3 };
	
	constexpr int z1 = 4;
	z = { z1 };

	//���ϸ�ֵ�����
	int x1 = 2;
	x1 = x1 + 2;

	x1 += 2; // x=x+2
	x1 *= 2; // x=x*2
    
	x = 2;
	y = 3;
	x ^= y ^= x ^= y;
	std::cout << x << '\n';
	std::cout << y << '\n';
}

void fun4() //�����Լ������
{
	int x = 3;
	x = x + 1;
	x += 1;
	x++; //����prvalue��������Ϊ��ʱ����
	++x; //������ֵ�����ظ���֮���ֵ
	std::cout << x << '\n';

	int y = 1;
	int z;
	z = y++;
	std::cout << y << '\n';
	std::cout << z << '\n';
	z = ++y;
	std::cout << y << '\n';
	std::cout << z << '\n';
}

struct Str
{
	int x;
};

namespace ABC
{
	int x��
}

void fun5() //����������
{
	//��Ա���ʲ����� . and ->
	Str a;
	a.x;

	Str* ptr = &a;
	(*ptr).x;
	ptr->x; //���ָ��д��

	int y = 3;

	decltype(a.x) y1;
	std::cout << std::is_same_v<decltype(y1), int> << '\n';
	decltype((a.x)) y2 = y;
	std::cout << std::is_same_v<decltype(y2), int&> << '\n';
	decltype((Str().x)) y3 = 3;
	std::cout << std::is_same_v<decltype(y3), int&&> << '\n';
	decltype((ptr->x)) y4 = y; //��ͷ������������ֵ
	std::cout << std::is_same_v<decltype(y4), int&> << '\n';

	//������������ Ψһ����Ԫ������ �ɣ��ͣ����
	std::cout << (true ? 5 : 3) << '\n';
	std::cout << (false ? 3 : 5) << '\n';

	int x1 = 1;
	int x2 = 3;
	std::cout << (true ? ++x1 : ++x2) << '\n';
	std::cout << x1 << '\n';
	std::cout << x2 << '\n';

	//���������ʽ������ֵʱ�򷵻���ֵ�����򷵻���ֵ
	(false ? x1 : x2) = 12;
	std::cout << x2 << '\n';

	//�ҽ��
	int score = -100;
	int res = (score > 0) ? 1 : (score == 0) ? 0 : -1;
	std::cout << res << '\n';

	//���Ų�����,����������ֵ
	std::cout << (2, 3) << '\n';

	//sizeof������
	//sizeof(type) sizeof expression
	int x = 56;
	std::cout << sizeof(int) << sizeof(x) << sizeof x << '\n';

	//sizeof����ʵ����ֵ����ʮ������Ӧ�ĳߴ�
	int* ptr = nullptr;
	std::cout << sizeof(*ptr) << '\n';

	//�����������::
	ABC::x��

}

int main()
{
	//fun0();

	//fun1();

	//fun2();

	//fun3();

	//fun4();

	fun5();
}
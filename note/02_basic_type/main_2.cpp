#include <iostream>

// �������ڽ�������
// ��ֵ���ͣ��ַ����ͣ��������ͣ���������
// void

void fun_0()
{
	char c; //8λ��1���ֽڣ�256�֣�ASCII��
	wchar_t wc; //���ַ����ͣ���׼ȷ����
	//char8_t c8 = 'a';
	char16_t c16; //��������C++11
	char32_t c32; //��չλ4���ֽڣ�����Unicode����

	std::cout << sizeof(c) << std::endl;
	std::cout << sizeof(wc) << std::endl;
	//std::cout << sizeof(char8_t) << std::endl;
	std::cout << sizeof(c16) << std::endl;
	std::cout << sizeof(c32) << std::endl;

	//char�Ƿ��з���
	char ch1='a';
	signed char ch2='s'; //�з��ŵ�char
	unsigned char ch3='s'; //�޷��ŵ�char
}

void fun_1() //��������
{
	//��ͬ�������͵ĳߴ粻ͬ��C++��׼�ֽ��涨��ÿ�����͵���С�ߴ磬�ڲ�ͬ�Ļ����ֲ�ͬ
	//������
	short s; //ռ2���ֽ�
	int i; //ռ4���ֽ�
	long l=10;
	long long ll=10;

	std::cout << sizeof(s) << std::endl;
	std::cout << sizeof(i) << std::endl;
	std::cout << sizeof(long) << std::endl;
	std::cout << sizeof(long long) << std::endl;

	//�޷���
	unsigned short us=10;
	unsigned int ui=10; // unsigned �ȼ��� unsigned int
	unsigned long ul=10;
	unsigned long long ull=10;

	//�̶���ȵ���������
	//���Ӵ������ֲ��
	int32_t i32 = 888;
	std::cout << sizeof(int32_t) << std::endl;
}

void fun_2() //��������
{
	float f = 3.14; //������
	double d = 3.0; //˫����
	long double ld = 3.14; //��ȸ���

	std::cout << f << std::endl;
	std::cout << sizeof(f) << std::endl;
	std::cout << std::numeric_limits<float>::max() << std::endl;
	std::cout << std::numeric_limits<float>::min() << std::endl;
	std::cout << sizeof(d) << std::endl;
	std::cout << std::numeric_limits<double>::max() << std::endl;
	std::cout << std::numeric_limits<double>::min() << std::endl;
	std::cout << sizeof(ld) << std::endl;

}

void fun_3() //����ֵ����
{
	//1.3һ��Ϊdouble�ͣ�����ͨ����Ӻ�׺ת��Ϊfloat��1.3f��
	float f = 1.3f;
	unsigned long long ull = 2ULL; 	 
}

int operator "" _ddd(long double x) //�Զ�����������
{
	return (int)x * 2;
}

extern int g_x; //�������������ñ�����Դ���ⲿ
//���ڴ˸�ֵʱ��������ת��Ϊ���壬���ܳ����ظ����������

int sq_x;

void fun_4()
{
	std::cout << "ȫ��������ʼ��ʡȱ" << sq_x << std::endl;
	int sq_y=1;
	std::cout << "�����ڲ���ʼ��ʡȱ" << sq_y << std::endl;
	std::cout << "�����ڲ���ʼ��ʡȱʱ����" << std::endl;

	//ֱ�ӳ�ʼ��
	int zj_x(10); 
	int zj_y{10}; //Ҳ����ʹ�ô�����
	//������ʼ��
	int kb_x = 10;

	std::cout << zj_x << zj_y << kb_x << std::endl;

}

int main()
{
	std::cout << "�ַ�����" << std::endl;
	fun_0();
	std::cout << "��������" << std::endl;
	fun_1();
	/*
	int x = 10;
	int y;
	std::cout << sizeof(x) << std::endl;
	std::cout << sizeof(y) << std::endl;
	*/
	std::cout << "��������" << std::endl;
	fun_2();

	std::cout << sizeof(nullptr_t) << std::endl;

	int x = 3.14_ddd;
	std::cout << x << std::endl;

	//int g_x = 2;
	std::cout << "�����������ڶ���" << g_x << std::endl;

	//�����ĳ�ʼ��
	//�����ڲ���ʼ��ȱʡʱ������ֵ����ģ�δ֪��
	//int f_x=1;
	//std::cout << "�����ڲ�����������ʼ��ʡȱ" << f_x << std::endl;
	//ȫ�ֱ�����ʼ��ȱʡʱ����������ֵΪ0
	std::cout << "������ʼ��" << std::endl;
	fun_4();
}
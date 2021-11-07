#include <iostream>
#include <vector>


void fun0(int p1,int p2)  //��������ֵ˳��Ĳ�ȷ����
{
	std::cout << p1 << ' ' << p2 << '\n';
}

void fun1()
{
	std::cout << int{} << '\n'; //��ʱ����0��
}

void fun2(std::vector<int>&& vec)
{

}

struct Str
{
	int x;
};

void fun3()
{
	const int x = 3;
	//x��glvalue����û�м�������������x��lvalue
	//x��inmutable lvalue���޷����ڵȺ����

	int y = int{}; //int{}�ǹ�����ʱ������prvalue���޷���λ���ڴ�λ��
	Str{} = Str{}; //��ֵ���Է��ڵȺ����
}

void fun4(const int& par) //��ֵ����ֵת��
{
	int x = 3;
	int y = 3;
	int z;
	z = x + y; //lvalue to rvalue conversion
	
	//Temporaray Materialization ��ʱ���廯
	//prvalue to xvalue
	Str().x;  //��Str��Ӧ���ڴ���ȡ��x��Ӧ�Ĳ��֣�Str()��prvalueת��Ϊxvalue
}

void fun5() //decltype
{
	//prvalue -> type
	decltype(3) x;
	std::cout << std::is_same_v<decltype(x),int> << '\n';

	//lvalue -> type& ����
	decltype((x)) y = x;
	std::cout << std::is_same_v<decltype(y), int&> << '\n';

	//xvalue -> type&& ��ֵ����
	decltype(std::move(x)) z = 3;
	std::cout << std::is_same_v<decltype(z), int&&> << '\n';
}

void fun6()  //����ת��
{
	//��ʽ����ת��
	int x = 1 + 1.5;
	std::cout << x << '\n';

	//��ʽ����ת��
	//static_cast ���ܺõ�����ȫ
    //dynamic_cast ��ȫ�����ܽϲ�
	int y;
	y = static_cast<double>(3) + 0.5;
	std::cout << y << '\n';

	//�������Ĳ�������������������Ҳ������
	std::cout << (3 / 4) << '\n';
	std::cout << (3 / 4.0) << '\n';
	int z1 = 3;
	int z2 = 4;
	std::cout << (z1 / z2) << '\n';
	std::cout << (z1 / static_cast<double>(z2)) << '\n'; 

	//const_cast ȥ�������ӳ�����
	//ʹ�ý�ΪΣ�� 
	const int* ptr;
	const_cast<int*>(ptr); //ȥ������ָ��ĳ�����

	int x1 = 3;
	const int& ref = x1;
	int& ref2 = const_cast<int&>(ref);
	ref2 = 4;
	std::cout << x1 << '\n';

	//reinterpret_cast
	int x2 = 3;
	int* ptr2 = &x;
	double* ptr3 = reinterpret_cast<double*>(ptr2);
	float* ptr4 = reinterpret_cast<float*>(ptr2);
	//double y2 = reinterpret_cast<double>(x2);
	std::cout << *ptr3 << '\n';
	std::cout << *ptr4 << '\n';

	//C��ʽ������ת��
	//C++�в�����ʹ��
	double x3 = (double)3;
	std::cout << x3 << '\n';
}

int main()
{
	//int x = 0;
	//fun0(x = x + 1, x = x + 1);

	//fun1();

	//std::vector<int> x; //glvalue ��ֵ
	//fun2(std::move(x)); //ת��Ϊxvalue������x�е����ݲ��������ģ�������fun���ظ����� 

	//fun4(3); //3Ϊprvalue����Ҫת��Ϊxvalue���ܰ󶨵�par(parΪ���ã�������Ҫ�󶨵�������ֵ��

	//fun5();

	fun6();
}
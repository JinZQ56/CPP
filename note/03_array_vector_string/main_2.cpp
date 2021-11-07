#include <iostream>
#include <vector>
#include <string>

//C++��׼����������ݽṹ
//vector �� string
//���Ӳ���������

void fun0()  
{
	std::vector<int> x;
	std::vector<float> y;
	std::vector<int> x1;
	x1 = x; //vector֧�ָ��ƣ�֧�������ڶ�̬�ı�Ԫ�ظ���
}

void fun1()
{
	//ȱʡ��ʼ��������0��Ԫ��
	std::vector<int> x;
	std::cout << x.empty() << std::endl;

	//�ۺϳ�ʼ����ʹ��{}
	std::vector<int> x1 = { 1,2,3 };
	std::vector<int> x2(3); //����3��Ԫ���ҳ�ʼ��Ϊ0
	std::cout << x2.size() << std::endl;
	std::vector<int> x3(3, 1); //��������Ԫ�أ�ÿ��Ԫ��Ϊ1
	std::cout << x3.size() << std::endl;
	std::vector<int> x4{ 3,1 }; //��������Ԫ�أ�3��1
	std::cout << x4.size() << std::endl;

	//���롢ɾ��Ԫ��
	x.push_back(2);  //�ڽ�β��back���˲���
	std::cout << x.size() << std::endl;
	x.pop_back();  //�ڽ�β������pop��Ԫ��
	std::cout << x.size() << std::endl;

	//�Ƚϣ������ֵ�˳��ıȽ�
	std::cout << (x1 == x2) << std::endl;
	std::cout << (x1 > x2) << std::endl;

	//Ԫ�ص����������
	std::cout << x1[2] <<' '<< x1.at(2) << std::endl;

	auto b = std::begin(x1);
	auto b1 = x1.begin();
	auto c = std::end(x1);
	auto c1 = x1.end();  //�����ǻ�ȡָ�룬���ص�������iterator��������ģ��ָ�����Ϊ����һ���������������
	//std::cout << *b1 << ' ' << *c << std::endl;
	while (b != c)
	{
		std::cout << *b << std::endl;
		b = b + 1;
	}

	for (auto val : x1)
	{
		std::cout << val << std::endl;
	}

	auto q = x4.begin();
	auto p = x4.end();
	std::cout << *q << ' ' << *(p - 1) << std::endl;
	/*
	//���Ԫ�ص��µ�����ʧЧ
	x4.push_back(2);
	std::cout << *q << ' ' << *(p - 1) << std::endl;
	*/

	//��άvector
	std::vector<std::vector<int>> z;
	z.push_back(std::vector<int>());
	z[0].push_back(56);
	std::cout << z[0][0] << std::endl;

	std::vector<std::vector<int>> z1 = { {1,2,3},{3,4,5} };
	std::cout << z1[1][2] << std::endl;
	std::cout << z1[1].size() << std::endl;


	std::vector<std::vector<int>> z2 = { {1,2,3},{4,5} };  //���Խ���ÿһ��ά�Ȱ���Ԫ�ز�һ�µ�vector
	std::cout << z2[1][1] << std::endl;
	std::cout << z2[1].size() << std::endl;

	// . �� -> 
	std::vector<std::vector<int>>* ptr = &z1;
	std::cout << (*ptr).size() << std::endl;
	std::cout << ptr->size() << std::endl; //C+������﷨�ǣ����ڲ���ָ�����ָ��


}

void fun2()  //string
{
	std::string x = "Hello world"; 
	std::string y = x; //֧�ָ���
	std::string z(x);
	y = y + "!!!";
	z = z + '!';
	std::cout << y << ' ' << z << '\n';

	//����ͳ�ʼ��
	std::string x1(3, 'a');
	std::cout << x1 << '\n';

	//�Ƚ�
	std::cout << (y == x) << '\n';
	std::cout << (y > x) << '\n';

	//��ֵ
	x1 = "ccc";
	std::cout << x1 << '\n';

	//ƴ��
	x1 = y + z;
	std::cout << x1 << '\n';

	//����
	std::cout << x[10] << '\n';
	std::cout << x.at(10) << '\n';
	std::cout << x[11] << '\n';
	//std::cout << x[12] << '\n';

	//ת��ΪC�ַ���
	auto ptr = x.c_str(); //ת��Ϊָ��\0��β����ԭstring��ͬ��ָ��
	std::cout << ptr << std::endl;
	std::cout << *ptr << std::endl;
}

int main()
{
	//fun0();
	//fun1();
	fun2();
}
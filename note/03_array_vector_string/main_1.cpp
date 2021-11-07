#include <iostream>
#include <cstring>
#include <type_traits>

void fun0()  //C�ַ���
{
	char str[] = "Hello";  //char[6] null-terminated string
	auto ptr = str; //char* ����ʽ��ת��Ϊָ��
	std::cout << strlen(str) << std::endl;
	std::cout << strlen(ptr) << std::endl;

	char str1[] = { 'H','e','l','l','o' }; //char[5]
	auto ptr1 = str1;
	std::cout << strlen(str1) << std::endl; //strlen���������ֱ���ҵ�\0
	std::cout << strlen(ptr1) << std::endl;

	char str2[] = { 'H','e','l','l','o','\0' }; //char[6]
	auto ptr2 = str2;
	std::cout << strlen(str2) << std::endl; //strlen���������ֱ���ҵ�\0
	std::cout << strlen(ptr2) << std::endl;

	//strcmp �ַ����Ƚ�
	std::cout << strcmp(str1, str) << std::endl;
	std::cout << strcmp(str, str2) << std::endl;
}

void fun1() //��ά����
{
	//��ά����ȱʡ��ʼ��
	int x1[3];
	std::cout << x1[0] << std::endl;
	std::cout << sizeof(int) << std::endl;
	std::cout << sizeof(x1[0]) << std::endl;
	int x2[3][4];  //x2��������Ԫ�أ�ÿ��Ԫ����int[4]
	std::cout << sizeof(x2[0]) << std::endl;
	std::cout << std::is_same_v<decltype(x2[0]),int[4]> << std::endl;  //x2[0]�Ǳ��ʽ����l-value��decltype�᷵������
	std::cout << std::is_same_v<decltype(x2[0]), int(&)[4]> << std::endl;
	int x3[3][4][5]; //x3����3��Ԫ�أ�ÿ��Ԫ����int[4][5]
	std::cout << sizeof(x3[0]) << std::endl;
	std::cout << std::is_same_v<decltype(x3[0]), int[4][5]> << std::endl;
	std::cout << std::is_same_v<decltype(x3[0]), int(&)[4][5]> << std::endl;

	//��ά����ۺϳ�ʼ��
	int x4[3][4] = { 1,2,3,4,5 };
	//{int, int, int, int},{int, int, int, int},{int, int, int, int}
	//ǰ���Ԫ�ظ�ֵ������Ϊ0

	int x5[3][4] = { {1,2,3,4},{5,6,7,8} }; //����Ϊ0
	int x6[3][4] = { {1,2,3,4},{5,6,7} }; //����Ϊ0
	int x7[3][4] = { {1,2,3},{4,5,6,7} }; //����Ϊ0
	std::cout << x6[1][0] << " " << x6[1][3] << std::endl;
	std::cout << x7[1][0] << " " << x7[0][3] << std::endl;
	std::cout << x6[0] << " " << x6[2] << std::endl;

	int x8[][2] = { 1,2,3,4 }; //�������Զ��Ƶ���0ά
	std::cout << sizeof(x8) << std::endl;
	int x9[][3] = { 1,2,3,4 }; 
	std::cout << sizeof(x9) << std::endl;
	std::cout << std::is_same_v<decltype(x9), int[2][3]> << std::endl;

	int x10[][4] = { {1,2,3},{2,3,4,5} };
	std::cout << std::is_same_v<decltype(x10), int[2][4]> << std::endl;

	int x11[][4][5] = { {{1,2,3},{4,5,6}} }; //����ʡ�Ե�0ά�����ǲ��Ƽ�
	std::cout << sizeof(x11) << std::endl;
}

using A = int[4];

void fun2() //��ά��������������
{
	int x1[3][4] = { {1,2},{3,4},{5,6} };
	
	//range based for
	for (auto& p : x1)
	{
		for (auto q : p)
		{
			std::cout << q << '\n';
		}
	}

	/*
	int x2[3][4][5] = { 1,2,3 };
	for (auto& r : x2)
	{
		for (auto& p : r)
		{
			for (auto& q : p)
			{
				std::cout << q << '\n';
			}
		}
	}
	*/

	size_t index0 = 0;
	size_t index1 = 0;
	while (index0 < std::size(x1))
	{
		index1 = 0;
		while (index1 < std::size(x1[index0]))
		{
			std::cout << x1[index0][index1] << ' ';
			if (index1 == 3)
			{
				std::cout << '\n';
			}
			index1 = index1 + 1;
		}
		index0 = index0 + 1;
	}

	int x3[3][4] = {1,2,3,4,5,6,7,8};
	auto ptr3 = x3; //ptrΪָ�뵫����ʧ���λ��Ϣ����������ά�ȵ���Ϣ
	std::cout << std::is_same_v<decltype(ptr3), int(*)[4]> << std::endl;
	std::cout << ptr3[0] << '\n';
	std::cout << ptr3[1][0] << '\n';

    /*
	std::cout << *ptr3 << '\n';
	std::cout << ptr3 << '\n';
	std::cout << ptr3[0] << '\n';
	std::cout << *(ptr3+1) << '\n'; 
	std::cout << ptr3 + 1 << '\n';
	std::cout << ptr3[1] << '\n';
	*/

	auto ptr4 = x3[0];
	std::cout << std::is_same_v<decltype(ptr4), int*> << std::endl;
	auto ptr5 = ptr3[0];
	std::cout << std::is_same_v<decltype(ptr5), int*> << std::endl;

	//ʹ�����ͱ����򻯶�ά����ָ�������
	A* ptr6 = x3; //ת��Ϊָ��ʱ����0ά�ȶ�ʧ
	std::cout << std::is_same_v<decltype(ptr6), int(*)[4]> << std::endl;

	A x4[3] = { 3,4,5,6,7,8 };
	std::cout << std::is_same_v<decltype(x4), int[3][4]> << std::endl; //true
	std::cout << std::is_same_v<decltype(x4), int[4][3]> << std::endl; //false

    //ʹ��ָ����������ά����
	auto ptr7 = x4; //or auto ptr7 = std::begin(x4)
	while (ptr7 != std::end(x4))
	{
		auto ptr8 = std::begin(*ptr7);
		while (ptr8 != std::end(*ptr7))
		{
			std::cout << *ptr8 << std::endl;
			ptr8 = ptr8 + 1;
		}
		ptr7 = ptr7 + 1;
	}
}


int main()
{
	//fun0();
	//fun1();
	fun2();
}
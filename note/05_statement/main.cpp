#include<iostream>
#include<vector>

void fun0()
{
	//���ʽ���
	//�Ա��ʽ��ֵ���������ܲ���������
	int x;
	x = 2 + 3;
	std::cout << x << '\n';
	//�����
	;

	//������䣨����壩
	if (x < 10)
	{
		++x;
	}
	std::cout << x << '\n';

	//��������γɶ����������
	int y = 56;
	std::cout << y << '\n';
	{
		int y = 65;
		std::cout << y << '\n';
	}

	//˳�����
	//��˳�����
	int z = 3;
	if (z) goto label;
	++z;
	std::cout << z << '\n';
label:
	std::cout << "label" << '\n';
}

void fun1()
{
	//��֧���
	int x = 5;
	//if���
	if (x > 2)
		std::cout << "x > 2" << '\n';
	else
		std::cout << "x < 2" << '\n';
	//����
	if (x > 2)
	{
		int y = 56;
		std::cout << y << '\n';
	}
	else
	{
		x = x * 2;
		std::cout << x << '\n';
	}
	//���֧
	if (x > 2)
	{
		std::cout << "x>2" << '\n';
	}
	else if (x > 0)
	{
		std::cout << "x>0" << '\n';
	}
	else
	{
		std::cout << "x<0" << '\n';
	}

	//else�������ifƥ�䣬����ͨ���������п���ƥ��
	int grade = 65;
	if (grade > 60)
		if (grade > 80)
		{
			std::cout << "Excellent\n";
		}
	else
		std::cout << "bad\n";

	//ͨ�������ſ���ƥ��
	if (grade > 60)
	{
		if (grade > 80)
		{
			std::cout << "Excellent\n";
		}
	}
	else
		std::cout << "bad\n";


	//constexpr if
	constexpr int gra = 80;
	if constexpr (gra < 60)  //����ӦΪ�������ʽ
	{
		std::cout << "fail\n";
	}
	else
	{
		std::cout << "pass\n";
	}

	//����ʼ������if��from C++ 17��
	/*
	int y = 3;
	if (int z = y * 3; z > 5)
	{
		std::cout << z << '\n';
	}
	*/

}

void fun2()
{
	//switch���
	//fallthrough ����
	//������break��case��ִ�к����ȫ�����
	//from C++17 �������԰�����ʼ�����
	int x;
	std::cin >> x;
	switch (x)
	{
	case 1:
		std::cout << "Hello\n"; [[fallthrough]];//from  C++17
	case 2:
		std::cout << "Bye\n"; break;
	case 3:
		{
		int y = 3;
		std::cout << y << '\n'; break;
		}
	case 4:
	case 5:
		std::cout << "double\n";  
	default:
		std::cout << "Hi\n"; break;
	}

	//��case��default�ж������Ҫ�Ӵ�����
}

void fun3()
{
	//ѭ�����
	//while���
	int x = 3;
	while (x < 10)
	{
		std::cout << x << '\n';
		++x;
	}
	

	//do-while���
	do
	{
		std::cout << x << '\n';
		--x;
	} while (x>2);
}

void fun4()
{
	//forѭ�����
	for (int x = 0; x < 5; ++x)
	{
		std::cout << x << '\n';
	}

	//��ʼ����䣬�������������ʽ������Ϊ�� 
	//for (;;)
	//	;

	//���ڷ�Χ��forѭ��
	//�﷨�ǣ���������ת��Ϊ��ͳforѭ���ĵ���
	std::vector<int> arr{ 1,2,3,4,5 };
	for (int v : arr)
	{
		std::cout << v << '\n';
	}

	std::vector<std::string> str{ "h","e","l" };
	for (const std::string& v : str)
	{
		std::cout << v << '\n';
	}

	//ʹ���������ã�universal reference���޸�Ԫ��
	for (auto&& v : arr)
	{
		v = v + 1;
	}
	for (const int& v : arr)
	{
		std::cout << v << '\n';
	}
	
}

void fun5()
{
	//break
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 5; ++j)  //break����ֹ��ѭ��
		{
			if (j == 2) break;
			std::cout << i << ' ' << j << '\n';
		}
	}

	//continue
	//��������ѭ�����ʣ�ಿ�֣�������ֹѭ��
	for (int i = 0; i < 10; i++)
	{
		if (i == 5) continue;
		std::cout << i << '\n';
	}

	//goto
	//����������������Ƕ��ѭ��
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 5; ++j)  //break����ֹ��ѭ��
		{
			if (j == 2) goto label;
			std::cout << i << ' ' << j << '\n';
		}
	}

	label:std::cout << "stop" << '\n';
}

void fun6()
{
	//����豸
	constexpr size_t buffer_count = 10000;
	std::vector<size_t> buffer(buffer_count);
	for (size_t i = 0; i < buffer_count; ++i)
	{
		buffer[i] = i;
	}

	size_t max_value = buffer[0];
	for (size_t i = 0; i < buffer_count; ++i)
	{
		max_value = (max_value > buffer[i]) ? max_value : buffer[i];
	}

	std::cout << max_value << '\n';

	max_value = buffer[0];
	for (size_t i = 0; i < buffer_count; i += 8)
	{
		max_value = (max_value > buffer[i]) ? max_value : buffer[i];
		max_value = (max_value > buffer[i + 1]) ? max_value : buffer[i + 1];
		max_value = (max_value > buffer[i + 2]) ? max_value : buffer[i + 2];
		max_value = (max_value > buffer[i + 3]) ? max_value : buffer[i + 3];
		max_value = (max_value > buffer[i + 4]) ? max_value : buffer[i + 4];
		max_value = (max_value > buffer[i + 5]) ? max_value : buffer[i + 5];
		max_value = (max_value > buffer[i + 6]) ? max_value : buffer[i + 6];
		max_value = (max_value > buffer[i + 7]) ? max_value : buffer[i + 7];

	}

	std::cout << max_value << '\n';

	max_value = buffer[0];
	for (size_t i = 0; i + 7 < buffer_count; i += 8)
	{
		max_value = (max_value > buffer[i]) ? max_value : buffer[i];
		max_value = (max_value > buffer[i + 1]) ? max_value : buffer[i + 1];
		max_value = (max_value > buffer[i + 2]) ? max_value : buffer[i + 2];
		max_value = (max_value > buffer[i + 3]) ? max_value : buffer[i + 3];
		max_value = (max_value > buffer[i + 4]) ? max_value : buffer[i + 4];
		max_value = (max_value > buffer[i + 5]) ? max_value : buffer[i + 5];
		max_value = (max_value > buffer[i + 6]) ? max_value : buffer[i + 6];
		max_value = (max_value > buffer[i + 7]) ? max_value : buffer[i + 7];

	}

	for (size_t i = (buffer_count / 8) * 8 ; i < buffer_count; ++i)
	{
		max_value = (max_value > buffer[i]) ? max_value : buffer[i];
	}


	std::cout << max_value << '\n';
}

void fun7()
{
	constexpr size_t buffer_count = 10004;
	std::vector<size_t> buffer(buffer_count);
	auto ptr = buffer.begin();
	size_t max_value = buffer[0];
	for (size_t i = 0; i < buffer_count; ++i)
	{
		buffer[i] = i;
	}

	for (size_t i = 0; i + 7 < buffer_count; i += 8)
	{
		max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
	}

	switch (buffer_count % 8)
	{
	case 7: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
	case 6: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
	case 5: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
	case 4: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
	case 3: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
	case 2: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
	case 1: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
	case 0: break;
	}

	std::cout << max_value << '\n';
}

void fun8()
{
	constexpr size_t buffer_count = 10003;
	std::vector<size_t> buffer(buffer_count);
	auto ptr = buffer.begin();
	size_t max_value = buffer[0];
	for (size_t i = 0; i < buffer_count; ++i)
	{
		buffer[i] = i;
	}

	size_t i = 0;
	switch (buffer_count % 8)
		for (; i < (buffer_count + 7) / 8; ++i)
		{
		case 0: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		case 7: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		case 6: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		case 5: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		case 4: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		case 3: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		case 2: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		case 1: max_value = (max_value > * ptr) ? max_value : *ptr; ++ptr;
		}

	std::cout << max_value << '\n';
}

int main()
{
	//fun0();

	//fun1();

	//fun2();

	//fun3();

	//fun4();

	//fun5();

	fun6();

	fun7();

	fun8();
}


//����С��
//2021.06.22

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


//�����ַ����е�0�ͷ���λ,Сд��ĸת��д��ĸ
void str_filter(std::string& str)
{
	//�ַ�������
	size_t length = str.size();

	//�ַ����з���λʱ��ֱ�ӹ��˷���λ���0
	//�ַ����޷���λʱ���ȹ���0�����ַ���ǰ��ӡ�+��
	if (str[0] == '+' || str[0] == '-')
	{
		size_t l = 0;
		for (size_t i = 1; i < length; ++i)
		{
			if (str[i] == '0') { ++l; }
			else { break; }
		}
		str.erase(1, l);
	}
	else
	{
		size_t l = 0;
		for (size_t i = 0; i < length; ++i)
		{
			if (str[i] == '0') { ++l; }
			else { break; }
		}
		str.erase(0, l);
		str.insert(0, "+");
	}

	//ͳһ�ַ����е���ĸΪ��д
	std::transform(str.begin(), str.end(), str.begin(), std::toupper);
}

//�Ƚ����������ľ���ֵ��ʹstr1Ϊ����ֵ�ϴ�ֵ
void abv_compar(std::string& str1, std::string& str2)
{
	std::string temp;

	if (str1.size() == str2.size())
	{
		size_t i = 1;
		for (; i < str1.size(); ++i)
		{
			if (str1[i] != str2[i]) { break; }
		}
		if ((str1[i] - '0') < (str2[i] - '0'))
		{
			temp = str1;
			str1 = str2;
			str2 = temp;
		}
	}
	else
	{
		if (str1.size() < str2.size())
		{
			temp = str1;
			str1 = str2;
			str2 = temp;
		}
	}
}

//���ַ���
void read_str(std::string test_case, std::string& str1, std::string& str2, std::string& real)
{
	//����������ַ
	//std::string path = "..\\test\\" + test_case;  //����Ŀ¼��ͬ���ļ����У���Ҫ���˳���ǰ�Ĺ���Ŀ¼
	//std::string path = ".\\test\\" + test_case;  //����Ŀ¼�����ļ�����
	//std::string path = test_case; //��cpp�ļ���ͬһ���ļ�����
	std::string path = "D:\\06 KIT2021\\CS_Robo\\SL_C++\\00_Code\\05_Project\\Project1\\test\\" + test_case;

	std::ifstream infile(path);
	std::getline(infile, str1);
	std::getline(infile, str2);
	std::getline(infile, real);

}

//�������
int arg_check(std::string& str, int M)
{
	//���M�Ƿ����36
	if (M > 36) { return -1; }

	//���str�������Ƿ�����Ʋ���
	int num;
	for (size_t i = 1; i < str.size(); ++i)
	{
		if (std::isalpha(str[i]))
		{
			num = str[i] - 'A' + 10;
			if (num >= M) { return -1; }
		}
		else
		{
			num = str[i] - '0';
			if (num >= M) { return -1; }
		}
	}

	//��������
	return 0;
}

//����ת����M����ת��ΪN����
std::string M_to_N(std::string str, int M, int N)
{
	int input[1010] = {0};
	std::string output;

	//���ַ������������
	for (size_t i = 1; i < str.size(); i++)
	{
		if (std::isalpha(str[i])) { input[i-1] = str[i] - 'A' + 10; }
		else { input[i-1] = str[i] - '0'; }
	}
	
	int len = str.size() - 1;
	char num;

	//ת�����ƣ����������ַ���
	for (int i = 0; i < len;)
	{
		int re=0;
		for (int j = i; j < len; ++j)
		{
			int temp = (input[j] + re * M) % N;
			input[j] = (input[j] + re * M) / N;
			re = temp;
		}
		if (re > 9) { num = 'A' + (re - 10); output = output + num; }
		else { num = '0' + re; output = output + num; }
		
		while (input[i] == 0) { ++i; }
	}

	//��ӷ���λ��ȡ��
	output = output + str[0];
	std::reverse(output.begin(), output.end());

	return output;
}

//�����ӷ�
std::string big_num_add(std::string& str1, std::string& str2, int M = 10, int N = 10)
{
	std::string result;
	char temp;
	int len1 = str1.size() - 1, len2 = str2.size() - 1, carry = 0;
	int num1, num2, sum;

	//��λ���ӷ�������9���λ
	while (len1 > 0)
	{
		num1 = str1[len1] - '0';
		if (len2 > 0) { num2 = str2[len2] - '0'; }
		else { num2 = 0; }
		sum = num1 + num2 + carry;
		carry = sum / 10;
		temp = '0' + (sum % 10);
		result = result + temp;
		--len1;
		--len2;
	}

	//���н�λʱ���ڽ��ǰ��1
	if (carry == 1) { result = result + "1"; }

	if (result.size() == 0)
	{
		return "0";
	}
	else
	{
		//��ӷ���λ
		result = result + str1[0];
		//ȡ��
		std::reverse(result.begin(), result.end());
		return result;
	}
}

//��������
std::string big_num_sub(std::string& str1, std::string& str2, int M = 10, int N = 10)
{
	std::string result;
	char temp;
	int len1 = str1.size() - 1, len2 = str2.size() - 1;
	int num1, num2, sub;

	//��λ��������������ʱ��λ
	while (len1 > 0)
	{
		num1 = str1[len1] - '0';
		if (len2 > 0) { num2 = str2[len2] - '0'; }
		else { num2 = 0; }
		if (num1 >= num2) { sub = num1 - num2; }
		else { sub = num1 + 10 - num2; str1[len1 - 1] = str1[len1 - 1] - 1; }
		temp = '0' + sub;
		result = result + temp;
		--len1;
		--len2;
	}

	//ȥ�������0
	int len_re = result.size() - 1, l = 0;
	for (; len_re > 0; --len_re)
	{
		if (result[len_re] == '0') { ++l; }
		else { break; }
	}
	result.erase(len_re + 1, l);

	//�жϽ���Ƿ�Ϊ0
	if (result[len_re] == '0')
	{
		return result;
	}
	else if (result.size() == 0)
	{
		return "0";
	}
	else
	{	
		//��ӷ���λ��ȡ��
		result = result + str1[0];
		std::reverse(result.begin(), result.end());
		return result;
	}

}

//�����ļ�
void test(std::string test_mode="test", int M=10, int N=10)
{
	if (test_mode == "test")
	{
		std::string num;
		std::string txt = ".txt";
		for (int i = 0; i < 21; ++i)
		{
			std::string test_case = "test_case";
			num = std::to_string(i);
			test_case = test_case + num + txt;
			std::cout << test_case << '\n';

			if (i > 12) { M = 16; N = 16; }

			//��������ļ����ַ���
			std::string str1;
			std::string str2;
			std::string real;

			//�Ӳ����ļ��ж�ȡ�ַ���
			read_str(test_case, str1, str2, real);

			//���˷���λ��ǰ��0����Сд��ĸȫ��ת��Ϊ��д��ĸ
			str_filter(str1);
			str_filter(str2);

			//�������
			if (arg_check(str1, M) || arg_check(str2, M))
			{
				std::cout << "argument false" << '\n';
				continue;
			}

			//����ת��
			if (M != 10)
			{
				str1 = M_to_N(str1, M, 10);
				str2 = M_to_N(str2, M, 10);
			}

			//ʹstr1�������ֵ�ϴ��ֵ
			abv_compar(str1, str2);

			//���������������Ĵ�����
			//std::cout << str1.size() << '\n';
			//std::cout << str1 << '\n';
			//std::cout << str2.size() << '\n';
			//std::cout << str2 << '\n';

			//����λ��ͬ��ʹ�üӷ�������λ��ͬ��ʹ�ü���
			std::string result;
			if (str1[0] == str2[0]) { result = big_num_add(str1, str2); }
			else { result = big_num_sub(str1, str2); }

			//ʮ���ƽ��
			//std::cout << result << '\n';

			//����ת��
			if (N != 10) { result = M_to_N(result, 10, N); }

			//�жϽ���ķ���λ
			if (result[0] == '+') { result.erase(0, 1); }

			//������
			//std::cout << result.size() << '\n';
			std::cout << "You Program out: " << result << '\n';
			std::cout << "Standard answer: " << real << '\n';
		}
	}
	else
	{
		std::string test_case = test_mode;
		std::cout << test_case << '\n';
		//��������ļ����ַ���
		std::string str1;
		std::string str2;
		std::string real;
		//�Ӳ����ļ��ж�ȡ�ַ���
		read_str(test_case, str1, str2, real);
		//���˷���λ��ǰ��0����Сд��ĸȫ��ת��Ϊ��д��ĸ
		str_filter(str1);
		str_filter(str2);
		//�������
		if (arg_check(str1, M) || arg_check(str2, M))
		{
			std::cout << "argument false" << '\n';
			exit(-1);
		}
		//����ת��
		if (M != 10)
		{
			str1 = M_to_N(str1, M, 10);
			str2 = M_to_N(str2, M, 10);
		}
		//ʹstr1�������ֵ�ϴ��ֵ
		abv_compar(str1, str2);
		//����λ��ͬ��ʹ�üӷ�������λ��ͬ��ʹ�ü���
		std::string result;
		if (str1[0] == str2[0]) { result = big_num_add(str1, str2); }
		else { result = big_num_sub(str1, str2); }
		//����ת��
		if (N != 10) { result = M_to_N(result, 10, N); }
		//�жϽ���ķ���λ
		if (result[0] == '+') { result.erase(0, 1); }
		//������
		std::cout << "You Program out: " << result << '\n';
		std::cout << "Standard answer: " << real << '\n';
	}
}

int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		switch (argc)
		{
		case 2:test(argv[1]); break;
		case 3:test(argv[1], std::stoi(argv[2]), std::stoi(argv[2])); break;
		case 4:test(argv[1], std::stoi(argv[2]), std::stoi(argv[3])); break;
		default:std::cout << "argument false" << '\n';
		}
		
	}
	else
	{
		test();
	}
	return 0;
}
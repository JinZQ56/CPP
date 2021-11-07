//后卫小金
//2021.06.22

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


//过滤字符串中的0和符号位,小写字母转大写字母
void str_filter(std::string& str)
{
	//字符串长度
	size_t length = str.size();

	//字符串有符号位时，直接过滤符号位后的0
	//字符串无符号位时，先过滤0后在字符串前添加“+”
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

	//统一字符串中的字母为大写
	std::transform(str.begin(), str.end(), str.begin(), std::toupper);
}

//比较两个大数的绝对值，使str1为绝对值较大值
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

//读字符串
void read_str(std::string test_case, std::string& str1, std::string& str2, std::string& real)
{
	//测试用例地址
	//std::string path = "..\\test\\" + test_case;  //工程目录的同级文件夹中，需要先退出当前的工程目录
	//std::string path = ".\\test\\" + test_case;  //工程目录的子文件夹中
	//std::string path = test_case; //与cpp文件在同一个文件夹中
	std::string path = "D:\\06 KIT2021\\CS_Robo\\SL_C++\\00_Code\\05_Project\\Project1\\test\\" + test_case;

	std::ifstream infile(path);
	std::getline(infile, str1);
	std::getline(infile, str2);
	std::getline(infile, real);

}

//参数检查
int arg_check(std::string& str, int M)
{
	//检查M是否大于36
	if (M > 36) { return -1; }

	//检查str中数字是否与进制不符
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

	//参数正常
	return 0;
}

//进制转换：M进制转换为N进制
std::string M_to_N(std::string str, int M, int N)
{
	int input[1010] = {0};
	std::string output;

	//将字符串保存进数组
	for (size_t i = 1; i < str.size(); i++)
	{
		if (std::isalpha(str[i])) { input[i-1] = str[i] - 'A' + 10; }
		else { input[i-1] = str[i] - '0'; }
	}
	
	int len = str.size() - 1;
	char num;

	//转换进制，结果保存进字符串
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

	//添加符号位，取逆
	output = output + str[0];
	std::reverse(output.begin(), output.end());

	return output;
}

//大数加法
std::string big_num_add(std::string& str1, std::string& str2, int M = 10, int N = 10)
{
	std::string result;
	char temp;
	int len1 = str1.size() - 1, len2 = str2.size() - 1, carry = 0;
	int num1, num2, sum;

	//按位做加法，大于9则进位
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

	//仍有进位时，在结果前加1
	if (carry == 1) { result = result + "1"; }

	if (result.size() == 0)
	{
		return "0";
	}
	else
	{
		//添加符号位
		result = result + str1[0];
		//取逆
		std::reverse(result.begin(), result.end());
		return result;
	}
}

//大数减法
std::string big_num_sub(std::string& str1, std::string& str2, int M = 10, int N = 10)
{
	std::string result;
	char temp;
	int len1 = str1.size() - 1, len2 = str2.size() - 1;
	int num1, num2, sub;

	//按位做减法，不够减时借位
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

	//去除多余的0
	int len_re = result.size() - 1, l = 0;
	for (; len_re > 0; --len_re)
	{
		if (result[len_re] == '0') { ++l; }
		else { break; }
	}
	result.erase(len_re + 1, l);

	//判断结果是否为0
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
		//添加符号位并取逆
		result = result + str1[0];
		std::reverse(result.begin(), result.end());
		return result;
	}

}

//测试文件
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

			//定义测试文件和字符串
			std::string str1;
			std::string str2;
			std::string real;

			//从测试文件中读取字符串
			read_str(test_case, str1, str2, real);

			//过滤符号位和前置0，将小写字母全部转换为大写字母
			str_filter(str1);
			str_filter(str2);

			//参数检查
			if (arg_check(str1, M) || arg_check(str2, M))
			{
				std::cout << "argument false" << '\n';
				continue;
			}

			//进制转换
			if (M != 10)
			{
				str1 = M_to_N(str1, M, 10);
				str2 = M_to_N(str2, M, 10);
			}

			//使str1保存绝对值较大的值
			abv_compar(str1, str2);

			//输出两个参与运算的大整数
			//std::cout << str1.size() << '\n';
			//std::cout << str1 << '\n';
			//std::cout << str2.size() << '\n';
			//std::cout << str2 << '\n';

			//符号位相同则使用加法，符号位不同则使用减法
			std::string result;
			if (str1[0] == str2[0]) { result = big_num_add(str1, str2); }
			else { result = big_num_sub(str1, str2); }

			//十进制结果
			//std::cout << result << '\n';

			//进制转换
			if (N != 10) { result = M_to_N(result, 10, N); }

			//判断结果的符号位
			if (result[0] == '+') { result.erase(0, 1); }

			//输出结果
			//std::cout << result.size() << '\n';
			std::cout << "You Program out: " << result << '\n';
			std::cout << "Standard answer: " << real << '\n';
		}
	}
	else
	{
		std::string test_case = test_mode;
		std::cout << test_case << '\n';
		//定义测试文件和字符串
		std::string str1;
		std::string str2;
		std::string real;
		//从测试文件中读取字符串
		read_str(test_case, str1, str2, real);
		//过滤符号位和前置0，将小写字母全部转换为大写字母
		str_filter(str1);
		str_filter(str2);
		//参数检查
		if (arg_check(str1, M) || arg_check(str2, M))
		{
			std::cout << "argument false" << '\n';
			exit(-1);
		}
		//进制转换
		if (M != 10)
		{
			str1 = M_to_N(str1, M, 10);
			str2 = M_to_N(str2, M, 10);
		}
		//使str1保存绝对值较大的值
		abv_compar(str1, str2);
		//符号位相同则使用加法，符号位不同则使用减法
		std::string result;
		if (str1[0] == str2[0]) { result = big_num_add(str1, str2); }
		else { result = big_num_sub(str1, str2); }
		//进制转换
		if (N != 10) { result = M_to_N(result, 10, N); }
		//判断结果的符号位
		if (result[0] == '+') { result.erase(0, 1); }
		//输出结果
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
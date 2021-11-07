#include <iostream>
#include <string>
#include <string_view>
#include <span>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <ranges>

void fun_view(std::string_view strv)
{
	if (!strv.empty())
	{
		std::cout << strv[0] << std::endl;
	}

	//string_view���ɶ�ȡԭʼ�ַ�������Ϣ�����ܽ���д����
}


void fun_span(std::span<int> input)
{
	//since C++20
	for (auto p : input)
	{
		std::cout << p << ' ';
	}
	std::cout << std::endl;

	//span֧��д����
	input[0] = 8;
} 

void fun_stack()
{
	//������vector��deque��list��֧��back(),push_back(),pop_back()����������
	std::stack<int, std::vector<int>> p;
	p.push(3);
	p.push(2);
	p.pop();
	std::cout << p.top() << std::endl;
}

void fun_queue()
{
	//������deque��list��֧��back(),front(),push_back(),pop_front����������
	std::queue<int, std::list<int>> q;
	q.push(3);
	q.push(2);
	q.push(1);
	q.pop();
	std::cout << "front: " << q.front() << std::endl;
	std::cout << "back: " << q.back() << std::endl;
}

void priority_queue()
{
	//�ڲ�������Ԫ����Ҫ֧�ֱȽϲ���
}


bool isEven(int i)
{
	return 1 % 2 == 0;
}

//void fun_ranges()
//{
//   //C++ 20
//	 std::vector<int> v{ 1,2,3,4,5 };
//	 for (auto p : std::ranges::filter_view(v, isEven))
//	 {
//		 std::cout << p << ' ';
//	 }
//	 std::cout << std::endl;
//}

int main()
{
	fun_view("1234");
	fun_view(std::string("6789"));
	std::cout << sizeof(std::string_view) << std::endl;
	std::cout << sizeof(std::string) << std::endl;

	//string_view����ʹ�õ��������й��죬 since C++20
	//std::string s("456");
	//std::string_view sv;
	//sv = std::string_view(s.begin(), s.begin()+2)
	 
	int a[3] = { 1,2,3 };
	fun_span(a);
	fun_span(a);
	std::vector<int> v{ 4,5,6 };
	fun_span(v);
	fun_span(v);
	
	fun_stack();
	fun_queue();
}
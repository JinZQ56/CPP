#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <sstream>
#include <random>
#include <chrono>
#include <execution>

void fun0()
{
	int x[100];
	std::vector<int> v(100);

	// �����㷨ͨ�����������������н���
	std::sort(std::begin(x), std::end(x));
	std::sort(std::begin(v), std::end(v));
	// ����ʹ�������ڵķ�����õ�����
	std::sort(v.begin(), v.end());
 }

// ��һ�ࣺ���㷨
// �����������䣬��ȡ����Ԫ�ز����м���
void read_algo()
{
	// accumulate
	std::vector<int> v{ 1,2,3,3 };
	int sum = std::accumulate(v.begin(), v.end(), 0);
	std::cout << "accumulate: " << sum << std::endl;

	// find
	auto f = std::find(v.begin(), v.end(), 2);
	std::cout << "find: " << f-v.begin() << " " << *f << std::endl;

	// count
	auto c = std::count(v.begin(), v.end(), 3);
	std::cout << "count: " << c << std::endl;
}

// �ڶ��ࣺд�㷨
// ��һ����������д��Ԫ��
void write_algo()
{
	// write
	// fill
	std::vector<int> v{1, 2, 3};
	std::cout << v[1] << std::endl;
	std::fill(v.begin(), v.end(), 5);
	for (auto i : v) 
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

}

int zwei(int i)
{
	return 2 * i;
}

void rw_algo()
{
	// read and write
	std::vector<int> v{ 1,2,3,4 };
	std::vector<int> t(4);
	std::transform(v.begin(), v.end(), t.begin(), zwei);
	for (auto i : v)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (auto i : t)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

// �����ࣺ�����㷨 
// �ı�����������Ԫ�ص�˳��
void sort_algo()
{
	// sort
	// Ĭ������´�С����
	std::vector<int> v{ 1,4,2,2,2,9,8,5 };
	std::sort(v.begin(), v.end());
	for (auto i : v)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	// unique
	auto u = std::unique(v.begin(), v.end());
	std::cout << "unique: " << u - v.begin() << " " << *u << std::endl;
	for (auto i : v)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	v.erase(u, v.end());
	for (auto i : v)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

// iterator
void insert_it()
{
	std::vector<int> v;
	std::fill_n(std::back_insert_iterator<std::vector<int>>(v), 10, 2);
	for (auto i : v)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::fill_n(std::back_inserter(v), 10, 3);
	for (auto i : v)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void stream_it()
{
	std::cout << "istream_it: " << std::endl;
	std::istringstream str("1 2 34 5 678");
	std::istream_iterator<int> x(str); //�������Ŀ�ͷ
	std::cout << *x << std::endl;
	++x;
	std::cout << *x << std::endl;
	std::istream_iterator<int> y{}; //�������Ľ�β
	for (; x != y; ++x)
	{
		std::cout << *x << " ";
	}
	std::cout << std::endl;

	std::cout << "ostream_it: " << std::endl;
	std::ostream_iterator<char> oc{ std::cout };
	std::ostream_iterator<int> oi{ std::cout, ", " };
	std::fill_n(oi, 5, -1);
	*oc++ = '\n';
	std::fill_n(oi, 5, 1);
	*oc++ = '\n';
	std::copy(std::istream_iterator<int>(std::cin),
		std::istream_iterator<int>(),
		std::ostream_iterator<int>(std::cout, "\n"));
}

void r_it()
{
	std::vector<int> v{ 1,2,3,4,5 };
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	// ���������
	std::copy(v.rbegin(), v.rend(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

void move_it()
{
	std::vector<std::string> v{ "this","_","is","_","an","_","example" };
	std::cout << "before move: ";
	for (auto i : v)
	{
		std::cout << i;
	}
	std::cout << std::endl;
	// move_it ��Ԫ�ش�һ������ת�Ƶ���һ������
	std::string concat = std::accumulate(std::make_move_iterator(v.begin()),
										 std::make_move_iterator(v.end()),
										 std::string());
	std::cout << "after move: ";
	for (auto i : v)
	{
		std::cout << i;
	}
	std::cout << std::endl;
	std::cout << concat << std::endl;
}

// �ڱ�
// ��ʶ�����β�ĵ�����
bool sentinel()
{
	// ��ranges��Ӧ��
	return true;
}

// �����㷨(c++17/c++20)
void execution()
{
	std::random_device rd;
	std::vector<double> vals(10000000);
	for (auto& d : vals)
	{
		d = static_cast<double>(rd());
	}
	
	for (int i = 0; i < 3; ++i)
	{
		using namespace std::chrono;
		std::vector<double> sorted(vals);
		const auto startTime = high_resolution_clock::now();
		// std::sort(sorted.begin(), sorted.end());
		std::sort(std::execution::par, sorted.begin(), sorted.end());
		const auto endTime = high_resolution_clock::now();
		std::cout << "Latency: "
			      << duration_cast<duration<double, std::milli>>(endTime - startTime).count()
			      << std::endl;

	}

}

int main()
{
	// fun0();
	// read_algo();
	// write_algo();
	// rw_algo();
	// sort_algo();
	// insert_it();
	// stream_it();
	// r_it();
	// move_it();
	execution();
}
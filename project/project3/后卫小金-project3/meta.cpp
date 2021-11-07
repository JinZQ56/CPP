/*
	project: 编译期长整数加法
	author：后卫小金
	date：2021.11.07
*/

#include <iostream>
#include <type_traits>


/*Container*/
template <unsigned int...> class Cont;
using num1 = Cont<9,8,1,3,7>;
//using num1 = Cont<1,0>;
using num2 = Cont<2,6,8,4>;

/*Print*/
// PrintHelper 1 -> loop programming
template <typename T>
class PrintHelper1;
// specialization 1
template <unsigned int val, unsigned int... vals>
class PrintHelper1<Cont<val, vals...>>
{
public:
	static void Print()
	{
		std::cout << val ;
		PrintHelper1<Cont<vals...>>::Print();
	}
};
// specialization 2
template <>
class PrintHelper1<Cont<>>
{
public:
	static void Print()
	{
		std::cout << std::endl;
	}
};
// PrintHelper2 -> fold expression (C++ 17)
template <typename T>
class PrintHelper2;
// specialization 1
template <unsigned int... vals>
class PrintHelper2<Cont<vals...>>
{
public:
	static void Print()
	{
		((std::cout << vals), ...);
		std::cout << std::endl;
	}
};
// function template
template <typename T>
void print()
{
	PrintHelper1<T>::Print();
	// PrintHelper2<T>::Print();
}

/*Reverse*/
template <typename pro, typename rem>
class ReverseHelper;
// specialization 1
template <unsigned int... pro, unsigned int val, unsigned int... rem>
class ReverseHelper<Cont<pro...>, Cont<val, rem...>>
{
public:
	using Reverse = ReverseHelper<Cont<val, pro...>, Cont<rem...>>::Reverse;
};
// specialization 2
template <unsigned int... pro>
class ReverseHelper<Cont<pro...>, Cont<>>
{
public:
	using Reverse = Cont<pro...>;
};
// reverse num1 and num2
using num1_r = ReverseHelper<Cont<>, num1>::Reverse;
using num2_r = ReverseHelper<Cont<>, num2>::Reverse;

/*Add*/
template <typename res, typename num1, typename num2, unsigned int x=0>
class AddHelper;
// specialization 1
// num1 and num2 are not empty
template <unsigned int... res, unsigned int val1, unsigned int... num1, unsigned int val2, unsigned int... num2, unsigned int x>
class AddHelper<Cont<res...>, Cont<val1, num1...>, Cont<val2, num2...>, x>
{
public:
	constexpr static unsigned int c = ((val1 + val2 + x) < 10) ? 0 : 1;
	constexpr static unsigned int val = (c == 0) ? (val1 + val2 + x) : (val1 + val2 + x - 10);
	using Add = AddHelper<Cont<res..., val>, Cont<num1...>, Cont<num2...>, c>::Add;
};
// specialization 2
// num1 is empty
template <unsigned int... res, unsigned int val2, unsigned int... num2, unsigned int x>
class AddHelper<Cont<res...>, Cont<>, Cont<val2, num2...>, x>
{
public:
	constexpr static unsigned int c = ((val2 + x) < 10) ? 0 : 1;
	constexpr static unsigned int val = (c == 0) ? (val2 + x) : (val2 + x - 10);
	using Add = AddHelper<Cont<res..., val>, Cont<>, Cont<num2...>, c>::Add;
};
// specialization 3
// num2 is empty
template <unsigned int... res, unsigned int val1, unsigned int... num1, unsigned int x>
class AddHelper<Cont<res...>, Cont<val1, num1...>, Cont<>, x>
{
public:
	constexpr static unsigned int c = ((val1 + x) < 10) ? 0 : 1;
	constexpr static unsigned int val = (c == 0) ? (val1 + x) : (val1 + x - 10);
	using Add = AddHelper<Cont<res..., val>, Cont<num1...>, Cont<>, c>::Add;
};
// specialization 4
// num1 and num2 are all empty and x = 0
template <unsigned int... res>
class AddHelper<Cont<res...>, Cont<>, Cont<>, 0>
{
public:
	using Add = Cont<res...>;
};
// specialization 5
// num1 and num2 are all empty and x = 1
template <unsigned int... res>
class AddHelper<Cont<res...>, Cont<>, Cont<>, 1>
{
public:
	using Add = Cont<res..., 1>;
};

/*Result*/
using res_r = AddHelper<Cont<>, num1_r, num2_r>::Add;
using res = ReverseHelper<Cont<>, res_r>::Reverse;

/*Division and Take Remainder*/
template <typename res, typename num, unsigned int m, unsigned n, unsigned int r=0>
class DivisionHelper;
// specialization 1
template <unsigned int... res, unsigned int val, unsigned int... vals, unsigned int m, unsigned n, unsigned int r>
class DivisionHelper<Cont<res...>, Cont<val, vals...>, m, n, r>
{
public:
	constexpr static unsigned int temp = (val + r * m) % n;
	constexpr static unsigned int val_temp = (val + r * m) / n;
	using Division = DivisionHelper<Cont<res..., val_temp>, Cont<vals...>, m, n, temp>::Division;
	constexpr static unsigned int Remainder = DivisionHelper<Cont<res..., val_temp>, Cont<vals...>, m, n, temp>::Remainder;
};
// specialization 2
template <unsigned int... res, unsigned int m, unsigned n, unsigned int r>
class DivisionHelper<Cont<res...>, Cont<>, m, n, r>
{
public:
	using Division = Cont<res...>;
	constexpr static unsigned int Remainder = r;
};

/*Base Conversion*/
template <typename res, typename rem, unsigned int m, unsigned n, unsigned int r>
class ConversionHelper;
// specialization 1
template <unsigned int... res, unsigned int val, unsigned int... rem, unsigned int m, unsigned int n, unsigned int r>
class ConversionHelper<Cont<res...>, Cont<val, rem...>, m, n, r>
{
public:
	using division = DivisionHelper<Cont<>, Cont<val, rem...>, m, n>::Division;
	constexpr static unsigned int remainder = DivisionHelper<Cont<>, Cont<val, rem...>, m, n>::Remainder;
	using Conversion = ConversionHelper<Cont<remainder, res...>, division, m, n, remainder>::Conversion;
};
// specialization 1
template <unsigned int... res, unsigned int... rem, unsigned int m, unsigned int n, unsigned int r>
class ConversionHelper<Cont<res...>, Cont<0, rem...>, m, n, r>
{
public:
	using Conversion = ConversionHelper<Cont<res...>, Cont<rem...>, m, n, 0>::Conversion;
};
// specialization 3
template <unsigned int... res, unsigned int m, unsigned int n, unsigned int r>
class ConversionHelper<Cont<res...>, Cont<>, m, n, r>
{
public:
	using Conversion = Cont<res...>;
};

// test
using m_to_n = ConversionHelper<Cont<>, num1, 10, 2, 0>::Conversion;

int main()
{
	// 编译期长整数加法
	// 近考虑两个十进制非负整数得相加
	// template<unsigned int...> class Cont;
	// using res=Add<Cont<1,9,9>,Cont<1>>;
	// res : Cont<2,0,0>
	// 容器接收类型类unsigned，数值取值为0-9

	// step1 实现数组翻转元函数，低位位于开头，高位位于结尾
	// step2 实现加法逻辑，结果地位位于开头，高位位于结尾
	// step3 将结果翻转
	// print

	std::cout << "orginal numbers: " << std::endl;
	print<num1>();
	print<num2>();

	std::cout << "reversed numbers: " << std::endl;
	print<num1_r>();
	print<num2_r>();

	std::cout << "reversed result: " << std::endl;
	print<res_r>();

	std::cout << "result: " << std::endl;
	print<res>();

	std::cout << "base conversion: " << std::endl;
	print<m_to_n>();
}
#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

// A ����������а���1�ĸ���
template <int x>
constexpr auto fun = (x % 2) + fun<x / 2>;
// % ��ȡ��
// / �൱��������λ

template <>
constexpr auto fun<0> = 0;

constexpr auto x = fun<99>;

// B ѭ����������
// ��������ģ�������
template <typename...> class arr;
using input = arr<int, char, double, bool, void, float>;
// ģ������
template <typename res, typename rem> // res������ֵ��remΪ�������������
struct imp;
// �ػ�1
template <typename... processed, typename T1, typename T2, typename... Trem>
struct imp<arr<processed...>, arr<T1, T2, Trem...>> // rem���ڵ�������Ԫ��
{
	using t1 = arr<processed..., T1>; // ��T1�Ž����
	using t = typename imp<t1, arr<Trem...>>::t;
};
// �ػ�2
template <typename... processed, typename T1>
struct imp<arr<processed...>, arr<T1>> // remֻ��һ��Ԫ��ʱ���ػ�
{
	using t = arr<processed..., T1>;
};
// �ػ�3
template <typename... processed>
struct imp<arr<processed...>, arr<>>
{
	using t = arr<processed...>; // remΪ��ʱ���ػ�
};
// �������
using output = imp<arr<>, input>::t;

// C ��ȡ��������������Ԫ��
// ģ������
template <typename res, typename rem>
struct imp1;
// �ػ�1 �������3��Ԫ��
template <typename U1, typename U2, typename U3, typename T, typename... Trem>
struct imp1<arr<U1, U2, U3>, arr<T, Trem...>>
{
	using t1 = arr<U2, U3, T>;
	using t = typename imp1<t1, arr<Trem...>>::t;
};
// �ػ�2 �������2��Ԫ��
template <typename U1, typename U2, typename T, typename... Trem>
struct imp1<arr<U1, U2>, arr<T, Trem...>>
{
	using t1 = arr<U1, U2, T>;
	using t = typename imp1<t1, arr<Trem...>>::t;
};
// �ػ�3 �������1��Ԫ��
template <typename U1, typename T, typename... Trem>
struct imp1<arr<U1>, arr<T, Trem...>>
{
	using t1 = arr<U1, T>;
	using t = typename imp1<t1, arr<Trem...>>::t;
};
// �ػ�4 ���Ϊ��
template <typename T, typename... Trem>
struct imp1<arr<>, arr<T, Trem...>>
{
	using t1 = arr<T>;
	using t = typename imp1<t1, arr<Trem...>>::t;
};
// �ػ�5 ����Ϊ��
template <typename... T>
struct imp1<arr<T...>, arr<>>
{
	using t = arr<T...>;
};
// ���
using output2 = imp1<arr<>, input>::t;

int main()
{
	// ѭ������

	// A ��ʾ��������������а���1�ĸ���
	std::cout << x << std::endl;

	// B ʹ�õݹ�ʵ��ѭ��

	// C �κ�һ�ַ�֧����ı�д��ʽ����Ӧ��Ӧ��ѭ�������д��ʽ

	// D ʹ��ѭ���������飺��ȡ������id=0��2��4��6...��Ԫ��
	std::cout << std::is_same_v<output, arr<int, double, void>> << std::endl;
	std::cout << "�����𺳣�����" << std::endl;

	// E ��Ը��ӵ�ʾ������ȡ�������������Ԫ��
	std::cout << std::is_same_v<output2, arr<bool, void, float>> << std::endl;
}
#include <iostream>
#include <vector>
#include <type_traits>

// case 1
template <size_t A>
struct Wrap_ {
	template <size_t ID, typename TDummy=void>
	struct imp
	{
		constexpr static size_t value = ID + imp<ID - 1>::value;
	};

	template <typename TDummy> // Ƕ�׵���ģ�岻����ʹ����ȫ�ػ�������TDummy���Ը�����ɲ����ػ�
	struct imp<0, TDummy>
	{
		constexpr static size_t value = 0;
	};

	template <size_t ID>
	constexpr static size_t value = imp<A + ID>::value;
};

// case 2
using res1 = std::conditional_t<false,
	std::remove_reference_t<int&>,
	std::remove_reference_t<double&>>; // ����ʵ���϶�

// using res = std::remove_reference_t<std::conditional_t<false, int&, double&>>;
using res2 = std::conditional_t<false,
	std::remove_reference<int&>,
	std::remove_reference<double&>>::type; // ����ʵ������
// std::remove_reference<double&> û�з����κ����ݳ�Ա�����Բ��Ὠ��ʵ����

// case 3
template <typename T>
struct Identity
{
	using type = T;
};

using res3 = std::conditional_t<true,
	Identity<double&>,
	std::remove_reference<double&>>::type; // ����ʵ������

// case 4
template <typename T>
constexpr bool intordouble1 = std::is_same_v<T, int> || std::is_same_v<T, double>;
// Ԫ���ʱ�����۵�һ��ֵ�ý������ͻ򶼻�����඼��ֵ

// ����ʹ�� std::conjuction (logical and) std::disjunction (logical or) ����ʵ����
template <typename T>
constexpr bool intordouble2 = std::disjunction_v<std::is_same<T, int>, std::is_same<T, double>>;

// case 5
template <typename... T> class arr;

template <typename T, unsigned id>
struct at;

template <typename Tcur, typename... T, unsigned id>
struct at<arr<Tcur, T...>, id>
{
	using type = typename at<arr<T...>, id - 1>::type;
};

template <typename Tcur, typename... T>
struct at<arr<Tcur, T...>, 0>
{
	using type = Tcur;
};

using res = at<arr<double, float, int, bool>, 2>::type;

int main()
{
	// ����ʵ�����ļ���

	// A ����ʵ������ԭ��
	// ���������ٶȣ����ٱ��������ڴ�
	std::vector<int> a;
	std::vector<int> b; // �ڶ��ι�������Ҫ����Դ���ڵ�һ�ι���
	
    // ���ⲻ�ʺ�Ԫ���
	// Ƕ�׵���ģ����Χ��ģ��ʱ��ͬ��
	std::cout << Wrap_<3>::value<2> << std::endl;
	std::cout << Wrap_<10>::value<2> << std::endl;

	// B ��ؼ���
	// ��ȡ�ظ��߼��Խ���ʵ������
	// conditionalʹ��ʱ����ʵ����
	// ʹ��std::conjunction/std::disjunction�����·�߼�
	std::cout << std::is_same_v<res1, double> << std::endl;
	std::cout << std::is_same_v<res2, double> << std::endl;
	std::cout << std::is_same_v<res3, double&> << std::endl;

	std::cout << intordouble1<int> << std::endl;
	std::cout << intordouble2<int> << std::endl;

	// C ��������
	// ���ٷ�̯���Ӷȵ�����Ԫ�ط��ʲ���
	std::cout << std::is_same_v<res, int> << std::endl;
}
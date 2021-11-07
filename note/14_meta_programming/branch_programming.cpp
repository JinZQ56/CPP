#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

// ���� if constexpr
template <int x>
int fun_if() // �������ڵĺ����������˱����ڵķ�֧
{
	if constexpr (x > 3)
	{
		return x * 2;
	}
	else
	{
		return x * 4;
	}
}

// ����ƫ�ػ������֧
template <int x>
class fun_cla
{
public:
	constexpr static int value = x * 1;
	using type = int;
};

template <>
class fun_cla<5>
{
public:
	const static int value = 5 * 3;
	using type = double;
};

template <int x>
requires (x<=3)
class fun_cla<x>
{
public:
	constexpr static int value = x * 2;
	using type = int;
};

template <int x>
requires (x>3)
class fun_cla<x>
{
public:
	constexpr static int value = x * 4;
	using type = int;
};

// ����conditional�����֧
// ��һ������Ϊtrue�򷵻ص�1�������ͣ����򷵻ص�2������
typedef std::conditional<true, int, double>::type ty1;
typedef std::conditional<false, int, double>::type ty2;

// ���� SFINAE �����֧
// ����ģ��
template <int x, std::enable_if_t<(x <= 3)>* = nullptr> // void*
constexpr auto fun_sfinae()
{
	return x * 2;
}
	
template <int x, std::enable_if_t<(x > 3)>* = nullptr>
constexpr auto fun_sfinae()
{
	return x * 4;
}

// ��ģ��
template<int x, typename = void*>
class cla_sfinae
{
public:
	constexpr static int value = x * 2;
};

template<int x>
class cla_sfinae<x, std::enable_if_t<(x<=3)>*>
{
public:
	constexpr static int value = x * 2;
};

template<int x>
class cla_sfinae<x, std::enable_if_t<(x>3)>*>
{
public:
	constexpr static int value = x * 4;
};

// ������Ԫ����������֧
// ��ֵ�汾
template<int x>
constexpr auto fun_to = (x < 3) ? x * 2 : x * 4;


int main()
{
	// ��֧����
	// A ���� if constexpr �ķ�֧
	// ֻ�ܴ�����ֵ���⣬ͬʱҪС�����������ڼ���
	int x1 = fun_if<5>(); // �γ��˺���
	// �����constexpr����+if�����޷��γɺ���

	// B ���ڣ�ƫ���ػ������֧
	// �����ķ�֧���뷽ʽ�����Ǳ�д����
	using x = fun_cla<5>::type;
	std::cout << std::is_same_v<x, double> << std::endl;

	std::cout << fun_cla<2>::value << std::endl;
	std::cout << fun_cla<5>::value << std::endl;
	std::cout << fun_cla<8>::value << std::endl;


	// C ���� std::conditional �����֧
	// std::conditional<bool b, T, U>
	// bΪtrue����T��bΪfalse����U
	// �﷨�򵥵�Ӧ�ó�������
	std::cout << typeid(ty1).name() << std::endl;
	std::cout << typeid(ty2).name() << std::endl;

	// D ���� SFINAE �����֧
	// ����std::enable_if�����֧���﷨���ӵ�����ǿ��ע������ʡȱģ��ʵ�β��������֧
	// ����std::void_t�����֧��C++17��ͨ������Ч��䡱������֧
	std::cout << fun_sfinae<2>() << std::endl;
	std::cout << fun_sfinae<8>() << std::endl;

	std::cout << cla_sfinae<2>::value << std::endl;
	std::cout << cla_sfinae<8>::value << std::endl; 

	// E ����concept�����֧
	// since C++ 20���������滻enable_if

	// F ������Ԫ����������֧
	// std::conditional����ֵ�汾

}
#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

// Ԫ���
// ex1 Ϊ��������ȥ�����ò����const
template <typename T>
struct str1
{
	using re_ref = typename std::remove_reference<T>::type;
	using con_type = typename std::add_const<re_ref>::type;
};

// ex2 �ж����������ȥ�����ú�ߴ��Ƿ�������������
// �����޶�����ֹ����
template <typename T, unsigned U>
struct str2
{
private:
	using re_ref = typename std::remove_reference<T>::type;

public:
	constexpr static bool value = (sizeof(re_ref) == U);
};

// �������ģ��򻯵��÷�ʽ
template <typename T, unsigned U>
constexpr auto str2_v = str2<T, U>::value;

int main()
{
	// ˳�����ı�д��ʽ

	// A ����ת��ʾ����Ϊ��������ȥ�����ò����const
	str1<int&>::con_type x = 3; // const int x = 3;

	// B �����������ں�����
	// ͨ������ģ���У���ͷ�ļ�����ʽ�ṩ

	// C ����ʾ��
	// ����ֵ�����ͣ�ģ����Ϊ����
	// ����ֵ�����ͣ�ģ����Ϊ���
	constexpr bool res = str2<int&, 4>::value;
	std::cout << res << std::endl;

	// D �����޶�����ֹ����

	// E ͨ������ģ��򻯵��÷�ʽ
	std::cout << str2_v<int&, 4> << std::endl;
}
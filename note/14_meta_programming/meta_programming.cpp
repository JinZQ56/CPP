#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

// ģ��Ԫ����
template <int x>
struct str
{
	constexpr static int val = x + 1;
};

// constexpr����
constexpr int fun(int x)
{
	return x + 1;
}

// ����������
// ���ñ䳤ģ��
template <unsigned... T> struct arr; // ��ֵ����
template <auto... T> struct arr2;
template <typename... T> struct arr3;
template <template<typename> class... T> struct arr4; // ģ������

// �����ڳ�����������ΪԪ�������������
constexpr int c = 3;

int main()
{
	// A Ԫ���
	// ������ݳ���ĳ���
	// �����ڼ���

	// B Ԫ�������ʽ
	// ģ�壬constexpr���������������ڿ�ʹ�õĺ������� sizeof��
	// ͨ���Ժ���Ϊ��λ��Ҳ����Ϊ����ʽ���
	str<3>::val;
	constexpr int x = fun(3);
	int y = sizeof(int);

	// C Ԫ����
	// �����ں����ܹ����պͲ�����Ԫ����
	// ����Ԫ���ݣ���ֵ�����ͣ�ģ��
	// ����

	// D Ԫ���������
	// ���������Ϊ�������������������޷����ı䣬�ͱ������Ա�
	// ���������ڿ��Ա�����
	// �����޸����ã�������ͬ����������ͬ�����

	// E type_traitsԪ��̿�
	// since C++ 11
}
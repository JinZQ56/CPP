#pragma once
#include <iostream>
#include <vector>
#include <string>

// ģ��Ķ���
template <typename T>
void fun_h(T x)
{
	std::cout << "template in hearder: " << x << std::endl;
}

// ��ģ�������ʽʵ����
template void fun_h<int>(int x);
template void fun_h(std::string x);

#pragma once
#include <iostream>
#include <vector>
#include <string>

// 模板的定义
template <typename T>
void fun_h(T x)
{
	std::cout << "template in hearder: " << x << std::endl;
}

// 对模板进行显式实例化
template void fun_h<int>(int x);
template void fun_h(std::string x);

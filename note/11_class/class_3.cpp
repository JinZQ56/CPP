#include <iostream>
#include <vector>
#include <string>

class cla
{
public:
	// 缺省构造函数
	// cla() = deault;
	cla()
	{
		std::cout << "constructor is called" << std::endl;
 	}
	// 拷贝构造函数
	cla(const cla&) = default;
	// 移动构造函数
	cla(cla&&) noexcept = default;

	// 构造函数
	cla(int val, const std::string& str)
		: x(val)
		, s(str)
	{}

	// 拷贝赋值函数
	cla& operator= (const cla& c)
	{
		// 判断自身赋值
		if (&c == this)
		{
			std::cout << "dummy assigment" << std::endl;
			return *this;
		}
		std::cout << "copy assigment is called" << std::endl;
		x = c.x;
		s = c.s;
		return *this;
	}

	// 移动赋值函数
	cla& operator= (cla&& c)
	{
		// 判断自身赋值（不知道怎么体现移动赋值）
		if (&c == this)
		{
			std::cout << "dummy assigment" << std::endl;
			return *this;
		}

		// 当类包含指针时
		// delete ptr； //删除原有的ptr
		// ptr = x.ptr;
		// x.ptr = nullptr
		// 以上方法不适用于自身赋值的情况

		std::cout << "move assigment is called" << std::endl;
		x = std::move(c.x);
		s = std::move(c.s);
		return *this;
	}
	
	// 析构函数
	// ~cla() noexcept = default;
	~cla()
	{
		std::cout << "destructor is called" << std::endl;
	}

	// 成员函数
	void print()
	{
		std::cout << "x=" << x << " " << "s=" << s << std::endl;
	}

private:
	int x = 0;
	std::string s = "abc";
	// int* ptr;

};

class ccla
{
public:
	// 当没有定义其它构造函数时，编译器会自动合成拷贝赋值和移动赋值函数
	int x = 0;
	std::string s = "abc";

	void print()
	{
		std::cout << "x=" << x << " " << "s=" << s << std::endl;
	}
};

int main()
{
	// A 拷贝赋值与移动赋值函数
	// operator= 
	// 实际为运算符重载
	// 赋值函数不能使用初始化列表
	// 通常返回当前类型的引用 为了适用于 c3 = c2 = c1
	std::cout << "--------------------" << std::endl;
	cla c1(1,"asd");
	cla c2;
	c2 = c1;
	c1.print();
	c2.print();

	cla c3;
	c3 = std::move(c2);
	c2.print();
	c3.print();

	c3 = c3;
	c3.print();

	// 系统自动合成拷贝赋值和移动赋值
	ccla cc1;
	cc1.x = 1;
	cc1.s = "asd";
	ccla cc2;
	cc2 = cc1;
	cc1.print();
	cc2.print();

	// B 析构函数
	// destructor
	// ~当前类型，无参数，无返回值
	// 用于释放资源
	// 内存回收是在调用完析构函数时才进行
	// 内存回收和析构函数是两个概念 
	// 除非显式声明，否则比那一起会自动合成，其内部逻辑时平凡的
	// 析构函数不能抛出异常
	// 编译器会自动完成内存的分配与销毁，或者手动操作
	std::cout << "--------------------" << std::endl;
	cla* ccc = new cla(); // 先分配内存再调用构造函数
	// 显示的内存创建必须进行显示的内存回收
	delete ccc; // 先调用析构函数再进行内存回收
	// new 配合 delete
	// malloc 配合 free 仅分配内存 没有类型和大小

}
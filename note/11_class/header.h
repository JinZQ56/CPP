
struct str4
{
	// 静态成员的类内初始化
	const static int array_size = 100;
	int buffer[array_size];
};

struct str5
{
	// 内联静态成员初始化 since c++ 17
	// int处可以换成auto
	inline const static int array_size = 100;
	int buffer[array_size];
};


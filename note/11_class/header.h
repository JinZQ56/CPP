
struct str4
{
	// ��̬��Ա�����ڳ�ʼ��
	const static int array_size = 100;
	int buffer[array_size];
};

struct str5
{
	// ������̬��Ա��ʼ�� since c++ 17
	// int�����Ի���auto
	inline const static int array_size = 100;
	int buffer[array_size];
};


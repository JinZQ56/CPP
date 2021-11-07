#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

void fun0()
{
	//����������˳�������ļ���ͬ
	std::vector<int> v{ 5,6,7 };
	std::cout << v[0] << std::endl;

	std::map<char, int> m{ {'a', 1},{'b', 2} };
	std::cout << m['a'] << std::endl;

	//C++�ж�����8�ֹ�������
	//��һ�ࣺʹ�ú����ʵ�֣�set��map��multiset��multimap
	//�ڶ��ࣺʹ��hash��ʵ�֣�unordered_xxx
}

struct st
{
	int x;

	bool operator==(const st& val) const
	{
		return (this->x == val.x);
	}
};

bool st_comp(const st& val1, const st& val2)
{
	return val1.x < val2.x;
}

void fun_set()
{
	//������Ԫ�ص�˳�򲢲���Ҫ��Ԫ�ز����ظ�
	std::set<int> s{ 6,4,2,8 };
	for (auto ptr = s.begin(); ptr != s.end(); ++ptr)
	{
		std::cout << *ptr << ' ';
	}
	std::cout << std::endl;

	//ͨ����set�е�Ԫ����Ҫ֧�ֱȽϴ�С
	//�����Զ���Ƚ���
	std::set<int, std::greater<int>> s1{ 6,4,2,8 };
	for (auto ptr = s1.begin(); ptr != s1.end(); ++ptr)
	{
		std::cout << *ptr << ' ';
	}
	std::cout << std::endl;

	std::set<st, decltype(&st_comp)> s2({ st{3}, st{4}, st{8} }, st_comp);
	for (auto ptr = s2.begin(); ptr != s2.end(); ++ptr)
	{
		std::cout << (*ptr).x << ' ';
	}
	std::cout << std::endl;
	std::cout << typeid(st_comp).name() << std::endl;
	std::cout << typeid(&st_comp).name() << std::endl;

	//����Ԫ��
	s2.insert(st{ 10 });
	s2.emplace(st{ 20 }); //�������ݵ��ƶ��͸���
	auto ptr_h = s2.end();
	s2.emplace_hint(ptr_h, st{ 30 }); //��ʾ���ݴ�Լ��������룬���������ٶȣ�ͨ��������������ʾ
	for (auto ptr = s2.begin(); ptr != s2.end(); ++ptr)
	{
		std::cout << (*ptr).x << ' ';
	}
	std::cout << std::endl;

	//ɾ��Ԫ��
	//����key���ߴ��������
	s2.erase(st{ 20 });
	s2.erase(s2.begin());

	//����Ԫ��
	//����ͨ��[]����Ԫ�أ�����ʹ��find��count��contains
	//����ָ�����ֵ�ĵ���������û�ҵ��򷵻�end������
	auto ptr_f = s2.find(st{ 8 });
	std::cout << (*ptr_f).x << std::endl;
	//since C++20 set����contains���� ���Դ��boolֵ
	//std::cout << s.contains(st{ 8 }) << std::endl;

	//�޸�Ԫ��
	//set������ָ��konst������ͨ���������޸� 
	//ʹ��erase()+insert()������ͬ��Ч��������extractЧ�ʸ���
	auto n = s2.extract(st{ 4 });
	n.value() = st{ 5 };
	s2.insert(std::move(n));
	for (auto ptr = s2.begin(); ptr != s2.end(); ++ptr)
	{
		std::cout << (*ptr).x << ' ';
	}
	std::cout << std::endl;
}

void fun_map()
{
	//�����ÿ���ڵ���pair������key��value
	//key��Ҫ֧�ֱȽϲ���
	std::map<int, bool> m{ {2,false},{1,true},{3,false} };
	for (auto ptr = m.begin(); ptr != m.end(); ++ptr)
	{
		auto p = *ptr; //std::pair<const int, bool>;
		std::cout << p.first << ' ' << p.second << std::endl;
	}
	for (auto p : m)
	{
		std::cout << p.first << ' ' << p.second << std::endl;
	}
	for (auto [k, v] : m) //ʹ�ÿ����ķ�ʽ��ȡ���
	{
		std::cout << k << ' ' << v << std::endl;
	}

	//��������set�Զ���ȽϺ���

	//��Ҫ����pair
	m.insert(std::pair<int, bool>(4, true));
	m.insert({ 5,false });
	//ɾ��Ԫ��key
	m.erase(2);
	
	//����Ԫ��
	//find����pair��iteritor
	auto i = m.find(5);
	std::cout << i->first << ' ' << i->second << std::endl;
	std::cout << (*i).first << ' ' << (*i).second << std::endl;

	//contains����bool(since C++20)
	//std::cout << m.contains(5) << std::endl;

	// []��at,��û���ҵ�ʱ��at���׳��쳣
	// [key]�����ڵĻ���������µĽڵ㣬�ڵ��keyʱ[]�е�key
	// ֵ���ʱclass�Ļ���ȱʡ��ʼ���� ���������0��ʼ��
	std::cout << m[4] << std::endl;
	std::cout << m[100] << std::endl;
	std::cout << m.at(4) << std::endl; 
	for (auto [k, v] : m) //ʹ�ÿ����ķ�ʽ��ȡ���
	{
		std::cout << k << ' ' << v << std::endl;
	}

	std::cout << "ʹ�õ���������value:" << std::endl;
	auto ptr = m.find(5);
	ptr->second = true;
	for (auto [k, v] : m) //ʹ�ÿ����ķ�ʽ��ȡ���
	{
		std::cout << k << ' ' << v << std::endl;
	}
}

void fun_multixxx()
{
	//��set��map���ƣ��������ظ���ֵ���
	//����Ҳ�Ǻ����
	//������������ıȽ���
	std::multiset<int> ms{ 1, 2, 3, 1 };
	for (auto i : ms)
	{
		std::cout << i << std::endl;
	}

	//Ԫ�ط���
	//find�����ҵ����׸�Ԫ��
	auto ptr = ms.find(1);
	std::cout << *ptr << std::endl;
	std::cout << *(++ptr) << std::endl;
	std::cout << *(++ptr) << std::endl;
	//count����Ԫ�ظ���
	std::cout << ms.count(1) << std::endl;
	//���ز�������
	auto lb = ms.lower_bound(1);
	auto ub = ms.upper_bound(1);
	for (auto ptr = lb; ptr != ub; ++ptr)
	{
		std::cout << *ptr << std::endl;
	}
	auto r = ms.equal_range(1); //����std::pair,��Ӧlb��ub
	//auto [l,u] = ms.equal_range(1); 
	//����ʹ�ð󶨵ķ�ʽ
	for (auto ptr = r.first; ptr != r.second; ++ptr)
	{
		std::cout << *ptr << std::endl;
	}
}

size_t st_hash(const st& val)
{
	return val.x;
}

bool st_equal(const st& val1, const st& val2)
{
	return (val1.x == val2.x);
}

class MyHash {
public:
	size_t operator() (const st& val) const
	{
		return val.x;
	}
};

//including unordered_set, unordered_map, unordered_multiset, unordered_multimap
void fun_unordered_xxx()
{
	//ʹ��hash��ʵ��
	//����Ҫ���㣺����ת��Ϊhashֵ���е�
	std::unordered_set<int> us1{ 4,3,1,5,4,1 };
	std::unordered_set<int> us2{ 4,3,1,5,4,1 };
	for (auto p : us1)
	{	
		std::cout << p << ' ';
	}
	std::cout << std::endl;

	//unorderded_xxx��֧�ֳ�==��!=���������������
	//�����ʵ�ֵ�����֧������������
	std::set<int> s1{ 2,4,5,7 };
	std::set<int> s2{ 3,6,8,9 };
	std::cout << "set�жϴ�С�� ";
	std::cout << (s1 < s2) << std::endl;
	std::cout << "unordered_set�ж���ȣ� ";
	std::cout << (us1 == us2) << std::endl;

	//�Զ���hash�������еȺ���
	std::unordered_set<st, decltype(&st_hash), decltype(&st_equal)> us_st(1, st_hash, st_equal);
	us_st.insert(st{ 2 });
	us_st.insert(st{ 4 });
	for (auto p : us_st)
	{
		std::cout << p.x << ' ';
	}
	std::cout << std::endl;

	std::unordered_set<st, MyHash> us_st1;
	us_st1.insert(st{ 1 });
	us_st1.insert(st{ 5 });
	for (auto p : us_st1)
	{
		std::cout << p.x << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	//fun_set();
	//fun_map();
	//fun_multixxx();
	fun_unordered_xxx();
}
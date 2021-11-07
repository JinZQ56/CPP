#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

void fun0()
{
	//关联容器与顺序容器的键不同
	std::vector<int> v{ 5,6,7 };
	std::cout << v[0] << std::endl;

	std::map<char, int> m{ {'a', 1},{'b', 2} };
	std::cout << m['a'] << std::endl;

	//C++中定义了8种关联容器
	//第一类：使用红黑树实现，set、map、multiset、multimap
	//第二类：使用hash表实现，unordered_xxx
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
	//集合中元素的顺序并不重要，元素不能重复
	std::set<int> s{ 6,4,2,8 };
	for (auto ptr = s.begin(); ptr != s.end(); ++ptr)
	{
		std::cout << *ptr << ' ';
	}
	std::cout << std::endl;

	//通常，set中的元素需要支持比较大小
	//可以自定义比较器
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

	//插入元素
	s2.insert(st{ 10 });
	s2.emplace(st{ 20 }); //避免数据的移动和复制
	auto ptr_h = s2.end();
	s2.emplace_hint(ptr_h, st{ 30 }); //提示数据大约在哪里插入，提升插入速度，通过迭代器进行提示
	for (auto ptr = s2.begin(); ptr != s2.end(); ++ptr)
	{
		std::cout << (*ptr).x << ' ';
	}
	std::cout << std::endl;

	//删除元素
	//传入key或者传入迭代器
	s2.erase(st{ 20 });
	s2.erase(s2.begin());

	//访问元素
	//不能通过[]访问元素，可以使用find，count，contains
	//返回指向查找值的迭代器，若没找到则返回end迭代器
	auto ptr_f = s2.find(st{ 8 });
	std::cout << (*ptr_f).x << std::endl;
	//since C++20 set包含contains函数 可以打出bool值
	//std::cout << s.contains(st{ 8 }) << std::endl;

	//修改元素
	//set迭代器指向konst，不能通过迭代器修改 
	//使用erase()+insert()具有相同的效果，但是extract效率更高
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
	//红黑树每个节点是pair，包含key和value
	//key需要支持比较操作
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
	for (auto [k, v] : m) //使用拷贝的方式获取结果
	{
		std::cout << k << ' ' << v << std::endl;
	}

	//可以类似set自定义比较函数

	//需要插入pair
	m.insert(std::pair<int, bool>(4, true));
	m.insert({ 5,false });
	//删除元素key
	m.erase(2);
	
	//访问元素
	//find返回pair的iteritor
	auto i = m.find(5);
	std::cout << i->first << ' ' << i->second << std::endl;
	std::cout << (*i).first << ' ' << (*i).second << std::endl;

	//contains返回bool(since C++20)
	//std::cout << m.contains(5) << std::endl;

	// []和at,当没有找到时，at会抛出异常
	// [key]不存在的话，会插入新的节点，节点的key时[]中的key
	// 值如果时class的话会缺省初始化， 其它情况用0初始化
	std::cout << m[4] << std::endl;
	std::cout << m[100] << std::endl;
	std::cout << m.at(4) << std::endl; 
	for (auto [k, v] : m) //使用拷贝的方式获取结果
	{
		std::cout << k << ' ' << v << std::endl;
	}

	std::cout << "使用迭代器更改value:" << std::endl;
	auto ptr = m.find(5);
	ptr->second = true;
	for (auto [k, v] : m) //使用拷贝的方式获取结果
	{
		std::cout << k << ' ' << v << std::endl;
	}
}

void fun_multixxx()
{
	//与set、map类似，但允许重复的值或键
	//本质也是红黑树
	//可以引入独立的比较器
	std::multiset<int> ms{ 1, 2, 3, 1 };
	for (auto i : ms)
	{
		std::cout << i << std::endl;
	}

	//元素访问
	//find返回找到的首个元素
	auto ptr = ms.find(1);
	std::cout << *ptr << std::endl;
	std::cout << *(++ptr) << std::endl;
	std::cout << *(++ptr) << std::endl;
	//count返回元素个数
	std::cout << ms.count(1) << std::endl;
	//返回查找区间
	auto lb = ms.lower_bound(1);
	auto ub = ms.upper_bound(1);
	for (auto ptr = lb; ptr != ub; ++ptr)
	{
		std::cout << *ptr << std::endl;
	}
	auto r = ms.equal_range(1); //返回std::pair,对应lb和ub
	//auto [l,u] = ms.equal_range(1); 
	//可以使用绑定的方式
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
	//使用hash表实现
	//键需要满足：可以转换为hash值，判等
	std::unordered_set<int> us1{ 4,3,1,5,4,1 };
	std::unordered_set<int> us2{ 4,3,1,5,4,1 };
	for (auto p : us1)
	{	
		std::cout << p << ' ';
	}
	std::cout << std::endl;

	//unorderded_xxx不支持除==和!=外的容器级的运算
	//红黑树实现的容器支持容器级运算
	std::set<int> s1{ 2,4,5,7 };
	std::set<int> s2{ 3,6,8,9 };
	std::cout << "set判断大小： ";
	std::cout << (s1 < s2) << std::endl;
	std::cout << "unordered_set判断相等： ";
	std::cout << (us1 == us2) << std::endl;

	//自定义hash函数和判等函数
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
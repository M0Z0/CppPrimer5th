//#include <memory.h>
#include <vector>
#include <iostream>

//using namespace std;

//vector<int> func()
//{
//	vector<int> vi = { 0, 1, 2 };
//	return vi;
//}

std::vector<int>* new_vector(void)
{
	return new (std::nothrow)std::vector<int>;
}

void read_ints(std::vector<int> *pv)
{
	int v;

	//while (cin>>v)
	//	pv->push_back(v);
	for (int i = 0; i < 10; i++)
	{
		pv->push_back(i);
	}
}

void print_ints(std::vector<int> *pv)
{
	for (const auto &v : *pv)
		std::cout << v << "";
	std::cout << std::endl;
}




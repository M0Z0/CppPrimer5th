#include <iostream>
#include <vector>
//memory与memory.h不一样！！！
#include <memory>

using namespace std;

shared_ptr<vector<int>> new_vector(void)
{
	return make_shared<vector<int>>();
}

void read_ints(shared_ptr<vector<int>> pv)
{
	int v;

	for (int i = 0; i < 10; i++)
	{
		pv->push_back(i);
	}
}

void print_ints(shared_ptr<vector<int>> pv)
{
	for (const auto &v : *pv)
		std::cout << v << "";
	std::cout << std::endl;
}




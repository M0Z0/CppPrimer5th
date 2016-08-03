#include <vector>
#include <iostream>
#include <string>

using namespace std;
//行为像值得类
class HasPtr{
	friend void swap(HasPtr &lhs, HasPtr &rhs);
public:
	HasPtr(string &s = string()) : ps(new string(s)), i(0) { }
	HasPtr(const HasPtr &p) : ps(new string(*(p.ps))), i(p.i) { }
	HasPtr& operator=(const HasPtr &);
	~HasPtr() { delete ps; }
	string& operator*() { return *ps; }

private:
	string *ps;
	int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	auto newp = new string(*(rhs.ps));
	delete ps;
	ps = newp;
	i = rhs.i;
	return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	cout << "交换" << *lhs.ps << "和" << *rhs.ps << endl;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}
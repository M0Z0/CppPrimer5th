#include <vector>
#include <iostream>
#include <string>

using namespace std;
//行为像指针的类
class HasPtr{
public:
	HasPtr(string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) { }
	HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
	HasPtr& operator=(const HasPtr &);
	~HasPtr() { delete ps; }

private:
	string *ps;
	int i;
	size_t *use;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	auto newp = new string(*(rhs, ps));
	delete ps;
	ps = newp;
	i = rhs.i;
	return *this;
}
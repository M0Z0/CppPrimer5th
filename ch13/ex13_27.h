#include <vector>
#include <iostream>
#include <string>

using namespace std;
//行为像指针的类
class HasPtr{
	friend void swap(HasPtr&, HasPtr&);
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

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	swap(lhs.use, rhs.use);
}
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	++*rhs.use;
	if (--*(this->use) == 0)
	{
		delete ps;
		delete use;
	}
	i = rhs.i;
	ps = rhs.ps;
	use = rhs.use;
	return *this;
}
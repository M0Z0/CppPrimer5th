#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using namespace std;

class StrBlobPtr;

class StrBlob
{
	friend class StrBlobPtr;
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	//元素访问
	string& front();
	const string& front() const;
	string& back();
	const string& back() const;

	StrBlobPtr begin();
	StrBlobPtr end();

private:
	shared_ptr<vector<string>> data;
	//如果data[i]不合法，抛出一个异常
	void check(size_type i, const std::string &msg) const;

};

inline StrBlob::StrBlob() : data(make_shared<vector<string>>()) { }   //make_shared<vector<string>>()后面的括号一定要有！！！！！！！！！
inline StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) { }

inline void StrBlob::check(size_type i, const std::string &msg) const
{
	if (i > data->size())
		throw out_of_range(msg);
}

inline string& StrBlob::front()
{
	check(0, "empty");
	return data->front();
}

inline const string& StrBlob::front() const
{
	check(0, "empty");
	return data->front();
}

inline string& StrBlob::back()
{
	check(0, "empty");
	return data->back();
}

inline const string& StrBlob::back() const
{
	check(0, "empty");
	return data->back();
}

inline void StrBlob::pop_back()
{
	check(0, "empty");
	return data->pop_back();
}

class StrBlobPtr{
	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
public:
	StrBlobPtr() :curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) { }

	string& deref() const;
	StrBlobPtr& incr();
	StrBlobPtr& decr();

private:
	shared_ptr<vector<string>> check(size_t, const string&) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};

inline 
shared_ptr<vector<string>>
StrBlobPtr::check(size_t i, const string& msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

inline string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

//前缀递增
inline StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

//前缀递减
inline StrBlobPtr& StrBlobPtr::decr()
{
	--curr;
	check(-1, "increment past end of StrBlobPtr");
	return *this;
}

inline StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

inline
bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock();
	auto r = rhs.wptr.lock();
	if (l == r)
	{
		return (!r || lhs.curr == rhs.curr);
	}
	else{
		return false;
	}
}

inline
bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !eq(lhs, rhs);
}
#endif
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
	StrBlob(vector<string> *p);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	//Ԫ�ط���
	string& front();
	const string& front() const;
	string& back();
	const string& back() const;

	StrBlobPtr begin();
	StrBlobPtr end();

private:
	shared_ptr<vector<string>> data;
	//���data[i]���Ϸ����׳�һ���쳣
	void check(size_type i, const std::string &msg) const;

};

inline StrBlob::StrBlob(): data(make_shared<vector<string>>) { }
inline StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) { }
inline StrBlob::StrBlob(vector<string> *p) : data(p) { }

inline void StrBlob::check(size_type i, const std::string &msg) const
{
	if (i > data->size())
		throw out_of_range(msg);
}

#endif
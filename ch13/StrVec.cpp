#include "StrVec.h"


StrVec::StrVec(const StrVec &s)
{
	auto newVec = alloc_n_copy(s.begin(), s.end());
	elements = newVec.first;
	first_free = cap = newVec.second;
}

StrVec& StrVec::operator=(const StrVec &s)
{
	auto newVec = alloc_n_copy(s.begin(), s.end());
	free();
	elements = newVec.first;
	first_free = cap = newVec.second;
	return *this;
}

StrVec::~StrVec()
{
	free();
}

void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*> 
StrVec::alloc_n_copy(const std::string* begin, const std::string* end)
{
	auto data = alloc.allocate(end - begin);
	return {data, uninitialized_copy(begin, end, data)};
}

void StrVec::free()
{
	if (elements)
	{
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
{
	auto newCapcity = size() ? 2 * size() : 1;
	this->alloc_n_move(newCapcity);
}

void StrVec::alloc_n_move(size_t newCap)
{
	auto newData = alloc.allocate(newCap);
	auto dest = newData;
	auto ele = this->elements;
	for (int i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(ele));
	free();
	this->elements = newData;
	this->first_free = dest;
	this->cap = this->elements + newCap;
}

void StrVec::reserve(size_t new_cap)
{
	if (new_cap <= capacity()) return;
	alloc_n_move(new_cap);
}

void StrVec::resize(size_t count)
{
	resize(count, std::string());
}

void StrVec::resize(size_t count, const std::string& s)
{
	if (count > size()) {
		if (count > capacity()) reserve(count * 2);
		for (size_t i = size(); i != count; ++i)
			alloc.construct(first_free++, s);
	}
	else if (count < size()) {
		while (first_free != elements + count) alloc.destroy(--first_free);
	}
}

StrVec::StrVec(std::initializer_list<std::string> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

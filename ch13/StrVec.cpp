#include "StrVec.h"


StrVec::StrVec(const StrVec &s)
{
	auto newVec = alloc_n_copy(s.begin(), s.end());
	elements = newVec.first;
	first_free = cap = newVec.second;
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
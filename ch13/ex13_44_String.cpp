#include "ex13_44_String.h"
#include <iostream>
#include <algorithm>

std::pair<char*, char*> String::alloc_n_copy(const char* first, const char* last)
{
	auto newPtr = alloc.allocate(last - first);
	return{ newPtr, std::uninitialized_copy(first, last, newPtr) };
}

void String::range_initializer(const char* first, const char* last)
{
	auto newstr = alloc_n_copy(first, last);
	element = newstr.first;
	end = newstr.second;
}

String::String(const char* str)
{
	auto tmp = const_cast<char*>(str);
	while (*tmp) ++tmp;
	this->range_initializer(str, ++tmp);
}

String::String(const String& rhs)
{
	range_initializer(rhs.element, rhs.end);
	std::cout << "copy constructor" << std::endl;
}

void String::free()
{
	if (element)
	{
		std::for_each(element, end, [this](char& c) { alloc.destroy(&c); });
		alloc.deallocate(element, end - element);
	}
}

String::~String()
{
	free();
}

String& String::operator=(const String& rhs)
{
	auto newstr = alloc_n_copy(rhs.element, rhs.end);
	free();
	element = newstr.first;
	end = newstr.second;
	std::cout << "copy-assignment" << std::endl;
	return *this;
}
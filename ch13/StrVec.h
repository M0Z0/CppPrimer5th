#include <iostream>
#include <memory.h>

class StrVec{
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }

private:
	static std::allocator<std::string> alloc;
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};
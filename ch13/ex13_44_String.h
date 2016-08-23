#ifndef CP5_STRING_H__
#define CP5_STRING_H__

#include <memory>

class String{
public:
	String() : String("") { }
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

	const char* c_str() const { return element; }
	size_t size() const { return end - element; }
	size_t length() const { return end - element - 1; }

private:
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void range_initializer(const char*, const char*);
	void free();
	char* element;
	char* end;
	std::allocator<char> alloc;
};

#endif
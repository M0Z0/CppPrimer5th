#include <iostream>
#include <memory.h>

class StrVec{
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
	StrVec(const StrVec&);
	StrVec(std::initializer_list<std::string>);
	StrVec& operator=(const StrVec&);
	~StrVec();
	void push_back(const std::string&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - first_free; }
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }

private:
	static std::allocator<std::string> alloc;
	std::string *elements;
	std::string *first_free;
	std::string *cap;

	inline void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	void free();
	void reallocate();
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void alloc_n_move(size_t newCap);

	void reserve(size_t newCap);
	void resize(size_t count);
	void resize(size_t count, const std::string&);
};
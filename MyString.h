#include<iostream>
using namespace std;

class MyString
{ 
	friend	ostream &operator << (ostream& os, const MyString& str);
	friend	ostream &operator >> (ostream& is, const MyString& str);
public:
	MyString();
	MyString(char* const s, size_t len);
	MyString(const char* s); 
	MyString(const MyString& s);

	MyString& operator=(const MyString& str);
	MyString& operator=(const char*);

	
	//Element access
	const char& back() const;
	const char& front() const;
	char& at(unsigned pos) ;

	//Capacity
	bool empty() const;
	int size();
	int capacity();

	//Operations
	void clear();
	MyString& erase(size_t index, size_t count);
	void resize(size_t count);
	char *copy(char* dest,	size_t count) const;
	//MyString& insert(size_t index, size_t count, char ch);

	//Non-member functions
	friend MyString operator +(const MyString& lhs, const MyString& rhs);
	friend MyString operator +(const char* lhs, const MyString& rhs);
	friend MyString operator +(const MyString& lhs, const char* rhs);
	friend MyString operator +(const MyString& lhs, const char rhs);

	friend bool operator==(const MyString& lhs, const MyString& rhs);
	friend bool operator!=(const MyString& lhs, const MyString& rhs);
	friend bool operator<(const MyString& lhs, const MyString& rhs);
	friend bool operator<=(const MyString& lhs, const MyString& rhs);
	friend bool operator>(const MyString& lhs, const MyString& rhs);
	friend bool operator>=(const MyString& lhs, const MyString& rhs);

private:
	char *data_;
	size_t len_;
	int length;
	size_t npos;
};

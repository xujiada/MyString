#include "MyString.h"

ostream& operator << (ostream& os, const MyString& str)
{
	os << str.data_;
	return os;
}

istream& operator>> (istream& is, MyString& str)
{
	char input[255];
	is >> input;
	str = input;
	return is;
}

MyString::MyString() :data_(new char[1])
{
	*data_ = '\0';
}
MyString::MyString(const char* s) : data_(new char[strlen(s) + 1])
{
	strcpy(data_, s);
}
MyString::MyString(const MyString &s)
{
	data_ = s.data_;
	int len = strlen(data_);
	data_[len + 1] += 1;
}
MyString::MyString(char* const s, size_t len)
{

	if (!s)
	{
		len_ = 0;
		data_ = NULL;
	}
	else
	{
		len_ = (strlen(s) > len) ? len : strlen(s);
		data_ = new char[len_ + 1];
		strcpy(data_, s);
		data_[len + 1] = '\0';
	}
}

MyString& MyString::operator=(const MyString& s)
{
	data_ = s.data_;
	int len = strlen(data_);
	data_[len + 1] += 1;
	return *this;
}

MyString& MyString::operator=(const char* s)
{

	this->length = strlen(s);
	delete[] this->data_;
	this->data_ = new char[this->length + 1];
	strcpy(this->data_, s);
	return *this;
}

const char& MyString::front() const
{
	return data_[0];
}

const char& MyString::back() const
{
	return data_[strlen(data_ + 1)];
}

char& MyString::at(unsigned pos) 
{
	if (pos < data_[strlen(data_ + 1)])
		return data_[pos];
	else
		std::cout << "out_of_range" << std::endl;
}

int MyString::size()
{
	return strlen(data_);
}
int MyString::capacity()
{
	return data_[strlen(data_ + 1)];
}

bool MyString::empty() const
{
	if (*data_ == '\0') return true;
	return false;
}

void MyString::clear()
{
	delete[] data_;
	data_ = new char[1];
	data_[0] = '\0';
}

MyString& MyString::erase(size_t index, size_t count)
{
	int i;
	int pos = strlen(data_);
	for (i = index; i < pos - count + 1; i++)
	{
		data_[i] = data_[i + count];
	}
	data_[++i] = '\0';
	return *this;
}

void MyString::resize(size_t count)
{
	int pos = strlen(data_);
	erase(count, pos);
}

char *MyString::copy(char* dest, size_t count) const
{
	int i;
	strcpy(dest, data_);
	dest[count] = '\0';
	return dest;
}

/*MyString& MyString::insert(size_t index, size_t count, char ch)
{
size_t pos = strlen(data_), i;
char ret[100];
copy(ret, index);
for (i = index; count != 0; count--,i++)
{
ret[i] == ch;
}
++i;
for (; index < pos; index++,i++)
{
ret[i] = data_[index];
}
//strcpy(data_, ret);
return *this;
}*/

MyString operator +(const MyString& lhs, const MyString& rhs)
{
	MyString tmp;
	int len = strlen(lhs.data_) + strlen(rhs.data_);
	tmp.data_ = new char[len + 2];
	strcpy(tmp.data_, lhs.data_);
	strcat(tmp.data_, rhs.data_);
	tmp.data_[len + 1] = '1';
	return tmp;
}

MyString operator +(const char* lhs, const MyString& rhs)
{
	MyString tmp;
	int len = strlen(lhs) + strlen(rhs.data_);
	tmp.data_ = new char[len + 2];
	strcpy(tmp.data_, lhs);
	strcat(tmp.data_, rhs.data_);
	tmp.data_[len + 1] = '1';
	return tmp;
}

MyString operator +(const MyString& lhs, const char* rhs)
{
	MyString tmp;
	int len = strlen(lhs.data_) + strlen(rhs);
	tmp.data_ = new char[len + 2];
	strcpy(tmp.data_, lhs.data_);
	strcat(tmp.data_, rhs);
	tmp.data_[len + 1] = '1';
	return tmp;
}

MyString operator +(const MyString& lhs, const char rhs)
{
	MyString tmp;
	int len = strlen(lhs.data_) + strlen(&rhs);
	tmp.data_ = new char[len + 2];
	strcpy(tmp.data_, lhs.data_);
	strcat(tmp.data_, &rhs);
	tmp.data_[len + 1] = '1';
	return tmp;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return (strcmp(lhs.data_, rhs.data_) == 0);
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return (strcmp(lhs.data_, rhs.data_) != 0);
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return (strcmp(lhs.data_, rhs.data_) < 0);
}
bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return (strcmp(lhs.data_, rhs.data_) <= 0);
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return (strcmp(lhs.data_, rhs.data_) > 0);
}
bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return (strcmp(lhs.data_, rhs.data_) >= 0);
}

# MyString
==
该项目主要是根据C++ reference里的Strings library来实现（http://en.cppreference.com/w/cpp/string/basic_string）

实现过程中遇到的问题有：<br>
1.在实现'<<'时，写成 MyString &operator << (ostream& os, const MyString& str);
  而不是ostream &operator << (ostream& os, const MyString& str);
  导致发生错误。
 
 2.未初始化导致出现问题
 
 3.一开始使用模板实现，结果还是存在很多不熟练，最后放弃使用模板。。。
 
 4.*this
 
 5.*data_ = '\0' 和 data_ = '\0'
 
 6.MyString operator +(const MyString& lhs, const MyString& rhs);是参考网上的实现
 
 7.还有一些函数未实现

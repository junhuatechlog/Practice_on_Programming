#include "MyString.h"

MyString MyString::operator()(int i, int j){
	return MyString ((*this).substr(i, j).c_str());
}

MyString  MyString::operator+(const MyString &ms){
	string s1, s2;
	string s;
	s1 = ms; s2 = *this;
	s = s2 + s1;
	return MyString(s.c_str());
}

MyString  MyString::operator + (const char *ptr){
	string s1 = (*this);
	string s2(ptr);
	return MyString((s1 + s2).c_str());
}

MyString operator+(const char *ptr, const MyString &ms){
	string s1 = ms;
	string s2(ptr);
	return MyString((s2+s1).c_str());
}

ostream & operator<< (ostream& o, const MyString & ms){
	string s = ms;
	o << s.c_str();
	return o;
}

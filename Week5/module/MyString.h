#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class MyString : public string{

public:
	MyString(const char *s): string(s){

	}

	MyString() : string(){

	}

	MyString(const char c) : string(1, c){

	}

	MyString(const MyString & ms){
		*this = ms;
		//string(s);
	}

	MyString  operator()(int i, int j);
	MyString  operator+(const MyString &ms);
	MyString  operator+(const char *ptr);
	MyString  operator=(const char c);
	
	friend MyString  operator+(const char *ptr, const MyString &ms);
	friend ostream & operator<<(ostream & o, const MyString & ms);
};

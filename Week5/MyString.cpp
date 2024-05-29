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

	MyString operator()(int i, int j);
	MyString  operator+(const MyString &ms);
	MyString  operator+(const char *ptr);
	MyString  operator=(const char c);
	
	friend ostream & operator<<(ostream & o, const MyString & ms);
};

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

MyString  MyString::operator = (const char c){
	return MyString(c);
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

int CompareString(const void * e1, const void * e2) {

	MyString * s1 = (MyString *)e1;
	MyString * s2 = (MyString *)e2;
	if (*s1 < *s2)     return -1;
	else if (*s1 == *s2) return 0;
	else if (*s1 > *s2) return 1;

    return 0;
}

int main()   {
	/*MyString s1("abcd-"), s2,
		s3("efgh-");*/
	MyString s1("abcd-"), s2,
		s3("efgh-"), s4(s1);
	MyString SArray[4] = { "big", "me", "about", "take" };
	cout << "1. " << s1 << s2 << s3 << s4 << endl;
	s4 = s3;    
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;    
	s1 = "ijkl-";
	s1[2] = 'A';
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray, 4, sizeof(MyString), CompareString);
	for (int i = 0; i < 4; ++i)
		cout << SArray[i] << endl;
	//输出s1从下标0开始长度为4的子串
	cout << s1(0, 4) << endl;
	//输出s1从下标为5开始长度为10的子串
	cout << s1(5, 10) << endl;
	return 0;
}
/*
1. abcd-efgh-abcd-
2. abcd-
3.
4. abcd-efgh-
5. efgh-
6. c
7. abcd-
8. ijAl-
9. ijAl-mnop
10. qrst-abcd-
11. abcd-qrst-abcd- uvw xyz
about
big
me
take
abcd
qrst-abcd-
*/

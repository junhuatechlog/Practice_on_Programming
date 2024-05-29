#include <iostream>
using namespace std;
class MyInt{
	int nVal;
public:
	MyInt(int n) : nVal(n){}
	int ReturnVal(){ return nVal; }
	MyInt & operator-(int v);

};

MyInt& MyInt::operator-(int v){
	nVal -= v;
	return *this;
}

int main(void){
	MyInt objInt(10);
	objInt - 2 - 1 - 3;
	cout << objInt.ReturnVal() << endl;
	cout<<", ";

	objInt - 2 - 1;
	cout << objInt.ReturnVal() << endl;
	return 0;
}
/*#include <iostream >
using namespace std;
class B {
public:
	B(){ cout << "B_Con" << endl; }
	~B() { cout << "B_Des" << endl; }
};
class C :public B {
public:
	C(){ cout << "C_Con" << endl; }
	~C() { cout << "C_Des" << endl; }
};
int main() {
	C * pc = new C;
	delete pc;
	return 0;
}*/
/*
B_Con
C_Con
C_Des
B_Des
*/
#include <iostream >
using namespace std;
class Base {
public:
	int val;
	Base()
	{
		cout << "Base Constructor" << endl;
	}
	~Base()
	{
		cout << "Base Destructor" << endl;
	}
};
class Base1 :virtual public Base {  };
class Base2 :virtual public Base {  };
class Derived :public Base1, public Base2 { };
int main() { Derived d; 
return 0; }
/*
Base Constructor
Base Destructor
*/
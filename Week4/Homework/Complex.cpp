#include <iostream>
using namespace std;
class Complex{
	double r;
	double i;
public:
	void Print(){
		cout << r << "+" << i << "i" << endl;
	}
	Complex & operator=(string s);

};
Complex & Complex:: operator=(string s){
	int pos = s.find('+');
	string s1 = s.substr(0, pos);
	string s2 = s.substr(pos + 1, s.length() - pos - 2);
	//cout << s1.c_str() << " " << s2.c_str();
	r = atof(s1.c_str());
	i = atof(s2.c_str());
	return *this;
}
int main(void){
	Complex a;
	a = "3+4i";
	a.Print();
	a = "5+6i";
	a.Print();


	return 0;

}
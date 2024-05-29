#include <string>
#include <string.h>
#include <iostream>
using namespace std;

/*
data in BigInt: 0....0987654321
shang: quotient
Yushu: Remainder
*/
class BigInt{
	char *p;
	int size;
	int len;
	bool positive;
	int find_lposition(void) const;
	void doSubtraction(char * data, char * p, char *p1);
	int Update_Original_Dividend(const BigInt &remainder, const BigInt &Dividend);
	int get_length(void);//get the true length of the BigInt value. 
public:
	BigInt(int sz = 300, bool sym = true);
	BigInt(const BigInt & myInt);
	BigInt& operator=(string &s);
	BigInt& operator=(const BigInt &s);
	BigInt operator+(const BigInt &b);
	BigInt operator-(const BigInt &b);
	BigInt operator*(const BigInt &b);
	BigInt operator/ (const BigInt &b);
	BigInt get_dividend(const BigInt & I);
	bool is_positive()const { return positive; };
	int get_Quotient(const BigInt &Dividend,const BigInt & Divider);
	int Update_Quotient_and_Original_Dividend(const BigInt &Dividend, const BigInt & Divider, BigInt & quot);
	int Update_Quotient(const BigInt &Dividend, BigInt &quot, int quotient);
		~BigInt(){
		if (p) delete[] p;
	}
	void show_value(void) const;
	void print_value(void) const;
};
BigInt::BigInt(int sz, bool sym){
	//cout << "BigInt constructor called!" << endl;
	if (sz > 0){
		size = sz;
		p = new char[size];
		memset(p, '\0', size);
	}
	len = 0;
	positive = sym;
}
BigInt::BigInt(const BigInt & myInt){
	p = new char[myInt.size];
	size = myInt.size;
	memcpy(p, myInt.p, size);
	len = myInt.len;
	positive = myInt.positive;
	
}
int BigInt::find_lposition(void) const{
	for (int i = 0; i < size; i++){
		if (p[i] != 0) return i;
	}
	return size-1;
}
int BigInt::get_length(void){
	for (int i = 0; i < size; i++){
		if (p[i] != 0) return size - i;
	}
	return 0;

}
BigInt BigInt::get_dividend(const BigInt & Divider){
	BigInt myInt(300, true);
	BigInt c(300, true);

	memcpy(myInt.p + (size - Divider.len), p + (size - len), Divider.len);
	myInt.len = Divider.len;

	if (myInt.get_length() < Divider.len){
		cout << "There is no Dividend need to divide anymore!" << endl;
		myInt.len = myInt.get_length();
		return myInt;
	}
	c = (myInt - Divider);
	
/*	cout << "call get_dividend" << endl;
	c.show_value();
*/	if (c.positive == false){
		memcpy(myInt.p + (size - Divider.len) - 1, p + (size - len), Divider.len + 1);
		myInt.len = Divider.len + 1;
		/*cout << "goes here!" << endl;
		myInt.show_value();*/
	}
	
	return myInt;
}
BigInt *allDivider;
void allDivider_init(const BigInt & Divider){
	BigInt a(300, true);
	BigInt c(300, true);

	allDivider = new BigInt[9];
	for (int i = 9 - 1; i >= 0; i--){
		string s1(1, i + 1 + '0');
		a = s1;
        c = ((BigInt)Divider) * a;
		allDivider[i] = c;
/*		cout << i << endl;
		allDivider[i].show_value();
*/	}
}
int BigInt::get_Quotient(const BigInt &Dividend, const BigInt & Divider){
	BigInt c(300, true);
	Dividend.show_value();
	cout << " - " << endl;

	for (int i = 8; i >= 1; i--){
		allDivider[i].show_value();
		c = (BigInt)Dividend - allDivider[i];
		//cout << "First value in qet_Quotient:" << endl;
		c.show_value();
		if ((c.len == 0)||(c.positive == true)){
			//cout << "Second value in qet_Quotient:" << endl;
			//c.show_value();
			return i + 1;
		}

	}

	return 0;
}
int BigInt::Update_Original_Dividend(const BigInt &remainder, const BigInt &Dividend){
	int first_pos = find_lposition();
	//remainder.show_value();
	for (int i = 0; i < Dividend.len; i++){
		p[first_pos + i] = remainder.p[size - Dividend.len + i];
	}
	len = get_length();
	//(*this).show_value();
	return 0;
}
int BigInt::Update_Quotient(const BigInt &Dividend, BigInt &quot, int quotient){
	int first_pos = find_lposition();
	//cout << "first pos: " << first_pos << " " << Dividend.len <<" quotient: "<<quotient<< endl;
	quot.p[first_pos + Dividend.len-1] = quotient;
	quot.len = quot.get_length();
	//quot.show_value();
	return 0;
}
int BigInt::Update_Quotient_and_Original_Dividend(const BigInt &Dividend, const BigInt & Divider, BigInt &quot){
	BigInt c(300, true);
	int i = 0;
	//Dividend.show_value();
	int quotient = 0;
	//cout << " - " << endl;

	for (i = 8; i >= 0; i--){
		//allDivider[i].show_value();
		c = (BigInt)Dividend - allDivider[i];
		if ((c.len == 0) || (c.positive == true)){
			
			break;
		}
	}
	quotient = i + 1;
	Update_Quotient(Dividend, quot, quotient);
	Update_Original_Dividend(c, Dividend);

	return 0;
}

void BigInt::doSubtraction(char * data, char * ptra, char *ptrb){ //a - b
	for (int i = size - 1; i >= 0; i--){
		if (ptra[i] >= ptrb[i]){
			data[i] = ptra[i] - ptrb[i];
		}
		else{
			ptra[i - 1] -= 1;
			data[i] = ptra[i] - ptrb[i] + 10;
		}
	}

}

void BigInt::show_value(void) const{
	
	if (positive == false){
		cout << "-";
	}
	for (int i = find_lposition(); i < size; i++){
		cout << (char)(p[i]+'0');
	}
	cout << "\tlen: "<<len<<"\tpositive: "<<positive;
	cout << endl;
}
void BigInt::print_value(void) const{

	if (positive == false){
		cout << "-";
	}
	for (int i = find_lposition(); i < size; i++){
		cout << (char)(p[i] + '0');
	}
	cout << endl;
}
BigInt& BigInt::operator = (string &s){
	len = s.length();
	int pos = size - 1;

	memset(p, '\0', size);
	positive = true;
	for (int i = len-1; i >= 0; i--){
		char v = s[i];
		if ((v<'0') || (v>'9')){
			cout << "the input: "<< s << " is not valid!" << endl;;
			return *this;
		}
		p[pos--] = v-'0';
	}
	return *this;
}

BigInt & BigInt::operator=(const BigInt &I){
    if(p ==I.p) return *this;

    if(p){
        delete [] p;
    }

	size = I.size;
	len = I.len;
	p = new char[size];
    memcpy(p, I.p, size);
	positive = I.positive;
	return *this;
}
BigInt BigInt::operator / (const BigInt &b){
	BigInt a(300, true), c(300, false);
	BigInt quot(300, true);

	allDivider_init(b);
	c = *this - b;
	//c.show_value();
	while (c.is_positive() == true){
		c = (*this).get_dividend(b);
		//c.show_value();
		(*this).Update_Quotient_and_Original_Dividend(c, b, quot);
		//cout << "quot: ";
		//quot.show_value();
		c = (*this) - b;
	}
	//quot.show_value();

	return quot;
}
BigInt BigInt::operator + (const BigInt &b){
	BigInt myInt(300, true);
	
	for (int i = size - 1; i >= 0; i--){
		int x = p[i] + b.p[i]+myInt.p[i];
		myInt.p[i] = x % 10;
		myInt.p[i - 1] += x / 10;
	}
	myInt.len = myInt.get_length();
	return myInt;
}

BigInt BigInt::operator - (const BigInt &b){
	BigInt myInt(300, true);
	char Subtrahend[300];//jianshu
	char Minuend[300];//bei jianshu

	memcpy(Minuend, p, size);
	memcpy(Subtrahend, b.p, size);

	for (int i = 0; i < size; i++){
		if (Minuend[i] < Subtrahend[i]){
			myInt.positive = false;
			break;
		}
		else if (Minuend[i] > Subtrahend[i]){
			myInt.positive = true;
			break;
		}
	}
	//cout << "Result symbol: " << myInt.positive << endl;
	if (myInt.positive == false){
		doSubtraction(myInt.p, Subtrahend, Minuend);
	}
	else{
		doSubtraction(myInt.p, Minuend, Subtrahend);
	}
	myInt.len = myInt.get_length();
	return myInt;
}
BigInt BigInt::operator * (const BigInt &b){
	BigInt myInt(300, true);

	int lp = find_lposition();
	int b_lp = b.find_lposition();
	//cout << "pos" << "\tx" << "\tdata[pos]" << "\tdata[pos]" << "\tdata[pos-1]" << endl;
	for (int i= size-1; i >= b_lp; i--){
		int v = b.p[i];
		for (int j = size-1; j >= lp; j--){
			int x = v * p[j];
			int pos = j - (size - i - 1);
			//cout << "pos:\t" << pos << "\t" << x<<"\t"<<int (data[pos]);
			x = myInt.p[pos] + x;
			//cout << "\t" << x;
			myInt.p[pos] = x % 10;
			myInt.p[pos - 1] += x / 10;
			//cout << "\t" << int(data[pos]) << "\t" << int(data[pos - 1]) << endl;
		}

	}
	myInt.len = myInt.get_length();
	return myInt;
}


int main(void){
	BigInt a(300, true), b(300, false), c(300, false);
	string s1, s2, s3;
	cin >> s1;
	cin >> s2;
	cin >> s3;
/*	cout << s1;
	cout << s2;
	cout << s3;
*/	a = s1;
	b = s3;
	if (s2.compare("+") == 0){
		c  = a + b;
		c.print_value();
	}
	else if (s2.compare("-") == 0){
		c = a - b;
		c.print_value();
	}
	else if (s2.compare("*") == 0){
		c = a*b;
		c.print_value();
	}
	else if (s2.compare("/") == 0){
		c = a / b;
		c.print_value();
	}
	
	/*
	string s = "789";
    string s1 = "123452389";
	cout << "Do Subtraction:" << endl;
	a = s;
	a.show_value();
	b = s1;
	b.show_value();
	c = a.operator-(b);
	c.show_value();
	cout <<endl<< "Do Sum:" << endl;
	string s2 = "4400";
	a = s2;
	c = a + b;
	a.show_value();
	b.show_value();
	c.show_value();
	cout << endl<<"Do Multiply:" << endl;
	a.show_value();
	b.show_value();
	c = a * b;
	c.show_value();
	*/
	/*	cout <<endl<< "Do Division:" << endl;
	string s3 = "38572498698357268054278972389948235";
	//string s3 = "1242864785729";
	string s4 = "12428647857293";
	//string s3 = "385724";
	//string s4 = "124";
	//result should be 311
	//string s4 = "11";
	BigInt quot(300, true);

	a = s3;
	b = s4;
	a.show_value();
	b.show_value();
	allDivider_init(b);
	cout << "after allDivider_init" << endl;
	int count = 0;
	c = a - b;
	c.show_value();
	while (c.is_positive() == true){
		c = a.get_dividend(b);
		//c.show_value();
		a.Update_Quotient_and_Original_Dividend(c, b, quot);
		cout << "quot: ";
		quot.show_value();
		c = a - b;
		count++;
		//if (count == 2)break;
	}
	quot.show_value();
	
	c = a / b;
	c.show_value();
	*/
	if (allDivider)
		delete[] allDivider;
	return 0;
}

#include <iostream>
using namespace std;
class OneArray{
	int size;
	int *ptr;
public:
	OneArray(int _size){
		if (_size > 0){
			size = _size;
			ptr = new int[size];
		}else{
			ptr = NULL;
			size = 0;
		}
	}
	int & operator[](int i){
		if (i >= size){
			cout << "index is too big!" << i << endl;
		}
		return ptr[i];
	}
	int  operator()(int j) const
	{
		if (j >= size){
			cout << "value exceeded!" << endl;
		}
		return ptr[j];
	}
	~OneArray(){
		for (int i = 0; i < size; i++){
			delete[] ptr;
		}
	}
};

class Array2{
	int row;
	int column;
	OneArray **Array2Ptr;
public:
	Array2(){
		row = column = 0;
		Array2Ptr = NULL;
	}
	Array2(int _row, int _column){
		if ((_row > 0) && (_column > 0)){
			Array2Ptr = new OneArray *[row];//pointer array
			row = _row;
			column = _column;
			for (int i = 0; i < row; i++){
				Array2Ptr[i] = new OneArray(column);
			}
		}
	}
	OneArray & operator[](int i){
		if (i >= row){
			cout << "row index is too big!" << endl;
		}
		return *Array2Ptr[i];//it should be an object, not a pointer
	}
	int  operator()(int i, int j) const
	{
		if ((i >= row) || (j >= column)){
			cout << "i and j exceeded!" << endl;
		}
		return (*Array2Ptr[i])(j);
	}
	~Array2(){
		for (int i = 0; i < row; i++){
			delete[] Array2Ptr;
		}
	}
};

int main() {
	Array2 a(3, 4);
	int i, j;
	for (i = 0; i < 3; ++i)
	for (j = 0; j < 4; j++)
		a[i][j] = i * 4 + j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << a(i, j) << ",";
		}
		cout << endl;
	}
	
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << a[i][j] << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b; 	b = a;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}
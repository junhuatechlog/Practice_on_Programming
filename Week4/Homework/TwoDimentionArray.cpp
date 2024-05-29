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
	~OneArray(){
		for (int i = 0; i < size; i++){
			delete[] ptr;

		}
	}
};

class TwoArray{
	int row;
	int column;
	OneArray **TwoArrayPtr;
public:
	TwoArray(int _row, int _column){
		if ((_row > 0) && (_column > 0)){
			TwoArrayPtr = new OneArray *[row];//pointer array
			row = _row;
			column = _column;
			for (int i = 0; i < row; i++){
				TwoArrayPtr[i] = new OneArray(column);
			}
		}
	}
		OneArray & operator[](int i){
			if (i >= row){
				cout << "row index is too big!" << endl;
			}
			return *TwoArrayPtr[i];//it should be an object, not a pointer
		}
		~TwoArray(){
			for (int i = 0; i < row; i++){
				delete[] TwoArrayPtr;

			}
		}
};
/*
int main(void){
	OneArray a(10);
	for (int i = 0; i < 10; i++){
		a[i] = i;
	}
	for (int i = 0; i < 10; i++){
		cout << a[i] << endl;
	}
	cout << "OneArray test complete!" << endl;
	TwoArray t(3, 4);
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 4; j++){
		t[i][j] = i * 4 + j;
	}
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	cout << "TwoDimentionArray test complete!" << endl;
	return 0;
}*/

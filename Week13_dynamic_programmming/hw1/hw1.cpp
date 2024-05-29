#include <iostream>
using namespace std;

int s, num0, num1;
int *num[2];
int get_result(void){
	int count = 0;
	for(int i=0; i<num0; i++){
		for(int j=0; j<num1; j++){
			//cout<< num[0][i] << "+"<<num[1][j]<<endl;
			if(num[0][i] + num[1][j] == s) count ++;	
		}
	}
	return count;
}
void run_cases(void){
	int result;
	cin >> s;
	//cout<< "s: "<<s<<endl;


	cin >> num0;
	num[0] = new int[num0];
	for(int i=0; i<num0; i++){
		cin >> num[0][i];
	}

	cin >> num1;
	num[1] = new int[num1];
	for(int i=0; i<num1; i++){
		cin >> num[1][i];
	}

//for(int i=0; i<num0; i++){
//	cout << num[0][i];
//}
//cout << endl;
//for(int i=0; i<num1; i++){
//	cout << num[1][i];
//}
//
//cout << endl;
	result = get_result();	
	cout<<result<<endl;

	if(num[0] != NULL){
		delete [] num[0];
	}
	if(num[1] != NULL){
		delete [] num[1];
	}
}

int main(void){
	unsigned int case_num = 0;
	cin >> case_num;
	for(int i=0; i<case_num; i++){
		run_cases();		
		
	}
	return 0;
}

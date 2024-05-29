#include <iostream>
#include <string.h>
using namespace std;

unsigned int num_cond[250][250];//num condition
int N=0;

//int get_unimodal_num(int value, int cond){
//	int sum = 1;
//	if(num[value] != -1) {
//		cout<<"num["<<value<<"]: "<<num[value]<<endl;
//		return num[value];
//	}
//	for(int i =1; i<value; i++){
//		if(i <value -2* i){
//			num_1 ++;
//			cout<<"i: "<< i<< " get "<<value-2*i<<"'s value: "<<endl;
//			if(value-2*i >= 6){
//				sum = sum -1;
//			}
//			sum = sum + get_unimodal_num(value -2*i);
//			cout<<"sum: "<<sum<<endl;
//		}else if(i == value-2*i){
//			cout<<"i: "<<i<<" add 1"<<endl;
//			sum = sum + 1;
//			cout<<"sum: "<<sum<<endl;
//
//		}else if(i*2 == value){
//			cout<<"i: "<<i<<" add 1"<<endl;
//			sum = sum + 1;
//			cout<<"sum: "<<sum<<endl;
//		}
//		
//	}
//	num[value] = sum;
//	cout<<"got value num["<<value<<"]: "<<num[value]<<endl;
//	return num[value];
//}
int get_unimodal_num(int value, int cond){
	int sum = 1;
	if(num_cond[value][cond] != -1) {
		//cout<<"Mnum["<<value<<"]["<<cond<<"]: "<<num_cond[value][cond]<<endl;
		return num_cond[value][cond];
	}
	for(int i =cond; i<=value/2; i++){
		//cout<< "value: "<< value<<" i: "<<i<<endl;
		if( (i == value/2) && (value%2 == 0)) sum += 1;
		if(i <value -2* i){
			sum += get_unimodal_num(value -2*i, i);
		//	cout<<"sum: "<<sum<<endl;
		}else if(i == value-2*i){
			sum = sum + 1;
		//	cout<<"sum: "<<sum<<endl;

		}		
	}
	num_cond[value][cond] = sum;
	//cout<<"got value num["<<value<<"]["<<cond<<"]: "<<num_cond[value][cond]<<endl;
	return num_cond[value][cond];
}
int main(void){
	unsigned int result = 0;
	while(1){
		memset(num_cond, -1, sizeof(int) * 250*250);
		num_cond[0][0] = 1;
		num_cond[1][1] = 1;
		num_cond[2][1] = 2;
		cin >> N;
	//	cout<<"N: "<<N<<endl;
		if(N == 0) break;
		result = get_unimodal_num(N, 1);
		
		cout<<N<<" "<<result<<endl ;
	}

	return 0;
}

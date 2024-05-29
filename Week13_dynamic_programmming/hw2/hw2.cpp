#include <iostream>
using namespace std;

int N, K;
int *data;
int get_minmum(void){
	int min=10000;
	
	for(int i=0; i<N; i++){
		if(min > data[i]){
			min = data[i];
		}
	}
	return min;
}
int get_maxmum(void){
	int max=0;
	
	for(int i=0; i<N; i++){
		if(max < data[i]){
			max = data[i];
		}
	}
	return max;
}
int main(void){
	int sum=0;
	cin >> N >> K;
//	cout<<"N K"<<N<<" "<<K<<endl;	
	data = new int[N];
	for(int i=0; i<N; i++){
		cin >> data[i];		
	}

	int max = get_maxmum();
//	cout<<"max: "<< max<<endl;
	do{
		sum = 0;
		for(int i=0; i<N; i++){
			sum += data[i]/max;
		}
		if(sum >= K)break;
		max --;
	}while(max > 0);
	if(max >= 0)cout<<max<<endl;
	if(data) delete [] data;
	return 0;
}

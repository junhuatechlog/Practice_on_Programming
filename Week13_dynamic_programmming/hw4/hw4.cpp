#include <iostream>
using namespace std;

int hArray[100+2][100+2];
int longest[100+2][100+2];
unsigned int R, C; // Row, Column length

int longest_init(void){
	for(int i=1; i<=R; i++){
		for(int j=1; j<=C; j++){
			longest[i][j] = -1;
		}
	}
	for(int i=0; i<=R+1; i++){
		 longest[i][0] = 0;
		 longest[i][C+1] = 0;
	}
	for(int i=0; i<=C+1; i++) {
		longest[0][i] = 0;
		longest[R+1][i] = 0;
	}
	return 0;
}
void print_array_longest(){

	for(int i=0; i<= R+1; i++){
		for(int j=0; j<=C+1; j++){
			cout<<longest[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void print_array(){

	for(int i=0; i<= R; i++){
		for(int j=0; j<=C; j++){
			cout<<hArray[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

//int loopcount=0;
int found_longest_in_every_pos(int i, int j){
	int max = 1;
/*	loopcount ++;
	if(loopcount > 10) {
		cout<<"end"<<endl;
//		return -1;
	}
*/	//cout<<"test4"<<i<<" "<<j<<endl;
	if(longest[i][j] != -1) return longest[i][j];

	//cout<<"test3"<<i<<" "<<j<<endl;
	if((longest[i-1][j] == -1) &&(hArray[i][j]>hArray[i-1][j])) longest[i-1][j] = found_longest_in_every_pos(i-1, j);//left
	//cout<<"test2"<<i<<" "<<j<<endl;
	if((longest[i+1][j] == -1) &&(hArray[i][j]>hArray[i+1][j])) longest[i+1][j] = found_longest_in_every_pos(i+1, j);//right
	//cout<<"test1"<<i<<" "<<j<<endl;
	if((longest[i][j-1] == -1) &&(hArray[i][j]>hArray[i][j-1])) longest[i][j-1] = found_longest_in_every_pos(i, j-1);//up
	//cout<<"test0"<<i<<" "<<j<<endl;
	if((longest[i][j+1] == -1) &&(hArray[i][j]>hArray[i][j+1])) longest[i][j+1] = found_longest_in_every_pos(i, j+1);//down
	//cout<<"test"<<endl;
	if(hArray[i][j] > hArray[i-1][j]){
		max = longest[i-1][j] + 1;	
	}
	if(hArray[i][j] > hArray[i+1][j]){
		if(longest[i+1][j] + 1 > max){
			max = longest[i+1][j] + 1;
		}	
	}
	if(hArray[i][j] > hArray[i][j-1]){
		if(longest[i][j-1] + 1 > max){
			max = longest[i][j-1] + 1;
		}	
	}
	if(hArray[i][j] > hArray[i][j+1]){
		if(longest[i][j+1] + 1 > max){
			max = longest[i][j+1] + 1;
		}	
	}
//	cout<<"["<<i<<"]["<<j<<"]="<<max<<endl;
	longest[i][j] = max;
	return max;
}
int main(void){
	cin >> R >> C;
	//cout<<"R, C: "<<R<< " "<<C<<endl;
	longest_init();
	//print_array_longest();

	for(int i=0; i<102; i++){
		hArray[0][i] = 10000;
		hArray[101][i] = 10000;
	}
	for(int i=0; i<102; i++) {
		hArray[i][0] = 10000;
		hArray[i][101] = 10000;
	}

	for(int i=1; i<=R; i++){
		for(int j=1; j<=C; j++){
			cin >> hArray[i][j];
		}
	}
	//print_array();
	for(int i=1; i<=R; i++){
		for(int j=1; j<=C; j++){
			found_longest_in_every_pos(i,j);	
		}
	}

	//print_array_longest();

	int maxsteps=0, max= 0;
	for(int i=1; i<=R; i++){
		for(int j=1; j<=C; j++){
			if(maxsteps < longest[i][j]){
				maxsteps = longest[i][j];
				max = hArray[i][j];
			}	
		}
	}

	cout<< maxsteps<<endl;
	return 0;
}

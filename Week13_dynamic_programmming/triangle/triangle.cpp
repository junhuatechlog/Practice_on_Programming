#include <stdio.h>
#include <iostream>
using namespace std;
int N;
int **nArr;
int **midArr;
int getSum(int i, int j){
    cout<<"("<<i<< ", "<<j<<")"<<endl;
    if(i >= N-1) return nArr[i][j];

    int left = (midArr[i+1][j] == -1)? getSum(i+1, j): midArr[i+1][j];
    int right = (midArr[i+1][j+1] == -1)? getSum(i+1, j+1): midArr[i+1][j+1];
    midArr[i+1][j] = left;
    midArr[i+1][j+1] = right;

    cout<<"left: "<<left<<" right: "<<right<<endl;
    if(left > right){
        return nArr[i][j] + left;
    }
    return nArr[i][j]+ right;
//   if(nArr[i+1][j] > nArr[i+1][j+1]){
//       return nArr[i][j] + getSum(i+1, j);
//   }
//   return nArr[i][j]+ getSum(i+1, j+1);
}
int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        nArr = new int*[N];
    }
    for(int i=0; i<N; i++){
        nArr[i] = new int[N];
    }
    for(int i=0; i<N; i++){
        midArr = new int * [N];
    }
    for(int i=0; i<N; i++){
        midArr[i] = new int[N];
    }

    cout<<"input the array"<<endl;
    for(int i=1; i<=N; i++){
//        cout<<"index: "<<i<<endl;
        for(int j=0; j<i; j++){
            cin >> nArr[i-1][j];
        }
    }
    for(int i=0; i<N; i++){
//        cout<<"index: "<<i<<endl;
        for(int j=0; j<N; j++){
            midArr[i][j] = -1;
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=0; j<i; j++){
            cout << nArr[i-1][j]<<" ";
        }
    
        cout<<endl;
    }
    cout <<  getSum(0, 0)<< endl;
    return 0;
}

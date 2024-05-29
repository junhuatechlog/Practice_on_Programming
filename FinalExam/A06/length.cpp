#include <iostream>
#include <cstring>
using namespace std;

#define RIGHT 0
#define LEFT 1

int data[100];
int length[2][100];
int n = 0;

int getmax(int i, int direction){
    if(direction == LEFT){
        if(i==0){
            length[LEFT][i] = 1;
            return data[i];
        }
        int t = getmax(i-1, direction);
        if(data[i] > t){
            length[direction][i] = length[direction][i-1] + 1;
            return data[i];
        }else{
            length[direction][i] = length[direction][i-1];
            return t;
        }
    
    }else if(direction == RIGHT){
        if(i==n-1){
            length[RIGHT][i] = 1;
            return data[i];
        }
        int t = getmax(i+1, direction);
        if(data[i] > t){
            length[direction][i] = length[direction][i+1] + 1;
            return data[i];
        }else{
            length[direction][i] = length[direction][i+1];
            return t;
        }
    
    
    
    }

    cout<<"can't get here!"<<endl;
    return 0;
}
int aMaxLen[2][100];
int getmaxlength(void){
    int maxlen = 0;
    for(int j=0; j<2; j++){
        for(int i=0; i<n; i++){
            if(maxlen < aMaxLen[j][i])
                maxlen = aMaxLen[j][i];
        }
    }
    return maxlen;
}
int main(void){
    int testcase = 0;
    cin >> testcase;
    for(int j=0; j<testcase; j++){
        cin >> n;

        memset(data, 0, sizeof(data));
        memset(length, 0, sizeof(length));

        for(int i=0; i< n; i++){
            cin >> data[i];
        }
    //  for(int i=0; i<n; i++)
    //      cout<<data[i]<<" ";
    //  cout<<endl;
       aMaxLen[RIGHT][0] = 1;
       for(int i=1; i<n; i++){
        int nTmp = 0;
        for(int j=0; j<i; j++){
            if(data[i] > data[j]){
                if(nTmp < aMaxLen[RIGHT][j])
                    nTmp = aMaxLen[RIGHT][j];
            }
        }
        aMaxLen[RIGHT][i] = nTmp + 1;
       
       }
       aMaxLen[LEFT][n-1] = 1;
       for(int i=n - 1; i>=0; i--){
        int nTmp = 0;
        for(int j=n-1; j>i; j--){
            if(data[i] > data[j]){
                if(nTmp < aMaxLen[LEFT][j])
                    nTmp = aMaxLen[LEFT][j];
            }
        }
        aMaxLen[LEFT][i] = nTmp + 1;
       
       }
        cout<< getmaxlength()<<endl;

    }

    return 0;
}

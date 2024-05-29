#include <iostream>
#include <cstring>
using namespace std;
int n, k;
int chess[8][8];

void get_input(){
    char data[10];
    for(int i=0; i<n; i++){
        cin.getline(data, 10);
        //cout<<data<<endl;
        for(int j=0; j<n; j++){
                if(data[j] == '.') chess[i][j] = 0;
                if(data[j] == '#') chess[i][j] = 1;
        }
    }
//   for(int i=0; i<n; i++){
//       for(int j=0; j<n; j++)
//           cout<< chess[i][j]<<" ";
//       cout<<endl;
//   }


}

int arrayx[8];
int arrayy[8];
int count  = 0;
int flag[8];
bool DFS(int i, int j, int k){
    bool ret;
    //cout<<"DFS" <<k<<endl;
    if(k == 0) {
  //      cout<<"find one, count: ";
        count ++;
        //cout<<count<<endl;
        return true;
    }
    if(i+1>n){
        return false;
    }
    if(n - i < k) return false;

//        if(flag[i] == 0){
//            cout<<"jump to next to DFS";
//            cout<<"("<<i+1<<", "<<j<<") "<< k<<endl;
 //           flag[i] = 1; 
            DFS(i+1, 0, k);
  //      }
    for(int m=0; m <n; m++){
        //cout<<chess[i][m]<<endl;
        if(chess[i][m] == 1){
 //           cout<<"("<<i<<", "<<m<<"#)"<<"start DFS "<<k<<endl;
            if((arrayx[i] ==0)&&(arrayy[m] == 0)){
                arrayx[i] = 1;
                arrayy[m] = 1;
                ret = DFS(i+1, j, k-1);
                    arrayx[i] = 0;
                    arrayy[m] = 0;
            
            }
        }
    }


    return true;
}

int main(void){
        char data[10];
        cin >> n>> k;
        cin.getline(data, 10);
    do{
        //cout<< n << k<<endl;
        memset(arrayx, 0, sizeof(arrayx));
        memset(arrayy, 0, sizeof(arrayy));
        memset(flag, 0, sizeof(flag));
        get_input();
        DFS(0, 0, k);    
        cout<<count<<endl;
        count = 0;
        cin >> n>> k;
        cin.getline(data, 10);
    } while((n != -1) && (k != -1));



    return 0;
}

#include <iostream>
#include <cstring>
using namespace std;
string *gstr;
int num;

int get_j(int first, int second){
    int i;
    for(i=0; i<gstr[first].size(); i++){
        if(gstr[first][i] != gstr[second][i]) break;
    }
    return i;

}
int get_num(int first, int second){
    int j = 0;
    j = get_j(first, second);
    
    return 1 + gstr[second].size() - j;
}

//input should be n - 1
int get_compress_num(int n){
    if(n== 0) return gstr[0].size();
    return get_num(n-1, n) + get_compress_num(n-1);
}
int main(void){
    cin>>num;
    gstr = new string[num];
    for(int i=0; i<num; i++){
       cin>>gstr[i];
    }
/*
    for(int i=0; i<num; i++){
       cout<<gstr[i]<<endl;
    }
*/
    cout<<get_compress_num(num-1)<<endl;



    return 0;
}

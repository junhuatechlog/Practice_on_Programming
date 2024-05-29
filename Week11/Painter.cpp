#include <iostream>
using namespace std;

int wall[16][17];
int paint[16][17];
int num = 0;

void show_wall(){
    cout<<endl;
    for(int i=0; i<num+1; i++){
        for(int j=0; j<num+2; j++){
            if(wall[i][j] == 1){
                cout<< 'w';
            }else if(wall[i][j] == 0){
                cout<< 'y';
            }
        }
        cout<<endl;
    }
}
void show_paint(){
    cout<<endl;
    for(int i=0; i<num+1; i++){
        for(int j=0; j<num+2; j++){
            cout<<paint[i][j];
        }
        cout<<endl;
    }
}
void read_data(void){
    char szBuf[20];
    cin >> num;
    cin.getline(szBuf, 20);
    //cout<<num;
    for(int i=0; i<num; i++){
        cin.getline(szBuf, 20);
        for(int j=0; j<num; j++){
            if(szBuf[j] == 'w'){
                wall[i+1][j+1] = 1;
            }else if(szBuf[j] == 'y'){
                wall[i+1][j+1] = 0;
            }
        }
        //cout<<"i "<<i<<endl;
    }
    //show_wall();

}
bool guess(){
    int c, r;
    for(r = 1; r<num; r++)
        for(c = 1; c<num+1; c++){
            paint[r+1][c] =
                (wall[r][c] + paint[r][c] + paint[r-1][c] + paint[r][c-1] + paint[r][c+1])%2;
        }
    for(c=1; c<num+1; c++){
  //      cout<< "num:"<<num<<endl;
        if((paint[num][c-1] + paint[num][c] + paint[num][c+1]+paint[num - 1][c])%2 != wall[num][c]){
 //          cout<<"guess failed"<<endl;
 //          show_paint();
            return false;
        }
    }
//   cout<<"get the result"<<endl;
//   show_paint();
    return true;
}
int minmum = 10000;
void check_paint_count(void){
    int count = 0;
    for(int i=0; i<num+1; i++){
        for(int j=0; j<num+2; j++){
            count += paint[i][j];
        }
    }
    if(minmum > count) {
        minmum = count;
    }
}
bool increase_one(void){
    int c;
    paint[1][1]++;
    c = 1;
    while(paint[1][c] > 1){
        paint[1][c] = 0;
        c++;
        paint[1][c] ++;
    }
    for(int i=1; i<num+1; i++){
       if(paint[1][i] == 1) {
        return true;
       }
    }
    return false;
}
void enumate(void){
    int c ;
    bool result;
    for(c = 0; c<17; c++)
        paint[1][c] = 0;

    result = guess();
    while(1){
        if(result == true){
            check_paint_count();
        }
        if(increase_one()==false)break;

        //   cout<<"paint[1][]: \n";
        //   for(int i=0; i<num+2; i++)
        //       cout<<paint[1][i];
        //cout<<endl;
        for(int i=2; i<=15; i++)
            for(int j=0; j<17; j++)
                paint[i][j] = 0;
        result = guess();
    }
    return;
}
void clear_data(void){
    for(int i=0; i<17; i++){
        for(int j=0; j<16; j++){
                wall[j][i] = paint[j][i]= 0;
            }
    
    }
    num = 0;
    minmum = 10000;
}
int main(void){
    int n;
    cin >> n;
    for(int i=0; i< n; i++){
        clear_data();
        read_data();
        enumate();
        if(minmum != 10000) {
            cout<< minmum<<endl;
        }else {
            cout<<"inf"<<endl;
        
        }
    } 
    return 0;
}

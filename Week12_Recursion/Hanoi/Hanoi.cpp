#include <iostream>
using namespace std;

void Hanoi(int n, char src, char mid, char dest){
    if(n == 1){ 
        cout<<src<<" -> "<<dest<<endl;
        return;
    }
    Hanoi(n-1, src, dest, mid);
    Hanoi(1, src, mid, dest);
    Hanoi(n-1, mid, src, dest);



}
int main(void){
    int n;
    cin >> n;
    Hanoi(n, 'A', 'B', 'C');



    return 0;
}

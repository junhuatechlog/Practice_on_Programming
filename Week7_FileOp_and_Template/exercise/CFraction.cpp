#include <iostream>
using namespace std;

template <class T>
T MaxElement(T a[], int size){
    T tmp = a[0];
    for(int i=0; i<size; i++){
        if(tmp < a[i])
            tmp = a[i];
    }
    return tmp;
}
class CFraction{
    int numerator;
    int denumerator;
    public:
    bool operator<(const CFraction &cf);
    friend ostream & operator<<(ostream &o, CFraction &cf);
    CFraction(int x, int y):numerator(x), denumerator(y){}

};
bool CFraction::operator<(const CFraction &cf){
    if(denumerator * cf.denumerator > 0){
        return numerator*cf.denumerator < denumerator * cf.numerator;
    }else{
        return numerator*cf.denumerator > denumerator * cf.numerator;
    }

}
ostream & operator<<(ostream &o, CFraction &cf){
    cout<<cf.numerator<<" / "<<cf.denumerator<<endl;
    return o;
}
int main(void){
    int arr[10] = {9, 20, 30, 100, 40, 20, 1,8, 200, 10};
    CFraction f[4] = {CFraction(1, 20), CFraction(2, 3), CFraction(4, 6), CFraction(4, 5)};
    cout<<MaxElement(arr, 10)<<endl;
    CFraction c = MaxElement(f, 4);
    cout<<c;
//    cout <<MaxElement(f, 4)<<endl; ?
/*    for(int i=0; i<4; i++){
        cout<<f[i];
    }
*/    return 0;
}

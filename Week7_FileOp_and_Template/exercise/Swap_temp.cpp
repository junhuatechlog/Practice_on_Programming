#include <iostream>
using namespace std;

template <class T>
void SSwap(T &x, T &y)
{
    T tmp = x;
    x = y;
    y = tmp;

}

int main(void){
    int a = 5;
    int b = 6;
    SSwap(a, b);
    cout<<"a="<< a <<", b= "<<b<<endl;
    double c=3.5, d = 5.6;
    SSwap(c, d);
    cout <<"c="<<c<<", d= "<<d<<endl;
    return 0 ;
}

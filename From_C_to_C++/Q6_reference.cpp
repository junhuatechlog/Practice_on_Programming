#include <iostream>
using namespace std;

int main()
{
    int a = 3, b = 5;
    int & r = a;
    r = b;
    b = 7;
    cout << a << endl;
    return 0;
}

#include <iostream>
#include <set>
using namespace std;
int main(void){
    pair<int, double> p1;
    cout<<p1.first<<", "<<p1.second<<endl;
    pair<string, int>p2("this", 20);
    cout<<p2.first<<", "<<p2.second<<endl;
    pair<int, int>p3(pair<char, char>('c', 'd'));
    cout<<p3.first<<", "<<p3.second<<endl;
    pair<int, string> p4=make_pair(200, "hello");
    cout<<p4.first<<", "<<p4.second<<endl;


    return 0;
}

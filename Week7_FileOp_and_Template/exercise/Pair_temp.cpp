#include <iostream>
using namespace std;

template <class T1, class T2>
class Pair{
    public:
        T1 key;
        T2 value;
        bool operator<(const Pair<T1, T2> &p);
        Pair<T1, T2>(T1 k, T2 v):key(k), value(v){}
        Pair<T1, T2>(){
//            key = 0;
 //           value = 0;
        }

};

template <class T1, class T2>
bool Pair<T1, T2>::operator<(const Pair<T1, T2> &p){
    return key < p.key;
}
int main(){
    Pair<string, int> Student("Wang Junhua", 88);
    cout<<Student.key<<", "<<Student.value<<endl;
    Pair<int, double> Student1(61392064, 89.3);
    cout<<Student1.key<<", "<<Student1.value<<endl;
    Pair<int, double> Student2();
  //  cout<<Student2.key<<", "<<Student2.value<<endl;
    return  0;
}

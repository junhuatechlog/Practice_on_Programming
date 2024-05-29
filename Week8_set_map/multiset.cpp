#include <iostream>
#include <set>
using namespace std;

template <class T>
void Print(T first, T last){
    for(; first !=last; ++first){
        cout <<*first<<" ";
    }
    cout<<endl;

}
class A{
    private:
        int n;
    public:
        A(int n_) {n = n_;}
        friend bool operator< (const A &a1, const A &a2){
            return a1.n< a2.n;
        }
        friend ostream & operator<<(ostream &o,const A &a2){
            o<<a2.n; 
            return o;
        
        }
        friend class Myless;
};

typedef multiset <A> MSET1;
typedef multiset <A, class Myless> MSET2;
class Myless{
    public:
        bool operator()(const A &a1, const A& a2)
        {
            return (a1.n%10) <(a2.n%10);
        }
};


int main(void){
    const int SIZE = 7;
    A a[SIZE] = {4, 22, 19, 19, 8, 33, 40};
    MSET1 m1;
    m1.insert(a, a+SIZE);
    cout<<"1) "<<m1.count(22)<<endl;
    m1.insert(A(22));
    cout<<"1) "<<m1.count(22)<<endl;
    cout<<"2) ";
    Print(m1.begin(), m1.end());
    MSET1::iterator pp = m1.find(19);
    if(pp != m1.end())
        cout<<" found"<<endl;
    cout<<"3) ";
    cout<<*m1.lower_bound(9)<<", ";
    cout<<*m1.upper_bound(9)<<endl;
//    pp = m1.erase(m1.lower_bound(22), m1.upper_bound(22));
    cout <<"4) ";
    Print(m1.begin(), m1.end());
    MSET2 m2;
    m2.insert(a, a+SIZE);
    cout << "6) ";
    Print(m2.begin(), m2.end());
    return 0;
}

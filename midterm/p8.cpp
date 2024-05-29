#include <iostream>
#include <set>
using namespace std;
template <class T, class Pred=less<T> > 
class MySet:public set<T, Pred>{
    public:
        pair<typename MySet<T, Pred>::iterator,typename  MySet<T, Pred>::iterator> FindInterval(int s, int e){
            typename MySet<T, Pred>::iterator lii;
            typename MySet<T, Pred>::iterator uii;
            //cout<<"s: "<<s<<" e: "<<e<<endl;
               uii = this->upper_bound(e);
               lii = this->lower_bound(s);
            //cout<<"lii: "<<*lii<<" uii: "<<*uii<<endl;
            if(*(this->lower_bound(s)) == s){
              // cout<<"lii: "<<*lii<<endl;
               lii = ++this->lower_bound(s); 
               //cout<<"lii: "<<*lii<<endl;
            }
            if(*(this->upper_bound(e)) == e){
                uii = -- this->upper_bound(e);
               //cout<<"uii: "<<*uii<<endl;
            }
               //cout<<"lii: "<<*lii<<endl;
               //cout<<"uii: "<<*uii<<endl;
           return make_pair(lii, uii); 
        }
        MySet<T, Pred>(int *p, int *p1):set<T, Pred>(p, p1){
            
        }
        MySet<T, Pred>():set<T, Pred>(){
            
        }

};
/*template <class T> 
class MySet:public multiset<T>{
    public:
        pair<typename MySet<T>::iterator,typename  MySet<T>::iterator> FindInterval(int s, int e){
           return make_pair(this->lower_bound(s), this->upper_bound(e)); 
        }
        MySet<T>(int *p, int *p1):multiset<T>(p, p1){
            
        }
        MySet<T>():multiset<T>(){
            
        }

};*/
template <class T3>
void MyPrint(T3 p, T3 p1){
    for(; p!=p1; p++){
        cout<<*p<< " ";
    }
}
int main()
{
    int t;
    cin >> t;
    MySet<int> stInt;
    int a[100];
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0;i < n; ++i )
            cin >> a[i];
        MySet<int> stInt(a,a+n);
        //cout<<"stInt size: "<<stInt.size()<<endl;
        MyPrint(stInt.begin(),stInt.end()); 
        cout << endl;
        int s,e;
        cin >> s >> e; 
        pair<MySet<int>::iterator, MySet<int>::iterator> p;
        p  = stInt.FindInterval(s,e);
        if( p.first != p.second) {
            MyPrint(p.first,p.second);
            cout << endl;
        }
        else
            cout << "Interval Not Found" << endl;
        cin >> n; 
        MySet<double,greater<double> > stDouble;
       for( int i = 0;i < n; ++i)  {
            double d;
            cin >> d;
            stDouble.insert(d);
        }
        MyPrint(stDouble.begin(),stDouble.end());
        cout << endl;
        double w;
        cin >> w;
        cout << * stDouble.upper_bound(w) << endl;
    }
}


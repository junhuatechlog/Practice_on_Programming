    #include <iostream>
    #include <list>
    using namespace std;

class MyLess{
    public:
       bool  operator()(int a, int b){
           int t1, t2;
           t1 = a%10;
           t2 = b%10;
           if(t1 == t2) return a > b;
           else return t1 > t2;
       }


};
    int main()
    {
        int t;
        cin >> t;
        list<int> lst;
        while( t--) {
            int n;
            cin >> n;
            lst.clear();
            int m;
            for( int i = 0;i < n; ++i) {
                cin >> m;
                lst.push_back(m);
            }
            lst.sort(MyLess());
 //           lst.sort();
            list<int>::iterator it;
            for( it = lst.begin(); it != lst.end(); ++ it) {
                cout << * it  << " ";
            }
            cout << endl;
        }
        return 0;
    }

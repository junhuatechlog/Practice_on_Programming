    #include <iostream>
    #include <string>
    #include <vector>
    using namespace std;

template<class T, class T1>
void my_for_each(T first, T second, T1 op){
    for(; first != second; first ++)
        op(*first);
}
    void Print(int n)
    {
        cout << n*n << ",";
    }
    struct MyPrint
    {
        void operator()( const string & s ) {
            cout << s << ",";
        }
    };
    int main()
    {
        int t;
        int a[5];
        vector<string> vt;
        cin >> t;
        while( t--) {
            vt.clear();
            for(int i = 0;i < 5; ++i)
                cin >> a[i];
            for(int i = 0;i < 5; ++i) {
                string s;
                cin >> s;
                vt.push_back(s);
            }
            my_for_each(a,a+5,Print);
            cout << endl;
            my_for_each(vt.begin(),vt.end(),MyPrint());
            cout << endl;
        }

        return 0;
    }

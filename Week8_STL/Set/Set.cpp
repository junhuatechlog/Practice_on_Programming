#include <iostream>
#include <set>
using namespace std;

int main(){
    multiset<int> mset;
    set<int> myset;
    unsigned int n;
    string s;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        if(s == "add"){
            int x;
            cin >> x;
            mset.insert(x);
            cout<<mset.count(x)<<endl;
            myset.insert(x);
        }
        if(s == "ask"){
            int x;
            cin >> x;
            if(myset.count(x) == 0){
                cout<<"0 ";
            }else{
                cout << "1 ";
            }
            cout<<mset.count(x)<<endl;
        }
        if(s == "del"){
            int x;
            cin >> x;
            cout<<mset.count(x)<<endl;
            mset.erase(x);
        }

    }
    return 0;
}

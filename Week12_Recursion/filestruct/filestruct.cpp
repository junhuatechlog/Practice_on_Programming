#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    vector<string> vs;
    vs.push_back("lmn");
    vs.push_back("xyz");
    vs.push_back("def");
    vs.push_back("abc");

    sort(vs.begin(), vs.end());


    vector<string>::iterator i;
    for(i=vs.begin(); i!=vs.end(); i++){
    
        cout << *i<<endl;
    }
    cout<<"size: "<<vs.size()<<endl;
    vs.clear();
    cout<<"size: "<<vs.size()<<endl;
   /* list<string> ls;
    ls.push_back("lmn");
    ls.push_back("xyz");
    ls.push_back("def");
    ls.push_back("abc");

    ls.sort();


    list<string>::iterator i;
    for(i=ls.begin(); i!=ls.end(); i++){
    
        cout << *i<<endl;
    }



*/

return 0;
}

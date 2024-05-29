#include <iostream>
#include <list>
#include <vector>
using namespace std;

template <class T>
void Print(T first, T last){
    for(; first != last; ++first)
            cout<<*first<<" ";
    cout<<endl;

}
vector<list<int> *> lst_ptr(10000);
int main(void){
    unsigned int n;

    string s;
    cin >> n;
    //cout<< n;
    for(int i=0; i<n; i++){
        cin>>s;
        if(s == "new"){
            int id =0;
            cin >> id;
            if(lst_ptr[id] == NULL){
                lst_ptr[id] = new list<int>();
                //cout<<"list "<<id<<" newed!"<<endl;
            }
        }
        if(s == "add"){
            int id;
            int num;
            cin >> id >> num;
            /*            if(lst_ptr[id] == NULL){  
                          lst_ptr[id] = new list<int>();
                          }
             */           (*lst_ptr[id]).push_back(num);
        }
        if(s == "merge"){
            int id1, id2;
            cin >> id1 >> id2;
            if(lst_ptr[id1] == NULL){
                cout<<"no data in lst_ptr["<<id1<<"]"<<endl;
                return -1;
            }
            if(lst_ptr[id2] == NULL){
                cout<<"no data in lst_ptr["<<id2<<"]"<<endl;
                return -1;
            }
            if(id1 != id2){
                (*lst_ptr[id1]).merge(*lst_ptr[id2]);
            }


        }

        if(s == "unique"){
            int id;
            cin >> id;
            if(lst_ptr[id] == NULL){
                cout<<"no data in lst_ptr["<<id<<"]"<<endl;
                return -1;
            }
            //Print((*lst_ptr[id]).begin(), (*lst_ptr[id]).end());
            //cout<<"unique is called: "<<id<<endl;
            (*lst_ptr[id]).sort();
            (*lst_ptr[id]).unique();
            //Print((*lst_ptr[id]).begin(), (*lst_ptr[id]).end());

        }
        if(s == "out"){
            int id;
            cin >> id;
            if(lst_ptr[id] == NULL){
                cout<<"no data in lst_ptr["<<id<<"]"<<endl;
                return -1;
            }

            (*lst_ptr[id]).sort();
            //cout<<i;
            Print((*lst_ptr[id]).begin(), (*lst_ptr[id]).end());

        }

    }
    return 0;
}


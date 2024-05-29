#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> vs[100];
int gcase_index = 1;
void print_head(){
    if(gcase_index > 1) cout<<endl;
    cout<<"DATA SET "<<gcase_index<<":"<<endl;
    cout<<"ROOT"<<endl;
}

void print_prefix(int layer) {
    for(int i=0; i<layer; i++){
        cout<<"|     ";
    }

}
void print_files(int layer){
    sort(vs[layer].begin(), vs[layer].end());
    vector<string>::const_iterator i;
    for(i=vs[layer].begin(); i!=vs[layer].end(); i++){
        print_prefix(layer);
        cout<<*i<<endl;
    }
}
void clear_files(int layer){
    vs[layer].clear();
}
void clear_all_files(void){

    for(int i=0; i<100; i++){
        if(!vs[i].empty()){
       /*     cout<<"layer: "<<i<<endl;
            print_files(i);
        */    //vs[i].clear(); 
        }
    }
} 
int first =0;
int parse_next_item(int layer){
    string s;
    cin>>s;
    if(s[0] == 'd'){
        if(layer == 0&& first ==0){
            print_head();
            first =1;
        }
        print_prefix(layer+1); 
        cout<<s<<endl;
        parse_next_item(layer+1);
    }else if(s[0] == 'f'){
        if(layer == 0&& first ==0){
            print_head();
            first =1;
        }
        vs[layer].push_back(s); 
        parse_next_item(layer);
    }else if(s[0] == ']'){
        print_files(layer);
        clear_files(layer);
        parse_next_item(layer-1);

    }else if(s[0] == '*'){
        print_files(layer);
        clear_files(layer);
        //clear_all_files(); 
        gcase_index++;
        first =0;
//       cout<<"peek: "<<cin.peek()<<endl;
//       if(cin.peek() == '#'){
//           cout<<"get end"<<endl;
//           return -1;
//       }
    
    }else if(s[0] == '#'){
        //    cout<<"get end"<<endl;
        return -1;
    
    }
    return 0;
}
int main(void){
    int rc=0;
    rc = parse_next_item(0);
    while(rc != -1){
        rc = parse_next_item(0);
    }


    return 0;
}

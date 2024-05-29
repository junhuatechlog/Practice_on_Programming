#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


//   enum cmd_type{
//       COPY,
//       ADD,
//       FIND,
//       RFIND,
//       INSERT,
//       RESET,
//       PRINT,
//       PRINTALL,
//       OVER
//   };
void split(std::string& s, const std::string& delim,std::vector< std::string >* ret)  
{  
    size_t last = 0;  
    size_t index=s.find_first_of(delim,last);  
    while (index!=std::string::npos)  
    {  
        ret->push_back(s.substr(last,index-last));  
        last=index+1;  
        index=s.find_first_of(delim,last);  
    }  
    if (index-last>0)  
    {  
        ret->push_back(s.substr(last,index-last));  
    }  
}  
stack<string> gparamstk;
string *gstr[20];
bool is_digit(const char *buf, int len){
    for(int i=0; i<len; i++){
        if(buf[i]<'0' || buf[i]>'9')
            return false;
    }
    return true;
}
string  stringadd(string &s1, string &s2){
    string s;
    unsigned int value1;
    unsigned int value2;
    if(is_digit(s1.c_str(), s1.size())!=true){
        return s1+s2;
    }
    if(is_digit(s2.c_str(), s2.size())!=true){
        return s1+s2;
    }
    value1 = atoi(s1.c_str());
    value2 = atoi(s2.c_str());
    if(value1<0 || value1>99999){
        return s1+s2;
    }
    if(value2<0 || value2>99999){
        return s1+s2;
    }
    char buf[20];
    unsigned int value = value2 + value1;
    snprintf(buf, 20, "%d", value);
    return buf;
}
string  stringcopy(int n, int x, int l){
    string s;
    //cout<<"stringcopy "<<n<< " "<< x<< " "<<l<<endl;
    s = gstr[n-1]->substr(x, l);
    //cout<<"s: "<<s<<endl;
    return s;
}
string find (int s, int n){
    char buf[20] ;
    snprintf(buf, 20, "%d", s);
    int pos = gstr[n-1]->find_first_of(buf);
    if(pos == string::npos){
        pos = gstr[n-1]->size();
    }
    snprintf(buf, 20, "%d", pos);
    return buf;
}
string rfind (int s, int n){
    char buf[20] ;
    snprintf(buf, 20, "%d", s);
    int pos = gstr[n-1]->find_last_of(buf);
    if(pos == string::npos){
        pos = gstr[n-1]->size();
    }
    snprintf(buf, 20, "%d", pos);
    //cout<<"buf: "<<buf<<endl;
    return buf;
}
void insert(string s, int n, int x){
    gstr[n-1]->insert(x, s);
}
void reset(string s, int n){
    delete gstr[n-1];
    gstr[n-1] = new string(s);

}

void print(int n){
    if(gstr[n-1] != NULL){
    cout<<*gstr[n-1]<<endl;
    }
}
void printall(){
   for(int i=0; i<20; i++){
        print(i+1);
   } 
}



int main(void){
    int n;
    char buff[1024];
    string s;
       cin >> n;
         for(int i=0; i<n; i++){
         cin >>s;
         gstr[i] = new string(s); 
         }
         vector<string> vs;
    while(1){
        vs.clear();
        cin.getline(buff, 1024);
        string ss = string(buff);
        split(ss, " ", &vs);
        stack<string> stk;
        vector<string>::iterator rI;
        for(rI=vs.begin(); rI!=vs.end(); ++rI){
            //cout<<*rI<<endl;
            stk.push(string(*rI)); 
        }
        //cout<<"stk size: "<<stk.size()<<endl;
        while(!stk.empty()){
            string s = stk.top(); 
            stk.pop();
            if(s == "copy"){

                int n = atoi(((gparamstk.top()).c_str())); gparamstk.pop();
                int x = atoi(((gparamstk.top()).c_str())); gparamstk.pop();
                int l = atoi(((gparamstk.top()).c_str())); gparamstk.pop();

                //cout<<s<<" "<<n<< " "<<x<<" "<<l<<endl;
                s = stringcopy(n, x, l);
                //cout<<"copy: "<<s<<endl;
                gparamstk.push(s);
                //cout<<"param size: "<<gparamstk.size()<<endl;
            }else if(s=="add"){
                string ss;
                string s1 = gparamstk.top(); gparamstk.pop();
                string s2 = gparamstk.top(); gparamstk.pop();
                //cout<<"s1: "<<s1<<" s2: "<<s2<<endl;
                ss = stringadd(s1, s2);
                //cout<<ss<<endl;
                gparamstk.push(ss);
                //cout<<"param size: "<<gparamstk.size()<<endl;
            }else if(s=="find"){

                int ss = atoi(gparamstk.top().c_str()); gparamstk.pop();
                int nn = atoi(gparamstk.top().c_str()); gparamstk.pop();

                //cout<<s<<" " <<ss<< " "<<nn<<endl;
                string pos = find (ss, nn);
                gparamstk.push(pos);
                //cout<<"param size: "<<gparamstk.size()<<endl;

            }else if(s=="rfind"){
                //cout<<"rfind"<<endl;
                int s = atoi(gparamstk.top().c_str()); gparamstk.pop();
                int n = atoi(gparamstk.top().c_str()); gparamstk.pop();
                //cout<<"n "<<n<<" s"<<s<<endl;
                string pos = rfind (s, n);
                gparamstk.push(pos);

            }else if(s=="insert"){

                string ss = gparamstk.top(); gparamstk.pop();
                int nn = atoi(gparamstk.top().c_str()); gparamstk.pop();
                int xx = atoi(gparamstk.top().c_str()); gparamstk.pop();

                //cout<<s<<" "<<ss<<" "<<nn<<" "<< xx<<endl;
                insert(ss, nn, xx); 
                //cout<<"param size: "<<gparamstk.size()<<endl;

            }else if(s=="reset"){
                string ss = gparamstk.top();
                gparamstk.pop();
                int n = atoi(gparamstk.top().c_str());
                gparamstk.pop();
                //cout<<"reset "<<ss<< " "<<n<<endl;
                reset(ss, n); 
                //cout<<"param size: "<<gparamstk.size()<<endl;

            }else if(s=="print"){
                //cout<<s<<endl;
                int n = atoi(gparamstk.top().c_str());
                gparamstk.pop();
                print(n);

            }else if(s=="printall"){
                printall(); 

            }else if(s=="over"){
                //cout<<s<<endl;
                    exit(0);
                 //   cout<<"param: "<<gparamstk.size()<<endl;
            }else{
                //cout<<"param: " << s<<endl;
                gparamstk.push(s);
            }

        }
    } 
    return 0;
}

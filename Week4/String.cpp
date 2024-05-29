#include <iostream>
using namespace std;
class String{
    char * str;
    public:
    String():str(NULL){}
    String(const char * s ){
        int len = strlen(s);
        if (len > 0){
            str = new char[len + 1];
            strcpy(str, s);
            str[len] = '\0';
        }
    }
    char * operator=(const char * s);
    const char * c_str(){
        return str;
    }
    ~String(){ 
        if (str){ 
            delete[]str; 
        }
    }
};
char * String::operator=(const char * s)
{
    if(str){
        delete [] str;
    }
    if(s!=NULL){
        str = new char[strlen(s) + 1];
        strcpy(str, s);
        str[strlen(s)] = '\0';
    }else{
        str = NULL;
    }
    return str;
}
int main(void){
    String s1("www.baidu.com");
    cout << s1.c_str() << endl;
    String s2 = "www.google.com";
    cout << s2.c_str() << endl;
    s2 = "www.sina.com.cn";
    cout << s2.c_str() << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Student{
    string name;
    int id;
    public:
    Student(string n, int _id):name(n), id(_id){ }
    Student(){ }
    void Read(void){
        cin>> name;
        cin >> id;
    }
    void Print(void){
        cout<< id<<" "<<name<<endl; 
    }
};
// .........

int main()
{
    int t;
    cin >> t;
    Student s("Tom",12);
    while( t-- )    {
        int n;
        cin >> n;
        Student st;
        for( int i = 0;i < n; ++i) {
            st.Read();
            st.Print();
        }
        cout << "****" << endl;
    }
    return 0;
}


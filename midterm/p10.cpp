#include <iostream>
#include <string>
using namespace std;

class Student {
    private:
        int id;
        static int count;
    public:
        Student(){
            count ++; 
        //    cout<<"constructor 1"<<endl;
        }
        Student(Student & s){
            id = s.id;
            if(count < 3){
            count ++;
            }
         //   cout<<"constructor 2"<<endl;
        }
        Student(int v){
            id = v;
            count ++; 
          //  cout<<"constructor 3"<<endl;
        }
        friend void PrintCount();
        friend void Print(Student s);
        static void InitCount(void){
            count  = 0;
        }
            // .........

};
int Student::count;
void PrintCount() {
    cout << "Total " << Student::count << " students" << endl;
}
void Print(Student s)
{
    cout << "the id is " << s.id << endl;
}

int main()
{
    Student::InitCount();
    Student s;
    PrintCount();
    Student s1(10);
    Student s2(s1);
    PrintCount();
    Print(s2);
    PrintCount();
    return 0;
}


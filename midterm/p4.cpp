    #include <iostream>
    #include <string>
    #include <cstring>
    #include <algorithm>
    #include <vector>
    using namespace std;
class Student{
    string name;
    int score;
    public:
        Student():name(""), score(0){}
        friend istream & operator>>(istream &in, Student &s){
            in>>s.name;
            in>>s.score;
            return in;
    }
    friend ostream & operator<<(ostream &o, Student &s){
        o<<s.name;
        return o;
    }
    friend bool operator<(const Student& s1, const Student& s2){
       return s1.score < s2.score; 
    }

    /*bool operator<(const Student& s2){
       return score < s2.score; 
    }//why this doesn't work?
    */
};

    int main()
    {
        int t;
        vector<Student> v;
        cin >> t;

        while( t--) {
            int n;
            cin >> n;
            Student st;
            v.clear();
            for( int i = 0;i < n; ++i ) {
                cin >> st;
                v.push_back(st);
            }
                sort(v.begin(),v.end());
            for( int i = 0;i < v.size(); ++ i)
                cout << v[i] << endl;
            cout << "****" << endl;
        }
        return 0;
    }


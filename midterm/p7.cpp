    #include <iostream>
    #include <map>
    using namespace std;

    struct Student
    {
        int id;
        string name;
        int score;
        Student(int id_,const string & nm,int sc):
            id(id_),name(nm),score(sc) { }
        Student() { }


    };


    struct Info
    {
        string name;
        int score;
        Info(const string & s,int sc):name(s),score(sc) { }
    };
pair<int, Info> MyMakePair(Student &s){
    return make_pair(s.id, Info(s.name, s.score));
}
Student MyFind(map<int, Info> mymap, int id){
    map<int, Info>::iterator ii;
    ii = mymap.find(id);
    if(ii != mymap.end()){
        return Student(id, ii->second.name, ii->second.score);
    }

}
    int main()
    {
        std::map<int,Info>  mp;
        int t;
        cin >> t;
        while( t -- ) {
            mp.clear();
            int n;
            cin >> n;
            Student st;
            for( int i = 0;i < n; ++i) {
                cin >> st.id >> st.name >> st.score;
                mp.insert(MyMakePair(st));
            }
            cin >> n;
            st = MyFind(mp,n) ;
            cout << st.name << " " << st.score  << endl;
        }
        return 0;
    }


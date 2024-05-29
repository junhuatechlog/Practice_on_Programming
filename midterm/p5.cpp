    #include <iostream>
    using namespace std;
    class A{
protected:
        int v;
        public:
        A(int _v):v(_v){}
        virtual void Print(void){
            cout<<"A "<< v<<endl;
        } 
    };
class B:public A{
    public:
        B(int _v):A(_v){
        }
        virtual void Print(void){
            cout<<"B "<<A::v<<endl;

        }
};
void PrintInfo(A *p){
    p->Print();
}
A *a[1000];
int main()
{
    int t;
    cin >> t;
    while( t -- ) {
        int n;
        cin >> n;
        for( int i = 0;i < n; ++i)  {
            char c; int k;
            cin >> c >> k;
            if( c == 'A')
                a[i] = new A(k);
            else
                a[i] = new B(k);
        }
        cout << n << endl;
        for( int i = 0;i < n; ++i)
            PrintInfo(a[i]);
        cout << "****" << endl;
    }
    return 0;
}


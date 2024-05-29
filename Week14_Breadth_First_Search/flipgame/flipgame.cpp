#include <iostream>
#include <bitset>

using namespace std;
#define BLACK 0
#define WHITE 1
int oStatus;
//bitset<0xffff>Flags;
bitset<65535+1>Flags;
int qHead, qTail;
void PrintTable(int input[4][4]){
    cout<<"the table:"<<endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<(int)input[i][j]<<" ";
        }
        cout<<endl;
    }
}
int get_input(void){
    int input[4][4];
    char data[5];
    int status =0;
    char buf[16];
    int i=0;
    while(cin.getline(data, 5)){
        for(int j=0; j<4; j++){
            if(data[j] == 'b')input[i][j] = BLACK;
            if(data[j] == 'w') input[i][j] = WHITE;
        } 
        i++;
        if(i>4) break;
    }
    //PrintTable(input);
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++)
            status |=input[i][j] << (15 - (i*4 + j)); 
    
    }
    //cout<<status<<endl;
    return status;
}
struct Point{
    int status;
    int father;
    int id;
    Point(int s, int f, int _id):status(s), father(f), id(_id){}
    Point(){}
    friend ostream & operator<<(ostream & o, Point &p){
        int table[4][4];
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if((p.status & (1<<(15-(i*4+j)))) == (1<<(15-(i*4+j)))){
                    table[i][j] = WHITE;
                }else{
                    table[i][j] = BLACK;
                }
            }
        }
        int x, y;
        x = p.id%4;
        y = p.id/4;
        o<<"("<<y<<" , "<<x<<")"<<endl;
        return o; 
    }

};
#define MAXS 100000
Point myQueue[MAXS];

//int result[MAXS]; 
void PrintOutStatus(int st){
    cout<<st<<endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            //cout<<(15 -(i*4+j))<< " ";
            //cout<<(st & (1<<(15 -(i*4+j))))<<endl;
            if((st & (1<<(15-(i*4+j)))) == (1<<(15-(i*4+j)))){
                cout<<"w ";
            }else{
                cout<<"b ";
            }
        }
        cout<<endl;
    }
}
void StatusToTable(int st, int table[6][6]){
   // cout<<"table with 6 dimentional:"<<endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if((st & (1<<(15-(i*4+j)))) == (1<<(15-(i*4+j)))){
                table[i+1][j+1] = WHITE;
            }else{
                table[i+1][j+1] = BLACK;
            }
        }
    }
 /*   for(int i=0; i<6; i++){
        for(int j=0; j<6; j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }
    */
}
int TableToStatus(int table[6][6]){
    int status = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++)
            status |= table[i+1][j+1] << (15 - (i*4 + j)); 
    }
    //cout<<"status: "<<hex<<status;
    //cout<<dec<<endl;
    return status;
}
int NewStatus(int nStatus, int id){
    //id =0 table[0][0]
    //id = 15 table[3][3]
    int cur_x, cur_y;

    int table[6][6] = {};

    StatusToTable(nStatus, table);
    cur_y = id/4+1;
    cur_x = id%4+1;

    table[cur_y][cur_x] = (table[cur_y][cur_x]+1)%2;
    table[ cur_y ][cur_x-1] = (table[ cur_y ][cur_x-1]+1)%2;
    table[ cur_y ][cur_x+1] = (table[ cur_y ][cur_x+1]+1)%2;
    table[cur_y-1][ cur_x ] = (table[cur_y-1][ cur_x ]+1)%2;
    table[cur_y+1][ cur_x ] = (table[cur_y+1][ cur_x ]+1)%2;
    return TableToStatus(table);
}

bool Bfs(int nStatus){
    int nNewStatus;
    int cur_x; 
    int cur_y;
    Flags.reset();
    qHead = 0; qTail = 1;
    myQueue[qHead] = Point(nStatus, -1, 0);
    while(qHead != qTail){
        //cout<<qHead<<", "<<qTail<<endl;
        nStatus = myQueue[qHead].status;
        //cout<<"nStatus: "<<nStatus<<endl;
        if((nStatus == 0xffff) ||(nStatus == 0x0)){
            return true;
        }
       //if((nStatus == 0xffff) ||(nStatus == 0x0))
       //    return true;
        for(int i=0; i<16; i++){
            nNewStatus = NewStatus(nStatus, i); 
            if(nNewStatus == -1) continue;
            if(Flags[nNewStatus]) continue;
            Flags.set(nNewStatus, true);
            myQueue[qTail++] = Point(nNewStatus, qHead, i);
        }
        qHead++;

    }
    return false;
}

int main(void){
	oStatus = get_input();

    PrintOutStatus(oStatus);

    if(!Bfs(oStatus)) {
        cout<< "Impossible"<<endl;
        return 0;
    }

    cout<< myQueue[qHead]<<endl;
    int father = myQueue[qHead].father;
    int count = 0;
    while(father != -1){
        count ++;
        cout<<"father: "<<father<<endl;
        cout<<myQueue[father];        
        father = myQueue[father].father;
    }
    cout << count<<endl;
	return 0;
}

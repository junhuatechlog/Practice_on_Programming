#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;
int maze[200][200];

char sz4Moves[] = "udlr";
int M, N, T;
class Point{
	public:
	int x, y;
    int check;
	int father;
	public:
	Point(int _x, int _y, int f, int c): x(_x), y(_y), father(f), check(c){}
	Point(){}
	bool operator==(Point & p){
		return x == p.x && y == p.y;
	}
	bool is_extensible(){
		return (maze[x][y] != 1);
	}
	friend ostream & operator<<(ostream & o, Point &p){
		o<<"("<<p.x<<", "<<p.y<<")";
		return o;
	}
	friend Point NewPoint(Point np, char cMove, int father);

};
Point start;
Point goal;

void get_input(void){
    cin >> M>> N>> T;
    cout<< M << " "<<N<<" "<<T<<endl;

	char data[200+10];
    cin.getline(data, 200);	
	for(int i=0; i<M; i++){
        memset(data, 0, sizeof(data));
		cin.getline(data, 200);	
        cout<< data<<endl;
		for(int j=0; j<N; j++){
			if(data[j] == '*')maze[i][j]= 0;
			else if(data[j] == '#') maze[i][j]= 1;
            else if(data[j] == '@') start = Point(i, j, -1, T);
            else if(data[j] == '+') goal = Point(i, j, -1, 0);
		}
	}
}
void print_maze(void){ 
cout<<"maze: "<<endl;
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++)
			cout<<maze[i][j]<< " ";
		cout<<endl;
	}
	cout<<endl;

}
const int MAX = 2500;
Point myQueue[MAX];
int qHead, qTail;
bitset<2500> Flags;
Point NewPoint(Point np, char cMove, int father){
    int check =np.check;
	switch(cMove){
		case 'u': if(np.y <= 0) return Point(-1, -1, -1, -1);
			else {
                if(maze[np.x][np.y-1] == 1){
                    check = np.check -1;
                    if(check < 0) return Point(-1, -1, -1, -1);
 
                } 
				return Point(np.x, np.y -1,father, check); 
			}
		break;
		case 'd': if(np.y >= N-1) return Point(-1, -1, -1, -1);
			else {
                if(maze[np.x][np.y+1] == 1){
                    check = np.check -1;
                    if(check < 0) return Point(-1, -1, -1, -1);
                } 
				return Point(np.x, np.y +1,father, check); 
			}
		break;
		case 'l': if(np.x <=0) return Point(-1, -1, -1, -1);
			else{ 
                if(maze[np.x-1][np.y] == 1){
                    check = np.check -1;
                    if(check < 0) return Point(-1, -1, -1, -1);
                } 
                return Point(np.x -1, np.y, father, check); 
            }
                break;
		case 'r': if(np.x >=M-1) return Point(-1, -1, -1, -1);
			else {
                if(maze[np.x+1][np.y] == 1){
                    check = np.check -1;
                    if(check < 0) return Point(-1, -1, -1, -1);
                } 
                return Point(np.x +1, np.y, father, check);
            }
		break;
	}
	
}
bool Breadth_first_search(){
	Point nNewPoint;
	qHead = 0;
	qTail = 1;
	Flags.reset();
	myQueue[qHead] = start;
	
	cout<<myQueue[qHead]<<endl;
	while(qHead != qTail){
		Point nPoint = myQueue[qHead];
		qHead ++;
		cout<<"check point: "<<nPoint<<qHead<<endl;
		if(nPoint == goal) return true;
		if(Flags[nPoint.x*N+nPoint.y]) continue;
		Flags.set(nPoint.x*N+nPoint.y, true);
			
/*		if(!nPoint.is_extensible()){
           if(nPoint.check == 0) continue; 
        };
*/		for(int i=0; i<4; i++){
			nNewPoint = NewPoint(nPoint, sz4Moves[i], qHead-1);	
			if((nNewPoint.x == -1))continue;
			if(Flags[nNewPoint.x*N+nNewPoint.y]==false){
				myQueue[qTail++] = nNewPoint;
				cout<<nNewPoint<< qTail<<endl;
			}
		}
	}

	return false;
}
int Steps[1000]={};
int main(){
    memset(maze, 0, sizeof(maze));
	get_input();
    print_maze();
    //return 0;
//	print_maze();
    cout<<"start"<<start<<endl;
    cout<<"goal"<<goal<<endl;
	if(!Breadth_first_search()){
		cout<<-1<<endl;
		return -1;
	}
	//cout<< "found the route: "<<endl;
	int i=qHead -1;
	int k=0;
	while(i >= 0){
		Steps[k++] = i;
//		cout<<myQueue[i]<<endl;
		i = myQueue[i].father;
//		cout<<myQueue[i]<<endl;
	}
/*	for(int i=k-1; i>=0; i--){
		cout<<myQueue[Steps[i]]<<endl;
	}	
 */   cout<< k-1<<endl;
	return 0;
}

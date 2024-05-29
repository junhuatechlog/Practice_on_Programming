#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;
int maze[5][5];

char sz4Moves[] = "udlr";
void get_input(void){
	char data[100];
	for(int i=0; i<5; i++){
		cin.getline(data, 100);	
		int k=0;
		for(int j=0; j<strlen(data); j++){
			if(data[j] == '0')maze[i][k++] = 0;
			else if(data[j] == '1') maze[i][k++] = 1;
		}
	}
}
void print_maze(void){ 
cout<<"maze: "<<endl;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++)
			cout<<maze[i][j]<< " ";
		cout<<endl;
	}
	cout<<endl;

}
class Point{
	public:
	int x, y;
	int father;
	public:
	Point(int _x, int _y, int f): x(_x), y(_y), father(f){}
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
const int MAX = 250;
Point myQueue[MAX];
int qHead, qTail;
bitset<25> Flags;
Point goal(4, 4, -1);
Point NewPoint(Point np, char cMove, int father){
	switch(cMove){
		case 'u': if(np.y <= 0) return Point(-1, -1, -1);
			else {
				return Point(np.x, np.y -1,father); 
			}
		break;
		case 'd': if(np.y >= 4) return Point(-1, -1, -1);
			else {
				return Point(np.x, np.y +1,father); 
			}
		break;
		case 'l': if(np.x <=0) return Point(-1, -1, -1);
			else return Point(np.x -1, np.y, father); break;
		case 'r': if(np.x >=4) return Point(-1, -1, -1);
			else return Point(np.x +1, np.y, father);
		break;
	}
	
}
bool Breadth_first_search(){
	Point nNewPoint;
	qHead = 0;
	qTail = 1;
	Flags.reset();
	myQueue[qHead] = Point(0, 0, -1);
	
	//cout<<myQueue[qHead]<<endl;
	while(qHead != qTail){
		Point nPoint = myQueue[qHead];
		qHead ++;
		//cout<<"check point: "<<nPoint<<qHead<<endl;
		if(nPoint == goal) return true;
		if(Flags[nPoint.x*5+nPoint.y]) continue;
		Flags.set(nPoint.x*5+nPoint.y, true);
			
		if(!nPoint.is_extensible())continue;
		for(int i=0; i<4; i++){
			nNewPoint = NewPoint(nPoint, sz4Moves[i], qHead-1);	
			if((nNewPoint.x == -1))continue;
			if(Flags[nNewPoint.x*5+nNewPoint.y]==false){
				myQueue[qTail++] = nNewPoint;
				//cout<<nNewPoint<< qTail<<endl;
			}
		}
	}

	return false;
}
int Steps[100]={};
int main(){
	get_input();
//	print_maze();
	if(!Breadth_first_search()){
		cout<<"Unsolvable"<<endl;
		return 0;
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
	for(int i=k-1; i>=0; i--){
		cout<<myQueue[Steps[i]]<<endl;
	}	
	return 0;
}

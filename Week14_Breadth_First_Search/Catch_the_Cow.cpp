#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int N, K;
const int MAXN=100000;
int visited[MAXN+10];

struct Step{
	int x;
	int steps;
	Step(int xx, int s):x(xx), steps(s){}
};
queue<Step> q;
int main(void){
	cin >> N>>K;
	memset(visited, 0, sizeof(visited));	
	q.push(Step(N, 0));
	visited[N] = 1;
	while(!q.empty()){
		Step s= q.front();
		if(s.x == K){
			cout<<s.steps<<endl;	
			return 0;
		}else{//Breadth First Search
			if(s.x - 1>=0 && !visited[s.x-1]){
				q.push(Step(s.x -1, s.steps+1));
				visited[s.x -1] = 1;
			}
			if(s.x +1 <=MAXN && !visited[s.x+1]){
				q.push(Step(s.x +1, s.steps+1));
				visited[s.x +1] = 1;
				
			}
			if(s.x *2 <=MAXN && !visited[s.x*2]){
				q.push(Step(s.x*2, s.steps+1));
				visited[s.x*2] = 1;
				
			}
	


			q.pop();
		}




	}



	return 0;
}

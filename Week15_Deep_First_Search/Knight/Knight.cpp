#include <iostream>
#include <string.h>
using namespace std;

char chars[10] = "ABCDEFGH";
int chessboard[8][8];
int count = 0;

int R = 0;
int C = 0;

struct step{
    int row;
    char col;
    int ii, jj;
    step(int r, char c):row(r+1), col(chars[c]), ii(r), jj(c){
        
    }
    friend ostream & operator<<(ostream &o, step & s){
        o<<s.col<<s.row;
        return o;
    }
    step(){}
};

step steps[64];

bool allwalked(void){
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++){
            if(chessboard[i][j] == 0) return false;
        }
    return true;

}
step get_next_step(int i, int j){
    step tmpsteps[8];
    int stepcount = 0;

	if((i-1>=0) && (j-2>=0)){
        if(chessboard[i-1][j-2] == 0)
            tmpsteps[stepcount++] = step(i-1,j-2);
    }
    if((i+1<R) && (j-2>=0)){
        if(chessboard[i+1][j-2] == 0)
            tmpsteps[stepcount++] = step(i+1,j-2);
    }
	
    if((i-2>=0) && (j-1 >= 0)){
        if(chessboard[i-2][j-1] == 0)
            tmpsteps[stepcount++] = step(i-2,j-1);
    }
	if((i+2<R) && (j-1 >= 0)){
        if(chessboard[i+2][j-1] == 0)
            tmpsteps[stepcount++] = step(i+2,j-1);
    }
	
    if((i-2>=0) && (j+1 < C)){
        if(chessboard[i-2][j+1] == 0)
            tmpsteps[stepcount++] = step(i-2,j+1);
    }
    if((i+2<R) && (j+1 < C)){
        if(chessboard[i+2][j+1] == 0)
            tmpsteps[stepcount++] = step(i+2,j+1);
    }

  
    if((i-1>=0) && (j+2<C)){
        if(chessboard[i-1][j+2] == 0)
            tmpsteps[stepcount++] = step(i-1,j+2);
    }
    if((i+1<R) && (j+2<C)){
        if(chessboard[i+1][j+2] == 0)
            tmpsteps[stepcount++] = step(i+1,j+2);
    }
    

    if(stepcount == 0)return step(-1, -1);

    int min = 0;
    int sum  = 0;
    for(int k=0; k<stepcount; k++){
        if(sum > tmpsteps[k].col + tmpsteps[k].row){
            min = k;
            sum = tmpsteps[k].col + tmpsteps[k].row;
        }
    }

    return tmpsteps[min];
}
void DFS(int i, int j){
    step tmpstep;

    if(chessboard[i][j] == 1) return;
    chessboard[i][j] = 1;

    steps[count++] = step(i, j);    
   

    if((i-1>=0) &&(j-2>=0)&&(chessboard[i-1][j-2] == 0)){
        DFS(i-1, j-2);
        if(allwalked()) return;
    }

    if((i+1<R) && (j-2>=0) && (chessboard[i+1][j-2] == 0)){
        DFS(i+1, j-2);
        if(allwalked()) return;
    }

    if((i-2 >=0) && (j-1>=0) &&(chessboard[i-2][j-1] == 0)){
        DFS(i-2, j-1);
        if(allwalked()) return;
    }
    if((i+2<R) &&(j-1>=0) &&(chessboard[i+2][j-1] == 0)){
        DFS(i+2, j-1);
        if(allwalked()) return;
    }


    if((i-2>=0) &&(j+1<C) &&(chessboard[i-2][j+1] == 0)){
        DFS(i-2, j+1);
        if(allwalked()) return;
    }
    if((i+2 < R) && (j+1 < C) && (chessboard[i+2][j+1] == 0)){
        DFS(i+2, j+1);
        if(allwalked()) return;
    }

    if((i-1>=0) &&(j+2<C) &&(chessboard[i-1][j+2] == 0)){
        DFS(i-1, j+2);
        if(allwalked()) return;
    }
    if((i+1 <R) &&(j+2<C) && (chessboard[i+1][j+2] == 0)){
        DFS(i+1, j+2);
        if(allwalked()) return;
    }



    if(!allwalked()) {
        
        chessboard[i][j] = 0;
        count --;
    }
    return;
}
int main(void){
    int casenum = 0;
    bool ret = false;

    cin >> casenum;

    for(int k=0; k<casenum; k++){
        cout<<"Scenario #"<<k+1<<":"<<endl;
        R=0;
        C=0;
        cin >> R >> C;
        if(R>8 || C> 8){
            cout<<"impossible"<<endl; 
            cout<<endl;
            continue;
        } 
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                
                memset(chessboard, 0, sizeof(chessboard));
                count = 0;
                DFS(i, j);
                ret = allwalked();
                if(ret == true) 
                    break;

            }
            if(ret == true) break;

        }
        if(ret == true){
            for(int i=0; i<count; i++){
                cout<<steps[i];
            }
            cout<<endl;
        }else{
            cout<<"impossible"<<endl; 
        }

        cout<<endl;
    }
    return 0;
}

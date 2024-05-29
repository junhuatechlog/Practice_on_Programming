#include <iostream>
using namespace std;
struct Problem{
    int n;
    char src, mid, dest;

};


Problem stack[200];


int main(){
    cin >> stack[1].n;
    stack[1].src = 'A';
    stack[1].mid = 'B';
    stack[1].dest = 'C';
    int problemNum = 1;
    while(problemNum > 0){
        Problem curProblem = stack[problemNum];
        problemNum --;
        if(curProblem.n == 1){
            cout<<curProblem.src<<" -> "<<curProblem.dest<<endl;
            continue;
        }
        stack[++problemNum].n = curProblem.n-1;
        stack[problemNum].src = curProblem.mid;
        stack[problemNum].mid = curProblem.src;
        stack[problemNum].dest = curProblem.dest;

        stack[++problemNum].n = 1;
        stack[problemNum].src = curProblem.src;
        stack[problemNum].mid = curProblem.mid;
        stack[problemNum].dest = curProblem.dest;

        stack[++problemNum].n = curProblem.n-1;
        stack[problemNum].src = curProblem.src;
        stack[problemNum].mid = curProblem.dest;
        stack[problemNum].dest = curProblem.mid;
    
    }

    return 0;
}

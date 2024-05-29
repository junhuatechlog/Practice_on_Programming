#include <iostream>
#include <stdio.h>
using namespace std;

void output_value(int n, int i, int j){
    int value =0;
    if((n&(0x1<<i))!=0){
        value = 0x1<<i;
    }
    //printf("%d\n", n&(0x1<<j));
    if((n&(0x1<<j))==0){
        value += 0x1<<j;
     //   printf("value: %d\n", value);
    }
    printf("%d\n", value);

}

int main(void){
    int t=0;
    int n, i, j;
    scanf("%d", &t);
    for(int x =0; x<t; x++){
        scanf("%d %d %d", &n, &i, &j);
      //  printf("%d %d %d\n", n, i, j);
        output_value(n, i, j);
    }
    return 0;
}

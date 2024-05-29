#include <stdio.h>
#include <iostream>
using namespace std;

int myclock[9] = {};
int steps[10] = {};
int sum = 10000;
int mysteps[10] = {};
void get_steps(){
    for(int i=1; i<10; i++)
        cout<< steps[i]<< " ";
    cout<<endl;
    if(steps[1]>0 && steps[2]>0 && steps[4]>0 && steps[5]>0){
        steps[1] --;
        steps[2] --;
        steps[4] --;
        steps[5] --;
        cout<<1;
    }
    if(steps[1] > 0 && steps[2] > 0 && steps[3] >0){
        steps[1] --;
        steps[2] --;
        steps[3] --;
        cout<<2;
    }
    if(steps[2] > 0 && steps[3]>0&&steps[5]>0&&steps[6]>0){
        steps[2] --;
        steps[3] --;
        steps[5] --;
        steps[6] --;
        cout<<3;
    
    }
    if(steps[1] > 0 && steps[4]>0&&steps[7]>0){
        steps[1] --;
        steps[4] --;
        steps[7] --;
        cout<<4;
    }
    if(steps[2] > 0 && steps[4]>0&&steps[5]>0&&steps[6]>0&&steps[8]>0){
        steps[2] --;
        steps[4] --;
        steps[5] --;
        steps[6] --;
        steps[8] --;
        cout<<5;
    }
    if(steps[3] > 0 && steps[6]>0&&steps[9]>0){
        steps[3] --;
        steps[6] --;
        steps[9] --;
        cout<<6;
    }
    if(steps[4] > 0 && steps[5]>0&&steps[7]>0&&steps[8]>0){
        steps[4] --;
        steps[5] --;
        steps[7] --;
        steps[8] --;
        cout<<7;
    }
    if(steps[7] > 0 && steps[8]>0&&steps[9]>0){
        steps[7] --;
        steps[8] --;
        steps[9] --;
        cout<<8;
    }
    if(steps[5] > 0 && steps[6]>0&&steps[8]>0&&steps[9]>0){
        steps[5] --;
        steps[6] --;
        steps[8] --;
        steps[9] --;
        cout<<9;
    }
    cout<<endl;
    for(int i=1; i<10; i++){
        cout << steps[i];
    }
    cout <<endl;
}
void show_steps(){
    for(int i=1; i<10; i++)
        cout<< steps[i]<< " ";
    cout<<endl;
 /*   for(int i1=0; i1<=steps[1]; i1++)
    for(int i2=0; i2<=steps[2]; i2++)
    for(int i3=0; i3<=steps[3]; i3++)
    for(int i4=0; i4<=steps[4]; i4++)
    for(int i5=0; i5<=steps[5]; i5++)
    for(int i6=0; i6<=   steps[6]; i6++)
    for(int i7=0; i7<=   steps[7]; i7++)
    for(int i8=0; i8<=   steps[8]; i8++)
    for(int i9=0; i9<=   steps[9]; i9++){
    //    cout<<"test"<<endl;
        if((i1 == i2) && (i2 == i4)&&(i4==i5)&&(i4 >0)){
            cout<<"step " <<1<<endl;
        }
        if((i1==i2) &&(i2==i3)&&(i3>0)){
            cout<<"step " <<2<<endl;
        
        }
        if((i2==i3)&&(i3==i5)&&(i5==i6)&&(i5>0)){
            cout<<"step "<<3<<endl;
        }
        if((i1==i4)&&(i4==i7)&&(i7>0)){
            cout<<"step "<<4<<endl;
        }
        if((i2==i4)&&(i4==i5)&&(i5==i6)&&(i6==i7)&&(i7>0)){
            cout<<"step "<<5<<endl;
        }
        if((i3==i6)&&(i6==i9)&&(i9>0)){
            cout<<"step "<<6<<endl;
        }
        if((i4==i5)&&(i5==i7)&&(i7==i8)&&(i8>0)){
            cout<<"step "<<7<<endl;
        }
        if((i7==i8)&&(i8==i9)&&(i9>0)){
            cout<<"step "<<8<<endl;
        }
        if((i5==i6)&&(i6==i8)&&(i8==i9)&&(i9>0)){
            cout<<"step "<<9<<endl;
        }
    }
    */

}
enum CLOCK{
A,
B,
C,
D,
E,
F,
G,
H,
I

};
void enumate(void){

    for(int i1=0; i1<4; i1++)
    for(int i2=0; i2<4; i2++)
    for(int i3=0; i3<4; i3++)
    for(int i4=0; i4<4; i4++)
    for(int i5=0; i5<4; i5++)
    for(int i6=0; i6<4; i6++)
    for(int i7=0; i7<4; i7++)
    for(int i8=0; i8<4; i8++)
    for(int i9=0; i9<4; i9++){
            if(((i1+i2+i4+myclock[A]) %4 ==0) && 
                    ((i1+i2+i3+i5+myclock[B]) %4 ==0) &&
                    ((i2+i3+i6+myclock[C]) %4 ==0) &&
                    ((i1+i4+i5+i7+myclock[D]) %4 ==0) &&
                    ((i1+i3+i5+i7+i9+myclock[E])%4==0) &&
                    ((i3+i5+i6+i9+myclock[F]) %4 ==0) &&
                    ((i4+i7+i8+myclock[G]) %4 ==0) &&
                    ((i5+i7+i8+i9+myclock[H])%4==0)&&
                    ((i6+i8+i9+myclock[I])%4==0)){

//                cout<<"found one solution"<<endl; 
                int tmpsum = i1+i2+i3+i4+i5+i6+i7+i8+i9;
                if(tmpsum <sum){
                    sum = tmpsum;
                    steps[1] = i1; steps[2]=i2; steps[3]=i3; steps[4]=i4; steps[5] = i5; steps[6]=i6;
                    steps[7] = i7; steps[8] = i8; steps[9] = i9;
                }
                //show_steps();
            }



        }

}
int main(void){
    for(int i=0; i<3; i++){
        scanf("%d %d %d\n", &myclock[3*i], &myclock[3*i+1], &myclock[3*i+2]);
    }
    /*   for(int i=0; i<9; i++){
         cout<<myclock[i]<< " ";
         }
         cout<<endl;
     */
    enumate();
    //    cout<<"result: ";
    if(sum !=10000){
        //    get_steps();
        for(int i=1; i<10; i++){
            while(steps[i] >0){
                cout<< i<<" ";
                steps[i] --;
            }
        }
        cout<<endl;

    }

    //cout<<"Game over\n";
    return 0;
}

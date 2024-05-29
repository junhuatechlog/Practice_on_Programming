#include <iostream>  
#include <stdio.h>  
using namespace std;  
  
//???? ??????  
  
  
// clock???;  
int A[9]   ;  
  
// ???? ;  
int B[9][9] ={ 1,1,0,1,1,0,0,0,0,  
               1,1,1,0,0,0,0,0,0,     
               0,1,1,0,1,1,0,0,0,  
               1,0,0,1,0,0,1,0,0,  
               0,1,0,1,1,0,0,1,0,  
               0,0,1,0,0,1,0,0,1,  
               0,0,0,1,1,0,1,1,0,  
               0,0,0,0,0,0,1,1,1,  
               0,0,0,0,1,1,0,1,1 };  
//   int B[9][9] ={ 1,1,0,1,1,0,0,0,0,  
//                  1,1,1,0,0,0,0,0,0,     
//                  0,1,1,0,1,1,0,0,0,  
//                  1,0,0,1,0,0,1,0,0,  
//                  0,1,0,1,1,1,0,1,0,  
//                  0,0,1,0,0,1,0,0,1,  
//                  0,0,0,1,1,0,1,1,0,  
//                  0,0,0,0,0,0,1,1,1,  
//                  0,0,0,0,1,1,0,1,1 };  
  
// ?? :  ?? ?? ????? , ??????????3??  
  
bool isClock(int* a){  
    for (int i=0;i<9;i++)  
    {  
        if(a[i]!=0)  
            return false;  
    }  
    return true;  
}  
  
int main(){  
    int _min = 99999;  
    int lp1,lp2,lp3,lp4,lp5,lp6,lp7,lp8,lp9; // ???  
    int num; //????  
    int contain[10];  
    for (int i=0;i<9;i++)  
    {  
        cin>>A[i];  
    }  
    cout<<"input complete"<<endl;
    if (isClock(A))  
    {  
        cout<<"0"<<endl;  
        return 0;  
    }  
    for (lp1=0;lp1<=3;lp1++)  
    {  
        for (lp2=0;lp2<=3;lp2++)  
        {  
            for (lp3=0;lp3<=3;lp3++)  
            {  
                for (lp4=0;lp4<=3;lp4++)  
                {  
                    for (lp5=0;lp5<=3;lp5++)  
                    {  
                        for (lp6=0;lp6<=3;lp6++)  
                        {  
                            for (lp7=0;lp7<=3;lp7++)  
                            {  
                                for (lp8=0;lp8<=3;lp8++)  
                                {  
                                    for (lp9=0;lp9<=3;lp9++)  
                                    {     
                                        int flag =1;  
                                        for (int j=0;j<9;j++)  
                                        {  
                                            if( 0 != (A[j] + lp1*B[0][j] + lp2*B[1][j]+lp3*B[2][j]+lp4*B[3][j]+lp5*B[4][j]+lp6*B[5][j]+lp7*B[6][j]+lp8*B[7][j]+lp9*B[8][j])%4)  
                                                {  
                                                    flag =0;  
                                                    break;  
                                                }  
                                        }  
                                        if(flag){  
                                        cout<<lp1<<" "<<lp2<<" "<<lp3<<" "<<lp4<<" "<<lp5<<" "<<lp6<<" "<<lp7<<" "<<lp8<<" "<<lp9<<" "<<endl;  
                                        num = lp1+lp2+lp3+lp4+lp5+lp6+lp7+lp8+lp9;  
                                        if (num<_min)  
                                        {  
                                            _min = num;  
                                              
                                            contain[1]=lp1;  
                                            contain[2]=lp2;  
                                            contain[3]=lp3;  
                                            contain[4]=lp4;  
                                            contain[5]=lp5;  
                                            contain[6]=lp6;  
                                            contain[7]=lp7;  
                                            contain[8]=lp8;  
                                            contain[9]=lp9;  
                                        }     
          
                                        }     
                                          
                                    }  
                                }  
                            }  
                        }  
                    }  
                }  
            }  
        }  
    }  
    /*int i; 
    for(i=1;i<=9;i++) 
        if(contain[i]!=0) 
            num = i; 
    for(i=1;i<num;i++) 
    { 
        while(contain[i]>0) 
        { 
            printf("%d ",i); 
            contain[i]--; 
        } 
    } 
    while(contain[num]>1) 
    { 
        printf("%d ",num); 
        contain[num]--; 
    } 
    printf("%d\n",num); 
    */  
    for (int i=1;i<=9;++i)  
    {  
        while (contain[i]--)  
        {  
            printf("%d ",i);  
        }  
    }  
//    while (1);  
    return 0;  
} 

#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
typedef map<unsigned int,  unsigned int> MYMAP;
typedef MYMAP::iterator IT;
MYMAP gmp;

int main(void){
    int n;
    unsigned int key, id;
    IT upper;
    IT lower;
    cin >> n;
    gmp.insert(MYMAP::value_type(1000000000, 1));
    for(int i=0; i<n; i++){
       scanf("%d %d", &id, &key); 
       lower = gmp.lower_bound(key);
       upper = gmp.upper_bound(key);
       if((upper == lower)&&(lower == gmp.begin())){
           printf("%d %d\n", id, lower->second); 
           gmp.insert(MYMAP::value_type(key, id));
            continue;  
       }
//            printf("lower first: %d\n", lower->first);
        if(lower->first - key >=0) {
            --lower;
//            printf("lower new first: %d\n", lower->first);
        }
 /*      printf("upper->first - key: %d\n", upper->first - key);
           printf("key - lower->first: %d\n", key - lower->first);
  */     if((upper->first - key) >= (key  - lower->first)){
           printf("%d %d\n", id, lower->second); 
           gmp.insert(MYMAP::value_type(key, id));
            continue;  
       }
       printf("%d %d\n", id, upper->second); 
        gmp.insert(MYMAP::value_type(key, id));
    }


    return 0;
}

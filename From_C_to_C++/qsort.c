#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//void qsort(void *base, size_t nmemb, size_t size,
//                                 int(*compar)(const void *, const void *));
int MyCompare(const void * e1, const void * e2)
{
    unsigned int *p1, *p2;
    p1 = (unsigned int *)e1;
    p2 = (unsigned int *)e2;
    return (*p1%10 - *p2%10);
}
int main()
{
    unsigned int arr[9] = {1, 57, 36, 58, 2210, 239, 23, 122, 564};
    int i;
    qsort(arr, 9, sizeof(unsigned int), MyCompare);

    for(i = 0; i<9; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

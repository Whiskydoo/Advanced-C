#include <stdio.h>
int isEqual(char A[], char B[])
{
    char *p1;
    char *p2;
    p1 = A;
    p2 = B;
    int i = 0;
    while(1)
    {
        if((int)(*(p1+i))!=(int)(*(p2+i)))
            return 0;
        if((int)(*(p1+i)==0)&&((int)*(p2+i)==0))
            return 1;
        i++;
    } 
} 

void main()
{
    char A[10] = "abcd";
    char B[10] = "abcd";
    if(sizeof(A)!=sizeof(B))
    {
        printf("These string are not equal");
        return;
    }
    if(isEqual(A, B)== 1)
        printf("These string are equal");
    else
        printf("These string are not equal");
}
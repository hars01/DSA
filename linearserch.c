#include <stdio.h>
int main() {
    int a[]={10,30,50,60,40};
    int e=30,t=0;
    for(int i=0; i<5; i++)
    {
        if(a[i]==e) {
         t=1;
         break;
        }
    }
    if(t==1)
     printf("Item will finded");
    else 
        printf("Not Finded");
    return 0;
}
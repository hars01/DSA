#include<stdio.h>
#include<string.h>
void soln(char a[])
{
    int n=strlen(a);
    int j=0;
    char s[100];
    for(int i=0; i<n;i++)
    {
        s[j]=a[i];
        j++;
    }
    s[j]='\0';
    
}
int main()
{
    char a[]="Ha1rs45h";
    char b[100];
    int j=0;
    int n=strlen(a);
    for(int i=0;i<n;i++)
    {
        printf("%c",a[i]);
    }
     for(int i=0; i<n;i++)
    {   
        if(a[i]=='0'&&a[i]=='1'&&a[i]=='2'&&a[i]=='3'&&a[i]=='4'&&a[i]=='5'&&a[i]=='6'&&a[i]=='7'&&a[i]=='8'&&a[i]=='9')
        {
        b[j]=a[i];
        j++;
        }
        else 
        return 0;
    }
    b[j]='\0';
    printf("\n");
    for(int k=0;k<j+1;k++)
    {
        printf("%c",b[k]);
    }
    return 0;
}
#include <stdio.h>
#include<string.h>
char* removeOccurrences(char*s, char* part) {
    int l=strlen(s);
    int p=strlen(part);
    int i=0;
    while(i<l)
    {
        if(strstr(&s[i],part)==&s[i])
        {
          l-=p;
          for(int j=i;j<l;j++)
          s[j]=s[j+p];
        }
        else 
        i++;
    }
    s[i]='\0';
    return s;
}
int main() {
   char str[]="Hate The Sine Love The Sinner";
   char s[]="The ";
   puts(str);
   removeOccurrences(str,s);
   puts(str);

    return 0;
}
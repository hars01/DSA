#include <stdio.h> 
#include <string.h> 
char v(char str[],char ch) {
    int len = strlen(str);
	for (int i = 0; i <= len-1; i++) { 
		if(str[i]==ch)
		{
		for (int k = 0, j = i; k <= j; k++, j--)
		{
		char c = str[k]; 
		str[k] = str[j]; 
		str[j] = c; 
		}
		break;
		}
	} 
	puts(str);
}

int main() 
{ 
	char str[100] = "harshya"; 
	puts(str); 
	v(str,'r');
	 
	return 0; 
}
#include<stdio.h>
#include<string.h>

int main()
{
	char s[30];
	int c,i,j;
	
	printf("digite uma string: ");
	scanf("%s", &s);
	for(i=0,j=strlen(s)-1;i<j;i++,j--)
	{
		c=s[i],s[i]=s[j],s[j]=c;//swap
	}
	printf("string invertida: %s\n", s);
	return 0;
}

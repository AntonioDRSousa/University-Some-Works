#include<stdio.h>
#include<ctype.h>

int atoi(char s[]);

int main()
{
	char s[30];
	printf("Digite uma string numerica: ");
	scanf("%s", &s);
	printf("%d",atoi(s));
	return 0;
}

int atoi(char s[])
{
	int i,n;
	n=0;
	for(i=0;isdigit(s[i]);i++)
	{
		n=10*n+(s[i]-'0');
	}
	return n;
}

	
	

#include<stdio.h>
#include<stdlib.h>

int toi(char*);

int main(){
	char s[30];
	printf("Digite: ");
	scanf("%s",s);
	printf("%d\n",toi(s));
	return 0;
}

int toi(char*s){
	int i,n;
	n=0;
	for(i=0;*(s+i)>='0' && *(s+i)<='9';++i){
		n=10*n+(*(s+i)-'0');
	}
	return n;
}
	

#include<stdio.h>
#include<stdlib.h>

void copy(char*,char*);

int main(){
	char to[30],from[30];
	printf("Digite: ");
	scanf("%s",to);
	printf("to -> %s\n",to);
	copy(to,from);
	printf("from -> %s\n",from);
	return 0;
}

void copy(char*to,char*from){
	int i=0;
	while((*(from+i)=*(to+i))!='\0')
		i++;
}

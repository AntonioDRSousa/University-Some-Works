#include<stdio.h>

char lower(char c);

int main(){
	char c;
	printf("Digite um caracter: ");
	c=getchar();
	printf("\n%c\n", lower(c));
	return 0;
}

char lower(char c){
	if(c>='A'&&c<='Z'){
		return c+'a'-'A';
	}
	else{
		return c;
	}
}
	

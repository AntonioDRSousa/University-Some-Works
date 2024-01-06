#include<stdio.h>

int main(){
	int a=1;
	int c;
	int b;
	printf("A: ");
	scanf("%d", &a);
	printf("B: ");
	scanf("%d", &b);

	c=(a>b)?(a-b):(b-a);
	printf("c= %d",c);
	return 0;
}

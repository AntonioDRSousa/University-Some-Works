#include<stdio.h>

int main(void){
	int *x[10];
	int i;

	for(i=0;i<10;i++)
	{
		x[i]=&i;
	}
	printf("\n");
	for(i=0;i<10;i++)
	{
		printf("%d ", *x[i]);
	}
	return 0;
} 

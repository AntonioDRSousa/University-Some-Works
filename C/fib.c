#include<stdio.h>

int fib(int);

int main(){
	int n,m;
	scanf("%d",&n);
	m=fib(n);
	printf("F(%d) = %d\n",n,m);
	return 0;
}

int fib(int x){
	if(x<=1){
		return x;
	}
	else{
		return fib(x-1)+fib(x-2);
	}
}	

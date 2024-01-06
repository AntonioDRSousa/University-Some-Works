#include<stdio.h>

void bal(int);

int main(){
	int n;
	printf("n = ");
	scanf("%d",&n);
	bal(n);
	return 0;
}

void bal(int n){
	static int i=1;
	if(n>0){
		if(n%3==1){
			printf("+%d ",i);
			n--;
		}
		else if(n%3==2){
			printf("-%d ",i);
			n++;
		}
		i*=3;
		bal(n/3);
	}
}

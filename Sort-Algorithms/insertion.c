#include<stdio.h>

void vinput(int v[],int);
void impr(int v[],int);
void insertion(int v[],int);

int main(){
	int n;
	printf("n = ");
	scanf("%d",&n);
	printf("\n\n\n");
	int v[n];
	vinput(v,n);
	printf("\n\n\n");
	impr(v,n);
	printf("\n\n\n");
	insertion(v,n);
	printf("\n\n\n");
	impr(v,n);
	return 0;
}

void insertion(int v[], int n){
	if(n>0){
		insertion(v,n-1);
		register int i=n-2,a=v[n-1];
		while(i>=0 && v[i]>a){
			v[i+1]=v[i];
			i--;
		}
		v[i+1]=a;
	}
}	

void vinput(int v[],int n){
	register int i;
	for(i=0;i<n;i++){
		printf("V[%d] = ",i+1);
		scanf("%d",&v[i]);
	}
}

void impr(int v[],int n){
	register int i;
	for(i=0;i<n;i++){
		printf("%d ",v[i]);
	}
}

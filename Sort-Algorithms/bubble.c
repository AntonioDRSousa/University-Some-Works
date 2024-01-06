#include<stdio.h>

void vinput(int v[],int);
void impr(int v[],int);
void bubble(int v[],int);

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
	bubble(v,n);
	printf("\n\n\n");
	impr(v,n);
	return 0;
}

void bubble(int v[], int n){
	if(n>0){
		register int i,temp;
		for(i=0;i<n-1;i++){
			if(v[i]>v[i+1]){
				temp=v[i];
				v[i]=v[i+1];
				v[i+1]=temp;
			}
		}
		bubble(v,n-1);
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

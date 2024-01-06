#include<stdio.h>

void selection(int b[],int n){
	int i,j,t;
	int pmax;
	for(i=n-1;i>=1;i--){
		pmax=0;
		for(j=1;j<=i;j++){
			if(b[pmax]<=b[j]){
				pmax=j;
			}
		}
		t=b[i];
		b[i]=b[pmax];
		b[pmax]=t;
	}
}

int main(){
	int n,i;
	printf("Digite n: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		printf("A[%d] = ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\n\n\n");
	selection(a,n);
	for(i=0;i<n;i++){
		printf("A[%d] = %d\n",i+1,a[i]);
	}
	return 0;
}


#include<stdio.h>

void insertion(int a[],int n){
	int i,j,t;
	for(i=1;i<=n;i++){
		j=i-1;
		while(j>=0 && a[j]>a[j+1]){
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
			j=j-1;
		}
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
	insertion(a,n);
	for(i=0;i<n;i++){
		printf("A[%d] = %d\n",i+1,a[i]);
	}
	return 0;
}


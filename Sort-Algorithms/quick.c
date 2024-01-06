#include<stdio.h>

void quicksort(int*,int,int);
void particao(int*,int,int,int*,int*);

int main(){
	int n;
	scanf("%d",&n);
	int v[n];
	printf("\n");
	for(register int i=0;i<n;i++){
		printf("v[%d] = ",i+1);
		scanf("%d",&v[i]);
	}
	printf("\nv = ");
	for(register int i=0;i<n;i++){
		printf("%d ",v[i]);
	}
	quicksort(v,0,n);
	printf("\nv = ");
	for(register int i=0;i<n;i++){
		printf("%d ",v[i]);
	}
	return 0;
}

void quicksort(int*v,int e,int d){
	if(d>e){
		int i,j;
		particao(v,e,d,&i,&j);
		quicksort(v,e,j);
		quicksort(v,i,d);
	}
}
void particao(int*v,int e,int d,int*i,int*j){
	*i=e;
	*j=d;
	int t=v[(e+d)/2];
	while(*i<=*j){
		while(v[*i]<t){
			(*i)++;
		}
		while(v[*j]>t){
			(*j)--;
		}
		if(*i<=*j){
			int*temp;
			temp=i;
			i=j;
			j=temp;
			(*i)++;
			(*j)--;
		}
	}
}

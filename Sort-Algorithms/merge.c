#include<stdio.h>

void sort(int v[],int,int,int);
void merge(int v[],int,int,int,int);
void vinput(int v[],int);
void impr(int v[],int);

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
	sort(v,0,n-1,n);
	printf("\n\n\n");
	impr(v,n);
	return 0;
}

void sort(int v[],int i,int f,int n){
	static int x=0;
	int m;
	if(i<f){
		printf("%d sort\n", ++x);
		m=(f/2)+(i/2);
		sort(v,i,m,n);
		sort(v,m+1,f,n);
		merge(v,i,m,f,n);
	}
}
void merge(int v[],int i,int m,int f,int n){
	printf("merge\n");
	int t[n];
	int r=i,s=m+1;
	int k;
	for(k=i;k<=f;k++){
		if(s>f || (r<=m && v[r]<v[s])){
			t[k]=v[r];
			r++;
		}
		else{
			t[k]=v[s];
			s++;
		}
	}
	for(k=i;k<=f;k++){
		v[k]=t[k];
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
	
	

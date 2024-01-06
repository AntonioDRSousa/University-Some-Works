#include<stdio.h>
#include<stdlib.h>

void swap(float*,float*);
void maxmin(float*,float*);

int main(){
	float max,min;
	fscanf(stdin,"%f%f",&max,&min);
	maxmin(&max,&min);
	fprintf(stdout,"maior numero -> %f\nmenor numero -> %f\n",max,min);
	return 0;
}

void swap(float*x,float*y){
	float temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void maxmin(float*a,float*b){
	if((*a)<(*b)){
		swap(a,b);
	}
}
	
	

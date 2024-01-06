//implementacao que representa uma lista encadeada [1,2,3,4]

#include<stdio.h>
#include<stdlib.h>

typedef struct no{
		int x;
		struct no * next;
}no;

struct no * phead=NULL; 

void insere(struct no**,int);//insere elemento no final da lista
void impr(struct no*);
void imprimelista(struct no*);//imprime a lista

void main(void){
	insere(&phead,1);
	insere(&phead,2);
	insere(&phead,3);
	insere(&phead,4);

	impr(phead);
}

void insere(struct no **p,int x){
	if(*p){
		insere(&((*p)->next),x);
	}
	else{
	
		struct no * q=(struct no*) malloc(sizeof(struct no));
		q->x=x;
		
		struct no * elem=q;
		elem->next=NULL;
		
		*p=elem;
	}
}

void impr(struct no * p){
	printf("[ ");
	imprimelista(phead);
	printf(" ]");
}

void imprimelista(struct no * p){
	if(p){
	
		printf("%d",p->x);
		
		if(p->next!=NULL){
			printf(", ");
		}
		
		imprimelista(p->next);
		
	}
}

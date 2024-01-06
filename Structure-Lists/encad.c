#include<stdio.h>
#include<stdlib.h>

typedef struct coord{
		int x,y;
		struct coord * next;
}coord;

struct coord * criaelem(int,int);//
void insereinicio(struct coord**,int,int);//
void inserefim(struct coord**,int,int);//
void imprimeelemento(struct coord*);//
void imprimelista(struct coord*);//
struct coord * buscacoord(int,int, struct coord*);//
void excluielemcoord(int,int,struct coord **);//
void excluielempont(struct coord *, struct coord **);
void limparlista(struct coord**);//

int main(int argc,char*argv[]){
	register int i;
	int x,y;
	struct coord *phead=NULL;
	for(i=1;i<6;i++){
		insereinicio(&phead,i,i+2);
		printf("\nInicio -> \n");
		imprimelista(phead);
		inserefim(&phead,i*2,i*2+2);
		printf("\nFim -> \n");
		imprimelista(phead);
	}
	printf("\n\nLista Final -> \n");
	imprimelista(phead);
	printf("\nDigite x e y: ");
	scanf("%d %d",&x,&y);
	if(buscacoord(x,y,phead)){
		printf("Existe!\n");
	}
	else{
		printf("Nao existe!\n");
	}
	printf("\nDigite x e y: ");
	scanf("%d %d",&x,&y);
	excluielemcoord(x,y,&phead);
	imprimelista(phead);
	printf("\n");
	limparlista(&phead);
	imprimelista(phead);
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////
struct coord * criaelem(int x,int y){
	struct coord * p=(struct coord*) malloc(sizeof(struct coord));
	p->x=x;
	p->y=y;
	return p;
}
void insereinicio(struct coord **p,int x,int y){
	struct coord * elem = criaelem(x,y);
	elem->next= *p;
	*p=elem;
}
void inserefim(struct coord **p,int x,int y){
	if(*p){
		inserefim(&((*p)->next),x,y);
	}
	else{
		struct coord * elem=criaelem(x,y);
		elem->next=NULL;
		*p=elem;
	}
}
///////////////////////////////////////////////////////////////////////////////////////
void imprimeelemento(struct coord * e){
	if(e){
		printf("(%d,%d)\n",e->x,e->y);
	}
	else{
		printf("Elemento inexistente!\n");
	}
}
void imprimelista(struct coord * p){
	if(p){
		imprimeelemento(p);
		imprimelista(p->next);
	}
	else{
		printf("Fim da Lista\n");
	}
}
////////////////////////////////////////////////////////////////////////////////////////////
struct coord * buscacoord(int x,int y,struct coord * p){
	if(p){
		if((x==p->x) && (y==p->y)){
			return p;
		}
		else{
			return buscacoord(x,y,p->next);
		}
	}
	else{
		return NULL;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////
void excluielemcoord(int x,int y,struct coord**p){
	if(*p){
		if((x==(*p)->x) && (y==(*p)->y)){
			struct coord *e=*p;
			*p=e->next;
			free(e);
			printf("Elemento excluido com sucesso!\n");
		}
		else{
			excluielemcoord(x,y,&((*p)->next));
		}
	}
	else{
		printf("Elemento nao encontrado!\n");
	}
}
void excluielempont(struct coord * e, struct coord ** p){
	if(*p){
		if(*p==e){
			*p=e->next;
			free(e);
			printf("Elemento excluido com sucesso!\n");
		}
		else{
			excluielempont(e,&((*p)->next));
		}
	}
	else{
		printf("Elemento nao encontrado!\n");
	}
}
void limparlista(struct coord **p){
	if(*p){
		limparlista(&((*p)->next));
		free(*p);
		*p=NULL;
	}
}

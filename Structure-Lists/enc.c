#include<stdio.h>
#include<stdlib.h>

typedef struct coord{
		int x,y;
		struct coord * next;
}coord;

struct coord *phead=NULL; //a variável global e' alocada na memoria estática

struct coord * criaelem(int,int);
void insereinicio(struct coord**,int,int);
void inserefim(struct coord**,int,int);
void imprimeelemento(struct coord*);
void imprimelista(struct coord*);
struct coord * buscacoord(int,int, struct coord*);
void excluielemcoord(int,int,struct coord **);
void limparlista(struct coord**);

void main(void){
	int x,y,op;//as 3 variáveis são alocadas na pilha

	for(;;){
		printf("-----------------\n");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
		printf("1 - Cria Lista Encadeada\n");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
		printf("2 - Insere Elemento na Lista Encadeada no Inicio\n");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
		printf("3 - Insere Elemento na Lista Encadeada no Fim\n");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
		printf("4 - Busca de Elemento\n");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
		printf("5 - Remover elemento\n");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
		printf("6 - Limpar Lista Encadeada\n");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
		printf("7 - Imprime Lista\n");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
		printf("8 - Sair\n");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
		printf("-----------------\n");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
		scanf("%d",&op);//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha

		switch(op){
			case 1:
				if(phead!=NULL){
					free(phead);//e' desalocada memoria da heap
				}
				phead=NULL;
				break;
			case 2:
				printf("\nDigite x e y: ");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
				scanf("%d %d",&x,&y);//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
				insereinicio(&phead,x,y);//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
				break;
			case 3:
				printf("\nDigite x e y: ");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
				scanf("%d %d",&x,&y);//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
				inserefim(&phead,x,y);//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
				break;
			case 4:
				printf("\nDigite x e y: ");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
				scanf("%d %d",&x,&y);//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
				if(buscacoord(x,y,phead)){//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
					printf("Existe!\n");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
				}
				else{
					printf("Nao existe!\n");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
				}
				break;
			case 5:
				printf("\nDigite x e y: ");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
				scanf("%d %d",&x,&y);//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
				excluielemcoord(x,y,&phead);//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
				break;
			case 6:
				limparlista(&phead);//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
				break;
			case 7:
				printf("\n\n~~~~~~~~~~\n\n");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
				imprimelista(phead);//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
				printf("\n\n~~~~~~~~~~\n\n");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
				break;
			case 8:
				if(phead!=NULL){
					free(phead);//e' desalocada memoria da heap
				}
				phead=NULL;
				exit(0);
		}
		
	}
}

//insere elemento na lista encadeada
struct coord * criaelem(int x,int y){//os argumentos sao alocadas na pilha
	struct coord * p=(struct coord*) malloc(sizeof(struct coord));//a variavel local de endereco e' alocada na pilha, mas o malloc aloca uma regiao de memoria para o qual ela aponta
	p->x=x;
	p->y=y;
	return p;
}
void insereinicio(struct coord **p,int x,int y){//os argumentos sao alocados na pilha
	struct coord * elem = criaelem(x,y);//a variavel local e' alocada na pilha
	elem->next= *p;
	*p=elem;
}
void inserefim(struct coord **p,int x,int y){//os argumentos sao alocados na pilha
	if(*p){
		inserefim(&((*p)->next),x,y);//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
	}
	else{
		struct coord * elem=criaelem(x,y);//a variavel local e' alocada na pilha
		elem->next=NULL;
		*p=elem;
	}
}

//imprime lista encadeada
void imprimeelemento(struct coord * e){//os argumentos sao alocados na pilha
	if(e){
		printf("(%d,%d)\n",e->x,e->y);//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
	}
	else{
		printf("Elemento inexistente!\n");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
	}
}
void imprimelista(struct coord * p){//os argumentos sao alocados na pilha
	if(p){
		imprimeelemento(p);//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
		imprimelista(p->next);//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
	}
}

//busca elemento na lista encadeada
struct coord * buscacoord(int x,int y,struct coord * p){//os argumentos sao alocados na pilha
	if(p){
		if((x==p->x) && (y==p->y)){
			return p;
		}
		else{
			return buscacoord(x,y,p->next);//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
		}
	}
	else{
		return NULL;
	}
}

//exclui elemento de lista encadeada
void excluielemcoord(int x,int y,struct coord**p){//os argumentos sao alocados na pilha
	if(*p){
		if((x==(*p)->x) && (y==(*p)->y)){
			struct coord *e=*p;//a variavel local e' alocada na pilha
			*p=e->next;
			free(e);//a memoria do ponteiro e' desalocada da heap
			printf("Elemento excluido com sucesso!\n");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
		}
		else{
			excluielemcoord(x,y,&((*p)->next));//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
		}
	}
	else{
		printf("Elemento nao encontrado!\n");//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
	}
}

//limpa lista encadeada
void limparlista(struct coord **p){//os argumentos sao alocados na pilha
	if(*p){
		limparlista(&((*p)->next));//toda a chamada de funcoes aloca os argumentos e variaveis locais na pilha
		free(*p);//a memoria do ponteiro e' desalocada da heap
		*p=NULL;
	}
}

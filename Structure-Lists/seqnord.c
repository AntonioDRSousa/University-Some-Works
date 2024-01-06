#include<stdio.h> //lista linear sequencial não ordenada
#include<stdlib.h>
#define max 100
typedef struct no{
	int chave;
	int elem;
} no;
typedef struct linear{
	no val[max+1];
	int N;
} linear;
void constroi(linear * L){
	L->N=0;
}
void enumera(linear * L){
	register int i;
	for(i=1;i<=L->N;i++){
		printf("posicao=%d, chave=%d, elemento=%d\n",i,L->val[i].chave,L->val[i].elem);
	}
}
void insere(linear * L,int c,int x){
	if(L->N<max){
		L->val[L->N+1].chave=c;
		L->val[L->N+1].elem=x;
		L->N=L->N+1;
	}
	else{
		printf("lista cheia\n");
		exit(0);
	}
}
void insereem(linear * L,int pos,int c,int x){
	no t;//para o swap
	if(L->N<max){
		L->val[L->N+1].chave=c;
		L->val[L->N+1].elem=x;
		L->N=L->N+1;
		t=L->val[pos];
		L->val[pos]=L->val[L->N];
		L->val[L->N]=t;
	}
	else{
		printf("lista cheia\n");
		exit(1);
	}
}
int busca(linear * L, int c){//busca sequencial
	int i;
	for(i=1;i<=L->N;i++){
		if(L->val[i].chave==c){
			return L->val[i].elem;
		}
	}
	return -1;
}
int buscaem(linear * L, int pos){
	return L->val[pos].elem;
}
int buscapos(linear * L,int c){
	int i=1;
	while(i<=L->N && L->val[i].chave!=c){
		i=i++;
	}
	if(i<=L->N){
		return i;
	}
	else{
		return -1;
	}
}
int removeem(linear * L,int pos){
	if(L->N>0){
		int x=L->val[pos].elem;
		L->val[pos]=L->val[L->N];
		L->N=L->N-1;
		return x;
	}
	else{
		printf("underflow\n");
		exit(2);
	}
}
int rve(linear * L,int c){//remove
	int pos=buscapos(L,c);
	if(pos>0){
		return removeem(L,pos);
	}
}	
int main(){
	linear L;
	register int i;
	int c,x,pos;
	char s;
	int m;
	printf("Digite o tamanho da lista: ");
	scanf("%d",&m);
	constroi(&L);
	for(i=0;i<m;i++){
		printf("Digite a chave e o elemento: ");
		scanf("%d%d",&c,&x);
		insere(&L,c,x);
	}
	enumera(&L);
	for(i=0;i<m;i++){
		printf("Digite a chave, o elemento e a posicao: ");
		scanf("%d%d%d",&c,&x,&pos);
		insereem(&L,pos,c,x);
	}
	enumera(&L);
	for(;;){
		printf("Diga uma posicao a remover: ");
		scanf("%d",&pos);
		x=removeem(&L,pos);
		printf("Elemento removido: %d\n",x);
		printf("Informa uma chave a remover: ");
		scanf("%d",&c);
		x=rve(&L,c);
		printf("Elemento removido: %d\n",x);
		printf("Sair(s)?");
		scanf("%c",&s);
		if(s=='s'){
			break;
		}
	}
	enumera(&L);
	for(;;){
		printf("Digite uma chave: ");
		scanf("%d",&c);
		x=busca(&L,c);
		pos=buscapos(&L,c);
		printf("Elemento correspondente: %d\n",x);
		printf("Posicao correspondente: %d\n",pos);
		printf("Digite a posicao: ");
		scanf("%d",&pos);
		x=buscaem(&L,pos);
		printf("Elemento correspondente: %d\n",x);
		printf("Sair(s)?");
		scanf("%c",&s);
		if(s=='s'){
			break;
		}
		printf("\n");
	}
	
	return 0;
}
		

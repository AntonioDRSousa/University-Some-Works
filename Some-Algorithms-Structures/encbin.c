//opção usal quando a arvore é binaria
#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	int chave;
	int elem;
	struct no * esq;
	struct no * dir;
} no;
typedef struct arvore{
	no * raiz;
} arvore;
void constroi(arvore T){
	T.raiz=NULL;
}

int main(){
	arvore T;
	constroi(T);
	return 0;
}
	


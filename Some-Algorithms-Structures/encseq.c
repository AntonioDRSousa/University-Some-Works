//arvore m-ária
//alocação encadeada de nós
//alocação sequencial de filhos
#include<stdio.h>
#include<stdlib.h>

#define M 5//arvore 5-ária
typedef struct no{
	int chave;
	int elem;
	struct no * nosfilhos[M];
} no;
typedef struct arvore{
	no * raiz;
	int m;
} arvore;
void constroi(arvore T,int m){
	T.raiz=NULL;
	T.m=m;
}

int main(){
	arvore T;
	constroi(T,M);
	return 0;
}
	
	

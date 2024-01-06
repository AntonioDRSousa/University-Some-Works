#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int Chave;
	int Elem;
	struct No * Prox;
} No;

typedef struct ListaLinear {
	No * Inicio;
	int N; //número corrente de elementos na lista
} ListaLinear;

void Constroi(ListaLinear * L) {
	(*L).N = 0; //L->N = 0;
	L->Inicio = NULL;
}

int Busca(ListaLinear * L, int c) {
	No * noCorr;

	noCorr = L->Inicio;
	while (noCorr != NULL) {
		if (noCorr->Chave == c) {
			return noCorr->Elem;
		} else {
			noCorr = noCorr->Prox;
		}
	}
	return -1;
}

void Insere(ListaLinear * L, int c, int x) {
	No * novo;
	novo = (No *) malloc(sizeof(No));
	novo->Chave = c;
	novo->Elem = x;
	novo->Prox = L->Inicio;
	L->Inicio = novo;
	L->N = L->N+1;
}

int main() {
	
	ListaLinear L; //<Caracter, Inteiro>
	Constroi(&L);

	Insere(&L, 1, 4);
	Insere(&L, 2, 2);	
	Insere(&L, 3, 1);	

	int c;
    printf("entre com uma chave: ");
	scanf("%d", &c);
	int q;
	q = Busca(&L, c);
	if (q == -1) {   //"NULO" = -1
		printf("nao encontrado.\n");
	} else {
		printf("%d\n", q);
	}

	return 0;
}



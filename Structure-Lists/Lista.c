#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

typedef struct No {
	int Chave;
	int Elem;
} No;

typedef struct ListaLinear {
	No Val[MAX_N+1]; //posicao 0 sem uso
	int N; //número corrente de elementos na lista
} ListaLinear;

void Constroi(ListaLinear * L) {
	(*L).N = 0; //L->N = 0;
}

int Busca(ListaLinear * L, int c) {
	int i;
	for (i=1; i<=L->N; i++) {
		if (L->Val[i].Chave == c) {
			return L->Val[i].Elem;
		}
	}
	return -1;
}

void Insere(ListaLinear * L, int c, int x) {
	if (L->N < MAX_N) {
		L->Val[L->N+1].Chave = c;
		L->Val[L->N+1].Elem = x;
		L->N = L->N+1;

	} else {
		printf("lista cheia!\n");
		exit(0);
	}
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



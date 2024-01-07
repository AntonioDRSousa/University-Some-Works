#include<stdio.h>

#include<stdlib.h>

#define MAX 100000000
#define MEMSIZE(n) sizeof(int)*n



int * v;

int size;



void initTamanho(int * n){

	for(;;){

		printf("Digite o tamanho inicial do vetor: ");

		scanf("%d",n);

		if(*n<=0){

			printf("Erro. Tamanho do vetor menor ou igual a zero.....\n");

		}
		else if(*n>MAX){
			printf("Erro. Tamanho acima da capacidade maxima %d.....\n",MAX);
		}

		else{

			break;

		}

	}

}



void criaVetor(int n){

	v=(int *)(calloc(n,(sizeof(int))));

	size=n;

}



void insere(int x, int pos){
	if((pos-1)>MAX){
		printf("Erro. Posicao acima da capacidade maxima %d.....\n",MAX);
	}
	else{

		if(pos>=size){

			v=(int*)(realloc(v,(pos+1)*(sizeof(int))));

			size=pos+1;

		}

		v[pos]=x;
	}

}



int main(void){

	int n;
	int op;

	

	for(;;){

		int x, pos, i;

		printf("-------------------\n1 - Cria Novo Vetor\n2 - Insere Elemento\n3 - Imprime\n");
		printf("4 - Libera Memoria\n5 - Quantidade de Memoria Ocupada pelo Vetor\n6 - Sair\n-------------------\n\n");
		fflush(stdout);
		scanf("%d",&op);

		if(op==6){

			break;

		}

		switch(op){

			case 1: //cria novo vetor

				if(v!=NULL){

					free(v);

				}

				initTamanho(&n);

				criaVetor(n);

				break;

			case 2: //insere elemento no vetor

				printf("Digite um elemento inteiro a inserir: ");

				scanf("%d",&x);

				printf("Digite a posicao a inserir: ");

				scanf("%d",&pos);

				insere(x,pos);

				break;

			case 3: //imprime

				printf("Tamanho = %d\nV =  ",size);

				for(i=0;i<size;i++){

					printf("%d ",v[i]);

				}

				printf("\n\n");

				break;

			case 4:

				if(v!=NULL){

					free(v);

					v=NULL;

					size=0;

				}

				break;
			case 5:
				printf("Tamanho de um int = %d\n",sizeof(int));
				printf("Quantida de Memoria Ocupada pelo Vetor v = %d\n",MEMSIZE(size));
				break;
			default:
				printf("Erro.....\n");

		}

	}



	free(v);

	

	return 0;

}
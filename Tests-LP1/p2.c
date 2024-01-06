#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRINT_MSG(NUM) printf("\n\n***********\n     %d     \n***********\n\n",NUM);

struct histograma{
	unsigned int Maximo;
	long int *Vetor;
};

struct histograma criaHistograma(char*);
int comparaHistogramas(struct histograma, struct histograma);
void deletaHistograma(struct histograma*);
void imprimeHistograma(struct histograma);

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("Erro: numero de argumentos deve ser igual a três\n");
		return 1;
	}

   struct histograma Histograma1 = criaHistograma(argv[1]);
	imprimeHistograma(Histograma1);

	struct histograma Histograma2 = criaHistograma(argv[2]);
	imprimeHistograma(Histograma2);

	if (comparaHistogramas(Histograma1, Histograma2))
		printf("Os histogramas das imagens %s e %s são idênticos\n\n",argv[1],argv[2]);
	else
		printf("Os histogramas das imagens %s e %s são distintos\n\n",argv[1],argv[2]);

	deletaHistograma(&Histograma1);
	deletaHistograma(&Histograma2);
}

struct histograma criaHistograma(char* arq){
    FILE *fp;
    register int i; 
    unsigned int x,y; 
    struct histograma h;
    //abre arquivo
    if((fp=fopen(arq,"r"))==NULL){
        fprintf(stderr,"Erro ao abrir arquivo\n");
        exit(2);
    }
    ////pula a primeira linha//////
    while(getc(fp)!='\n')
        ;
    //////////////////////////////
    fscanf(fp,"%u %u",&x,&y); 
    fscanf(fp,"%u",&h.Maximo); 
    //aloca vetor
    if((h.Vetor=(long int *) calloc((h.Maximo+1),sizeof(long int)))==NULL){
        fprintf(stderr,"Erro no calloc\n");
        exit(3);
    }
    //atribuição
    for(;;){
        fscanf(fp,"%u",&x);
        if(feof(fp)){
            break;
        }
        h.Vetor[x]++;
    }
    //fecha arquivo
    if(fclose(fp)){
        fprintf(stderr,"Erro ao fechar arquivo\n");
        exit(4);
    }
    return h;
}
    
int comparaHistogramas(struct histograma h1, struct histograma h2){
    register int i;
    if(h1.Maximo==h2.Maximo){ //verifica se os tamanhos são iguais
        for(i=0;i<((h1.Maximo)+1);i++){
            if(h1.Vetor[i]!=h2.Vetor[i]){ //verifica se celula é diferente
                return 0;
            }
        }
        return 1;
    }
    else{
        return 0;
    }
}

void deletaHistograma(struct histograma* h){
    free(h->Vetor);
    h->Maximo=0;
    h->Vetor=NULL;
}

void imprimeHistograma(struct histograma h){
    register int i;
    for(i=0;i<((h.Maximo)+1);i++){
        printf("%ld ",(h.Vetor)[i]);
    }
    printf("\n");
}


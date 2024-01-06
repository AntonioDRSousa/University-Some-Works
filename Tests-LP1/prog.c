#include<stdio.h>
#include<stdlib.h>

long int ler(FILE *fp,FILE *pp,FILE *sp);
void erro(FILE * fp); //para verificar erro 

int main(void){
    FILE *fp,*pp,*sp;
    
    //abre os arquivos
    if((fp=fopen("arq1.txt","r"))==NULL){
        printf("Erro ao abrir arquivo.....\n");
        exit(1);
    }
    if((pp=fopen("arq2.txt","r"))==NULL){
        printf("Erro ao abrir arquivo.....\n");
        exit(1);
    }
    if((sp=fopen("saida.txt","w"))==NULL){
        printf("Erro ao abrir arquivo.....\n");
        exit(1);
    }
    
    printf("%ld\n",ler(fp,pp,sp));
    
    //fflush 
    if(fflush(sp)==EOF){
        printf("Erro fflush.....\n");
        exit(2);
    }
    
    //fecha arquivos
    if(fclose(fp)==EOF){
        printf("Erro ao fechar arquivo.....\n");
        exit(3);
    }
    if(fclose(pp)==EOF){
        printf("Erro ao fechar arquivo.....\n");
        exit(3);
    }
    if(fclose(sp)==EOF){
        printf("Erro ao fechar arquivo.....\n");
        exit(3);
    }
    
    return 0;
}

long int ler(FILE *fp,FILE *pp,FILE *sp){
    long int n=0; //numero de chaves
    long int x,y; //chaves
    do{
        fscanf(fp,"%ld",&x);
        erro(fp);
        fscanf(pp,"%ld",&y);
        erro(pp);
        for(;;){
            if(x==y){
                n++;
                fprintf(sp,"%ld\n",x);
                erro(sp);
                break;
            }
            else if(x>y){
                 fscanf(pp,"%ld",&y);
                 erro(pp);
            }
            else{
                 fscanf(fp,"%ld",&x);
                 erro(fp);
            }
            
            if(feof(fp) || feof(pp)){
                break;
            }
        }

    } while((!feof(fp)) || (!feof(pp)));
    return n;
}

void erro(FILE *fp){
    if(ferror(fp)){
        printf("Erro em operação com arquivo.....\n");
        exit(4);
    }
}

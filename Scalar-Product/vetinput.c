#include<stdio.h>
#include<stdlib.h>

int vetinput(char s[],float v[]){
    FILE * fp;
    register int i;
    int n;
    if((fp=fopen(s,"r"))==NULL){
        printf("Erro ao abrir arquivo.....\n");
        exit(1);
    }
    fscanf(fp,"%d",&n);
    for(i=0;i<n;i++){
        fscanf(fp,"%f",&v[i]);
    }
    fclose(fp);
    return n;
}    
    
    
    

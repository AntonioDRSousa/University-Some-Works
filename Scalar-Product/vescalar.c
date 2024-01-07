#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "vetinput.h"
#include "escalar.h"

void impr(float v[],int n);

int main(){
    float  a[50],b[50];
    char s[30],t[30];
    int m,n;
    float esc;
    printf("Digite o nome dos dois arquivos: ");
    scanf("%s %s",s,t);
    strcat(s,".txt");
    strcat(t,".txt");

    m=vetinput(s,a);
    n=vetinput(t,b);
    impr(a,m);
    impr(b,n);
    esc=escalar(a,b,n-1);
    printf("%f\n",esc);
    return 0;
}

void impr(float v[],int n){
    register int i;
    for(i=0;i<n;i++){
        printf("%f ",v[i]);
    }
    printf("\n\n\n");
}

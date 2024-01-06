#include<stdio.h>

double SomaRec(double Vet[],int);

int main(void)
{
    double Vet[]={1.0, 2.0, 3.0, 4.0, 5.0};
    printf("O somatório é igual a %lf\n", SomaRec(Vet, 5));
    return 0;
}

double SomaRec(double Vet[], int n){
    if(n==0){
        return Vet[n];
    }
    else{
        return Vet[n]+SomaRec(Vet, n-1);
    }
}


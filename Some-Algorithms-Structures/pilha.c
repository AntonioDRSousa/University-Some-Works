#include<stdio.h>
#include<stdlib.h>

#define SIZE 50

void push(int i);
int pop(void);

int *tos,*p1,stack[SIZE];

int main(void) //0 retira uma item da pilha, -1 encerra o programa
{
	int value;

	tos=stack; //faz 'tos' conter o topo da pilha
	p1=stack; //inicializa p1

	do
	{
		printf("Digite o valor: ");
		scanf("%d", &value);
		if(value!=0)
		{
			push(value);
		}
		else
		{
			printf("valor do topo e %d\n", pop());
		}
	}while(value != -1);

	return 0;
}

void push(int i)
{
	p1++;
	if(p1==(tos+SIZE))
	{
		printf("Estouro da pilha");
		exit(1);
	}
	*p1=i;
}

int pop(void)
{
	if(p1==tos)
	{
		printf("Estouro da pilha");
		exit(1);
	}
	p1--;
	return *(p1+1);
}

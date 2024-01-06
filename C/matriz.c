/* Matrizes Bidimensionais */
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int l,c; //variaveis globais que indicam o numero de linhas e colunas

void dim(void); //informa a dimensão da linha e da coluna
void init_matrix(int mat[][c]); //inicializa a matriz
void display_matrix(int mat[][c]); //mostra a matriz

int main(void)
{
	char ch, str[80];
	dim();
	int mat[l][c];//matriz
	for(;;)
	{
		do
		{	
			printf("Digite 'd' para digitar a matriz\n");
			printf("Digite 'm' para mostrar a matriz\n");
			printf("Digite 's' para sair\n");
			gets(str);
			ch=tolower(*str);
		}while(ch!='d' && ch!='m' && ch!='s');
		printf("\n");
		switch(ch)
		{
			case 'd':
					init_matrix(mat);
				break;
			case 'm':
				display_matrix(mat);
				break;
			case 's':
				exit(0);
		}
	}
	return 0;
}

void dim(void)
{
		printf("Digite a quantidade de linhas: ");
		scanf("%d", &l);
		printf("Digite a quantidade de colunas: ");
		scanf("%d", &c);
		printf("\n");
}

void init_matrix(int mat[][c])
{
	register int i,j;
	for(i=0;i<l;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Digite A[%d,%d]= ", i,j);
			scanf("%d", &mat[i][j]);
		}
	}
	printf("\n");
}

void display_matrix(int mat[][c])
{
	register int i,j;
	for(i=0;i<l;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

				
				
		
		
		
	
	

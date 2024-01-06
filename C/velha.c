#include<stdio.h>
#include<stdlib.h>

char matrix[3][3];

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

int main(void)
{
	char done;
	printf("JOGO DA VELHA\n");
	done=' ';
	init_matrix();
	do
	{
		disp_matrix();
		get_player_move();
		done=check(); //verifica se há vencedor
		if(done!=' ') //vencedor
		{
			break;
		}
		get_computer_move();
		done=check(); //verifica se há vencedor
	}while(done==' ');
	if(done=='X')
	{
		printf("Voce Ganhou!\n");
	}
	else
	{
		printf("Voce Perdeu!\n");
	}
	disp_matrix(); //mostra as posições finais
	return 0;
}

void init_matrix(void) //inicializa a matriz
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			matrix[i][j]=' ';
		}
	}
}

void get_player_move(void) //obtem a jogada do jogador
{
	int x,y;
	printf("\nDigite as coordenadas para o X\n");
	printf("linha= ");
	scanf("%d", &x);
	printf("coluna= ");
	scanf("%d", &y);
	x--; y--;
	if(matrix[x][y]!=' ')
	{
		printf("Posição invalida, tente novamente.\n");
		get_player_move();
	}
	else
	{
		matrix[x][y]='X';
	}
	printf("\n");
}

void get_computer_move(void) //obtem a jogada do computador
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(matrix[i][j]==' ')
			{
				break;
			}
		}
		if(matrix[i][j]==' ')
		{
			break;
		}
	}
	if(i*j==9)
	{
		printf("EMPATE\n");
		exit(0);
	}
	else
	{
		matrix[i][j]='O';
	}
}

void disp_matrix(void) //mostra a matriz na tela
{
	int t;
	for(t=0;t<3;t++)
	{
		printf(" %c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
		if(t!=2)
		{
			printf("\n---|---|---\n");
		}
	}
	printf("\n");
}

char check(void)
{
	int i;
	for(i=0;i<3;i++) //verifica as linhas
	{
		if(matrix[i][0]==matrix[i][1]&&matrix[i][1]==matrix[i][2])
		{
			return matrix[i][0];
		}
	}
	for(i=0;i<3;i++) //verifica as colunas
	{
		if(matrix[0][i]==matrix[1][i]&&matrix[1][i]==matrix[2][i])
		{
			return matrix[0][i];
		}
	}
	//testa as diagonais
	if(matrix[0][0]==matrix[1][1]&&matrix[1][1]==matrix[2][2])
	{
		return matrix[0][0];
	}
	if(matrix[0][2]==matrix[1][1]&&matrix[1][1]==matrix[2][0])
	{
		return matrix[0][2];
	}

	return ' ';
}
	
		
		
	


	

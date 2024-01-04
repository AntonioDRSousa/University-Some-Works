// Este programa exercitará as facilidades para formatação de saídas numéricas usando 
// a biblioteca iomanip. Você possui uma tabela de dados numéricos (matriz) que variam
// somente entre 0.0 e 100.0, e deverá formatá-la de acordo com o que será pedido.
//
// 1. Rode o programa como ele está.
// 2. Formate a saída para que todos os números exibam duas casas decimais.
// 3. Pense no tamanho, em caracteres, do maior elemento possível para essa tabela.
//	  Seja T esse tamanho, formate a saída para que todos os elementos ocupem T+1
//    caracteres.
// 4. Formate a saída para que, em linhas pares apenas, os espaços adicionais gerados 
//    na etapa anterior sejam preenchidos pelo caracter '~'. (considere que a primeira
//	  linha é a linha 0). Em linhas ímpares, o preenchimento deverá ser um espaço em branco.
// 5. Rode o programa, perceba que os valores estão alinhados à direita. Alinhe-os
//	  à esquerda.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const int linhas = 5, colunas = 5;
	double matriz[linhas][colunas] = {	{100.0, 2.6578, 50.3125, 24.10, 0.0},
										{29.1293123, 82.5093, 3.64957, 0.0, 71.48123},
										{11.219583, 45.678011, 0.0, 88.015, 1.95502},
										{7.865747, 0.0, 10.6949246123, 64.8676215, 100.0},
										{0.0, 97.6653, 52.09402, 6.364671, 36.58901}}; //T=13

	char fill = ' ';

	for(int i=0; i<linhas; ++i) {
		for(int j=0; j<colunas; ++j) {
			if(i%2==0){
				cout <<fixed<<setw(14)<<left<<setfill('~')<<setprecision(2)<< matriz[i][j];
			}
			else{
				cout <<fixed<<setw(14)<<left<<setfill(' ')<<setprecision(2) <<matriz[i][j];
			}
		}
		cout << endl;
	}

    return 0;
}

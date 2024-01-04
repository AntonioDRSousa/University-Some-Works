// Este programa mostra o uso de templates aplicado a classes.
// Está disponibilizada uma classe Arvore simples que comporta
// apenas números inteiros. O método geraMetade cria uma cópia
// da árvore fazendo com que todas as chaves adquiram metade do
// seu valor original.
// 1. Rode o programa da forma que está.
// 2. Altere a definição da classe para que ela aceite qualquer tipo de chave.
// 3. Modifique a definição da árvore 'R' fornecida no main() explicitamente para que 
//    comporte chaves do tipo double. Faça o mesmo para a árvore 'M'. Não modifique		
//	  os valores passados nas chamadas de "criaFilho!"
// 4. Rode o programa novamente. Se o passo 3 foi feito corretamente, os valores
//    divididos por 2 agora mostrarão suas casas decimais.
// 5. Estenda a template da classe para que ela aceite um número estático N de filhos,
//	  passado para a árvore em sua criação. A classe também deve funcionar caso N
//    não seja especificado pelo usuário, assumindo o valor padrão N = 2. Modifique
//    a árvore 'R' acrescentando chamadas criaFilho para verificar se o código
//    está correto.

#include <iostream>
using namespace std;
template <typename T,int N=2>
struct Arvore {
	T chave;
	int profundidade;
	int num_filhos;
	
	Arvore *filhos[N];
	
	//Construtor
	Arvore(T c, int h = 0): chave(c), profundidade(h) {
		num_filhos = 0;
	}
	
	Arvore* criaFilho(T chave) {
		filhos[num_filhos++] = new Arvore(chave, profundidade+1);
		return filhos[num_filhos-1];
	}
	
	/* Não altere as duas funções abaixo! */
	void imprime() {
		cout << string(profundidade, '\t') << chave << endl;
		for(int i = 0; i < num_filhos; ++i) 
			filhos[i]->imprime();
	}
	
	Arvore* geraMetade() {
		Arvore * metade = new Arvore(chave/2, profundidade);
		for(int i = 0; i < num_filhos; ++i) 
			metade->filhos[i] = filhos[i]->geraMetade();
		metade->num_filhos = num_filhos;
		return metade;
	}
	////////////////////////////////////////
};

int main() {
	//Instancia uma árvore
	Arvore<double> * R = new Arvore<double>(5); //5 será a raiz
	
	//Cria os nós filhos
	R->criaFilho(7);
	R->criaFilho(2); //7 e 2 serão os dois filhos de 5
	R->criaFilho(93);
	R->filhos[0]->criaFilho(11);
	R->filhos[0]->criaFilho(9); //11 e 9 serão os dois filhos de 7
	R->filhos[1]->criaFilho(1); //1 será o único filho de 2
	
	//Gera a árvore com as chaves divididas por 2
	Arvore<double> * M = R->geraMetade();
	
	//Visualização da árvore: os espaços denotam a profundidade
	cout<<"Impressao da arvore:"<<endl;
	R->imprime();
	cout<<endl<<"Valores divididos por 2:"<<endl;
	M->imprime();
	
	return 0;
}

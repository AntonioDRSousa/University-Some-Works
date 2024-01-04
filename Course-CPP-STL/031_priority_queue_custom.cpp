// Neste programa você vai trabalhar com a inserção em lista de prioridade.
// Agora, o critério de inserção é customizado.
// 1. Rode o programa como está.
// 2. Troque o critério para ordenar primeiro pelo nome, do lexicograficamente
//    menor para o maior. (A a Z)
#include <queue>
#include <iostream>
#include <iomanip>
using namespace std;

struct Aluno 
{ 
	float media; 
	string nome; 
};

class Compara 
{
    public: 
	  bool operator()(Aluno& a1, Aluno& a2) 
	  {
		if(a1.nome==a2.nome) return a1.nome < a2.nome;
		else return a1.nome > a2.nome;
	  } 
};

int main()
{
	priority_queue<Aluno, vector<Aluno>, Compara> pq;
	Aluno novo_aluno;
	for(int i = 0; i < 4; ++i) 
	{
		cout<< "Nome: ";
		cin>> novo_aluno.nome;
		cout<< "Media: ";
        cin>> novo_aluno.media;
		pq.push(novo_aluno);
	}
	cout<< setw(12) << left << "Nome" << " ";
	cout << setw(5) << "Media" << endl;
	for(;!pq.empty();  pq.pop()) 
	{
		Aluno aluno_atual = pq.top();
		cout<< setw(12) << left<< aluno_atual.nome << " "; 
		cout<< setw(5) << aluno_atual.media << endl;
	}

    return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct Comum{ char nome[50];
              int nivel;
              int experiencia;
              int dinheiro;
              int saude;
              int maxSaude;
              int vel;
              int ataque;
              int defesa;
};
            
enum CLASSE { Guerreiro, Mago, Sacerdote };
struct Avatar { struct Comum padrao;
                enum CLASSE c;
                union {
                    struct { int armadura;
                             int nEspada;
                             int nArco;
                             int nEscudo;
                    };
                    struct { int mana;
                             int maxMana;
                             int poder;
                             int conhecimento;
                    };
                    struct { int reza;
                             int maxReza;
                             int cura;
                             int protecao;
                    };
                };
};

int main(){
	struct GUERREIRO;
	struct Mago;
	struct Sacerdote;
	return 0;
}


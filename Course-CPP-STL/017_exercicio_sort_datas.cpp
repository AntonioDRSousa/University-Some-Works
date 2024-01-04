// Neste exercício você vai continuar trabalhando com sort, para resolver o
// seguinte problema:
//    1. Dada uma série de registros, contendo uma letra e uma data, ordenar
//      os registros por data.
//    Dica: a data d1/m1/a1 é menor que d2/m2/a2, se (a1*10000+m1*100+d1) < (a2*10000+m2*100+d2)

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct no{char c; int dia, mes, ano;};  
no dado;  vector<no> v;

void print() 
{   for(int i = 0; i < v.size(); i++) 
    {   cout << v[i].c << " " << v[i].dia << "/" << v[i].mes << "/" << v[i].ano << endl;
    }
}

bool custom(no a, no b) 
{
	int x,y;
	x=(a.ano*10000)+(a.mes*100)+a.dia;
	y=(b.ano*10000)+(b.mes*100)+b.dia;
	return x<y;
     
}

int main()
{   dado.c = 'A'; dado.dia = 1;  dado.mes = 2;   dado.ano = 1995;  v.push_back(dado);
    dado.c = 'B'; dado.dia = 15; dado.mes = 9;   dado.ano = 2010;  v.push_back(dado);
    dado.c = 'C'; dado.dia = 3;  dado.mes = 11;  dado.ano = 2007;  v.push_back(dado);
    dado.c = 'D'; dado.dia = 30; dado.mes = 3;   dado.ano = 1999;  v.push_back(dado);
    dado.c = 'E'; dado.dia = 28; dado.mes = 5;   dado.ano = 2001;  v.push_back(dado);
    
    print();
    cout<<endl;
    sort(v.begin(), v.end(), custom);
    print();
//    sort(v.begin(), v.end(), greater<int>());
//    print();
//    sort(v.begin(), v.end(), custom);
//    print();

    return 0;
}


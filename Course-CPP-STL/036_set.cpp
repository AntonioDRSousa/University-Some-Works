// Neste programa demonstramos diferentes construtores do set.
// 1. Rode o programa como está.
// 2. Imprima cada um dos sets criados indicando no console qual set
//    está sendo impresso. (Melhor usar template) pois 
//    (set<int> != set<int,classcomp>)
// 3. Adicione elementos em s1, s5 e s6 com a função insert(elemento) 
//    para não ficarem vazios.
// 4. O que fica armazenado no pair correspondente ao retorno do insert?
//  Resposta: Um iterator apontando para o elemento inserido, e um valor booleano verdadeiro se o elemento foi inserido ou falso se o elemento já existe no set
//
//
#include <iostream>
#include <set>
using namespace std;

bool fncomp (int lhs, int rhs) {return lhs<rhs;}
struct classcomp {
	bool operator() (const int& lhs, const int& rhs) const
		{return lhs>rhs;}
};

template<typename T,typename P>
void imprime(set<T,P> s,const char * c){
	typename set<T,P>::iterator it=s.begin();
	cout << c <<" = { ";
    while(it != s.end()) {
         cout << *it << " "; ++it;
    }
    cout << "}" << endl;
}

int main() 
{
	set<int> s1;
	int mi[]= {10,20,30,40,50};
	set<int> s2 (mi,mi+5); 
	set<int> s3 (s2);
	set<int> s4 (s2.begin(), s2.end()); 
	set<int,classcomp> s5;
	set<int,bool(*)(int,int)> s6 (fncomp);

	imprime(s1,"s1");
	imprime(s2,"s2");
	imprime(s3,"s3");
	imprime(s4,"s4");
	imprime <int,classcomp> ( s5,"s5");
	imprime <int,bool(*)(int,int)> ( s6,"s6");

	pair<set<int>::iterator,bool> ret1,ret2,ret3;
	
	ret1=s1.insert(3);
	if(!ret1.second){
		cout<<*ret1.first<<" ja existe"<<endl;
	}
	else{
		cout<<*ret1.first<<" inserido"<<endl;
	}

	ret2=s5.insert(17);
	if(!ret2.second){
		cout<<*ret2.first<<" ja existe"<<endl;
	}
	else{
		cout<<*ret2.first<<" inserido"<<endl;
	}
	

	ret3=s6.insert(8);
	if(!ret3.second){
		cout<<*ret3.first<<" ja existe"<<endl;
	}
	else{
		cout<<*ret3.first<<" inserido"<<endl;
	}
	

	cout<<endl<<endl;
	
	imprime(s1,"s1");
	imprime(s2,"s2");
	imprime(s3,"s3");
	imprime(s4,"s4");
	imprime <int,classcomp> ( s5,"s5");
	imprime <int,bool(*)(int,int)> ( s6,"s6");
	
	return 0;
}

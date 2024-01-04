// Este programa lê um string e separa e apresenta suas palavras.
// 1. Rode o programa da forma que está.
// 2. Acrescente código para ler vários inteiros e apresentar sua soma.

#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string linha;
    string n;
    istringstream ss,sss;
    int soma = 0;
    register int i;
    
    getline(cin, linha) ;
    ss.str(linha);
    while(ss >> n) { 
    	cout << n << endl; 
    }
    cout<<endl<<endl;

	int x;
	stringstream sst;
    while(true){
    	getline(cin, linha) ;
    	sss.str(linha);
    	sss >> linha;
    	sst<<linha<<endl;

    	sst>>x;
    	if(x<0){ //para quando lê numero negativo
    		break;
    	}
    	soma+=x;
    }
    cout<<"Soma = "<<soma<<endl;
    
    return 0;
}

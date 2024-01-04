// Este programa mostra o funcionamento básico de cin e cout.
// 1. Rode o programa da forma que está.
// 2. Verifique que a leitura está preparada para executar até fim de arquivo.
//    Mude isso para terminar quando ler (a = 0, b = 0).
//    Mude a impressão para escrever as seguintes três linhas:
//     * Na primeira linha, escreva os inteiros lidos separados por espaço
//     * Na segunda linha, escreva a soma a+b
//     * Na terceira, escreva o resultado de a^2 + b^2;

#include <iostream>
using namespace std;

int main() 
{
    int a=1, b=1;
    while(cin >> a >> b)
    {
    	if(a==0||b==0){
    		break;
    	}
        cout << a <<" "<< b << endl;
        cout<<a+b<<endl;
        cout<<(a*a)+(b*b)<<endl;
    }
    return 0;
}

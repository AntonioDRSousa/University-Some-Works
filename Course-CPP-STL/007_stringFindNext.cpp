// Este programa continua a apresentar facilidades para busca de 
// substrings, usando o comando find, mas agora com mais parâmetros.
// 1. Rode o programa como ele está.
// 2. Acrescente o código para contar quantas substrings existem 
//    na string procurada, imprimindo as posições em que encontrá-las.
#include <iostream>
using namespace std;

int main()
{
     string s = "Hello World, World, World, World, World, World.";
     int pos = s.find("World" ); 
     int pos2 = s.find("World" , pos+1);
     cout << pos2 << endl;

     cout<<endl<<endl;

     int p=0;
     int j=0;
     bool contem;
     for(int i=0;i<s.length();i++){
     	p=s.find("World",p);
     	if(p!=string::npos){
     		cout<<p<<" ";
     		p++;
     		j++;
     	}
     	else{
     		cout<<endl;
     		break;
     	}
     }
	cout<<"Numero de substrings World encontradas: "<<j<<endl;
     

     return 0;
}

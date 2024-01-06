#include<stdio.h>

void nom(int num);

int main(){
	int num;
	printf("Digite um numero entre 0 e 9: ");
	scanf("%d", &num);
	nom(num);
	return 0;
}

void nom(int num)
{
	static char*p[10]={
	"zero\n","um\n","dois\n",
	"três\n","quatro\n","cinco\n",
	"seis\n","sete\n","oito\n","nove\n"
	};
	printf("%s", p[num]);
}

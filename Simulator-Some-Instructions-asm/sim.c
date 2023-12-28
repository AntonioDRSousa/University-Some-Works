#include<stdio.h>

#define N_OPCODES 100

int mem[10000];
int reg[10000];
char isa[N_OPCODES][10] = {"add", "addi", "sub", "jlt", "je", "jmp", "ld", "sd", "hlt", "prt"};
int n;

typedef struct instr {
	char opcode;
	char dst;
	char a;
	char b;
	
} instr_t;

instr_t instrucoes[10000];

int execute(instr_t inst){
	char c=inst.opcode;

	if(c==0){//add <reg destino>,<reg a> <reg b> (exemplo: add r1,r2,r3)
		reg[inst.dst]=reg[inst.a]+reg[inst.b];
		printf("add r%d, r%d, r%d\n",inst.dst,inst.a,inst.b);
	}
	else if(c==1){//addi <reg destino>,<reg a>,<immediato> (exemplo: addi r1,r2,123);
		reg[inst.dst]=reg[inst.a]+inst.b;
		printf("addi r%d, r%d, %d\n",inst.dst,inst.a,inst.b);
	}
	else if(c==2){//sub -- semelhante a addl
		reg[inst.dst]=reg[inst.a]-reg[inst.b];
		printf("sub r%d, r%d, r%d\n",inst.dst,inst.a,inst.b);
	}
	else if(c==3){//jlt <reg endereco alvo>,<reg a>,<reg b> (desvio condicional para endereco alvo caso valor de reg a seja menor que o de reg b>.
		if(reg[inst.a]<reg[inst.b]){
			n=reg[inst.dst]-1;
		}
		printf("jlt r%d, r%d, r%d\n",inst.dst,inst.a,inst.b);
	}
	else if(c==4){//je -- mesmo que jlt, mas no caso dos valores serem iguais
		if(reg[inst.a]==reg[inst.a]){
			n=reg[inst.dst]-1;
		}
		printf("je r%d, r%d, r%d\n",inst.dst,inst.a,inst.b);
	}
	else if(c==5){//jmp <reg destino> (desvio incondicional)
		n=reg[inst.dst]-1;
		printf("jmp r%d\n",inst.dst);
	}
	else if(c==6){//ld <reg destino>,<reg endereco> (carrega o valor contino no endereco de memoria para o registrador de destino
		reg[inst.dst]=mem[reg[inst.a]];
		printf("ld r%d, r%d\n",inst.dst,inst.a);
	}
	else if(c==7){//sd <reg valor>,<reg endereco> (escreve o valor presente em reg valor no endereco de memoria dado por reg endereco
		mem[reg[inst.a]]=reg[inst.dst];
		printf("add r%d, r%d\n",inst.dst,inst.a);
	}
	else if(c==8){//hlt (halt, termina o programa)
		printf("hlt\n");
		return 1;
	}
	else{//prt <reg valor> (imprime na tela o caracter cujo valor esta em reg valor)
		printf("prt %d\n\n",inst.dst);
		printf("%c",reg[inst.dst]);
	}
	return 0; 
}

void imprReg(){
	printf("\nRegistradores\n");
	for(int i=0;i<10;i++){
		printf("%d %d\n",i,reg[i]);
	}
}

void imprMem(){
	printf("\nMemoria\n");
	for(int i=0;i<10;i++){
		printf("%d %d\n",i,mem[i]);
	}
}

void guardaInstrucoes(FILE *binary){
	int i=0;
	char c;
	instr_t inst;
		
	while (!feof(binary)) { //guarda as instrucoes
		fread(&c,sizeof(char),1,binary);
		
		i++;
		if(i==1){
			inst.opcode=c;
		}
		else if(i==2){
			inst.dst=c;
		}
		else if(i==3){
			inst.a=c;
		}
		else{
			inst.b=c;
			instrucoes[n]=inst;
			n++;	
			i=0;
		}
		
	}
	fclose(binary);
}

void sim(){
	instr_t inst;
	int flag=0;
	
	for(n=0;flag!=1;n++){
		printf("----------------------\n\n");
		inst = instrucoes[n];
		flag=execute(inst);
		imprReg();
		imprMem();
		printf("----------------------\n\n");
	}
}

int main(int argc, char *argv[]){
	FILE *binary = fopen(argv[1], "rb");
	guardaInstrucoes(binary);
	sim();
	return 0;
}

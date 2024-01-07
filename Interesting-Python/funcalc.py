from math import *

def leFuncao(funcoes):
    print("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
    print("Comando: <nome da funcao>(<nome de argumento 1>,...,<nome de argumento n>) = <expressao>")
    print("Pode-se usar funcoes da biblioteca math do python na expressao")
    print("Exemplo: 'soma(x,y) = x+y' e modulo(x)=abs(x)")
    funcao=input("Digite a funcao: \n")
    print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n")

    listArguments=[]
    funcao.replace(" ","")
    tmp=funcao.split('=')
    expression=tmp[1]
    tmp=tmp[0].split('(')
    name=tmp[0]
    tmp=tmp[1].split(')')
    listArguments = tmp[0].split(',')
    print(name+str(listArguments)+'='+expression)
    
    for i in range(0,len(funcoes)):
        if (funcoes[i])[0]==name:
            print("Funcao com o mesmo nome de uma funcao anterior.....")
            raise
    funcoes.append((name,listArguments,expression))

def strArgument(listArguments):
    s="("
    size=len(listArguments)
    for i in range(0,size):
        s+=listArguments[i]
        if i==(size-1):
            s+=")"
        else:
            s+=","
    return s

def listarFuncoes(funcoes):
    print("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
    for i in range(0,len(funcoes)):
        func=funcoes[i]
        print(func[0]+strArgument(func[1])+" = "+func[2])
    print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n")

def calc(funcoes):
    while True:
        print("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
        print("Comando: <nome da funcao>(<valor argumento 1>,...,<valor argumento n>)")
        print("Exemplo: 'soma(1,4)' e' um exemplo")
        s=input("Digite a funcao com os parametros ou aperte deixe vazio para interromper: \n")
        print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n")
        if s=="":
            break
        else:
            b=True
            tmp=s.split('(')
            name=tmp[0].replace(" ","")
            tmp=tmp[1].split(')')
            listArguments=eval("["+tmp[0]+"]")
            for i in range(0,len(funcoes)):
                func=funcoes[i]
                if func[0]==name:
                    d=dict(zip(func[1], listArguments))
                    print("\n"+s+" = "+str(eval(func[2],globals(),d))+"\n")
            if b:
                print("funcao nao encontrada\n")

def removerFuncao(funcoes):
    b=True
    name=input("Digite o nome da funcao a deletar: \n")
    for i in range(0,len(funcoes)):
        if (funcoes[i])[0]==name:
            funcoes.pop(i)
            print("funcao removida\n")
            break
    if b:
        print("funcao nao encontrada\n")


funcoes=[]      
while True:
    try:
        print("\n------------------------------------")
        print("Digite 'n' para uma criar uma nova funcao")
        print("Digite 't' para listar todas as funcoes")
        print("Digite 'd' para deletar uma funcao")
        print("Digite 'c' para calcular o valor de uma funcao")
        print("Digite qualquer outro caracter para sair")
        print("------------------------------------")
        c=input()
    
        if c=='n':
            leFuncao(funcoes)
        elif c=='t':
            listarFuncoes(funcoes)
        elif c=='d':
            removerFuncao(funcoes)
        elif c=='c':
            calc(funcoes)
        else:
            break
    except:
        print("Erro.....\n")


from math import *

lista = []

def leLista():
    i=0
    while True:
        try:
            x=int(input("lista["+str(i)+"] = "))
            if x<0:
                break
            lista.append(x)
            i+=1
        except:
            print("Erro.....")

def media():
    soma=0
    for i in range(0,len(lista)):
        soma+=lista[i]
    return soma/len(lista)

def desvio():
    m=media()
    soma=0
    for i in range(0,len(lista)):
        soma+=(lista[i]-m)**2
    return sqrt(soma/len(lista))

while True:
    try:
        print("\n\n----------------------")
        print("1 - Criar nova lista")
        print("2 - Calcular Media")
        print("3 - Calcular Desvio Padrao")
        print("4 - Ordenar Lista")
        print("5 - Inserir elemento na lista")
        print("6 - Imprime Lista")
        print("7 - Sair")
        print("----------------------\n\n")

        op=input()

        if op=='1':
            leLista()
        elif op=='2':
            if len(lista)==0:
                print("Nao e' possivel calcular media")
            else:
                print("\n\nMedia = "+str(media()))
        elif op=='3':
            if len(lista)==0:
                print("Nao e' possivel calcular desvio padrao")
            else:
                print("\n\nDesvio Padrao = "+str(desvio()))
        elif op=='4':
            lista.sort()
        elif op=='5':
            n=int(input("Digite um numero: "))
            lista.append(n)
        elif op=='6':
            print("lista = ",end="")
            for i in range(0,len(lista)):
                print(" "+str(lista[i]),end="")
        elif op=='7':
            break
        else:
            raise
    except:
        print("Erro.....\n")

from random import *
from math import *
import time

def Input():
    while True:
        try:
            x=int(input("x = "))
            y=int(input("y = "))
            if y<x:
                print ("Erro. y menor que x .....")
                raise
            
            numAl=int(input("Quantidade de Numeros Aleatorios = "))
            if numAl<=0:
               print ("Erro. Quantidade de Numeros Aleatorios menor do que 1 .....")
               raise

            #obtem aleatoriamente o numero de elementos distintos existentes
            numEltosDist = randint(1,numAl) # existem 1 ate' numAl elementos distintos
            print("\nnumero de elementos distintos = "+str(numEltosDist))

            break
            
        except:
            print ("Erro......\n")
            
    n = y-x+1
    
    return n,x,y, numAl, numEltosDist  

def Escolhe(S):
    a=next(S)
    i=1
    m=a
    a=next(S)
    while a!=None:
        i+=1
        p=random()
        if p<=(1/i):
            m=a
        a=next(S)
    return m

def initVectors():
    S=[]
    Conj=[]

    #gera o vetor de escolha
    for i in range(0,n):
        S.append(i+x)

    #obtem aleatoriamente os elementos distintos
    for i in range(0,numEltosDist):
        pos=randint(i,len(S)-1)
        S[pos], S[i] = S[i], S[pos] 
        Conj.append(S[i])
    print("\nelementos distintos escolhidos = "+str(Conj))
    Conj.append(None)

    #coloca os elementos distintos no conjunto
    for i in range(0,numEltosDist):
        V.append(Conj[i])

    #gera novos elementos que pertencem ao conjunto de elementos distintos para preencher o resto de numeros aleatorios, que nao sao distintos 
    for i in range(numEltosDist,numAl):
        V.append(Escolhe(iter(Conj)))

    #embaralha o vetor para tornar mais aleatorio 
    #shuffle(V)
    #print("\nvetor aleatorio = "+str(V))
    V.append(None)

def h(x):#dispersao
    hp=((hash(str(x))+(10**20)-1))/(10**15)
    hp=(hp-(int(hp)))
    #print("   h("+str(x)+") = "+str(hp))
    #input()
    return hp

def ContaElementosDistintos(S):
    hmin=inf
    a=next(S)
    while a!=None:
        hs=h(a)
        #print(str(a)+" : "+str(hs)+" : "+str(hmin))
        #input()
        hmin=min(hmin,hs)
        a=next(S)
    return (((1/(hmin)))-1)

def Impr():
    print("\n\nelementos distintos esperados = "+str(numEltosDist))
    print("Aproximacao do Numero de Elementos Distintos   = "+str(estim))
    #print("Tempo de Execucao = "+str(fim-ini))

while True:    
    V=[]
    n,x,y,numAl,numEltosDist=Input()

    soma=0
    iteracoes=int(input("numero de iteracoes = "))
    
    #ini = time.time()
    for i in range(0,iteracoes):
        #mul,mx=initVectors()
        initVectors()
        estim=ContaElementosDistintos(iter(V))
        #print("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n")
        #Impr()
        #print("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n")
        soma+=estim
    
    #fim = time.time()

    print("elementos distintos = "+str(numEltosDist))
    print("\n\n\n\nmedia = "+str(soma/iteracoes))
    
    c = input("\n\nDigite 's' para sair e outro caracter para continuar\n")
    if c=='s':
        break
    else:
        print()

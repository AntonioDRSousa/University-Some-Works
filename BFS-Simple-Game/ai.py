import random
from itertools import permutations

def verificaString(s):
    b, p, i = s.count('B'), s.count('P'), s.count('I')
    return (len(s)==5 and b==2 and p==2 and i==1)

def vitoria(v):
    s = ''.join(v)
    return (s.replace('I','') == "BPPB")

def jogada(estado,move,i,j):
    t = estado.copy()
    t[j], t[i] = t[i], 'I'
    tipo = { 1:'desliza', 2:'salta' }
    v=[tipo[abs(i-j)]+" "+t[j]+" da posicao "+str(i+1)+" para a posicao "+str(j+1)+"  ->  "+''.join(t)]
    return (t,move+v)

def possibilidades(e,i):
    f = list(filter(lambda x: x>=0 and x<=4, [i-2,i-1,i+1,i+2]))
    return [x for x in f if not e[i]=='I' and e[x]=='I']

def buscaLargura(e0):
    Q=[(e0,[])]
    while len(Q)>0:
        v = Q.pop(0)
        estado, move = v[0], v[1]
        if vitoria(estado):
            return move,estado
        for i in range(0,5):
            for j in  possibilidades(estado,i):
                Q.append(jogada(estado,move,i,j))

def novoEstado():
    print("----------------------------------------------------------")
    estado_inicial=(input("Digite o estado inicial com uma string de 5 caracteres 'B', 'P' e 'I' : ")).upper()
    if not verificaString(estado_inicial):
        raise
    movimentos,estado=buscaLargura(list(estado_inicial))
    impr(estado_inicial,estado,movimentos)

            
def aleatorio():
    estado_inicial=['B','P','P','B','I']
    random.shuffle(estado_inicial)
    print("\nestado inicial aleatorio -> "+''.join(estado_inicial)+"\n\n")
    movimentos,estado=buscaLargura(estado_inicial)
    impr(''.join(estado_inicial),estado,movimentos)
    
def listar():
    estados_iniciais=list(set([''.join(p) for p in permutations('BBIPP')]))
    num_conf=len(estados_iniciais)
    num_jog=[]
    for i in estados_iniciais:
        movimentos,estado=buscaLargura(list(i))
        num_jog.append(impr(i,estado,movimentos))
    print("estado inicial          numero de jogadas")
    for i in range(0,num_conf):
        print(" "*5+estados_iniciais[i]+" "*8+"->"+" "*12+str(num_jog[i]))
    print("\n\nnumero de jogadas    numero de estados")
    for i in range(0,max(num_jog)+1):
        print(" "*8+str(i)+" "*8+" ->"+" "*8+str(num_jog.count(i)))
    print("\nnumero de estados iniciais possiveis = "+str(num_conf)+"\n\n")

def impr(ei,ef,move):
    num_jogadas=len(move)
    print("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n")
    print("\nestado inicial  ->  "+ei+"\n\n")
    print(*move, sep="\n")
    print("\n\nestado final(vitoria)  ->  "+''.join(ef)+"\n\n")
    print("\nnumero de jogadas = "+str(num_jogadas))
    print("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n")
    return num_jogadas

def main():
    while True:
        try:
            print("----------------------------------------------------------")
            print("1 - digitar estado inicial")
            print("2 - estado inicial aleatorio")
            print("3 - listar todos os estados iniciais possiveis")
            print("4 - sair")
            print("----------------------------------------------------------")
            op=int(input("Digite a opcao: "))
            if op==1:
                novoEstado()
            elif op==2:
                aleatorio()
            elif op==3:
                listar()
            elif op==4:
                break
            else:
                raise
        except:
            print("Erro.........................................................")

main()


#multiplica por 2 todos os elementos da lista

l=[]

def duplica(x):
    return 2*x

def fmap(f,l):
    for i in range(0,len(l)):
        l[i]=f(l[i])

def leLista():
    print("Digite os elementos da lista ou '' para parar: ")
    while True:
        try:
            s=input()
            if s=="":
                break
            x=int(s)
            l.append(x)
        except:
            print("Erro.....")


leLista()
print(l)
fmap(duplica,l)
print(l)

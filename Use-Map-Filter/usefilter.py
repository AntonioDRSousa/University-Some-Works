#obtem os numeros pares de uma lista e retorna todos eles em uma nova lista

l1=[]

def par(x):
    return (x%2==0)

def ffilter(f,l):
    if l==[]:
        return []
    elif f(l[0]):
        return [l[0]]+ffilter(f,l[1:])
    else:
        return ffilter(f,l[1:])
    
def leLista():
    print("Digite os elementos da lista ou '' para parar: ")
    while True:
        try:
            s=input()
            if s=="":
                break
            x=int(s)
            l1.append(x)
        except:
            print("Erro.....")


leLista()
print(l1)
l2=ffilter(par,l1)
print(l2)

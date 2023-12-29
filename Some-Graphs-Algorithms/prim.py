import math
def prim():
    T=[]
    C = [None]*(n+1)
    vertices = [None]*(n+1)
    MV=[None]*(n+1)
    for i in range(1,n+1):
        C[i]=math.inf
        vertices[i]=0
    vertices[v]=1
    vertices_marcados=[v]
    for i in G[v]:
        z, peso = i[0], i[1]
        C[z]=peso
        MV[z]=v
    for i in range(1,n):
        minimo=math.inf
        w=0
        for j in range(1,len(C)):
            if ((C[j]<minimo) and (vertices[j]!=1)):
                minimo=C[j]
                w=j
        vertices[w]=1 # marca w
        vertices_marcados.append(w)
        T.append((w,MV[w]))
        for j in G[w]:
            z, peso = j[0], j[1]
            if ((vertices[z]!=1) and (C[z]>peso)):
                C[z]=peso
                MV[z]=w
    print("vertices marcados em ordem: "+str(vertices_marcados))
    print("arvore geradora minima: "+str(T))
"""
G=[[]]
G.append([(2,2),(4,12),(5,4)])
G.append([(1,2),(6,10),(3,5)])
G.append([(2,5),(7,7),(4,9)])
G.append([(3,9),(8,3),(1,12)])
G.append([(1,4),(6,8),(7,6)])
G.append([(5,8),(2,10),(7,11)])
G.append([(5,6),(6,11),(3,7),(8,1)])
G.append([(7,1),(4,3)])
"""
G=[[]]
G.append([(2,1),(4,1),(3,1)])
G.append([(1,1),(3,3),(4,5)])
G.append([(1,1),(2,3),(4,5),(5,8)])
G.append([(1,1),(2,5),(3,5),(5,6),(6,7)])
G.append([(3,8),(4,6),(6,2)])
G.append([(4,7),(5,2)])
n=len(G)-1
v=2
prim()

import math

def dijkstra(v):# v = vértice inicial do caminho
    Di = [None]*(n+1)
    vertices = [None]*(n+1)
    VCM = [None]*(n+1)
    for i in range(1,n+1):
        Di[i]=math.inf
        vertices[i]=0
    Di[v]=0
    VCM[v]=0
    while (0 in vertices):
        minimo=math.inf
        w=0
        for j in range(1,len(Di)):
            if ((Di[j]<minimo) and (vertices[j]!=1)):
                minimo=Di[j]
                w=j
                
        print(Di[1:])
        print("seleciona o vertice "+str(w))
        print()
        
        vertices[w]=1
        for j in G[w]:
            z, peso = j[0], j[1]
            if (vertices!=1):
                if ((Di[z])>(Di[w]+peso)):
                    VCM[z]=w
                Di[z]=min(Di[z],Di[w]+peso)

    print("VCM = "+str(VCM[1:]))
    print()
    for i in range(1,n+1):
        if (i!=v):
            cm = []
            t=i
            while(t!=0):
                cm.append(t)
                t=VCM[t]
            cm.reverse()
            print("caminho minimo do vertice "+str(v)+" ate o vertice "+str(i)+" : "+str(cm))

G=[[]]
G.append([(2,3),(4,5)])
G.append([(3,5)])
G.append([(7,10)])
G.append([(3,7),(8,12)])
G.append([(1,6),(7,12)])
G.append([(5,11),(2,8)])
G.append([(6,13)])
G.append([(7,15)])
n=len(G)-1
v = 8
print("v = "+str(v))
print()
dijkstra(v)

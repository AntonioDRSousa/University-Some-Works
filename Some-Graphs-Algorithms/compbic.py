def componentes_biconexas(G):
    n = len(G)
    vert_marc = [0]*(n+1)
    arest_marc = [[0]*(n+1)]*(n+1)
    pilha = []
    cpre = 0
    pre = [0]*(n+1)
    low = [0]*(n+1)
    Blocos (1, 1,cpre, G, pre, low, vert_marc, arest_marc,pilha)

def Blocos (p, v,cpre, G, pre, low, vert_marc, arest_marc, pilha):
    cpre = cpre+1
    pre[v] = cpre
    low[v] = cpre
    
    for w in G[v]:
        print(pilha)
        if arest_marc[w][v]==0:
            pilha.append((w, v))
            arest_marc[w][v]=1
        if pre[w] == 0:
            Blocos(v, w,cpre, G, pre, low, vert_marc, arest_marc, pilha)
            if pre[v] <= low[w]:
                vet=[]
                for i in range(len(pilha)-1,0,-1):
                    if pilha[i]==(w,v) or pilha[i]==(v,w):
                        vet+=pilha.pop()
                        break
                    else:
                        vet+=pilha.pop()
                s = set(vet)
                print("componente biconexa = "+str(s))
            low[v] = min(low[v], low[w])
        elif w != p:
            low[v] = min(low[v], pre[w])


G = [[],[2,3],[1,3],[1,2,6],[5,6],[4,6],[3,4,5]]
componentes_biconexas(G)
            


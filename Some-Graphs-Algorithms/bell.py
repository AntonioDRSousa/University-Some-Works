import math

def BellmanFord(v):
    D = [None]*(n+1)
    VCM = [None]*(n+1)
    for i in range(1,n+1):
        D[i] = math.inf
    D[v]=0
    for k in range(1,n):
        print("-----------------------------")
        print("k = "+str(k)+"\n")
        for i in range(1,n+1):
            for j in range(1,n+1):
                if (E[i-1][j-1]!=0):
                    if (D[j] > (D[i]+E[i-1][j-1])):
                        D[j] = D[i]+E[i-1][j-1]
                        VCM[j] = i
                    print(str((i,j))+" "+str(D[1:]))
        print("-----------------------------")
    print("\nVCM = "+str(VCM[1:])+"\n")
    
                
n=8
E = [ [ 0, 5, 0, 0, 4, 0, 0, 0 ] ,
      [ 0, 0, 11, 0, 0, 0, 0, 0 ] ,
      [ 0, 0, 0 , -3, 0, 0 , 0, 0 ] ,
      [ -1, 0, 0, 0, 0, 0, 0, -6 ] ,
      [ 0, 0, 0, 0, 0, 2, 0, 0 ] ,
      [ 0, 0, 0, 0, 0, 0, 10, 0 ] ,
      [ 0, 0, 8, 0, 0, 0, 0, -9 ] ,
      [ 0, 0, 0, 0, 0, -7, 0, 0 ] ]

print("------------------------")
for i in range(0,n):
    print(E[i])
print("------------------------")

v = 8
print("v = "+str(v))
print()
BellmanFord(v)

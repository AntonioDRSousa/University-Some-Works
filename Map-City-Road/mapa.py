mapa = []

# vertices
class Cidade:
	def __init__(self,nome):
		self.nome=nome
		self.ruas=[]

# arestas
class Rua:
    def __init__(self,nome,cidade):
        self.nome=nome
        self.cidade=cidade


# le o mapa   
def leMapa():
    while True:
        nome_cidade = str(input("Digite o nome da cidade: "))
        if nome_cidade=="":
            break
        mapa.append(Cidade(nome_cidade))

    while True:
        nome_rua = str(input("Digite o nome da rua: "))
        if nome_rua=="":
            break
        cidade_1 = str(input("Digite o nome da cidade 1: "))
        cidade_2 = str(input("Digite o nome da cidade 2: "))

        for i in mapa:
            if i.nome==cidade_1:
                i.ruas.append(Rua(nome_rua,cidade_2))
            elif i.nome==cidade_2:
                i.ruas.append(Rua(nome_rua,cidade_1))

# funcao que lista as cidades vizinhas de uma cidade
def cidadesVizinhas(nome_cidade):
    print("-----------------------------")
    for i in mapa:
        if i.nome==nome_cidade:
            for j in i.ruas:
                print(j.cidade)
    print("-----------------------------")

# funcao que retorna o par de cidades que esta' no meio de uma estrada
def cidadesRua(nome_rua):
    print("----------------------------")
    for i in mapa:
        for j in i.ruas:
            if j.nome==nome_rua:
                print("( "+i.nome+" , "+j.cidade+" ) ")
                return
    print("----------------------------")
        
        

leMapa()
while True:
    print("----------------------------")
    print("1 - Ver Cidades Vizinhas")
    print("2 - Ver par de Cidades ligadas por uma Estrada")
    print("3 - Sair")
    print("----------------------------")
    op=int(input())
    
    if op==1:
        c=str(input("Digite o nome da cidade: "))
        cidadesVizinhas(c)
    elif op==2:
        c=str(input("Digite o nome da rua: "))
        cidadesRua(c)
    elif op==3:
        break

class A:
    pass

class B:
    pass

s1="def som(self,x,y):\n\treturn x+y\n\n"
s2="def sub(self,x,y):\n\treturn x-y\n\n"
s3="def mul(self,x,y):\n\treturn x*y\n\n"
s4="def div(self,x,y):\n\treturn x/y\n\n"

d={"som": s1, "sub": s2, "mul": s3,"div": s4}

while True:
    print("Digite 't' para testar, 'c' para adicionar um metodo ou atributo a classe 'A' ou 'B' e outros caracteres para terminar a execucao")
    s=input()
    if s=="t":
        ss=""
        print("\nBEGIN")
        while True:
            c=input()
            if c=="END":
                break
            ss+=c+"\n"
        print("~~~~~~~~~~~~~~~~~~~~~~\n")
        exec(ss)
        print("~~~~~~~~~~~~~~~~~~~~~~\n")
    elif s=="c":
        print("Digite 'A' para selecionar a classe 'A' ou 'B' para selecionar a classe 'B'")
        nome=input()
        if nome=='A':
            print("atributos de "+nome+" : "+str(dir(A)))
        elif nome=='B':
            print("atributos de "+nome+" : "+str(dir(B)))
        else:
            continue
        print("Digite 'som' para adicionar a funcao soma, 'sub' para subtracao, 'mul' para multiplicacao e 'div' para divisao: ")
        f=input()
        if ((f=="som")or(f=="sub")or(f=="mul")or(f=="div")):
            code=compile(d[f],'codigo','exec')
            exec(code)
            setattr(eval(nome), f, eval(f))
    else:
        break

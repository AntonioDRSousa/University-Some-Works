from math import *

hlp=""
hlp+="  ~~~~~~~~~~~~Comandos~~~~~~~~~~~~\n"
hlp+="  '>>' : comando que declara e inicializa uma variavel(obrigatorio inicializar)\n"
hlp+="         '>>' <nome de variavel> = <expressao>\n"
hlp+="  '<<' : comando que remove uma variavel da lista de variaveis\n"
hlp+="         '<<' <nome da variavel>\n"
hlp+="  '<>' : comando que lista todas as variaveis\n"
hlp+="         '<>'\n"
hlp+="  '><' : comando que atribui um valor a uma variavel\n"
hlp+="         '><' <nome da variavel> = <expressao>\n"
hlp+="  '>'  : comando que imprime uma variável ou expressao\n"
hlp+="         '>' <expressao>\n"
hlp+="  '<'  : comando que remove todas as variaveis da lista de variaveis\n"
hlp+="         '<'\n"
hlp+="  '?'  : comando que informa a ajuda\n"
hlp+="         '?'\n"
hlp+="  Apertar Enter sem nada escrito termina a execucao do programa\n"

print("----------Calculadora Shell----------")
print(hlp)
d=dict({})

while True:
    try:
        s=input("$ ")
        if s=="":
            break
        
        if len(s)<2:
            cmd=s[0]
        else:
            cmd=s[0]+s[1]

        #detecta o comando    
        if cmd==">>": #declara variavel(obrigatorio inicializar)
            
            s=s.replace(" ","")
            tmp=s.split(">>")
            tmp=tmp[1].split("=")
            d[tmp[0]]=eval(tmp[1])
            
        elif cmd=="<<": #remove variavel
            
            s=s.replace(" ","")
            tmp=s.split("<<")
            del d[tmp[1]]
            
        elif cmd=="<>": #lista todas as variaveis
            
            print("\n  ~~~~~~~~~~~~~~~~")
            for chave, valor in d.items():
                print("  ",chave," = ",str(valor))
            print("  ~~~~~~~~~~~~~~~~\n")
            
        elif cmd=="><": #atribui valor a variavel
            
            s=s.replace(" ","")
            tmp=s.split("><")
            tmp=tmp[1].split("=")
            d[tmp[0]]=eval(tmp[1],globals(),d)
            
        elif cmd[0]==">": #imprime uma variavel ou valor de uma expressao
            
            s=s.replace(" ","")
            tmp=s.split(">")
            print("  ",eval(tmp[1],globals(),d))
            
        elif cmd[0]=="<": #remove todas as variaveis
            
            d=dict({})
            
        elif cmd[0]=="?": #ajuda
            
            print(hlp)
            
        else:
            
            print("\n  Erro. Comando invalido.....")
            
    except:
        print("  Erro.....")


precoRetrato::Integer->String->Double
precoRetrato n d = if fimSemana then custo*1.2 else custo
    where
        custo
            |n==1 = 100
            |n==2 = 130
            |n==3 = 150
            |n==4 = 165
            |n==5 = 175
            |n==6 = 180
            |otherwise = 185
        fimSemana = (d=="sabado")||(d=="domingo")

data Lista a = No a (Lista a) | Vazio 

-- criacao de uma lista que guarda sublistas de inteiros
v1::Lista Int
v1 = No 10 (No 23 (No 4 Vazio))

v2::Lista Int
v2 = No 12 (No 34 (No 67 (No 4 Vazio) ) ) 

v3::Lista Int
v3 = No 3 (No 5 Vazio)

v4::Lista Int
v4 = No 3 (No 5 (No 7 (No 11 Vazio) ) )

v5::Lista Int
v5 = No 4 (No 9 (No 16 (No 25 Vazio) ) )

v::Lista (Lista Int)
v = No v1 (No v2 (No v3 (No v4 (No v5 Vazio))))

-- para transformar a lista de listas de inteiros em string
toStringLL:: Lista (Lista Int) -> String
toStringLL x = "["++(tail (toStringLL' x))++"]"
                where
                    toStringLL' Vazio = ""
                    toStringLL' (No r t ) = ","++toStringL(r)++toStringLL'(t)
                    
                    toStringL x = "["++(tail (toStringL' x))++"]"
                    toStringL' Vazio = ""
                    toStringL' (No r t ) = ","++show(r)++toStringL'(t)
                    

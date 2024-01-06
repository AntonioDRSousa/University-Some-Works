data Arvore a = Galho (Arvore a) a (Arvore a) | Folha deriving Show
data Lista a = No a (Lista a) | Vazio deriving Show

l1::Lista Int
l1 = No 1 (No 2 (No 3 (No 4 (No 5 Vazio))))

l2::Lista Int
l2 = No 6 (No 7 (No 8 (No 9 (No 10 Vazio))))

v::Lista [Int]
v = No [10,23,4] (No [12,34,67,4] (No [3,5] Vazio))

x:: Arvore Int
x = Galho (Galho (Galho Folha 1 Folha)
                 2
                 (Galho Folha 3 Folha))
          4
          (Galho (Galho Folha 5 Folha)
                 6
                 (Galho Folha 7 Folha))

y:: Arvore Bool
y = Galho (Galho (Galho Folha True Folha)
                 True
                 (Galho Folha False Folha))
          False
          (Galho (Galho Folha False Folha)
                 False
                 (Galho Folha True Folha))

z:: Arvore [Int]
z = Galho (Galho (Galho Folha [1,8,7] Folha)
                 [12,2]
                 (Galho Folha [5,9] Folha))
          [423]
          (Galho (Galho Folha [2,5] Folha)
                 [297,6,7]
                 (Galho Folha [11,23,34,7] Folha))

conc:: Lista a -> Lista a->Lista a
conc (v1) (v2) = conc' (v1)
                 where
                     conc' Vazio = v2
                     conc' (No r t) = No r (conc' t)

lista :: Arvore a -> Lista a
lista Folha = Vazio
lista (Galho e a d) = No a (conc (lista e) (lista d))

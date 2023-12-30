quociente::Integer->Integer->Integer
quociente a b
    | a<b = 0
    |otherwise = 1 + quociente (a-b) b

resto::Integer->Integer->Integer
resto a b
    | a<b = a
    |otherwise = resto (a-b) b

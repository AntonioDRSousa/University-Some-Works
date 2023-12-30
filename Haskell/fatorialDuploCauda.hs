fatorialDuploCauda::Integer->Integer
fatorialDuploCauda n = fatorialDuploCauda' n 1

fatorialDuploCauda'::Integer->Integer->Integer
fatorialDuploCauda' n y
    | (n==0)||(n==1) = y
    | n>1 = fatorialDuploCauda' (n-2) (n*y)

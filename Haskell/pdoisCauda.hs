pdoisCauda::Integer->Integer
pdoisCauda n = pdoisCauda' n 1

pdoisCauda'::Integer->Integer->Integer
pdoisCauda' n y
    | n==0 = y
    | n>0  = pdoisCauda' (n-1) (2*y) 

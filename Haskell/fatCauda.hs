fatCauda::Integer->Integer
fatCauda n = fatCauda' n 1

fatCauda'::Integer->Integer->Integer
fatCauda' n y
    | n==0 = y
    | n>0  = fatCauda' (n-1) (y*n)


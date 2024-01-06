parCauda::Integer->Bool
parCauda n = parCauda' n True

parCauda'::Integer->Bool->Bool
parCauda' n y
    | n==0 = y
    | n>0  = parCauda' (n-1) (not y)

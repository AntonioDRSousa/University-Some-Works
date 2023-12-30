mulIntervaloCauda::Integer->Integer->Integer
mulIntervaloCauda m n = mulIntervaloCauda' m n 1

mulIntervaloCauda'::Integer->Integer->Integer->Integer
mulIntervaloCauda' m n y
    | m==(n-1) = y
    | m>=n  = mulIntervaloCauda' (m-1) n (m*y)

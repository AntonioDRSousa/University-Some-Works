pot::Integer->Integer->Integer
pot n e
    | e==0 = 1
    | otherwise = n*(pot n (e-1))

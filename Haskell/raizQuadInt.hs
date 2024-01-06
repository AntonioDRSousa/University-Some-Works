raizQuadradaInteira::Integer->Integer
raizQuadradaInteira n = raizQuadradaInteira' n 1

raizQuadradaInteira'::Integer->Integer->Integer
raizQuadradaInteira' n y
    | n<(y^2) = y-1
    | otherwise = raizQuadradaInteira' n (y+1)

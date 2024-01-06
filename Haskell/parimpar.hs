par::Int->Bool
par n | n==0      = True
      | n>0       = impar (n-1)
      | otherwise = par (-n)

impar::Int->Bool
impar n | n==0      = False
        | n>0       = par (n-1)
        | otherwise = impar (-n)

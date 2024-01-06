numRaizes::Double->Double->Double->Int
numRaizes a b c
    |delta>0 = 2
    |delta<0 = 0
    |otherwise = 1
    where
        delta = (b**2)-(4*a*c)

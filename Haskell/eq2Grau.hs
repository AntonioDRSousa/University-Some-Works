eq2Grau::Double->Double->Double->[Double]
eq2Grau a b c
    | delta>0 = [x1,x2]
    | delta==0 = [x3]
    | otherwise = error "Não tem raízes reais"
    where
        delta = (b**2) - (4*a*c)
        x1 = ((-b) + (sqrt delta))/(2*a)
        x2 = ((-b) - (sqrt delta))/(2*a) 
        x3 = (-b)/(2*a)

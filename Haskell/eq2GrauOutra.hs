eq2Grau'::Double->Double->Double->[Double]
eq2Grau' a b c = do let delta = (b**2) - (4*a*c)
                        x1 = ((-b) + (sqrt delta))/(2*a)
                        x2 = ((-b) - (sqrt delta))/(2*a) 
                        x3 = (-b)/(2*a)
                    if delta>0
                        then [x1,x2]
                        else if delta==0
                                then [x3]
                                else error "Não tem raízes reais"

data Produto = Produto { nome :: String 
                       , tipo :: String
                       , qtd :: Int
                       , preco :: Double
                       } deriving Show

lDisp::[Produto]->Double->[Produto]->[Produto]
lDisp prod din compr = filter disp prod
                       where
                           dAtual = din - (foldr (sum) 0 compr)
                           sum x y = (preco x) + y
                           disp x = if ((qtd x)>=1)&&(dAtual>=(preco x)) then
                                        True
                                    else
                                        False
                                      

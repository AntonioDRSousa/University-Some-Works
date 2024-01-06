import Data.List

-- ordena vetores em ordem crescente de acordo com o seu tamanho 
-- se os tamanhos forem iguais ordena por modulo
sortVectors::[[Double]]->[[Double]]
sortVectors lv = sortBy cmp lv
                 where
                     modulo::[Double]->Double
                     modulo v = sqrt (foldr (sumQ) 0 v)
                     sumQ x y = (x**2)+y
                     
                     cmp v w = if (lExprL1 v w) then
                                   LT 
                               else if (lExprL2 v w) then
                                   GT
                               else if (lExprM v w) then
                                   LT
                               else
                                   GT
                     lExprL1 v w = (length v) < (length w)
                     lExprL2 v w = (length v) > (length w)
                     lExprM v w = (modulo v) < (modulo w)
                       

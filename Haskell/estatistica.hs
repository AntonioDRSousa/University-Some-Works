estatistica::[Double]->(Double,Double)
estatistica lista = (media,(desvio media))
                    where
                        n = fromIntegral (length lista) :: Double
                        
                        media:: Double
                        media = (foldr (+) 0 lista) / n

                        desvio::Double->Double
                        desvio m = sqrt ( ( foldr (\ x y -> ((x - m)**2) + y ) 0 lista) / n )

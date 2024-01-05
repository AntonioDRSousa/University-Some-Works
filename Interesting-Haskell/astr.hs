-- simulador de um sistema que segue a lei da gravitacao universal de newton

-- vetor em tres dimensoes
data Vetor = Vetor { x :: Double
                   , y :: Double
                   , z :: Double
                   } deriving Show

data Corpo = Corpo { pos    :: Vetor --posicao do corpo
                   , desl   :: Vetor -- vetor deslocamento c/relacao ao corpo principal 
                   , massa  :: Double -- massa do corpo
                   } deriving Show

constG = 6.67/(10^(11)) -- constante da gravitacao universal


calc corpo1 v = sumVect (ace corpo1) v
                     where
                         -- componentes do vetor 
                         rx corpo = (x (desl corpo))
                         ry corpo = (y (desl corpo))
                         rz corpo = (z (desl corpo))

                         -- modulo do vetor
                         modr corpo = sqrt ( ((rx corpo)^2)+((ry corpo)^2)+((rz corpo)^2) )
                         
                         m corpo = massa corpo

                         coef corpo = constG*((m corpo)/((modr corpo)^3))

                         -- aceleracao do corpo
                         ace corpo = Vetor { x = (coef corpo)*(rx corpo), y = (coef corpo)*(ry corpo), z = (coef corpo)*(rz corpo) }

                         --soma de vetores
                         sumVect v1 v2 = Vetor { x = (x v1)+(x v2), y = (y v1)+(y v2), z = (z v1)+(z v2) }

calcForca massaCorpo lCorpos =  pEsc (massaCorpo) aceleracao
                                where
                                    -- vetor nulo
                                    vNulo = Vetor { x = 0, y = 0, z = 0 }

                                    -- aceleracao resultante
                                    aceleracao = (foldr (calc) (vNulo) lCorpos)

                                    -- produto escalar
                                    pEsc e v = Vetor { x = e*(x v), y = e*(y v), z = e*(z v) }

--leCorpos n x y z = if n==0 then
                       --[]
                   --else
                       --((leC n):(leCorpos (n-1) x y z))
                   --where
                       --leC n = do putStrLn "/////////////////////////////////////////"
                                  --putStrLn ("Corpo "++(show n))
                                  --putStr "massa = "
                                  --massa<-readLn::IO Double
                                  --putStr "-- posicao em x = "
                                  --x<-readLn::IO Double
                                  --putStr "-- posicao em y = "
                                  --y<-readLn::IO Double
                                  --putStr "-- posicao em z = "
                                  --z<-readLn::IO Double
                                  --putStrLn "/////////////////////////////////////////"
                                  --return (Corpo{})
                                  
                                
                                

--menu = do putStrLn "========================================================="
          --putSTrLn "---------------------------------------------------------"
          --putStr "\n Digite o corpo principal: " -- corpo para o qual se calcular forca exercida sobre ele
          --putStr "-- massa = "
          --massa<-readLn::IO Double
          --putStr "-- posicao em x = "
          --x<-readLn::IO Double
          --putStr "-- posicao em y = "
          --y<-readLn::IO Double
          --putStr "-- posicao em z = "
          --z<-readLn::IO Double
          --putSTrLn "---------------------------------------------------------"

          --putSTrLn "---------------------------------------------------------"
          --putStrLn "\nQuantos corpos fixos tem o sistema: " -- corpos que n sao o principal
          --n<-readLn::IO Int
          --leCorpos n x y z
          --putSTrLn "---------------------------------------------------------"
          
          
           
                            
                         
                         
             

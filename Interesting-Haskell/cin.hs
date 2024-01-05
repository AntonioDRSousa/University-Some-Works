data Corpo = Corpo { pos :: Double -- posicao no espaco unidimensional
                   , vel :: Double -- velocidade do corpo
                   , ace :: Double -- aceleracao do corpo
                   } deriving Show

criarCorpo s v a = Corpo { pos = s, vel = v, ace = a }

movimento lCorpos t = map (mov) lCorpos
                      where
                          mov corpo = corpo { pos = (newPos corpo) , vel = (newVel corpo)}
                          newPos corpo = s (pos corpo) (vel corpo) (ace corpo)
                          newVel corpo = v (vel corpo) (ace corpo)
                          s s0 v0 a =  s0 + (v0*t) +  (1/2)*a*(t**2)
                          v v0 a = v0 + (a*t)

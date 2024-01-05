module Main(main)where
import System.IO(stdout,hSetBuffering,BufferMode(NoBuffering))

data Forca = Forca { x :: Double -- componente x do vetor forca
                   , y :: Double -- '' y
                   , z :: Double -- '' z
                   , c :: Int -- corpo que a forca interage
                   } deriving Show

leForcas::Int->[Forca]
leForcas qtd = do putStrLn "------------------------------"
                  putStr "x = "
                  x'<-readLn::IO Double
                  putStr "y = "
                  y'<-readLn::IO Double
                  putStr "z = "
                  z'<-readLn::IO Double
                  putStrLn "corpo que atua a forca = "
                  c'<-readLn::IO Int
                  if ((c'<=0)||(c'>qtd))then do
                      leForcas qtd
                  else do
                      putStrLn "------------------------------"
                      let f = Forca {x=x', y=y',z=z', c=c'}
                      putStrLn "Continuar(s/n)?"
                      ch<-getChar
                      if ch=='s' then do
                          [f]++(leForcas qtd)
                      else do
                          [f]

calcRes forcas qtd = map (res) [1..qtd]
                     where
                         res x = (foldr (sumVect) vNulo (filter (\ x' -> (c x')==x) forcas))
                         sumVect v1 v2 = Forca { x = (x v1)+(x v2), y = (y v1)+(y v2), z = (z v1)+(z v2) , c=(c v1) }
                         vNulo = Forca { x = 0, y = 0, z = 0, c=0 }
              

main = do hSetBuffering stdout NoBuffering
          putStrLn "==================================="
          putStrLn "Digite a quantidade de corpos: "
          qtd<-readLn::IO Int
          putStrLn "Digite as forcas: "
          let forcas = leForcas
          print forcas
          let resultantes = calcRes forcas qtd
          print (resultantes)
          putStrLn "==================================="

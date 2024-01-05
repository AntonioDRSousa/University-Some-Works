module Main(main)where
import System.IO(stdout,hSetBuffering,BufferMode(NoBuffering))

data Forca = Forca { fx    :: Double -- componente x do vetor forca
                   , fy    :: Double -- '' y
                   , fz    :: Double -- '' z
                   , corpo :: Int -- corpo que a forca interage
                   } deriving Show

initForca x' y' z' c' = Forca { fx=x' , fy=y' , fz=z' , corpo=c' }

impr [] = return ()
impr (x:xs) = do print x
                 impr xs

calcRes forcas qtd = filter (\ x -> (corpo x)/=0 ) (map (res) [1..qtd])
                     where
                         res x = (foldr (sumVect) vNulo (filter (\ x' -> (corpo x')==x) forcas))
                         sumVect v1 v2 = v1 { fx = fx', fy = fy', fz = fz'}
                                         where
                                             fx'=(fx v1)+(fx v2)
                                             fy'=(fy v1)+(fy v2)
                                             fz'=(fz v1)+(fz v2)
                         vNulo = Forca { fx = 0, fy = 0, fz = 0, corpo=0 }
              

main = do hSetBuffering stdout NoBuffering
          let f1 = initForca 12 45 36 1
          let f2 = initForca 30 78 89 2
          let f3 = initForca 50 2 12 1
          let f4 = initForca 1 39 34 2
          let f5 = initForca 90 90 40 3
          let f6 = initForca 24 23 12 3
          let f7 = initForca 10 56 56 1
          let f8 = initForca 100 150 54 3
          
          let forcas = [f1,f2,f3,f4,f5,f6,f7,f8]

          putStrLn "----------------------Forcas----------------------"
          impr (forcas)
          putStrLn "--------------------------------------------------\n\n"

          putStrLn "----------------Forcas Resultantes----------------"
          impr (calcRes forcas 8)
          putStrLn "--------------------------------------------------"
          

module Main(main)where
import System.IO(stdout,hSetBuffering,BufferMode(NoBuffering))

main::IO()
main = do hSetBuffering stdout NoBuffering
          putStr "Digite o número de iterações: "
          n<-readLn::IO Integer
          putStr "aproximação para pi: "
          print (piRecursivo n)

piRecursivo::Integer->Double
piRecursivo n
    | n==(-1) = 0
    | otherwise = parcela + (piRecursivo (n-1))
    where
        parcela::Double
        parcela = (fromIntegral (4*((-1)^n)) / (fromIntegral (2*n+1)))
        

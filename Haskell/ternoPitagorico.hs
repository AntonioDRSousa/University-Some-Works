module Main(main)where
import System.IO(stdout,hSetBuffering,BufferMode(NoBuffering))

main::IO()
main = do hSetBuffering stdout NoBuffering
          putStrLn "Verificação de ternos pitagóricos"
          putStrLn "----------------------------"
          putStr "Digite o primeiro número positivo .....: "
          a<-readLn::IO Int
          putStr "Digite o segundo número positivo .....: "
          b<-readLn::IO Int
          putStr "Digite o terceiro número positivo .....: "
          c<-readLn::IO Int
          if isPositive a b c then
              if pit a b c then putStr "Os números formam um terno pitagórico" else putStr "Os números não formam um terno pitagórico"
          else
              putStr "Números inválidos"
      where
          isPositive a b c = (a>0)&&(b>0)&&(c>0)
          pit  a b c = ((a^2)+(b^2))==(c^2)

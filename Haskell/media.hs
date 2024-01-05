module Main(main)where
import System.IO(stdout,hSetBuffering,BufferMode(NoBuffering))

main::IO()
main = do putStrLn "Cálculo da média aritemética"
          putStrLn "-------------------------------"
          putStrLn "Digite uma sequência de números (um por linha)"
          putStrLn "Para terminar digite um valor negativo"
          lista<-leNumeros

          let
              tamanho = size lista
              media = (soma lista)/tamanho
              
          if tamanho>0
              then do putStr "média = "
                      print media
              else putStr "não existe média"
       where
           size [] = 0
           size (x:xs)= 1 + (size xs)

leNumeros = do x<-readLn::IO Double
               if x<0
                   then return []
                   else do xs<-leNumeros
                           return (x:xs)

soma [] = 0
soma (x:xs) = x + soma(xs)



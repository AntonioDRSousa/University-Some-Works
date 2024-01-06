module Main(main)where
import System.IO(stdout,hSetBuffering,BufferMode(NoBuffering))

main::IO()
main = do hSetBuffering stdout NoBuffering
          n <- leNatural
          lista <- leNumeros n
          putStr "Soma dos números digitados: "
          print (soma lista)

leNatural = do putStr "Quantidade de números: "
               n <- readLn
               if n<=0
                   then do putStrLn "Erro. Número menor que zero"
                           n<-leNatural
                           return n
                   else do putStrLn ""
                           return n

leNumeros n = do if n==0
                     then return []
                     else do putStr "Digite um número: "
                             x <- readLn
                             xs <- leNumeros (n-1)
                             return (x:xs)

soma [] = 0
soma (x:xs) = x + soma xs

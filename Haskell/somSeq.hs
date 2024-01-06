module Main(main)where

main = do putStrLn "Digite uma sequência de números (um por linha)"
          putStrLn "Para terminar digite o valor zero"
          soma <- lerESomar
          putStr "A soma dos números digitados é "
          print soma

lerESomar = do n <- readLn
               if n==0
                   then return 0
                   else do somaResto <- lerESomar
                           return (n+somaResto)

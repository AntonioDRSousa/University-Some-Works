--com recursividade de cauda
module Main(main)where

main = do putStrLn "Digite uma sequência de números (um por linha)"
          putStrLn "Para terminar digite o valor zero"
          soma <- lerESomar 0
          putStr "A soma dos números digitados é "
          print soma

lerESomar total = do n <- readLn
                     if n==0
                         then return total
                         else lerESomar (total+n)

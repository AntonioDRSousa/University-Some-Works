module Main(main)where

main = do putStrLn "Digite uma sequência de números"
          putStrLn "Termina com negativo"
          lista <- lerLista
          putStr ""
          putStr "sequencia ->   "
          impr lista
          print (soma lista)

lerLista = do x<-readLn
              if x<0
                  then return []
                  else do resto<- lerLista
                          return (x:resto)

impr [] = do putStrLn ""
             putStrLn ""
             return ()
impr (x:xs)= do putStr (show x)
                putStr " "
                impr xs

soma [] = 0
soma (x:xs) = x + soma xs

module Main(main)where

main::IO()
main = do putStrLn "Digite um numero: "
          s1 <- getLine
          putStrLn "Digite outro numero: "
          s2 <- getLine
          putStrLn "Soma dos numeros digitados: "
          let n1 = read s1::Double
              n2 = read s2::Double
              s  = n1+n2
          putStrLn (show s)

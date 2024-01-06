module Main(main)where
import System.IO(stdout,hSetBuffering,BufferMode(NoBuffering))

main::IO()
main = do hSetBuffering stdout NoBuffering
          putStrLn "Digite uma frase: "
          s<-getLine
          if s==(reverse(s))
              then putStr "É um palindromo"
              else putStr "Não é um palindromo"

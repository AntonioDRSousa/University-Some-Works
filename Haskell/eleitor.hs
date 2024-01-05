module Main(main)where
import System.IO(stdout,hSetBuffering,BufferMode(NoBuffering))

main::IO()
main = do hSetBuffering stdout NoBuffering
          putStrLn "Classe eleitoral"
          putStrLn "-------------------------------------------"
          putStrLn "Digite a idade da pessoa: "
          idade<-readLn::IO Int
          if idade<16
              then putStr "não eleitor"
              else if (idade>=18)&&(idade<=65)
                       then putStr "eleitor obrigratório"
                       else putStr "eleitor facultativo"

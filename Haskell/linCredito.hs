module Main(main)where
import System.IO(stdout,hSetBuffering,BufferMode(NoBuffering))

main::IO()
main = do hSetBuffering stdout NoBuffering
          putStrLn "Análise de crédito\n-------------------------------------------"
          putStr "Salário bruto: "
          salarioBruto<-readLn::IO Double
          putStr "Valor da prestação: "
          valorPrestação<-readLn::IO Double
          if analise valorPrestação salarioBruto
              then putStr "O emprestimo pode ser concedido"
              else putStr "O emprestimo não pode ser concedido"
          where
              analise::Double->Double->Bool
              analise valorPrestação salarioBruto= valorPrestação<(salarioBruto*0.3)

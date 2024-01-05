module Main(main)where
import System.IO(stdout,hSetBuffering,BufferMode(NoBuffering))

main::IO()
main = do hSetBuffering stdout NoBuffering
          putStr "Informe o salário: "
          salario<-readLn::IO Double
          putStr "Ano de contratação: "
          anoContrato<-readLn
          putStr "Ano Atual: "
          anoAtual<-readLn
          let
              salarioAtual = (aumento salario anoContrato anoAtual) + salario
          putStr "Salário Atual: "
          putStr (show salarioAtual)

aumento::Double->Integer->Integer->Double
aumento salario anoContrato anoAtual = aumento' salario anoContrato anoAtual 0.015
    where
        aumento'::Double->Integer->Integer->Double->Double
        aumento' salario anoContratado anoAtual percentagem
            | anoContratado == anoAtual = 0
            | anoContratado == (anoAtual-1) = percentagem*salario
            | anoContratado < anoAtual = aumento' salario (anoContratado+1) anoAtual (percentagem*2)
            | otherwise = error "Erro. Ano de Contrato posterior ao Ano Atual."

module Main(main)where
import System.IO(stdout,hSetBuffering,BufferMode(NoBuffering))

menu = do putStrLn "---------------------------"
          putStrLn "Opções:"
          putStrLn "---------------------------"
          putStrLn "1. Imposto"
          putStrLn "2. Novo salário"
          putStrLn "3. Classificação" 
          putStrLn "---------------------------"
          putStr "Digite a opção desejada: "

imposto = do putStrLn "Cálculo do imposto"
             putStr "Digite o salário: "
             salario<-readLn::IO Double
             putStr ("Imposto calculado: "++show(imposto salario))
          where
              imposto salario
                  |salario<500 = salario*0.05
                  |salario>850 = salario*0.15
                  |otherwise = salario*0.1

novoSalario = do putStrLn "Cálculo do novo salário"
                 putStr "Digite o salário: "
                 salario<-readLn::IO Double
                 putStr ("Novo salário: "++show(salario+(aumento salario)))
              where
                  aumento salario
                      |salario>1500 = 25
                      |salario<450 = 100
                      |(salario>=450)&&(salario<750) = 75
                      |otherwise = 50

classificação = do putStrLn "Classificação do salário"
                   putStr "Digite o salário: "
                   salario<-readLn::IO Double
                   putStr "Classificação obtida: "
                   if salario<=750
                       then putStr "mal remunerado"
                       else putStr "bem remunerado"
                 

main::IO()
main = do hSetBuffering stdout NoBuffering
          menu
          op<-readLn
          if op==1 
              then imposto
              else if op==2 
                       then novoSalario
                       else if op==3
                                then classificação
                                else putStr "Opção inválida!"
          

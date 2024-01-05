module Main(main)where
import System.IO(stdout,hSetBuffering,BufferMode(NoBuffering))

c1 = [5,9,3,7,10]
c2 = [8,2,5,4]
c3 = [9,7,8]
c4 = [2,7]
c5 = [3,1]
c6 = [6,2]
c7 = [5,4]
c8 = [4,8,2]
c9 = [6,7,9,8]
c10 =[4,6,4,8,3]

circuitos::[[Double]]
circuitos = [c1,c2,c3,c4,c5,c6,c7,c8,c9,c10]

resParalelo::[Double]->Double
resParalelo c = 1 / (foldr (\ x y -> (1/x)+y) 0 c)

resSerie::[Double]->Double
resSerie c = foldr (+) 0 c

calc::[Double]->IO ()
calc c = do hSetBuffering stdout NoBuffering
            putStrLn "---------------------"
            putStrLn "Digite a opcao:"
            putStrLn "1 - Calcular Itensidade de Corrente dos Circuitos"
            putStrLn "2 - Calcular DDP dos Circuitos"
            putStrLn "3 - Calcular Resistencia Total dos Circuitos juntos em Serie"
            putStrLn "4 - Calcular Resistencia Total dos Circuitos juntos em Paralelo"
            putStrLn "5 - Analisar Circuitos"
            putStrLn "6 - Ver Resistencias Totais de cada Circuito"
            putStrLn "7 - Sair"
            putStrLn "---------------------"
            op<-readLn::IO Int
            if op==1 then do
                putStr "ddp = "
                ddp<-readLn::IO Double
                putStrLn "========================"
                putStr "Intensidades de Corrente = "
                print (map (\ x -> ddp/x) c)
                putStrLn "========================"
                calc c    
            else if op==2 then do
                putStr "I = "
                i<-readLn::IO Double
                putStrLn "========================"
                putStr "DDP = "
                print (map (\ x -> x*i) c) 
                putStrLn "========================"
                calc c   
            else if op==3 then do
                putStrLn "========================"
                putStr "Resistencia Total em Serie = "
                print (resSerie c)
                putStrLn "========================"
                calc c
            else if op==4 then do
                putStrLn "========================"
                putStr "Resistencia Total em Paralelo = "
                print (resParalelo c)
                putStrLn "========================"
                calc c
            else if op==5 then do
                let m = (foldr (+) 0 c) / (fromIntegral (length c)::Double)
                let lc = filter (\ x -> x<m) c
                let hc = filter (\ x -> x>m) c
                putStrLn "========================"
                putStr "Resistencia Total Media dos Circuitos = "
                print (m)
                putStr "Resistencias Totais Inferiores a Media = "
                print (lc)
                putStr "Resistencia Totais Superiores a Media = "
                print (hc)
                putStrLn "========================"
                calc c
            else if op==6 then do
                putStrLn "========================"
                putStr "Resistencia Total dos Circuitos = "
                print (c)
                putStrLn "========================"
                calc c
            else if op==7 then do
                menu
            else do
                calc c
                

menu = do hSetBuffering stdout NoBuffering
          putStrLn "---------------------"
          putStrLn "Digite a opcao:"
          putStrLn "1 - Resistencia dos Circuitos em Serie"
          putStrLn "2 - Resistencia dos Circuitos em Paralelo"
          putStrLn "3 - Sair"
          putStrLn "---------------------"
          op<-readLn::IO Int
          if op==1 then do
              calc (map (\ c -> (resSerie c)) circuitos)
          else if op==2 then
              calc (map (\ c -> (resParalelo c)) circuitos)
          else if op==3 then
              putStr "Sair"
          else
              menu


main = do menu

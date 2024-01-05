module Main(main)where
import System.IO(stdout,hSetBuffering,BufferMode(NoBuffering))

main::IO()
main = do hSetBuffering stdout NoBuffering
          putStr "Digite a Massa Inicial: "
          m0<-readLn::IO Double
          print m0
          putStrLn "\n"
          radioatividade m0

radioatividade m0 = radioatividade' m0 0
   where
        radioatividade' m0 t = do if t==70
                                      then return()
                                      else do 
                                              let
                                                  massa = m0*((exp 1)**((-k)*t))
                                              putStr ((show massa)++" ")
                                              radioatividade' massa (t+10)
                               where
                                   k = 0.05

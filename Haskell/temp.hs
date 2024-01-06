module Main(main)where
import System.IO(stdout,hSetBuffering,BufferMode(NoBuffering))

celsius::Double->Double
celsius fahrenheit = (5/9)*(fahrenheit-32) 

main::IO()
main = do hSetBuffering stdout NoBuffering
          putStr "Temperatura em Fahrenheit: "
          f<-readLn::IO Double
          putStr ("Temperatura em Celsius: "++show(celsius f))

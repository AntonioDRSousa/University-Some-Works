module Main(main) where

import System.IO (hSetBuffering, stdout, BufferMode(NoBuffering))

main::IO()
main =
    do 
        hSetBuffering stdout NoBuffering
        putStr "n1 = "
        n1 <- readLn::IO Double
        putStr "n2 = "
        n2 <- readLn::IO Double
        putStr "n3 = "
        n3 <- readLn::IO Double
        print (n1*n2*n3)
    

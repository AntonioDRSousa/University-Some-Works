module Main(main)where

import System.IO

main::IO()
main = do putStr "n1 = "
          hFlush stdout
          n1 <- readLn :: IO Double
          putStr "n2 = "
          hFlush stdout
          n2 <- readLn :: IO Double
          putStr "n1 + n2 = "
          putStrLn (show (n1+n2))
          

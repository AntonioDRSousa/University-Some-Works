module Main(main) where

import Data.Char (toLower, toUpper)

main::IO()
main = do letra <- getChar
          putChar (toLower letra)
          putChar (toUpper letra)

module Main(main)where

mostraLista::Show a => [a] -> IO()
mostraLista [] = return ()
mostraLista (x:xs) = do print x
                        mostraLista xs

main::IO()
main = mostraLista [0,2..30]

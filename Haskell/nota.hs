module Main where

import System.IO (hSetBuffering, stdout, BufferMode(NoBuffering))

main :: IO ()
main =
    do  hSetBuffering stdout NoBuffering
        putStr "Digite a nota do trabalho de laboratório ...: "
        laboratório <- readLn
        putStr "Digite a nota da avaliação semestral .......: "
        semestral <- readLn
        putStr "Digite a nota do exame final ...............: "
        final <- readLn
        putStrLn ""
        putStr "Conceito obtido: "
        let conceitoObtido = conceito laboratório semestral final
        putStrLn [conceitoObtido]

conceito :: Float -> Float -> Float -> Char
conceito tl na ne
    | media>=8 = 'A'
    | media>=7 = 'B'
    | media>=6 = 'C'
    | media>=5 = 'D'
    |otherwise = 'E'
    where
        media = ((tl*2)+(na*3)+(ne*5))/10 

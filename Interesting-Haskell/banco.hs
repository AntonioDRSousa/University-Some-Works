module Main(main)where
import System.IO(stdout,hSetBuffering,BufferMode(NoBuffering))

data Conta = Conta { numConta :: Int
                   , senha :: Int
                   , nome :: String
                   , valor :: Double
                   } deriving Show

listaContas [] = return ()
listaContas (x:xs) = do print x
                        listaContas xs

criarConta lContas = do putStrLn "Digite o nome: "
                        n <- getLine
                        putStrLn "Digite uma senha com 6 digitos(sem 0 como primeiro algarismo a' esquerda): "
                        s <- readLn::IO Int
                        if ((s>(10^5))&&(s<(10^6))) then do
                            let l = lContas ++ [Conta {numConta = (length lContas), senha = s, nome = n, valor = 0 }]
                            putStr "numero da Conta = "
                            putStrLn (show (length lContas))
                            menuPrincipal l
                        else do
                            putStrLn "\nErro. Senha Invalida....."
                            criarConta lContas

acaoConta lContas n = do putStrLn "-------------------"
                         putStrLn "Digite a opcao: "
                         putStrLn "1 - Sacar Dinheiro"
                         putStrLn "2 - Transferir Dinheiro"
                         putStrLn "3 - Depositar Dinheiro"
                         putStrLn "4 - Ver Saldo"
                         putStrLn "5 - Sair"
                         putStrLn "-------------------"
                         op <- readLn::IO Int
                         let l1 = take n lContas
                         let l2 = drop (n+1) lContas
                         let cnt1 = lContas !! n
                         if (op==1) then do
                             putStrLn "\nInforme o valor a sacar: "
                             v<-readLn::IO Double
                             let cnt1' = cnt1 {valor = ((valor cnt1)-v)}
                             acaoConta ((l1 ++ [cnt1']) ++ l2) n
                         else if (op==2) then do
                             putStrLn "Numero da Conta a Transferir: "
                             n' <- readLn::IO Int
                             putStrLn "\nInforme o valor a sacar: "
                             v<-readLn::IO Double
                             let cnt1' = cnt1 {valor = ((valor cnt1)-v)}
                             let lContas' = (l1 ++ [cnt1']) ++ l2
                             let l1' = take n' lContas'
                             let l2' = drop (n'+1) lContas'
                             let cnt2 = lContas' !! n'
                             let cnt2' = cnt2 {valor = ((valor cnt2)+v)}
                             acaoConta ((l1' ++ [cnt2']) ++ l2') n
                         else if (op==3) then do
                             putStrLn "\nInforme o valor a depositar: "
                             v<-readLn::IO Double
                             let cnt1' = cnt1 {valor = ((valor cnt1)+v)}
                             acaoConta ((l1 ++ [cnt1']) ++ l2) n
                         else if (op==4) then do
                             putStr "\nsaldo = "
                             putStrLn (show (valor cnt1))
                             acaoConta lContas n
                         else if (op==5) then do
                             menuPrincipal lContas
                         else do
                             acaoConta lContas n

verConta lContas = do putStrLn "Digite o numero da Conta: "
                      nCont<-readLn::IO Int
                      let cont = lContas !! (nCont)
                      putStrLn "Digite a senha: " 
                      s<-readLn::IO Int
                      if (s==(senha cont)) then do
                          acaoConta lContas nCont
                      else do
                          putStrLn "Erro....."
                          menuPrincipal lContas        

menuPrincipal lContas = do putStrLn "-------------------"
                           putStrLn "Digite a opcao:"
                           putStrLn "1 - Criar Conta"
                           putStrLn "2 - Consultar Conta"
                           putStrLn "3 - Listar Contas"
                           putStrLn "4 - Passar 1 mês"
                           putStrLn "5 - Sair"
                           putStrLn "-------------------"
                           op <- readLn::IO Int
                           if (op==1) then do
                               criarConta lContas
                           else if (op==2) then do
                               verConta lContas
                           else if (op==3) then do
                               listaContas lContas
                               menuPrincipal lContas
                           else if (op==4) then do
                               putStrLn "passou 1 mes"
                               menuPrincipal (map (\x -> x {valor=(valor x)*1.005}) lContas)
                           else if (op==5) then do
                               return ()
                           else
                               menuPrincipal lContas

main = do hSetBuffering stdout NoBuffering
          let lContas = []
          menuPrincipal lContas

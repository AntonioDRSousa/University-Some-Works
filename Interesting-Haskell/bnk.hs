data Conta = Conta { numConta :: Int
                   , senha :: Int
                   , nome :: String
                   , valor :: Double
                   } deriving Show
                   
atualizar lContas = map (\x -> x {valor=(valor x)*1.005}) lContas

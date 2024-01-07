-- propriedades em todas as classes
data Comum = Comum { nome :: String
                   , nivel :: Int
                   , experiencia :: Int -- experiencia
                   , dinheiro :: Int -- dinheiro
                   , saude :: Int -- pontos de saude
                   , maxSaude :: Int -- numero maximo de pontos de saude
                   , vel :: Int -- pontos de velocidade do personagem
                   , ataque :: Int -- pontos de ataque do personagem
                   , defesa :: Int -- pontos de defesa do personagem
                   } deriving Show

data Avatar = Guerreiro { padrao   :: Comum 
                        , armadura :: Int -- nivel de armadura
                        , nEspada  :: Int -- nivel da espada
                        , nArco    :: Int -- nivel do arco
                        , nEscudo  :: Int -- nivel de escudo
                        } 
              | 
              Mago { padrao :: Comum
                   , mana :: Int -- pontos de mana
                   , maxMana :: Int -- numero maximo dos pontos de mana
                   , poder :: Int
                   , conhecimento :: Int
                   }
             | 
             Sacerdote { padrao :: Comum
                       , reza :: Int 
                       , maxReza :: Int
                       , cura :: Int
                       , protecao :: Int
                       } 
            deriving Show

                     
                                     
                     

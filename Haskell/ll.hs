v1 = [1,23,4]
v2 = [1,2,3,4,5]
v3 = [7,3,1,9,10]
v4 = [0,1]
v5 = [(-2), (-5), 45, 12,7]
v6 = [2, 3, 5, 7, 11]
v7 = [0,0,0,0,1]
v8 = [0,7,0,12,(-34)]
v9 = [0,1,0]
v10 = [1,4,9,16,25,36,49,64,81,100]

v::[[Double]]
v = [v1,v2,v3,v4,v5,v6,v7,v8,v9,v10]

-- obtem o vetor unitario de cada vetor
tornarUnitarios::[[Double]]
tornarUnitarios =  map (\ x -> (map (\ y -> y/(m x)) x) ) v

-- calcula o modulo de cada vetor
modulo::[Double]
modulo = map m v

-- modulo de um vetor
m::[Double]->Double
m w = sqrt (foldr (sumQ) 0 w)
      where
          sumQ x y = (x**2)+y

-- obtem todos os vetores que sao unitarios
verificarUnitarios::[[Double]]
verificarUnitarios = filter (\ x -> (m x)==1) v


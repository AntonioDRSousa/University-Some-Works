module Main(main)where
import System.IO(stdout,hSetBuffering,BufferMode(NoBuffering))

-- para extrair os valores de tuplas com 4 elementos
e1::(a,b,c,d)->a
e1 (e,_,_,_) = e

e2::(a,b,c,d)->b
e2 (_,e,_,_) = e

e3::(a,b,c,d)->c
e3 (_,_,e,_) = e

e4::(a,b,c,d)->d
e4 (_,_,_,e) = e

-- para extrair os valores de tuplas com 3 elementos
v1::(a,b,c)->a
v1 (e,_,_) = e

v2::(a,b,c)->b
v2 (_,e,_) = e

v3::(a,b,c)->c
v3 (_,_,e) = e

--constante de coulomb
k=8.988*(10**9)

-- barions com velocidade inicializada no (0,0,0)
proton = ("proton","uud",938.3,(1.0/2.0))
neutron = ("neutron","ddu",939.6,(1.0/2.0))
lambdaZero = ("lambda 0","uds",1115.6,(1.0/2.0))
sigmaMais = ("sigma +","uus",1189.4,(1.0/2.0))
sigmaZero=("sigma 0","uds",1192.5,(1.0/2.0))
sigmaMenos=("sigma -","dds",1197.3,(1.0/2.0))
deltaMaisMais=("delta ++","uuu",1232,(3.0/2.0))
deltaMais=("delta +","uud",1232,(3.0/2.0))
deltaZero=("delta 0","udd",1232,(3.0/2.0))
deltaMenos=("delta -","ddd",1232,(3.0/2.0))
xiZero=("xi 0","uss",1315,(1.0/2.0))
xiMenos=("xi -","dss",1321,(1.0/2.0))
omega=("omega","sss",1672,(3.0/2.0))
lambdaCharmed=("lambda charmed","udc",2281,(1.0/2.0))

-- lista das particulas
--(nome, (tipo ,quarks , massa, spin), velocidade , (x,y,z) )
particulas::[([Char],([Char],[Char],Double,Double),(Double,Double,Double),(Double,Double,Double))]
particulas= [("p1",sigmaMais,(0,0,0),(0,0,0)),("p2",deltaZero,(0,0,0),(10,0,0)),("p3",deltaMaisMais,(0,0,0),(0,10,0)),("p4",omega,(0,0,0),(7,7,7)),("p5",omega,(0,0,0),(0,0,10)),("p6",proton,(0,0,0),(10,10,0)),("p7",lambdaZero,(0,0,0),(10,0,10)),("p8",deltaMais,(0,0,0),(0,10,10)),("p9",xiMenos,(0,0,0),(10,10,10)),("p10",sigmaMais,(0,0,0),(20,20,20)),("p11",lambdaZero,(0,0,0),(30,30,30)),("p12",lambdaCharmed,(0,0,0),(40,40,40)),("p13",neutron,(0,0,0),(50,50,50)),("p14",proton,(0,0,0),(20,10,20)),("p15",sigmaMenos,(0,0,0),(30,10,20)),("p16",deltaMaisMais,(0,0,0),(100,100,100)),("p17",sigmaMenos,(0,0,0),(10,100,50)),("p18",sigmaZero,(0,0,0),(25,0,25)),("p19",xiZero,(0,0,0),(75,50,25)),("p20",neutron,(0,0,0),(15,20,30))]

--obtem o valor da carga de uma particula a partir dos quarks
carga [] = 0
carga q = if (((head q)=='u')||((head q)=='c')||((head q)=='t')) then (2.0/3.0)+(carga (tail q)) else (-1.0/3.0)+(carga (tail q))

sinal x = if x>0 then "+"++(show x) else (show x)

--imprime na tela uma lista de particulas
impr::[([Char],([Char],[Char],Double,Double),(Double,Double,Double),(Double,Double,Double))]->Double->IO ()
impr part t = do let p = (head part)
                 putStrLn "==========================="
                 putStrLn (e1 p)
                 putStrLn (e1 (e2 p))
                 putStr "quarks -> "
                 putStrLn (e2 (e2 p))
                 putStr "massa -> "
                 print (e3 (e2 p))
                 putStr "spin -> "
                 print (e4 (e2 p))
                 putStr "carga -> "
                 putStrLn (sinal (carga (e2 (e2 p))))
                 putStr "velocidade -> "
                 print (e3 p)
                 putStr "posicao -> "
                 print (e4 p)
                 if ((tail part)/=[]) then do
                     impr (tail part) t
                 else do
                     putStrLn "==========================="

--movimenta particulas
calc prt b t = map mv prt
            where
                mv p = ((e1 p),(e2 p),(nVel p),(nPos p))

                --nova posicao
                nPos p = ((posx p),(posy p),(posz p))
                         where
                             posx p = (v1 (e4 p))+(v1 (e3 p))*t+(v1 (a p))*(0.5)*(t**2)
                             posy p = (v2 (e4 p))+(v2 (e3 p))*t+(v2 (a p))*(0.5)*(t**2)
                             posz p = (v3 (e4 p))+(v3 (e3 p))*t+(v3 (a p))*(0.5)*(t**2)

                --nova velocidade            
                nVel::([Char],([Char],[Char],Double,Double),(Double,Double,Double),(Double,Double,Double))->(Double,Double,Double)
                nVel p = ((velx p),(vely p),(velz p))
                         where
                             velx::([Char],([Char],[Char],Double,Double),(Double,Double,Double),(Double,Double,Double))->Double
                             velx p = (v1 (e3 p))+(v1 (a p))*t

                             vely::([Char],([Char],[Char],Double,Double),(Double,Double,Double),(Double,Double,Double))->Double
                             vely p = (v2 (e3 p))+(v2 (a p))*t

                             velz::([Char],([Char],[Char],Double,Double),(Double,Double,Double),(Double,Double,Double))->Double
                             velz p = (v3 (e3 p))+(v3 (a p))*t

                --aceleracao            
                a::([Char],([Char],[Char],Double,Double),(Double,Double,Double),(Double,Double,Double))->(Double,Double,Double)           
                a p = ((v1 (forca p))/(e3 (e2 p)),(v2 (forca p))/(e3 (e2 p)),(v3 (forca p))/(e3 (e2 p)))

                --forca
                forca p = ((fx p), (fy p) , (fz p))
                          where
                              fx p = (v1 (forcaE p))+(v1 (prod (e3 p) b))
                              fy p = (v2 (forcaE p))+(v2 (prod (e3 p) b))
                              fz p = (v3 (forcaE p))+(v3 (prod (e3 p) b))

                --forca produzida pelo campo eletrico
                forcaE p = (fex,fey,fez) 
                           where
                               fex = (carga (e2 (e2 p)))*(v1 (campoE p))  
                               fey = (carga (e2 (e2 p)))*(v2 (campoE p))  
                               fez = (carga (e2 (e2 p)))*(v3 (campoE p))  

                --campo eletrico                         
                campoE p = (foldr (ce) (0,0,0) (outras p))
                          where
                              ce p' s = ( (cex p p')+(v1 s)  , (cey p p')+(v2 s)  , (cez p p')+(v3 s) )
                              cex p p' = (const p p')*(v1 (desl p p'))
                              cey p p' = (const p p')*(v2 (desl p p'))
                              cez p p' = (const p p')*(v3 (desl p p'))
                              const p p' =  k*(carga (e2 (e2 p')))/((modr (desl p p'))**3)

                --produto vetorial              
                prod v b = ( (v2 v)*(v3 b)-(v3 v)*(v2 b) , (v1 v)*(v3 b)-(v3 v)*(v1 b) , (v1 v)*(v2 b)-(v2 v)*(v1 b))

                --modulo
                modr r = sqrt (((v1 r)**2)+((v2 r)**2)+((v3 r)**2))

                --vetor deslocamento
                desl::([Char],([Char],[Char],Double,Double),(Double,Double,Double),(Double,Double,Double))->([Char],([Char],[Char],Double,Double),(Double,Double,Double),(Double,Double,Double))->(Double,Double,Double)
                desl p1 p2 = ((v1 (e4 p2))-(v1 (e4 p1)),(v2 (e4 p2))-(v2 (e4 p1)),(v3 (e4 p2))-(v3 (e4 p1)))

                --obtem todas as particulas sem ser "p"
                outras p = (filter (\ x -> (e1 x)/=(e1 p)) prt)

-- movimenta a cada 0.001 do tempo t
alterar::[([Char],([Char],[Char],Double,Double),(Double,Double,Double),(Double,Double,Double))]->(Double,Double,Double)->Int->Double->[([Char],([Char],[Char],Double,Double),(Double,Double,Double),(Double,Double,Double))]
alterar prt b n t = if n==1 then (calc prt b t) else (alterar (calc prt b t) b (n-1) t)

-- menu principal
input prt t = do hSetBuffering stdout NoBuffering
                 putStrLn "\n\n---------------------------------------"
                 putStrLn "Digite a opcao"
                 putStrLn "1 - Reiniciar"
                 putStrLn "2 - Imprimir particulas"
                 putStrLn "3 - Listar particulas de carga positiva"
                 putStrLn "4 - Listar particulas de carga neutra"
                 putStrLn "5 - Listar particulas de carga negativa"
                 putStrLn "6 - Incrementar Tempo(par movimentar as particulas)"
                 putStrLn "7 - Sair"
                 putStrLn "---------------------------------------"
                 op<-readLn::IO Int
                 if op==1 then do
                     input particulas 0
                 else if op==2 then do
                     putStrLn "..........................."
                     putStr "Particulas em t = "
                     print (t)
                     putStrLn "..........................."
                     impr prt t
                     input prt t
                 else if op==3 then do
                     impr (filter (\ x -> (carga (e2 (e2 x)))>0) prt) t
                     input prt t
                 else if op==4 then do
                     impr (filter (\ x -> (carga (e2 (e2 x)))==0) prt) t
                     input prt t
                 else if op==5 then do
                     impr (filter (\ x -> (carga (e2 (e2 x)))<0) prt) t
                     input prt t
                 else if op==6 then do
                     putStrLn "\nDigite o campo magnetico: "
                     putStr "Bx = "
                     bx<-readLn::IO Double
                     putStr "By = "
                     by<-readLn::IO Double
                     putStr "Bz = "
                     bz<-readLn::IO Double
                     let b = (bx,by,bz)
                     putStr "Digite a quantidade de segundos a avancar (maior ou igual a 0.001): "
                     t'<-readLn::IO Double
                     if t'>=0.001 then do
                         input (alterar prt b (round (t'/0.001)) t') (t+t')
                     else
                         input prt t
                 else if op==7 then do
                     putStrLn "Sair"
                 else do
                     input prt t

main = do input particulas 0
             

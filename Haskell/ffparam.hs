-- o uso do nome "filter" entrou em conflito com o filter do prelude, sendo necessario adotar o "ffilter"
ffilter :: (a -> Bool) -> [a] -> [a]
ffilter f [] = []
ffilter f v = if (f (head v)) then
                 (head v):(ffilter f (tail v))
             else
                 ffilter f (tail v)


f x = ( (mod x 2) == 0 )

-----------------------------------------------

fold :: (a -> b -> b) -> b -> [a] -> b
fold f i [] = i
fold f i v  = f (head v) (fold f i (tail v))

s::Int->Int->Int
s x y = x + y





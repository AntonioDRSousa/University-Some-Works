potDois'::Integer->Integer
potDois' n
    |n==0=1
    |otherwise=2*(potDois' (n-1))

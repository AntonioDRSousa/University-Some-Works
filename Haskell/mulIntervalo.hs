mulIntervalo::Integer->Integer->Integer
mulIntervalo m n
    | m==n = 1
    | m>n  = m*mulIntervalo (m-1) n

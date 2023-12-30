fatorialDuplo::Integer->Integer
fatorialDuplo n
    | (n==0)||(n==1) = 1
    | n>1 = n * fatorialDuplo (n-2)

fibonacci n = fibonacci' n 0 1
    where
        fibonacci' n a b
            | n==0 = a
            | n==1 = b
            | n>=2 = fibonacci' (n-1) b (a+b)

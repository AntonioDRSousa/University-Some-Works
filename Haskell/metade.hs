metade::[a]->([a],[a])
metade lista = (take meio lista,reverse (take (meio+resto) (reverse lista)))
    where
        meio = div (length lista) 2
        resto = mod (length lista) 2

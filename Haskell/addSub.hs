add::Integer->Integer->Integer
add a b
    | b==0 = a
    | otherwise = succ (add a (pred b))

sub::Integer->Integer->Integer
sub a b
    | b==0 = a
    | otherwise = pred (sub a (pred b))

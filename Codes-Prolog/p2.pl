le_n(X):-
nl,
write('n = '),
read(X).

fib(0, 0).
fib(1, 1).
fib(X, Y):-
X>1, X1 is X-1, X2 is X-2, fib(X1,Y1), fib(X2,Y2), Y is Y1+Y2.

fibonacci :-
le_n(N),nl,nl,
fib(N,F),
write(F).
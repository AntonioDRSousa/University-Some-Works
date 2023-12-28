pertence(X,[P|R]):-
    X=P;
    pertence(X,R).

uniao([],[],[]).
uniao(L1,[],L1).

uniao(L1, [Cabeca2|Cauda2], [Cabeca2|L3]):-
    not(pertence(Cabeca2,L1)), 
    uniao(L1,Cauda2,L3).

uniao(L1, [Cabeca2|Cauda2], L3):-
    pertence(Cabeca2,L1), 
    uniao(L1,Cauda2,L3).  

listas(L1,L2):-
write('L1 = '),write(L1),nl,write('L2 = '),write(L2),nl,
uniao(L1,L2,L3),nl,write('Uniao de L1 com L2 = '),write(L3).
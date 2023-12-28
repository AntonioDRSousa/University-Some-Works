le_n(X,S):-
nl,
write(S),nl,
read(X).

maior(R,X,Y,Z) :-
X>=Y, X>=Z -> R = X;
Y>=X, Y>=Z -> R = Y;
Z>=X, Z>=Y -> R = Z.

media(R,X,Y,Z) :-
R is ((X+Y+Z)/3).

le_3_numeros :-
le_n(N1,'n1 = '),
le_n(N2,'n2 = '),
le_n(N3,'n3 = '),
maior(M,N1,N2,N3),
media(MEDIA,N1,N2,N3),
nl,nl,nl,
write('maior numero = '),
write(M),
nl,
write('media = '),
write(MEDIA).
parent(richard, sam).
parent(richard, catherine).
parent(richard, charles).
parent(mary, sam).
parent(mary, catherine).
parent(mary, charles).
parent(james, richard).
parent(georgia, richard).
parent(james, elizabeth).
parent(georgia, elizabeth).
parent(elizabeth, sophia).
parent(elizabeth, bob).
parent(john, sophia).
parent(john, bob).
male(john).
male(james).
male(richard).
male(bob).
male(sam).
male(charles).
female(catherine).
female(mary).
female(georgia).
female(sophia).
female(elizabeth).

mother(X , Y):-
    female(X),
    parent(X,Y).
father(X , Y):-
    male(X),
    parent(X,Y).
brother(X, Y):-
    male(X),
    not(X=Y),
    parent(Z, X),
    parent(Z, Y).
sister(X, Y):-
    female(X),
    not(X=Y),
    parent(Z, X),
    parent(Z, Y).
grandfather(X, Y):-
    father(X, Z),
    parent(Z, Y).

grandmother(X, Y):-
    mother(X, Z),
    parent(Z, Y).
haschild(X):-
    parent(X,_).








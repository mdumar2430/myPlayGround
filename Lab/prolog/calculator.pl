add(X,Y):-
    RES is X+Y,
    write(RES).
sub(X,Y):-
    RES is X-Y,
    write(RES).
mul(X,Y):-
    RES is X*Y,
    write(RES).
divide(X,Y):-
    RES is X//Y,
    write(RES).
exp(X,Y):-
    RES is X**Y,
    write(RES).
mod(X,Y):-
    RES is X mod Y,
    write(RES).
neg(X):-
    RES is -X , write(RES).

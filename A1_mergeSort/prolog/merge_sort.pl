% Run the program with ?- merge_sort.
% Parameters are hard-coded

% msort( L, S )
% True if S is a sorted copy of L, using merge sort
msort([], []).
msort([X], [X]).
msort(U, S) :- split(U, L, R), msort(L, SL), msort(R, SR), merge(SL, SR, S).

% split( LIST, L, R )
% Alternate elements of LIST in L and R
split([], [], []).
split([X], [X], []).
split([L, R | T], [L | LT], [R | RT]) :- split(T, LT, RT).

% merge( LS, RS, M )
% Assuming LS and RS are sorted, True if M is the sorted merge of the two
merge([], RS, RS).
merge(LS, [], LS).
merge([L | LS], [R | RS], [L | T]) :- L =< R, merge(LS, [R | RS], T).
merge([L | LS], [R | RS], [R | T]) :- L > R, merge([L | LS], RS, T).

% main predicate to hardcode data and print the original and sorted list
merge_sort :-
    Original = [170, 45, 75, -90, -802, 24, 2, 66],   % Hardcoded list
    writeln('Original List:'),
    writeln(Original),
    msort(Original, Sorted),
    writeln('Sorted List:'),
    writeln(Sorted).

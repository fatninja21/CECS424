% "star_tricked.pl"
% wilfredo Mendivil
% Assignment 5
% CECS 424
% Logic Puzzle
% Each person spots a UFO.

weirdo('Ms.Barrada').     % fact Quoted atom 'Ms.Barrada' for formatting    
weirdo('Ms.Gort').        % fact Quoted atom 'Ms.Gort' for formatting
weirdo('Mr.Klatu').       % fact Quoted atom 'Mr.Klatu' for formatting
weirdo('Mr.Nikto').       % fact Quoted atom 'Mr.Nikto' for formatting

coverup(balloon).        % fact atom watertower is a coverup
coverup(clothesline).    % fact atom clothesline is a coverup
coverup(frisbee).        % fact atom frisbee is a coverup
coverup(watertower).     % fact atom watertower is a coverup

% Solve the puzzle.
solve :-

    %    ":-" read as "if"
    %    ","  read as "and"
	%    ";"  read as "or"
	   
	% possible weirdo per day
    weirdo(TuesdayWeirdo), weirdo(WednesdayWeirdo), weirdo(Thursday_weirdo), weirdo(Friday_Weirdo),
    % make sure there is no cover up of weirdos
    all_different([TuesdayWeirdo, WednesdayWeirdo, Thursday_weirdo, Friday_Weirdo]),
	
    %possible coverups per day
    coverup(TuesdayCoverup), coverup(WednesdayCoverup),
    coverup(ThursdayCoverup), coverup(FridayCoverup),
    % make sure there is no duplicate of coverups
    all_different([TuesdayCoverup, WednesdayCoverup, ThursdayCoverup, FridayCoverup]),
	
    % list of possabilities for weirdos and coverups for tuesday- thursday
    Triples = [ [TuesdayWeirdo, TuesdayCoverup, 'Tuesday'],
                [WednesdayWeirdo, WednesdayCoverup, 'Wednesday'],
                [Thursday_weirdo, ThursdayCoverup, 'Thursday'],
                [Friday_Weirdo, FridayCoverup,'Friday'] ],


% 1. Mr.Katu made his sighting at some point earlier in the week than anyone who saw the ballon,
	% but at some point later in the week than the one who spotted the Frisbee(who isn't Ms. Gort).
	\+ member([ 'Mr.Klatu' , balloon, _],Triples),             % Mr.Klatu did not see the balloon and
	\+ member([ 'Mr.Klatu' , frisbee, _], Triples),            % Mr.Klatu did not see the frisbee and
	\+ member([ 'Ms.Gort', frisbee , _], Triples),	           % Mr.Klatu did not see the frisbee and
    earlier(['Mr.Klatu', _, _], [_, balloon, _], Triples),     % Mr Klatu is earlier in Trples than balloon and 
    earlier([_, frisbee, _], ['Mr.Klatu', _, _], Triples),     % The frisbee is earlier in Triples than Mr.Klatu and

	% 2. Friday's sighting was made by either Ms. Barrada or the one who saw a clothesline(or both).
    (member(['Ms.Barrada', _, 'Friday'], Triples);            % Ms.Barrada saw her sighting on friday or
	member([_, clothesline, 'Friday'], Triples) ;             % The clothesline was seen on Friday or
    member(['Ms.Barrada', clothesline, 'Friday'], Triples)),  % Ms.Barrada saw the clothesline on Friday
	
	% 3. Mr. Nikto did not make his sihgting on Tuesday.
	\+ member( ['Mr.Nikto', _ , 'Tuesday' ], Triples),        % Mr. Nikto's sighting was not on Tusday and
	
	% 4. Mr. Klatu isn't the one whose object trurned out to be a water tower.
	\+ member([ 'Mr.Klatu' , watertower , _ ], Triples),      % Mr.Klatu did not see the watertower and
    
    tell(TuesdayWeirdo, TuesdayCoverup, 'Tuesday'),          % Pass line to write who saw the object on Tuesday
    tell(WednesdayWeirdo, WednesdayCoverup, 'Wednesday'),    % Pass line to write who saw the object on Wednesday
    tell(Thursday_weirdo, ThursdayCoverup, 'Thursday'),      % Pass line to write who saw the object on Thursday
    tell(Friday_Weirdo, FridayCoverup,'Friday').			 % Pass line to write who saw the object on Friday

% Succeed if all elements of the argument list are bound and different.
% Fail if any elements are unbound or equal to some other element.A
all_different([H | T]) :- member(H, T), !, fail.        % (1)
all_different([_ | T]) :- all_different(T).             % (2)
all_different([_]).                                     % (3)

% succeed if first element passed comes before second element in the list
% check if first element passed is the head of Triples
% if it is not it checks if second list passed is the head of triples. if that case is true then it removes that Triples 
% recursive call if neither A or B are the head of the list
earlier(A,_,[A | _]).        
earlier(_, B, [B | _]) :- !, fail.         
earlier(A,B,[ _ | T])  :- earlier(A,B,T). 
	
	
% Write out an English sentence with the solution.
tell(X, Y, Z) :-
    write(X), write(' saw the "'), write(Y), write('"'),      % print formatted line with name and object passed as X and Y
    write(' on '), write(Z), write('.'), nl.                  % print formatted line with Date passed as Z
	

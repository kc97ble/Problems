unit graderhelplib;

{ Alice's module playing the evil strategy }

interface

function get_n : longint;
{ initialize the game,
 returns n - the upper bound on the number
 that Alice has in mind }

function is_divisible_by(m : longint) : boolean;
{ question whether m divides Alice's number }
{ input: m > 0 }

procedure guess(k : longint);
{ attempts to guess Alice's number;
 should be called only once }

implementation

const
   MAXN		      = 1000000;
var
   l1, l2, n			     : longint;
   questions_number, questions_limit : longint;
   possible			     : array[1..MAXN] of boolean;

procedure endgame(result : boolean);
var f: text;
begin
   writeln;
   assign(f, '');
   rewrite(f);
   if result then
      writeln(f, 'OK')
   else
      writeln(f, 'WRONG');
   close(f);
   halt;
end;

function get_n: longint;
var i: longint; f: text;
begin
   if n <> 0 then 
      get_n := n
   else
   begin
      assign(f, '');
      reset(f);
      read(f, n, l1, l2, questions_limit);
      close(f);
      questions_number := 0;
      for i := l1 to l2 do
	 possible[i] := true;
      get_n := n;
   end;
   writeln('get_n() = ', get_n);
end;

function is_divisible_by(m : longint) : boolean;
var
   i : longint;
begin
   write('is_divisible_by(', m, ') ');
   if n = 0 then begin
      write('ERROR: Function `is_divisible_by'' was called before function `get_n''');
      endgame(false);
   end;
   if m <= 0 then begin
      write('ERROR: Function `is_divisible_by'' was called with negative m');
      endgame(false);
   end;
   if m > n then begin
      write('ERROR: Function `is_divisible_by'' was called with m > n');
      endgame(false);
   end;
   inc(questions_number);
   if (questions_number > questions_limit) then begin
      for i:=l1 to l2 do
	 if possible[i] then
	    break;
      l1 := i; l2 := i;
   end;
   { we try to answer NO if only it is possible }
   if m > 1 then begin
      is_divisible_by := true;
      for i := l1 to l2 do
	 if possible[i] and (i mod m <> 0) then begin
	    is_divisible_by := false;
	    break;
	 end;
      if not is_divisible_by then begin
	 i := l2 - l2 mod m;
	 while i >= l1 do begin
	    possible[i] := false;
	    dec(i, m);
	 end;
      end else begin { ans = 1 }
	 for i := l1 to l2 do
	    if i mod m <> 0 then
	       possible[i] := false;
      end;
   end;
   writeln('= ', is_divisible_by);
end;

procedure guess(k : longint);
var
   alice_k : longint;
   i	   : longint;
begin
   write('guess(', k, ')');

   if n = 0 then begin
      write(' ERROR: Procedure `guess'' was called before function `get_n''');
      endgame(false);
   end;

   alice_k := k;
   for i := l1 to l2 do
      if possible[i] and (i <> k) then begin
	 alice_k := i;
	 break;
      end;

   writeln;
   writeln('Alice''s secret number is ', alice_k);
   
   if questions_number > questions_limit then begin
      write('FAIL: Program asked ', questions_number,
	    ' questions - Questions limit ', questions_limit, ' was exceeded');
      endgame(false);
   end;

   if alice_k <> k then begin
      write('FAIL: Alice''s secret number is missed after asking ',
	    questions_number, ' questions');
      endgame(false);
   end;

   write('SUCCESS: Alice''s secret number guessed successively after asking ',
	    questions_number, ' questions');
   endgame(true);
end;

end.
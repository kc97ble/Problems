unit cmpdata;

interface

var boiAccesses     :integer;
var boiMem          :array [0..4095,0..10247] of Boolean;
var boiPhase        :integer;
var boiOrder        :array [0..16777215] of longint;
var boi_guessval    :integer;
var boi_cmpval      :integer;
var boi_storeval    :integer;

procedure bit_set(addr:integer); 
function bit_get(addr:integer):integer; 

implementation

procedure bit_set(addr:integer);
begin
	if boiPhase = 2 then begin
		writeln(stderr, 'ZERO POINTS: bit_set called by compare()');
		halt(1);
	end;

	if (addr > 10240) or (addr < 1) then begin
		writeln(stderr, 'ZERO POINTS: bit_set with addr out of range ', addr);
		halt(1);
	end;
	
	boiMem[boi_storeval,addr] := True;
	inc(boiAccesses);
	if boiAccesses > 20 then begin
		writeln('-1');
		writeln(stderr, 'ERROR: bit_set called more than 20 times');
		halt(1);
	end;

end;

function bit_get(addr:integer):integer; 
begin
	if boiPhase=3 then begin
    {write(stderr, 'M[', addr,']  ');}
	end;
	if boiPhase=1 then begin
		writeln(stderr, 'ZERO POINTS: bit_get called by remember()');
		halt(1);
	end;
	if (addr > 10240) or (addr < 1) then begin
		writeln(stderr, 'ZERO POINTS: bit_get with address out of range');
		halt(1);
	end;
	if boiMem[boi_guessval,addr] then
		bit_get:=1
	else
		bit_get:=0;
	inc(boiAccesses);
end;

end.

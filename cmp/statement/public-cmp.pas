uses cmpdata, cmp;

var maxa,maxb,x,y,i:longint;

begin
	maxa:=0;
	maxb:=0;
  
	boiPhase:=1;
  {Writeln(stderr, 'Phase 1: remember() calls');}

	for boi_storeval:=0 to 4095 do begin
    {Writeln(stderr, '[a=', boi_storeval,']');}
		boiAccesses :=0;
		remember(boi_storeval);
		if boiAccesses>maxa then
			maxa := boiAccesses;
	end;
  {Writeln(stderr, 'END of remember() calls');}
  {writeln(stderr, ' beginning compare calls');}
	boiPhase:=3;
	for i:=0 to 16777215 do boiOrder[i]:=i;
	randseed:=2;
	for i:=1 to 16777215 do begin
		x:=random(i);
		y:=boiOrder[i];
		boiOrder[i]:=boiOrder[x];
		boiOrder[x]:=y;
	end;
	randseed:=2;
	for i:=0 to 16777215 do begin
		boi_guessval:=boiOrder[i] mod 4096;
		boi_cmpval:=boiOrder[i] div 4096;
    {write(stderr,'guess=',boi_guessval,' compare=',boi_cmpval,' ');}
		boiAccesses:=0;
		x:=compare(boi_cmpval);
		y:=0;
		if boi_cmpval>boi_guessval then
			y:=1;
		if boi_cmpval<boi_guessval then
			y:=-1;
		if x<>y then begin
			Writeln(stderr, 'ZERO POINTS:\n For a=',boi_guessval,' and b=',boi_cmpval,', corect answer is ',y,', got ',x);
			halt(1);
		end;
		if boiAccesses>maxb then begin
			maxb:=boiAccesses;
		end;
    {writeln(stderr);}
	end;
	boiPhase:=2;
	x:=maxa+maxb;
	if x>20 then
		Writeln(stderr, 'ZERO POINTS: more than 20 accesses in the worst case');
	Writeln(stderr, 'maxAccesses = ', x);
end.

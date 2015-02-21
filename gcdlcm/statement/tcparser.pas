{$mode objfpc}
{$H+}

uses sysutils, classes, lineinfo;

var
	List: TStringList;
	
function RemoveLeading(SubStr, S: String): String;
begin
	if LeftStr(S, Length(SubStr))=SubStr then
		Result := Copy(S, Length(SubStr)+1, MaxInt)
	else
		Result := S;
end;

function TryFindExact(ll, rr: Integer; S: String; out Index: Integer; 
	out P: String): Boolean;
begin
	Index := List.IndexOf(S);
	Result := Index <> -1;
	if Result then P := List[Index];
end;

function TryFindStart(ll, rr: Integer; S: String; out Index: Integer;
	out P: String): Boolean;
var
	i: Integer;
begin
	Index := -1;
	for i := ll to rr do
	if LeftStr(List[i], Length(S))=S then
	begin Index := i; break; end;
	Result := Index <> -1;
	if Result then P := List[Index];	
end;

procedure Heading1(S: String);
begin
	Writeln(S);
	Writeln(StringOfChar('=', Length(S)));
	Writeln;
end;

procedure Heading2(S: String);
begin
	Writeln(S);
	Writeln(StringOfChar('-', Length(S)));
	Writeln;
end;

procedure Normal(S: String);
begin
	Writeln(S);
	Writeln;
end;

procedure Paragraph(S: String);
var
	Current, Next: String;
	x: Integer = 1;
	
	function NextSentence: String;
	var
		i: Integer;
	begin
		for i := x to Length(S)-1 do
		if (S[i]='.') and (S[i+1]<=#32) then
		Exit(Copy(S, x, i+1-x+1));
		Result := Copy(S, x, MaxInt);
	end;

begin
	Current := '';
	while x<=Length(S) do
	begin
		Next := NextSentence;
		if (Length(Current)+Length(Next) <= 80) or (Current='') then
		begin
			Current += Next;
			x += Length(Next);
		end
		else begin
			Writeln(Trim(Current));
			Current := '';
		end
	end;
	if Trim(Current)<>'' then
	writeln(Trim(Current));
	writeln;
end;

procedure DoPrb(ll, rr: Integer);
var
	i: Integer;
begin
	for i := ll to rr do
	if Trim(List[i]) <> '' then
	Paragraph(List[i]);
end;

procedure DoDef(ll, rr: Integer);
var 
	i: Integer;
begin
	for i := ll to rr do
	if Trim(List[i]) <> '' then
	Writeln('- ', List[i]);
	Writeln;
end;

procedure DoCon(ll, rr: Integer);
var
	i: Integer;
begin
	for i := ll to rr do
	if Trim(List[i]) <> '' then
	Writeln('- ', Trim(RemoveLeading('-', List[i])));
	Writeln;
end;

procedure DoTst(ll, rr: Integer);
var
	x, i: Integer;
	x1: String;
begin
	if not TryFindStart(ll, rr, 'Returns:', x, x1) then exit;
	Normal('::');
	for i := ll+1 to x-1 do
	writeln('    ', List[i]);
	writeln;
	//writeln(ll:5, rr:5, x:5, rr-1:5);
	DoPrb(x, rr-1);
end;

function ifthen(B: Boolean; IfTrue, IfFalse: Integer): Integer;
begin
	if B then 
		Result := IfTrue
	else 
		Result := IfFalse;
end;

procedure DoExm(ll, rr: Integer);
var
	Index: array of Integer;
	i: Integer;
	Expect: String;
begin
	for i := ll to rr do
	begin
		Expect := IntToStr(Length(Index)) + ')';
		if LeftStr(List[i], Length(Expect)) = Expect then
		begin
			SetLength(Index, Length(Index)+1);
			Index[High(Index)] := i;
		end;
	end;
	for i := 0 to Length(Index)-1 do
	begin
		Heading2(IntToStr(i)+')');
		DoTst(Index[i]+1, ifthen(i<>Length(Index)-1, Index[i+1]-1, rr));
	end;
end;

procedure DoAll(ll, rr: Integer);
var
	x, y, z, t, u: Integer;
	x1, y1, z1, t1, u1: String;
begin
	if not TryFindExact(ll, rr, 'Problem Statement', x, x1) then exit;
	if not TryFindExact(ll, rr, 'Definition', y, y1) then exit;
	if not TryFindExact(ll, rr, 'Constraints', z, z1) then exit;
	if not TryFindExact(ll, rr, 'Examples', t, t1) then exit;
	if not TryFindExact(ll, rr, 'This problem was used for:', u, u1) then exit;
	
	Heading1(x1); // Problem Statement
	DoPrb(x+1, y-1);
	Heading1(y1); // Definition
	DoDef(y+1, z-1);
	Heading1(z1); // Constraints
	DoCon(z+1, t-1);
	Heading1(t1); // Examples
	DoExm(t+1, u-2);
	Paragraph(List[u-1]);
	Paragraph(u1);
	DoPrb(u+1, rr);
end;

var
	FileName: String;
begin
	if ParamCount>=1 then
		FileName := ParamStr(1)
	else 
		readln(FileName);
	
	if ParamCount>=2 then
	begin
		Assign(Output, ParamStr(2));
		Rewrite(Output);
	end;
	
	List := TStringList.Create;
	List.LoadFromFile(FileName);
	DoAll(0, List.Count-1);
	List.Free;
end.

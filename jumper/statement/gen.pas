{$mode objfpc}
{$coperators on}
{$H+}
uses sysutils, classes;

procedure Decode(S: String; var FI, FO: Text);
var
  i: Integer;
begin
  with TStringList.Create do
  try
    for i := 1 to Length(S) do
    if (S[i] in ['{','}']) then S[i] := ' ';
    CommaText := S;
    WriteLn(FI, Strings[0]);
    Writeln(FI, Count-2);
    for i := 1 to Count-2 do
    Writeln(FI, Strings[i]);
    Writeln(FO, Strings[Count-1]);
    finally Free;
  end;
end;

procedure Decode(S: String; SI, SO: String);
var FI, FO: Text;
begin
  WriteLn(StdErr, Format('Decoding %s -> %s, %s', [S, SI, SO]));
  Assign(FI, SI); Rewrite(FI);
  Assign(FO, SO); Rewrite(FO);
  Decode(S, FI, FO);
  Close(FI); Close(FO);
end;

var i: Integer;
begin
  with TStringList.Create do
  try
    LoadFromFile('jumper.data');
    for i := 0 to Count-1 do
    Decode(Strings[i], Format('%d.in',[i]), Format('%d.ans',[i]));
    finally Free;
  end;
end.

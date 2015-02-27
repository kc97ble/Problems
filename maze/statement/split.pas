{$mode objfpc}
{$H+}
uses sysutils, classes;

procedure Process(const S: String; var FInput, FOutput: Text);
begin
  with TStringList.Create do
  try
    CommaText := S;
    WriteLn(FOutput, Strings[Count-1]);
    Delete(Count-1);
    WriteLn(FInput, Count, ' ', Length(Strings[0]));
    WriteLn(FInput, Text);
    finally Free;
  end;
end;

procedure Process(const S, SI, SO: String);
var
  FI, FO: Text;
begin
  WriteLn('Process ', SI, ' ; ', SO);
  Assign(FI, SI); Rewrite(FI);
  Assign(FO, SO); Rewrite(FO);
  Process(S, FI, FO);
  Close(FI); Close(FO);
end;

var
  S: String;
  List: TStringList;
  i: Integer;
begin
  List := TStringList.Create;
  ReadLn(S);
  S := Trim(S);
  if S[1]='''' then S := Copy(S, 2, Length(S)-2);
  List.LoadFromFile(S);
  for i := 0 to List.Count-1 do
  Process(List[i],
    ExtractFilePath(S)+Format('maze.%d.in', [i]),
    ExtractFilePath(S)+Format('maze.%d.out', [i]));
  List.Free;
end.
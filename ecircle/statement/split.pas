{$mode objfpc}
{$coperators on}
{$H+}
uses sysutils, classes;
const
  IName = 'ecircle.in';
  OName = 'ecircle.out';
  IFmt = '%d.in';
  OFmt = '%d.ans';
var
  IFile, OFile: Text;

procedure WriteFile(var F: Text; S: String);
begin Assign(F, S); Rewrite(F); end;

procedure RWTestCase(var IFile, OFile: Text; UName, VName: String);
var
  UFile, VFile: Text;
  S: String;
  n, m: Integer;
begin
  WriteFile(UFile, UName);
  WriteFile(VFile, VName);
  try
    ReadLn(OFile, S); WriteLn(VFile, S);
    ReadLn(IFile, n, m); WriteLn(UFile, n, ' ', m);
    for n := 1 to n do
    begin
      ReadLn(IFile, S);
      WriteLn(UFile, S);
    end;
  finally
    Close(UFile);
    Close(VFile);
  end;
end;

var
  TestCount, i: Integer;
begin
  Assign(IFile, IName); Reset(IFile);
  Assign(OFile, OName); Reset(OFile);
  ReadLn(IFile, TestCount);
  for i := 0 to TestCount-1 do
  begin
    WriteLn('RW test ', i);
    RWTestCase(IFile, OFile, Format(IFmt, [i]), Format(OFmt, [i]));
    TestCount += 1;
  end;
end.

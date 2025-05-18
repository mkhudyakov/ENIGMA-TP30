type
  TReflector = array[0..25] of integer;

procedure InitReflector(var Ref: TReflector; refType: TString);
const
  RefB: string[26] = 'YRUHQSLDPXNGOKMIEBFZCWVJAT';
var
  i: integer;
begin
  for i := 0 to 25 do
    Ref[i] := Ord(RefB[i+1]) - 65;
end;

function Reflect(c: integer; Ref: TReflector): integer;
begin
  Reflect := Ref[c];
end;

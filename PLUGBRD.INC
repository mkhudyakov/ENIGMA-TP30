type
  TPlugboard = array[0..25] of integer;

procedure InitPlugboard(var PB: TPlugboard);
var i: integer;
begin
  for i := 0 to 25 do
    PB[i] := i;
end;

function Plug(c: integer; PB: TPlugboard): integer;
begin
  Plug := PB[c];
end;

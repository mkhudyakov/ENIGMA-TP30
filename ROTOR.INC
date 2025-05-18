type
  TRotor = record
    Name: string[5];
    Wiring: array[0..25] of integer;
    Inverse: array[0..25] of integer;
    Position, Notch, Ring: integer;
  end;

procedure InitRotor(var R: TRotor; rotorType: TString; Pos, Ring: integer);
const
  RotorWiring: array[1..3] of string[26] = (
    'EKMFLGDQVZNTOWYHXUSPAIBRCJ',
    'AJDKSIRUXBLHWTMCQGZNPYFVOE',
    'BDFHJLCPRTXVZNYEIWGAKMUSQO'
  );
  Notches: array[1..3] of integer = (16, 4, 21);  { Q, E, V }
var
  i, index: integer;
begin
  if rotorType = 'I' then index := 1
  else if rotorType = 'II' then index := 2
  else index := 3;

  R.Name := rotorType;
  R.Position := Pos;
  R.Ring := Ring;
  R.Notch := Notches[index];

  for i := 0 to 25 do begin
    R.Wiring[i] := Ord(RotorWiring[index][i+1]) - 65;
  end;
  for i := 0 to 25 do
    R.Inverse[R.Wiring[i]] := i;
end;

function RotorEncipher(var R: TRotor; c: integer; forward: boolean): integer;
var shift: integer;
begin
  shift := R.Position - R.Ring;
  if forward then
    RotorEncipher := (R.Wiring[(c + shift + 26) mod 26] - shift + 26) mod 26
  else
    RotorEncipher := (R.Inverse[(c + shift + 26) mod 26] - shift + 26) mod 26;
end;

procedure StepRotor(var R: TRotor);
begin
  R.Position := (R.Position + 1) mod 26;
end;

function AtNotch(R: TRotor): boolean;
begin
  AtNotch := R.Position = R.Notch;
end;

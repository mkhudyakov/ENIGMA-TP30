type
  EnigmaDevice = record
    Left, Middle, Right: TRotor;
    Reflector: TReflector;
    Plugboard: TPlugboard;
  end;

procedure InitDevice(var D: EnigmaDevice; R1, R2, R3, Ref: TString;
                     P1, P2, P3, Ring1, Ring2, Ring3: integer;
                     Plug: TString);
begin
  InitRotor(D.Left, R1, P1, Ring1);
  InitRotor(D.Middle, R2, P2, Ring2);
  InitRotor(D.Right, R3, P3, Ring3);
  InitReflector(D.Reflector, Ref);
  InitPlugboard(D.Plugboard);
end;

procedure StepRotors(var D: EnigmaDevice);
begin
  if AtNotch(D.Middle) then begin
    StepRotor(D.Middle);
    StepRotor(D.Left);
  end else if AtNotch(D.Right) then
    StepRotor(D.Middle);
  StepRotor(D.Right);
end;

function EncryptChar(var D: EnigmaDevice; ch: char): char;
var
  c: integer;
begin
  if (ch < 'A') or (ch > 'Z') then begin
    EncryptChar := ch;
    exit;
  end;

  StepRotors(D);

  c := Ord(ch) - 65;
  c := Plug(c, D.Plugboard);
  c := RotorEncipher(D.Right, c, true);
  c := RotorEncipher(D.Middle, c, true);
  c := RotorEncipher(D.Left, c, true);
  c := Reflect(c, D.Reflector);
  c := RotorEncipher(D.Left, c, false);
  c := RotorEncipher(D.Middle, c, false);
  c := RotorEncipher(D.Right, c, false);
  c := Plug(c, D.Plugboard);
  EncryptChar := Chr(c + 65);
end;

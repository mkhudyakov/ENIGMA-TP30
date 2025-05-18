program Enigma;

type
  TString = string[64];

{$I ROTOR.INC}
{$I REFLECT.INC}
{$I PLUGBRD.INC}
{$I DEVICE.INC}


var
  encoder, decoder: EnigmaDevice;
  msg1, msg1Encoded, msg2, msg3: TString;
  i: integer;
begin
  InitDevice(encoder, 'I', 'II', 'III', 'B', 0, 0, 0, 0, 0, 0, '');
  InitDevice(decoder, 'I', 'II', 'III', 'B', 0, 0, 0, 0, 0, 0, '');

  msg1 := 'HELLO';
  Write('Plain: ', msg1, ', Encrypted: ');
  for i := 1 to Length(msg1) do
    Write(EncryptChar(encoder, msg1[i]));
  WriteLn;
  WriteLn;

  msg1Encoded := 'ILBDA';
  Write('Encrypted: ', msg1Encoded, ', Decrypted: ');
  for i := 1 to Length(msg1Encoded) do
    Write(EncryptChar(decoder, msg1Encoded[i]));
  WriteLn;

  WriteLn;

  msg2 := 'HAUPTFUHRERISNOTRESPONDINGHEILHITLER';
  Write('Plain: ', msg2, ', Encrypted: ');
  for i := 1 to Length(msg2) do
    Write(EncryptChar(encoder, msg2[i]));
  WriteLn;
  WriteLn;

  msg3 := 'SOVIETSARECLOSETOOURBORDERHEILHITLER';
  Write('Plain: ', msg3, ', Encrypted: ');
  for i := 1 to Length(msg3) do
    Write(EncryptChar(encoder, msg3[i]));
  WriteLn;
  WriteLn;

  ReadLn;
end.

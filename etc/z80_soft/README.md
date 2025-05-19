## Simulator
```
git clone https://github.com/simh/simh
```

## Running CP/M
```
./altairz80 
set cpu z80
attach dsk0 cpm2.dsk
attach dsk1 tp30.dsk
boot dsk0

B:
DIR
```

## ASSEMBLER 8080
```
ED HELLO.ASM

# To switch to Insert mode
I

# Then type

        ORG 100H
        MVI C,9
        LXI D,MSG
        CALL 5
        RET
MSG:    DB 'HELLO$'
        END

# Exit Insert Mode
CTRL-Z

# Save
E

# Compile
ASM HELLO

# Converts HELLO.HEX to HELLO.COM
LOAD HELLO

# Run
HELLO
```

## ASSEMBLER Z80
```
M80 =HELLO.ASM/Z
L80 HELLO,HELLO/N/E
HELLO
```

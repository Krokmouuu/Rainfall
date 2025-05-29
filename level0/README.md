Comment trouver le flag0

on a un executable level0 quand on le lance il segfault, si on met 1 argument il repond "No !"

Comme pour SnowFall on va disassemble le code

gdb -q ./level0

disassemble main

Et maintenant on a des adresse, il y en a une avec "cmp" donc une comparaison de "%eax" avec "0x1a7" en decimal ce qui donne 423

comme les 3 regles de la cybersecurite

Qui suis-je ? / Ou suis-je ? / Que puis-je faire ? 

on va executer whoami

On est apparement level1 donc on a acces a son mdp

cat /home/user/level1/.pass

on a notre flag

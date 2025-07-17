Comment trouver le flag0

ls -l

on a un executable level0 quand on le lance il segfault, si on met 1 argument il repond "No !"

Comme pour SnowFall on va disassemble le code

gdb -q ./level0

disassemble main

Et maintenant on a des adresse, juste apres un atoi donc on peut imaginer que c'est la la fonction dans laquelle on va mettre le parametre, il y en a une avec "cmp" donc une comparaison de "%eax" avec "0x1a7" en decimal ce qui donne 423 (https://www.rapidtables.com/convert/number/hex-to-decimal.html?x=1A7)

On comprend que c'est ce parametre qui doit etre donne a l'executable :

./level0 423

comme les 3 regles de la cybersecurite

Qui suis-je ? / Ou suis-je ? / Que puis-je faire ? 

on va executer whoami

On est apparement level1 donc on a acces a son mdp

cat /home/user/level1/.pass

on a notre flag

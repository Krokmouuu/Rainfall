En decompilant le code on voit qu'il y a des comparaisons avec auth service et login et il faut que auth[32] soit different de 0 pour passer l'exercice

auth est alloue de 4 donc auth[4]
il y a donc un probleme car auth[32] n'est pas alloue donc la comparaison n'est pas vraiment possible
grace a service qui fait un strdup + 7 (et donc touche a la memoire du malloc) il faut depasser l'espace de 32 bytes

on force une nouvelle allocation juste après celle de auth. En plaçant une chaîne de 33 caractères

"auth "
"service" + autant de caracteres pour augmenter le padding pour qu'il soit superieur a 32
"login"
gg

cat /home/user/level9/.pass
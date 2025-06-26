On disas le main et on voit qu'il y a beaucoup de comparaison

ligne 93 on a une valeur qui se compare 

donc x/s + l'address : 0x8048819

x/s 0x8048819

on voit donc que la chaine compare est : "auth "

ensuite ligne 228 on a 0x804881f

x/s 0x804881f

on voit que c'est "reset"

ensuite ligne 282 on a 0x8048825

on voit que c'est "service"

ensuite ligne 343 on a 0x804882d

on voit que c'est "login"

ensuite ligne 418 on a "Password:\n"

On va donc tout faire dans l'ordre

On va s'identifier en demandant le service login, mettant le mot de passe, en redemandant le service login et passer au niveau 9.

"auth "
"service"
"login"
Password:\n
"service"
"login"

cat /home/user/level9/.pass
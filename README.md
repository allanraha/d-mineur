README Démineur, Allan Raha, Hicham Bettahar


pour compiler le programme il suffit d'écrire make dans le terminal grace au Makefile.
Ensuite, on écrit: ./exec pour l'exécuter.

On nous demande alos de choisir une difficulté: -0 pour la difficulté débutante (grille 9x9)
                                                -1 pour la difficulté intermédiaire (grille 16x16)
                                                
La grille s'affiche ensuite en fonction du paramètre que vous avez entrez avant.
2 options: 0 pour dévoiler une case 
           1 pour placer un marqueur
           
0):
Lorsque vous dévoilez une case, On vous demande les coordonnées de la case que vous voulez dévoiler (ligne puis colonne).le nombre de mines autour se dévoile dans la case, si le nombre de mine autour est de 0 alors toutes les cases autour sont révélés jusqu'à ce que les cases autours ait une ou plusieurs mines à coté.
S'il y a une mine sur la case que vous voulez dévoiler, alors vous perdez la partie.
Si vous découvrez toutes les cases qui ne contiennent pas de mines, alors vous gagnez la partie.
Que vous perdiez ou gagniez, une option rejouer s'offre à vous (0 pour quitter, 1 pour rejouer).


1): 
Lorsque vous voulez placer un marqueur de bombe, on vous demande alors les coordonnées de la case.
   Vous pouvez placer un marqueur sur une case non dévoilée.
   Si vous placez votre marqueur sur un autre marqueur deja existant, alors ce dernier se retire et la case redeviens non dévoilée(~).
   Si vous placez votre marqueur sur une case déja révelée alors un message vous disant que c'est inutile de faire ca apparaitra.

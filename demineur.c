#include "demineur.h"   //initialisation du fichier header

int main(){
  int cond_victoire = 0; //intitalisation de la condition de victoire à 0
  int compt=0;           //initialisation d'un compteur
  int tour;              //initialisation d'une variable qui prendra comme valeur le retour de la fonction choixtour
  int rejouer=1;         //initialisation variable rejouer 
  char jeu[30][30];      //initialisation du tableau de jeu qu'on affichera avec la fonction grille 
  char mine[30][30];     //initialisation du tableau des mines que l'on affichera en cas de défaite
  int i,j;               //initailisation i,j pour les boucles for
  int l,c,nbmines;       //initialisation l=ligne, c=colonne, nbmines=nombre de mines
  int cond_defaite=0;    //initialisation de la condition de défaite à 0
  
  srand(time(NULL));    //initialisation de la fonction rand

  while(rejouer==1){                         //boucle while pour savoir si l'utilisateur veut rejouer ou pas
    choixdifficulte(&l,&c,&nbmines);         //choix de la difficulté qui nous donne alors le nombre de lignes et de colonnes du tableau et le nombre de mines
    init(mine,jeu,l,c);                      //on initialise les tableaux en les remplissant
    placermine(mine,nbmines,l,c);            //on place les mines aléatoirement
    grille(jeu,l,c);                         //on affiche le tableau de jeu
    cond_victoire = (l*c)-nbmines;           //condition de victoire = nombres de cases du tableau - nombre de mines            
    time_t temps1 = time(NULL);              //pour le chronomètre
    time_t temps2;
    while(compt!=cond_victoire && cond_defaite==0){   //tant que l'on a pas gagné ni perdu, on reste dans la boucle
      compt=0;                                        //on met le compteur à 0
      tour=choixtour();                               //en fonction du choix du tour:
      if(tour==0){                                    //on révèle la case 
        jouer(mine,jeu,l,c,&cond_defaite);
      }                      
      if(tour==1){             
        placerdrapeau(jeu,l,c);                       //on place un drapeau
      }
      for(i=0;i<l;i++){
        for(j=0;j<c;j++){
          if(jeu[i][j]!='~' && jeu[i][j]!='X'){       //on compte le nombre de cases révelés pour savoir si le joueur a gagné
            compt=compt+1;                            //si le nombre de cases révélées = condition de victoire alors on sort de la boucle
          }                           
        }  
      }
    
    }
    if(compt==cond_victoire){                       // Si le joueur a gagné:
      printf("Bravo vous avez gagnez !\n");
      temps2 = time(NULL);
      printf("Votre temps de jeu: %lf secondes\n",difftime(temps2, temps1));    // On affiche le temps du joueur
    }
    do{
      printf("Voulez vous rejouer ?\n");         
      printf("0:Quitter    1:rejouer\n");
      scanf("%d",&rejouer);        
      int c=0; 
      int r=0;
      do{
        r = scanf("%c", &c);                  //boucle pour éviter les erreurs du scanf
      }while(r==1 && c!='\n');         
    }while(rejouer!=0 && rejouer!=1);         //boucle pour éviter les erreurs du scanf
    cond_defaite=0;                           //on réinitialise les variables si le joueur veut rejouer
    compt=0;
  	}
  return 0;
}

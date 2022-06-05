#include "demineur.h"


void init(char mine[30][30],char jeu[30][30],int l,int c){        //preocédure qui initialise le tableau de jeu et le tableau de mines
  int i,j;
  for(i=0;i<20;i++){
    for(j=0;j<20;j++){
      jeu[i][j]='~';
      mine[i][j]='0';
    }
  }
}

void grille(char jeu[30][30],int lig,int col){                    //procédure qui affiche la grille de jeu
  int i,j;
  printf("\n\n    ");
  for(i=0;i<col;i++){
    if(i<10){
    	printf("%d   ",i);
    }
    else{
      printf("%d  ",i);
    }
  }
  printf("\n\n");
    for(i=0;i<lig;i++){
      if(i<10){
        printf("%d  ",i);
      }
    else{
      printf("%d ",i);
    }
      
    for(j=0;j<col;j++){
      printf("|");
      if(jeu[i][j]=='0'){
        couleur("36");                          //couleur cyan
        printf("%c",jeu[i][j]);
        couleur("0");                           //on remet la couleur en blanc
        printf("| ");
      }
      else if(jeu[i][j]=='1'){
        couleur("34");                          //couleur bleu
        printf("%c",jeu[i][j]);
        couleur("0");                           //on remet la couleur en blanc
        printf("| ");
      }
      else if(jeu[i][j]=='2'){
        couleur("32");                          //couleur vert
        printf("%c",jeu[i][j]);
        couleur("0");                           //on remet la couleur en blanc
        printf("| ");
      }
      else if(jeu[i][j]=='3'){
        couleur("33");                          //couleur jaune
        printf("%c",jeu[i][j]);
        couleur("0");                           //on remet la couleur en blanc
        printf("| ");
      }
      else if(jeu[i][j]=='4'){
        couleur("31");                         //couleur rouge
        printf("%c",jeu[i][j]);
        couleur("0");                          //on remet la couleur en blanc
        printf("| ");
      }
      else if(jeu[i][j]=='5'){
        couleur("35");                         //couleur magenta
        printf("%c",jeu[i][j]);
        couleur("0");                          //on remet la couleur en blanc
        printf("| ");
      }
      else if(jeu[i][j]=='X'){
        couleur("45");                         //couleur de fond magenta
        printf("%c",jeu[i][j]);
        couleur("0");                          //on remet la couleur en blanc
        printf("| ");
      }
      else{
        printf("%c| ",jeu[i][j]);
      }
    }
  printf("\n\n");
  }
}

void placermine(char mine[30][30],int nbmines,int lig,int col){       //procédure pour placer les mines         
  int i,j;
  int k=0;
  int l=0;
  for(i=0;i<nbmines;i++){
    l=rand()%lig;
    k=rand()%col;
    if(mine[l][k]=='0'){        //s'il n'y a pas de mines à la case choisi par hasard, alors on place une mine
      mine[l][k]='M';
    }
    else{                       //s'il y a une mine, on refait un tour dans la boucle
      nbmines++;
    }
  }
}

	
void MineAutour(char mine[30][30],char jeu[30][30],int l,int c,int taille_l,int taille_c){    //procédure récursive qui affiche le nombre de case autour
  char N;
	if(c==0){
    N=0;
		if(l==0){                              //cas du coin en haut à gauche
      if(mine[l+1][c]=='M'){               //On compte le nombre de mines autour
				N=N+1;
			}
			if(mine[l+1][c+1]=='M'){
				N=N+1;
			}
			if(mine[l][c+1]=='M'){
				N=N+1;
			}
			jeu[l][c]=N+'0';
			if(jeu[l][c]=='0'){                             //s'il n'y a aucune mine autour:
				if(jeu[l+1][c]!='0' && jeu[l+1][c]!='X'){        //si les cases ne sont pas révelées ou ne sont pas un drapeau
				  MineAutour(mine,jeu,l+1,c,taille_l,taille_c);     //alors on réapplique la fonction aux mines autour (on réapplique le même procédé aux autres cas)
				}
				if(jeu[l+1][c+1]!='0' && jeu[l+1][c+1]!='X'){
				  MineAutour(mine,jeu,l+1,c+1,taille_l,taille_c);
				}
				if(jeu[l][c+1]!='0' && jeu[l][c+1]!='X'){
				  MineAutour(mine,jeu,l,c+1,taille_l,taille_c);
				}
			}
		}
		if(l==taille_l){                               //cas du coin en bas à gauche
      if(mine[l-1][c]=='M'){
				N=N+1;
			}
			if(mine[l-1][c+1]=='M'){
				N=N+1;
			}
			if(mine[l][c+1]=='M'){
				N=N+1;
			}
			jeu[l][c]=N+'0';
			if(mine[l-1][c]=='0' && mine[l-1][c+1]=='0' && mine[l][c+1]=='0'){         //si pas de mines autour:
				if(jeu[l-1][c]!='0' && jeu[l-1][c]!='X'){
				  MineAutour(mine,jeu,l-1,c,taille_l,taille_c);
				}
				if(jeu[l-1][c+1]!='0' && jeu[l-1][c+1]!='X'){
				  MineAutour(mine,jeu,l-1,c+1,taille_l,taille_c);
				}
				if(jeu[l][c+1]!='0' && jeu[l][c+1]!='X'){
				  MineAutour(mine,jeu,l,c+1,taille_l,taille_c);
				}
			}
		}
		else if(l>0 && l<taille_l){	                                   //cas des cases du coté gauche, hors les coins
      if(mine[l-1][c]=='M'){
				N=N+1;
			}
			if(mine[l-1][c+1]=='M'){
				N=N+1;
			}
			if(mine[l][c+1]=='M'){
				N=N+1;
			}
			if(mine[l+1][c+1]=='M'){
				N=N+1;
			}
			if(mine[l+1][c]=='M'){
				N=N+1;
			}
			jeu[l][c]=N+'0';
			if(mine[l-1][c]=='0' && mine[l-1][c+1]=='0' && mine[l][c+1]=='0' && mine[l+1][c+1]=='0' && mine[l+1][c]=='0'){
				if(jeu[l-1][c]!='0' && jeu[l-1][c]!='X'){
				  MineAutour(mine,jeu,l-1,c,taille_l,taille_c);
				}
				if(jeu[l-1][c+1]!='0' && jeu[l-1][c+1]!='X'){
				  MineAutour(mine,jeu,l-1,c+1,taille_l,taille_c);
				}
				if(jeu[l][c+1]!='0' && jeu[l][c+1]!='X'){
				  MineAutour(mine,jeu,l,c+1,taille_l,taille_c);
				}
				if(jeu[l+1][c+1]!='0' && jeu[l+1][c+1]!='X'){
				  MineAutour(mine,jeu,l+1,c+1,taille_l,taille_c);
				}
				if(jeu[l+1][c]!='0' && jeu[l+1][c]!='X'){
				  MineAutour(mine,jeu,l+1,c,taille_l,taille_c);
				}
			}
		}
			
	}else if(c==taille_c){
    N=0;
		if(l==0){                                       //cas du coin en haut à droite
      if(mine[l][c-1]=='M'){
				N=N+1;
			}
		  if(mine[l+1][c-1]=='M'){
				N=N+1;
			}
			if(mine[l+1][c]=='M'){
				N=N+1;
			}
			jeu[l][c]=N+'0';
			if(mine[l][c-1]=='0' && mine[l+1][c-1]=='0' && mine[l+1][c]=='0'){
				if(jeu[l][c-1]!='0' && jeu[l][c-1]!='X'){
				  MineAutour(mine,jeu,l,c-1,taille_l,taille_c);
				}
				if(jeu[l+1][c-1]!='0' && jeu[l+1][c-1]!='X'){
				  MineAutour(mine,jeu,l+1,c-1,taille_l,taille_c);
				}
				if(jeu[l+1][c]!='0' && jeu[l+1][c]!='X'){
				  MineAutour(mine,jeu,l+1,c,taille_l,taille_c);
				}
			}
		}
		if(l==taille_l){                                 //cas du coin en bas à droite 
      if(mine[l-1][c]=='M'){
				N=N+1;
			}
			if(mine[l-1][c-1]=='M'){
				N=N+1;
			}
			if(mine[l][c-1]=='M'){
				N=N+1;
			}
			jeu[l][c]=N+'0';
				if(mine[l-1][c]=='0' && mine[l-1][c-1]=='0' && mine[l][c-1]=='0'){
					if(jeu[l-1][c]!='0' && jeu[l-1][c]!='X'){
				    MineAutour(mine,jeu,l-1,c,taille_l,taille_c);
				  }
				  if(jeu[l-1][c-1]!='0' && jeu[l-1][c-1]!='X'){
				    MineAutour(mine,jeu,l-1,c-1,taille_l,taille_c);
				  }
				  if(jeu[l][c-1]!='0' && jeu[l][c-1]!='X'){
				    MineAutour(mine,jeu,l,c-1,taille_l,taille_c);
				  }
				}
		}
		else if(l>0 && l<taille_l){                          //cas du coté droit hors les coins
      if(mine[l-1][c]=='M'){
				N=N+1;
			}
			if(mine[l-1][c-1]=='M'){
				N=N+1;
			}
			if(mine[l][c-1]=='M'){
				N=N+1;
			}
			if(mine[l+1][c-1]=='M'){
				N=N+1;
			}
		  if(mine[l+1][c]=='M'){
				N=N+1;
			}
			jeu[l][c]=N+'0';
			if(mine[l-1][c]=='0' && mine[l-1][c-1]=='0' && mine[l][c-1]=='0' && mine[l+1][c-1]=='0' && mine[l+1][c]=='0'){
				if(jeu[l-1][c]!='0' && jeu[l-1][c]!='X'){
				  MineAutour(mine,jeu,l-1,c,taille_l,taille_c);
				}
				if(jeu[l-1][c-1]!='0' && jeu[l-1][c-1]!='X'){
				  MineAutour(mine,jeu,l-1,c-1,taille_l,taille_c);
				}
				if(jeu[l][c-1]!='0' && jeu[l][c-1]!='X'){
				  MineAutour(mine,jeu,l,c-1,taille_l,taille_c);
				}
				if(jeu[l+1][c-1]!='0' && jeu[l+1][c-1]!='X'){
				  MineAutour(mine,jeu,l+1,c-1,taille_l,taille_c);
				}
				if(jeu[l+1][c]!='0' && jeu[l+1][c]!='X'){
				  MineAutour(mine,jeu,l+1,c,taille_l,taille_c);
				}
			}
		}
	}else if(l==0 && c!=0 && c!=taille_c){                         //cas du coté du haut hors les coins
    N=0;
		if(mine[l][c-1]=='M'){
			N=N+1;
		}
		if(mine[l+1][c-1]=='M'){
			N=N+1;
		}
		if(mine[l+1][c]=='M'){
			N=N+1;
		}
		if(mine[l+1][c+1]=='M'){
			N=N+1;
		}
		if(mine[l][c+1]=='M'){
			N=N+1;
		}
		jeu[l][c]=N+'0';
		if(mine[l][c-1]=='0' && mine[l+1][c-1]=='0' && mine[l+1][c]=='0' && mine[l+1][c+1]=='0' && mine[l][c+1]=='0'){
			if(jeu[l][c-1]!='0' && jeu[l][c-1]!='X'){
				MineAutour(mine,jeu,l,c-1,taille_l,taille_c);
			}
			if(jeu[l+1][c-1]!='0' && jeu[l+1][c-1]!='X'){
				MineAutour(mine,jeu,l+1,c-1,taille_l,taille_c);
			}
			if(jeu[l+1][c]!='0' && jeu[l+1][c]!='X'){
				MineAutour(mine,jeu,l+1,c,taille_l,taille_c);
			}
			if(jeu[l+1][c+1]!='0' && jeu[l+1][c+1]!='X'){
				MineAutour(mine,jeu,l+1,c+1,taille_l,taille_c);
			}
			if(jeu[l][c+1]!='0' && jeu[l][c+1]!='X'){
				MineAutour(mine,jeu,l,c+1,taille_l,taille_c);
			}
		}
			
	}else if(l==taille_l && c!=0 && c!=taille_c){                       //cas du coté bas hors les coins
    N=0;
		if(mine[l][c-1]=='M'){
			N=N+1;
		}
		if(mine[l-1][c-1]=='M'){
			N=N+1;
		}
		if(mine[l-1][c]=='M'){
			N=N+1;
		}
		if(mine[l-1][c+1]=='M'){
		  N=N+1;
		}
	  if(mine[l][c+1]=='M'){
			N=N+1;
		}
		jeu[l][c]=N+'0';
		if(mine[l][c-1]=='0' && mine[l-1][c-1]=='0' && mine[l-1][c]=='0' && mine[l-1][c+1]=='0' && mine[l][c+1]=='0'){
			if(jeu[l][c-1]!='0' && jeu[l][c-1]!='X'){
				MineAutour(mine,jeu,l,c-1,taille_l,taille_c);
			}
			if(jeu[l-1][c-1]!='0' && jeu[l-1][c-1]!='X'){
				MineAutour(mine,jeu,l-1,c-1,taille_l,taille_c);
			}
			if(jeu[l-1][c]!='0' && jeu[l-1][c]!='X'){
				MineAutour(mine,jeu,l-1,c,taille_l,taille_c);
			}
			if(jeu[l-1][c+1]!='0' && jeu[l-1][c+1]!='X'){
				MineAutour(mine,jeu,l-1,c+1,taille_l,taille_c);
			}
			if(jeu[l][c+1]!='0' && jeu[l][c+1]!='X'){
				MineAutour(mine,jeu,l,c+1,taille_l,taille_c);
			}
		}
	}
	else{                                         //tous les autres cas (c'est à dire hors les coins et les cotés du tableaux)
    N=0;
		if(mine[l][c-1]=='M'){
			N=N+1;
		}
		if(mine[l-1][c-1]=='M'){
			N=N+1;
		}
		if(mine[l-1][c]=='M'){
		  N=N+1;
		}
		if(mine[l-1][c+1]=='M'){
			N=N+1;
		}			
		if(mine[l][c+1]=='M'){
			N=N+1;
		}
		if(mine[l+1][c-1]=='M'){
		N=N+1;
		}
		if(mine[l+1][c]=='M'){
		N=N+1;
		}
		if(mine[l+1][c+1]=='M'){
		N=N+1;
		}
		jeu[l][c]=N+'0';
		if(mine[l][c-1]=='0' && mine[l-1][c-1]=='0' && mine[l-1][c]=='0' && mine[l-1][c+1]=='0' && mine[l][c+1]=='0' && mine[l+1][c-1]=='0' && mine[l+1][c]=='0' && mine[l+1][c+1]=='0' ){
		  if(jeu[l][c-1]!='0' && jeu[l][c-1]!='X'){
				MineAutour(mine,jeu,l,c-1,taille_l,taille_c);
			}
			if(jeu[l-1][c-1]!='0' && jeu[l-1][c-1]!='X'){
				MineAutour(mine,jeu,l-1,c-1,taille_l,taille_c);
			}
			if(jeu[l-1][c]!='0' && jeu[l-1][c]!='X'){
				MineAutour(mine,jeu,l-1,c,taille_l,taille_c);
			}
			if(jeu[l-1][c+1]!='0' && jeu[l-1][c+1]!='X'){
				MineAutour(mine,jeu,l-1,c+1,taille_l,taille_c);
			}
			if(jeu[l][c+1]!='0' && jeu[l][c+1]!='X'){
				MineAutour(mine,jeu,l,c+1,taille_l,taille_c);
			}
			if(jeu[l+1][c-1]!='0' && jeu[l+1][c-1]!='X'){
			  MineAutour(mine,jeu,l+1,c-1,taille_l,taille_c);
			}
			if(jeu[l+1][c]!='0' && jeu[l+1][c]!='X'){
				MineAutour(mine,jeu,l+1,c,taille_l,taille_c);
			}
		  if(jeu[l+1][c+1]!='0' && jeu[l+1][c+1]!='X'){
				MineAutour(mine,jeu,l+1,c+1,taille_l,taille_c);
			}
		}
	}
}


void choixdifficulte(int *pl,int *pc,int *pnbmines){      //procédure pour choisir la difficulté du jeu
  float diff=2;
  do{
    printf("\n0 = debutant , 1 = intermédiare\n");
    printf("Choisir la difficulte: ");
    scanf("%f",&diff);
    int c=0; 
    int r=0;
    do{
      r = scanf("%c", &c);        
    }while(r==1 && c!='\n');                             //boucle pour éviter les erreurs du scanf
  }while(diff!=0 && diff!=1);                            //boucle pour éviter les erreurs du scanf
  
  if(diff==0){                  
    *pl=TAILLEDEB;                                       //si choix=0 alors la taille = TAILLEDEB(9)
    *pc=TAILLEDEB;
    *pnbmines=10;                                        
  }
    
  if(diff==1){                      
    *pl=TAILLEINT;                                      //si choix=1 alors la taille = TAILLEINT(16)
    *pc=TAILLEINT;
    *pnbmines=40;
  }
}

void placerdrapeau(char jeu[30][30],int l,int c){     //procédure pour placer un drapeau
  int choix_c,choix_l;  
	do{
 	  printf("Quelle ligne ?\n");
    scanf("%d",&choix_l);
    int c1=0; 
    int r1=0;
    do{
      r1 = scanf("%c", &c1);        
    }while(r1==1 && c1!='\n');                     //boucle pour éviter les erreurs du scanf 
  }while(choix_l<0 || choix_l>=l);                 //boucle pour éviter les erreurs du scanf 
  do{  
    printf("Quelle colonne ?\n");
    scanf("%d",&choix_c); 
    int c2=0;
    int r2=0;
    do{
      r2 = scanf("%c", &c2);        
    }while(r2==1 && c2!='\n');                     //boucle pour éviter les erreurs du scanf 
  }while(choix_c<0 || choix_c>=c);                 //boucle pour éviter les erreurs du scanf 
  if(jeu[choix_l][choix_c]=='~'){                  //si la case n'est pas révélée:
    jeu[choix_l][choix_c]='X';                     //on place un drapeau
    grille(jeu,l,c);                               //on affiche la grille
  }
  else if(jeu[choix_l][choix_c]=='X'){             //si la case a deja un drapeau:
    jeu[choix_l][choix_c]='~';                     //on le retire
    grille(jeu,l,c);                               //on affiche la grille 
  }
  else{                                            //si la case est deja révelée:
    printf("La case est deja révélée ! Pas besoin de marqueur.\n");          
  }
}
  
int choixtour(){          //fonction pour choisir si on révele une case ou si on place un drapeau
  float choix=2;
    do{
      printf("0:dévoiler la case   1:placer un drapeau\n");
      printf("Quel est votre choix ?\n");
      scanf("%f",&choix);
      int c=0; 
      int r=0;
      do{
        r = scanf("%c", &c);           
      }while(r==1 && c!='\n');               //boucle pour éviter les erreurs
    }while(choix!=0 && choix!=1);            //boucle pour éviter les erreurs
  return choix; 
}


void jouer(char mine[30][30],char jeu[30][30],int l,int c,int *pconddéfaite){       //procédure lorsqu'on choisit de réveler une case
  int i,j;
  int choix_c,choix_l;  
  do{
 	  printf("Quelle ligne ?\n");
    scanf("%d",&choix_l);
    int c=0; 
    int r=0;
    do{
      r = scanf("%c", &c);        
    }while(r==1 && c!='\n');                     //boucle pour éviter les erreurs
  }while(choix_l<0 || choix_l>=l);               //boucle pour éviter les erreurs
  do{  
    printf("Quelle colonne ?\n");
    scanf("%d",&choix_c); 
    int ch=0;
    int r=0;
    do{
      r = scanf("%c", &ch);        
    }while(r==1 && ch!='\n');                   //boucle pour éviter les erreurs
  }while(choix_c<0 || choix_c>=c);              //boucle pour éviter les erreurs
  if(mine[choix_l][choix_c]=='M'){              //si la case choisit est une mine:
    printf("\nVous avez perdu :( \n");
    *pconddéfaite=1;                              //on met la condition de défaite sur 1
    printf("Voici où les mines étaient placées:\n\n");       //on affiche où les mines sont placées
    for(i=0;i<l;i++){               
      for(j=0;j<c;j++){
        printf(" %c",mine[i][j]);
      }
      printf("\n");
    }  
    printf("\n");
  }  
  else{                                    //si la case choisie n'est pas une mine 
    MineAutour(mine,jeu,choix_l,choix_c,l-1,c-1);        //on révèle le nombre de mine autour
    printf("\n\n");                        
    grille(jeu,l,c);                                    //on affiche la grille
    printf("\n");
  }
}


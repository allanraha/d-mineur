#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COULEURS
#define TAILLEDEB 9
#define TAILLEINT 16
#define couleur(param) printf("\033[%sm",param)

void Init(char mine[30][30],char jeu[30][30],int l,int c){
  int i,j;
  for(i=0;i<20;i++){
    for(j=0;j<20;j++){
      jeu[i][j]='~';
      mine[i][j]='0';
    }
  }
}

void GRILLE(char jeu[30][30],int lig,int col){
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
        couleur("36");
        printf("%c",jeu[i][j]);
        couleur("0");
        printf("| ");
      }
      else if(jeu[i][j]=='1'){
        couleur("34");
        printf("%c",jeu[i][j]);
        couleur("0");
        printf("| ");
      }
      else if(jeu[i][j]=='2'){
        couleur("32");
        printf("%c",jeu[i][j]);
        couleur("0");
        printf("| ");
      }
      else if(jeu[i][j]=='3'){
        couleur("33");
        printf("%c",jeu[i][j]);
        couleur("0");
        printf("| ");
      }
      else if(jeu[i][j]=='4'){
        couleur("31");
        printf("%c",jeu[i][j]);
        couleur("0");
        printf("| ");
      }
      else if(jeu[i][j]=='5'){
        couleur("35");
        printf("%c",jeu[i][j]);
        couleur("0");
        printf("| ");
      }
      else if(jeu[i][j]=='X'){
        couleur("45");
        printf("%c",jeu[i][j]);
        couleur("0");
        printf("| ");
      }
      else{
        printf("%c| ",jeu[i][j]);
      }
    }
  printf("\n\n");
  }
}

void MINE(char mine[30][30],int nbmines,int lig,int col){
	int i,j;
  int k=0;
	int l=0;
	for(i=0;i<nbmines;i++){
    l=rand()%lig;
    k=rand()%col;
    if(mine[l][k]=='0'){
      mine[l][k]='M';
    }
    else{
      nbmines++;
    }
  }
}

	
void MineAutour(char mine[30][30],char jeu[30][30],int l,int c,int taille_l,int taille_c){
	char N;
	if(c==0){
    N=0;
		if(l==0){
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
			if(jeu[l][c]=='0'){
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
		}
		if(l==taille_l){
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
			if(mine[l-1][c]=='0' && mine[l-1][c+1]=='0' && mine[l][c+1]=='0'){
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
		else if(l>0 && l<taille_l){	
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
		if(l==0){
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
		if(l==taille_l){
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
		else if(l>0 && l<taille_l){
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
	}else if(l==0 && c!=0 && c!=taille_c){
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
			
	}else if(l==taille_l && c!=0 && c!=taille_c){
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
	else{
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


void choixdifficulte(int *pl,int *pc,int *pnbmines){      //Fonction pour choisir la difficulté
  float diff=2;
  do{
    printf("\n0 = debutant , 1 = intermédiare\n");
    printf("Choisir la difficulte: ");
    scanf("%f",&diff);
    int c=0; 
    int r=0;
    do{
      r = scanf("%c", &c);        
    }while(r==1 && c!='\n');        //Boucles pour éviter les erreurs
  }while(diff!=0 && diff!=1);       //Boucles pour éviter les erreurs
  
  if(diff==0){                     //Si 0 choisit alors la taille des lignes
    *pl=TAILLEDEB;                   //Et des colonnes sera de 9
    *pc=TAILLEDEB;
    *pnbmines=10;
  }
    
  if(diff==1){                        //Si 1 choisit alors la taille des lignes
    *pl=TAILLEINT;                 //et des colonnes sera de 15
    *pc=TAILLEINT;
    *pnbmines=40;
  }
}

void placerdrapeau(char jeu[30][30],int l,int c){      //fonction permettant de placer un drapeau
  int choix_c,choix_l;  
 	printf("Quelle ligne ?\n");
  scanf("%d",&choix_l);
  printf("Quelle colonne ?\n\n");
  scanf("%d",&choix_c);
  if(jeu[choix_l][choix_c]=='~'){ // Si la case n'est pas découverte, un 
    jeu[choix_l][choix_c]='X';    // marqueur de bombe est placé à la case
    GRILLE(jeu,l,c);                  // souhaitée, puis on affiche la grille
  }
  else if(jeu[choix_l][choix_c]=='X'){   // Si la case a deja un marqeur de bombe
    jeu[choix_l][choix_c]='~';           // alors ce dernier est enlevé 
    GRILLE(jeu,l,c);                         // Puis on affiche la grille 
  }
  else{                                  //si la case est deja révelée:
    printf("La case est deja révélée ! Pas besoin de marqueur.\n");
  }
}
  
int choixtour(){ //fonction pour choisir l'action du tour
  float choix=2;
    do{
      printf("0:dévoiler la case   1:placer un drapeau\n");
      printf("Quel est votre choix ?\n");
      scanf("%f",&choix);
      int c=0; 
      int r=0;
      do{
        r = scanf("%c", &c);           
      }while(r==1 && c!='\n');              //Boucle pour les erreurs
    }while(choix!=0 && choix!=1);           //Boucle pour les erreurs
  return choix;
}


void jouer(char mine[30][30],char jeu[30][30],int l,int c,int *pconddéfaite){  //fonction pour dévoiler la case
  int i,j;
  int choix_c,choix_l;  
  do{
 	  printf("Quelle ligne ?\n");
    scanf("%d",&choix_l);
    int c=0; 
    int r=0;
    do{
      r = scanf("%c", &c);        
    }while(r==1 && c!='\n');        //Boucle pour les erreurs
  }while(choix_l<0 || choix_l>=l);   //Boucle pour les erreurs
  do{  
    printf("Quelle colonne ?\n");
    scanf("%d",&choix_c); 
    int ch=0;
    int r=0;
    do{
      r = scanf("%c", &ch);        
    }while(r==1 && ch!='\n');        //Boucle pour les erreurs
  }while(choix_c<0 || choix_c>=c);    //Boucle pour les erreurs
  if(mine[choix_l][choix_c]=='M'){   //si il y a une mine sur la case choisie
    printf("\nVous avez perdu :( \n");
    *pconddéfaite=1;                  //on met la condition de défaite sur 1
    printf("Voici où les mines étaient placées:\n\n");
    for(i=0;i<l;i++){               // On affiche les mines lorsque l'on perd
      for(j=0;j<c;j++){
        printf(" %c",mine[i][j]);
      }
      printf("\n");
    }  
    printf("\n");
  }  
  else{                                  //si il n'y a pas de mine sur la case:
    MineAutour(mine,jeu,choix_l,choix_c,l-1,c-1);//fonction qui dévoile le nombre de mine
    printf("\n\n");                        //autour de la case choisie
    GRILLE(jeu,l,c);                         //On réaffiche la grille
    printf("\n");
  }
}
 
  




int main(){
  int condvictoire = 0; //déclaration des variables
  int compt=0;
  int tour;
  int rejouer=1;
  char p;

  char JEU[30][30];
  char mine[30][30];

  int i,j;
  int l,c,nbmines;
  int conddéfaite=0;
  
  srand(time(NULL));   //Initialisation de la fonction rand

  while(rejouer==1){
    choixdifficulte(&l,&c,&nbmines);  //Choix de la difficulté
    Init(mine,JEU,l,c);          //On initialise le tableau
    MINE(mine,nbmines,l,c);  //On initialise la mine
    GRILLE(JEU,l,c);        //On affiche la grille
    condvictoire = (l*c)-nbmines;  //condition de victoire = nombre de cases -                                        //nombre de mines
    while(compt!=condvictoire && conddéfaite==0){ //tant que le compteur n'est pas
      compt=0;                                    //égal au nombre de cases révélés
      tour=choixtour();                           //ou tant que la case choisie 
      if(tour==0){                               //n'a pasde mines
        jouer(mine,JEU,l,c,&conddéfaite);
      }                       //en fonction de la fonction choix tour on appelle 
      if(tour==1){              //la fonction correspondante
        placerdrapeau(JEU,l,c);
      }
      for(i=0;i<l;i++){
        for(j=0;j<c;j++){
          if(JEU[i][j]!='~' && JEU[i][j]!='X'){
            compt=compt+1;          //Compteur qui compte le nombre de cases 
          }                           //révélés
        }  
      }
    
    }
    if(compt==condvictoire){         // Si on a gagné
      printf("Bravo vous avez gagnez !\n");
    }
    do{
      printf("Voulez vous rejouer ?\n");
      printf("0:Quitter    1:rejouer\n");
      scanf("%d",&rejouer);        //On regarde si le joueur veut rejouer 
      int c=0; 
      int r=0;
      do{
        r = scanf("%c", &c);               
      }while(r==1 && c!='\n');         //Boucle pour les erreurs
    }while(rejouer!=0 && rejouer!=1);  //Boucle pour les erreurs
    conddéfaite=0;                     //Si oui on retourne alors à la ligne 515
    compt=0;
  }
  return 0;
}

#include "demineur.h"


void init(char mine[30][30],char jeu[30][30],int l,int c){
  int i,j;
  for(i=0;i<20;i++){
    for(j=0;j<20;j++){
      jeu[i][j]='~';
      mine[i][j]='0';
    }
  }
}

void grille(char jeu[30][30],int lig,int col){
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

void placermine(char mine[30][30],int nbmines,int lig,int col){
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


void choixdifficulte(int *pl,int *pc,int *pnbmines){      
  float diff=2;
  do{
    printf("\n0 = debutant , 1 = intermédiare\n");
    printf("Choisir la difficulte: ");
    scanf("%f",&diff);
    int c=0; 
    int r=0;
    do{
      r = scanf("%c", &c);        
    }while(r==1 && c!='\n');        
  }while(diff!=0 && diff!=1);      
  
  if(diff==0){                  
    *pl=TAILLEDEB;              
    *pc=TAILLEDEB;
    *pnbmines=10;
  }
    
  if(diff==1){                      
    *pl=TAILLEINT;                
    *pc=TAILLEINT;
    *pnbmines=40;
  }
}

void placerdrapeau(char jeu[30][30],int l,int c){  
  int choix_c,choix_l;  
 	printf("Quelle ligne ?\n");
  scanf("%d",&choix_l);
  printf("Quelle colonne ?\n");
  scanf("%d",&choix_c);
  if(jeu[choix_l][choix_c]=='~'){ 
    jeu[choix_l][choix_c]='X';   
    grille(jeu,l,c);                
  }
  else if(jeu[choix_l][choix_c]=='X'){ 
    jeu[choix_l][choix_c]='~';          
    grille(jeu,l,c);                 
  }
  else{                            
    printf("La case est deja révélée ! Pas besoin de marqueur.\n");
  }
}
  
int choixtour(){ 
  float choix=2;
    do{
      printf("0:dévoiler la case   1:placer un drapeau\n");
      printf("Quel est votre choix ?\n");
      scanf("%f",&choix);
      int c=0; 
      int r=0;
      do{
        r = scanf("%c", &c);           
      }while(r==1 && c!='\n');              
    }while(choix!=0 && choix!=1);           
  return choix;
}


void jouer(char mine[30][30],char jeu[30][30],int l,int c,int *pconddéfaite){ 
  int i,j;
  int choix_c,choix_l;  
  do{
 	  printf("Quelle ligne ?\n");
    scanf("%d",&choix_l);
    int c=0; 
    int r=0;
    do{
      r = scanf("%c", &c);        
    }while(r==1 && c!='\n');       
  }while(choix_l<0 || choix_l>=l);   
  do{  
    printf("Quelle colonne ?\n");
    scanf("%d",&choix_c); 
    int ch=0;
    int r=0;
    do{
      r = scanf("%c", &ch);        
    }while(r==1 && ch!='\n');       
  }while(choix_c<0 || choix_c>=c);   
  if(mine[choix_l][choix_c]=='M'){  
    printf("\nVous avez perdu :( \n");
    *pconddéfaite=1;                 
    printf("Voici où les mines étaient placées:\n\n");
    for(i=0;i<l;i++){               
      for(j=0;j<c;j++){
        printf(" %c",mine[i][j]);
      }
      printf("\n");
    }  
    printf("\n");
  }  
  else{                                 
    MineAutour(mine,jeu,choix_l,choix_c,l-1,c-1);
    printf("\n\n");                        
    grille(jeu,l,c);                        
    printf("\n");
  }
}


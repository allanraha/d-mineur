#include "demineur.h"

int main(){
  int cond_victoire = 0; 
  int compt=0;
  int tour;
  int rejouer=1;
  char p;
  char jeu[30][30];
  char mine[30][30];
  int i,j;
  int l,c,nbmines;
  int cond_defaite=0;
  
  srand(time(NULL));   

  while(rejouer==1){
    choixdifficulte(&l,&c,&nbmines);   
    init(mine,jeu,l,c);          
    placermine(mine,nbmines,l,c);  
    grille(jeu,l,c);        
    cond_victoire = (l*c)-nbmines;                      
    time_t temps1 = time(NULL);
    time_t temps2;
    while(compt!=cond_victoire && cond_defaite==0){ 
      compt=0;                                    
      tour=choixtour();                           
      if(tour==0){                               
        jouer(mine,jeu,l,c,&cond_defaite);
      }                      
      if(tour==1){             
        placerdrapeau(jeu,l,c);
      }
      for(i=0;i<l;i++){
        for(j=0;j<c;j++){
          if(jeu[i][j]!='~' && jeu[i][j]!='X'){
            compt=compt+1;          
          }                           
        }  
      }
    
    }
    if(compt==cond_victoire){         
      printf("Bravo vous avez gagnez !\n");
      temps2 = time(NULL);
      printf("Votre temps de jeu: %lf secondes\n",difftime(temps2, temps1));
    }
    do{
      printf("Voulez vous rejouer ?\n");
      printf("0:Quitter    1:rejouer\n");
      scanf("%d",&rejouer);        
      int c=0; 
      int r=0;
      do{
        r = scanf("%c", &c);               
      }while(r==1 && c!='\n');         
    }while(rejouer!=0 && rejouer!=1);  
    cond_defaite=0;                   
    compt=0;
  }
  return 0;
}

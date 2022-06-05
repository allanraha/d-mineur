#include "main.h"

int main(){
  int condvictoire = 0; 
  int compt=0;
  int tour;
  int rejouer=1;
  char p;
  char JEU[30][30];
  char mine[30][30];
  int i,j;
  int l,c,nbmines;
  int conddéfaite=0;
  
  srand(time(NULL));   

  while(rejouer==1){
    choixdifficulte(&l,&c,&nbmines);   
    Init(mine,JEU,l,c);          
    MINE(mine,nbmines,l,c);  
    GRILLE(JEU,l,c);        
    condvictoire = (l*c)-nbmines;                      while(compt!=condvictoire && conddéfaite==0){ 
      compt=0;                                    
      tour=choixtour();                           
      if(tour==0){                               
        jouer(mine,JEU,l,c,&conddéfaite);
      }                      
      if(tour==1){             
        placerdrapeau(JEU,l,c);
      }
      for(i=0;i<l;i++){
        for(j=0;j<c;j++){
          if(JEU[i][j]!='~' && JEU[i][j]!='X'){
            compt=compt+1;          
          }                           
        }  
      }
    
    }
    if(compt==condvictoire){         
      printf("Bravo vous avez gagnez !\n");
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
    conddéfaite=0;                   
    compt=0;
  }
  return 0;
}

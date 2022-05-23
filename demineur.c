#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int JEU[20][20];
char mine[20][20];
int i,j;
int l,c,nbmines;

void Init(int l,int c){
      for(i=0;i<l;i++){
        for(int j=0;j<c;j++){
            JEU[i][j]='~';
            mine[i][j]='0';
        }
    }
  
}

void GRILLE(int lig,int col){
    char a;
    printf("   ");
    for(a='A';a<'A'+col;a++){
        printf("%c ",a);
    }
    printf("\n");
    for(i=0;i<lig;i++){
      if(i<10){
        printf("%d |",i);
      }
      else{
        printf("%d|",i);
      }
      
        for(j=0;j<col;j++){
            printf("%c|",JEU[i][j]);
        }
        printf("\n");
    }
}

void MINE(int nbmines,int lig,int col){
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
	
int MineAutour(int l,int c){
	int N=0;
	if(mine[l][c]=='M'){
		printf("BOOMMM! Vous avez perdu !!");
		N=50;
		exit(1);
		}
	N=0;
	if(c==0){
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
				return N;
			}
		if(l==9){
			if(mine[l-1][c]=='M'){
				N=N+1;
				}
			if(mine[l-1][c+1]=='M'){
				N=N+1;
				}
			if(mine[l][c+1]=='M'){
				N=N+1;
				}
				return N;
			}
		else{	
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
				return N;
			}
			
	}else if(c==9){
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
					return N;
				}
			if(l==9){
				if(mine[l-1][c]=='M'){
					N=N+1;
					}
				if(mine[l-1][c-1]=='M'){
					N=N+1;
					}
				if(mine[l][c-1]=='M'){
					N=N+1;
					}
					return N;
				}
			else{
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
					return N;
				}
	}else if(l==0 && c!=0 && c!=9){
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
				return N;
	}else if(l==9 && c!=0 && c!=9){
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
				return N;
	}
	else{
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
			return N;
		}
}


void choixdifficulte(){
  int diff;
  printf("0 = debutant , 1 = intermédiare\n");
  printf("Choisir la difficulte: ");
  scanf("%d",&diff);
  switch(diff){
    case 0:
      l=10;
      c=10;
      nbmines=10;
    break;
    
    case 1:
      l=17;
      c=17;
      nbmines=40;
    break;
  }

    
}

void jouer(){
  int choix_c,choix_l;  
 	printf("quel case ?");
  scanf("%d",&choix_l);
  scanf("%d",&choix_c);
  JEU[choix_l][choix_c]=MineAutour(choix_l,choix_c)+'0';
  printf("\n\n");
 	for(i=0;i<l;i++){
    for(j=0;j<c;j++){
      printf(" %c",mine[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  GRILLE(l,c);
}



int main(){
  int aut;
  char p;
  srand(time(NULL));
  
  
  choixdifficulte();
  Init(l,c);

	MINE(nbmines,l,c);
  GRILLE(l,c);
  

for(i=0;i<100;i++){
  jouer();
}
  

   
    
  return 0;
}




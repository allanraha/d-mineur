#include<stdio.h>
#define TAILLE 10

char pion(int p){
	if(p==0){
		return ' ';
	}
	if(p==1){
		return 'X';
	}
	if(p==2){
		return '_';
	}
	if(p==3){
		return 'O';
	}
	else{
		printf("Erreur");
		return 'E';
	}
}

void placer_bateau(int plateau[TAILLE][TAILLE]){
	char col;
	int lig;
	printf("Emplacement du bateau: ");
	printf("\nLettre: ");
	scanf("%c";&col);
	printf("\nNombre: ");
	scanf("%d";&lig);
	
}
	
	



void affiche_plateau(int plateau [TAILLE] [TAILLE]){
	char c;
	int i,j;
	printf("    ");
	for(c='A';c<'K';c++){
		printf("%c ",c);
	}
	printf("\n");
	printf("    ");
	for(i=0;i<TAILLE;i++){
		printf("_ ");
	}
	
	
	
	
	printf("\n");
	for(i=0;i<TAILLE;i++){
		if(i==TAILLE-1){
			printf("\n%d|",i+1);
		
		}
		else{
			printf("\n%d |",i+1);
		}
		for(j=0;j<TAILLE;j++){
			printf(" %c",pion(plateau[i][j]));
		}
	
	}
	printf("\n");

}

	

int main(){
	int plateau_joueur[TAILLE][TAILLE]={0};
	int plateau_adversaire[TAILLE][TAILLE]={0};
	
	affiche_plateau(plateau_joueur);
	printf("%c",pion(3));
	





	return 0;
}





#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char JEU[10][10];
char mine[10][10];
int i,j;


void GRILLEdeb(){
    printf("   A B C D E F G H I J\n");
    for(i=0;i<10;i++){
        printf("%d |",i);
        for(j=0;j<10;j++){
            printf("%c|",JEU[i][j]);
        }
        printf("\n");
    }
}

void MINEdeb(){
	int c=10;
	int k=0;
	int l=0;
	for(i=0;i<c;i++){
        l=rand()%10;
        k=rand()%10;
        if(mine[l][k]=='0'){
            mine[l][k]='M';
        }
        else{
            c++;
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
			if(mine[l][c-1]=='M'){
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








int main(){

    int i,j;
    int aut;
    srand(time(NULL));
    for(i=0;i<10;i++){
        for(int j=0;j<10;j++){
            JEU[i][j]='~';
            mine[i][j]='0';
        }
    }
    
    
	
       
    
    GRILLEdeb();
    MINEdeb();
    aut=MineAutour(0,0);
    printf("\n\n");
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf(" %c",mine[i][j]);
        }
        printf("\n");
    }
    printf("il y a %d mines autour de la case 0:0",aut);
    
    return 0;
}



#include <stdio.h>
#include <stdlib.h>                                                                       //Inclusion des bibliothèque
#include <time.h>

#define COULEURS
#define TAILLEDEB 9                                                                       //Définition des constantes et des couleurs
#define TAILLEINT 16
#define couleur(param) printf("\033[%sm", param)

void init(char mine[30][30], char jeu[30][30], int l, int c);

void grille(char jeu[30][30], int lig, int col);

void placermine(char mine[30][30], int nbmines, int lig, int col);                         //définition des fonctions

void MineAutour(char mine[30][30], char jeu[30][30], int l, int c, int taille_l,
                int taille_c);

void choixdifficulte(int *pl, int *pc, int *pnbmines);

void placerdrapeau(char jeu[30][30], int l, int c);

int choixtour();

void jouer(char mine[30][30], char jeu[30][30], int l, int c,int *pconddéfaite);

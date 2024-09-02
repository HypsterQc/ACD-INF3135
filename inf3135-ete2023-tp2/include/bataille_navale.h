#ifndef BATAILLE_NAVALE_H
#define BATAILLE_NAVALE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../include/stats.h"

/**
 * Structure représentant une case du jeu de bataille navale.
 */
typedef struct une_case
{
   int x;
   int y;
   char valeur; // Ajouter un champ valeur pour stocker '1', 'O', 'X' ou '.'
} Case;

/**
 * Structure représentant un navire du jeu de bataille navale.
 */
typedef struct navire
{
   int sens;           // La direction du bateau, 0 pour la droite, 1 pour le bas, 2 pour la gauche, 3 pour le haut
   Case premiere_case; // Les coordonnées de la première case
   int taille;
   char *nom; // Le nom du navire
   int sante; // La santé du navire
} Navire;

/**
 * Structure représentant la grille de jeu du jeu de bataille navale.
 */
typedef struct grille_jeu
{
   int taille_plateau;
   Case **cases;
   Navire **navires; // Un tableau de pointeurs vers des structures Navire
   int nb_bateaux_non_coules;
} GrilleJeu;

void init_nb_aleatoire();
int nb_aleatoire(int max);
void *allouer_memoire(size_t taille);
GrilleJeu *creer_grille(int taille, char remplissage);
Navire *creer_navire(int taille, char *nom);
int est_placement_valide(GrilleJeu *grille, Navire *navire);
int valider_info_navire(Navire *navire, int x, int y);
void generer_coordonnees(GrilleJeu *grille, Navire *navire, int *x, int *y);
void placer_navire(GrilleJeu *grille, Navire *navire, char c);
void afficher_grille(GrilleJeu *grille);
void jouer_partie(GrilleJeu *grille1, GrilleJeu *grille2, donner_stats stats, char *nom_fichier);
void detruire_grille(GrilleJeu *grille);

#endif
#ifndef MAIN_C
#define MAIN_C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/bataille_navale.h"
#include "../include/stats.h"

int main(int argc, char *argv[])
{

   init_nb_aleatoire(); // initialiser le générateur de nombres aléatoires

   donner_stats stats;
   stats.nb_total_coups = 0;
   stats.nb_misses_total = 0;
   stats.nb_touches_total = 0;
   stats.nb_deja_joues_total = 0;
   stats.nom_dernier_navire_coule = NULL;

   char *nom_fichier = verifier_args(argc, argv, stats);

   int taille;
   printf("Entrez la taille de la grille (entre 6 et 100) : ");

   if (scanf("%d", &taille) != 1 || taille < 6 || taille > 100)
   {
      printf("Entrée invalide. La taille doit être comprise entre 6 et 100.");
      return 1; // retourner avec un code d'erreur
   }

   GrilleJeu *grille1 = creer_grille(taille, '0');
   GrilleJeu *grille2 = creer_grille(taille, '.');

   int tailles_bateaux[] = {2, 3, 3, 4, 5};
   char *noms_bateaux[] = {"Torpilleur", "Contre-torpilleurs", "Contre-torpilleurs", "Croiseur", "Porte-avions"};
   for (int i = 0; i < 5; i++)
   {
      Navire *navire = creer_navire(tailles_bateaux[i], noms_bateaux[i]);
      placer_navire(grille1, navire, '1');
      grille1->navires[i] = navire; // Assigner l'objet navire au tableau
   }

   jouer_partie(grille1, grille2, stats, nom_fichier);

   detruire_grille(grille1);
   detruire_grille(grille2);

   return 0;
}

#endif
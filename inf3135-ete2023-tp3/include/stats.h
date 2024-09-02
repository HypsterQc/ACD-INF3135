#ifndef STATS_H
#define STATS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Structure pour stocker les statistiques du jeu de bataille navale.
 */
typedef struct donner_stats {
   int nb_lignes_fichier;
   int nb_mots_uniques;
   int nb_mots_doublons;
   char lettre_plus_frequente;
   int nb_categories;
   int nb_recettes;
   char categorie_max_recettes[256];
   char recette_plus_longue[256];
} donner_stats;

void ecrire_stats(char *fichier, donner_stats *stats);
void verifier_option(char *option);
void gerer_fichier(char *nom_fichier, donner_stats *stats);
void verifier_args(int argc, char *argv[], donner_stats *stats, char **nom_fichier_entree, char **nom_fichier_stats);
void est_txt(char *fichier);
void creer_fichier(char *fichier);
void initialiserStats(donner_stats *stats);

#endif
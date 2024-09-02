#ifndef STATS_H
#define STATS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

/**
 * Structure pour stocker les statistiques du jeu de bataille navale.
 */
typedef struct donner_stats
{
   int nb_total_coups;
   int nb_lettres_uniques_premier_navire_coule;
   int nb_misses_total;
   int nb_deja_joues_total;
   int nb_touches_total;
   char *nom_dernier_navire_coule;
} donner_stats;

void ecrire_stats(char *fichier, donner_stats stats);
void verifier_option(char *option);
void gerer_fichier(char *nom_fichier, donner_stats stats);
char *verifier_args(int argc, char *argv[], donner_stats stats);
int est_txt(char *fichier);
void creer_fichier(char *fichier);

#endif

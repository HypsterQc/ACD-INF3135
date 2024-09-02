#ifndef STATS_C
#define STATS_C

#include "../include/stats.h"

/**
 * Vérifie l'option de la ligne de commande.
 *
 * @param option Option à vérifier
 */
void verifier_option(char *option)
{
   if (strcasecmp(option, "-S") != 0)
   {
      printf("Option non reconnue. Utilisation : ./bataille_navale -S stats.txt\n");
      exit(1);
   }
}

/**
 * Vérifie si le fichier a une extension .txt.
 *
 * @param fichier Nom du fichier à vérifier
 * @return 1 si le fichier a une extension .txt, 0 sinon
 */
int est_txt(char *fichier)
{
   char *extension = strrchr(fichier, '.');
   if (extension != NULL && strcmp(extension, ".txt") == 0)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

/**
 * Crée un fichier s'il n'existe pas ou l'écrase s'il existe déjà.
 *
 * @param fichier Nom du fichier à créer
 */
void creer_fichier(char *fichier)
{
   FILE *sortie = fopen(fichier, "w");
   if (sortie == NULL)
   {
      printf("Impossible de créer le fichier '%s'\n", fichier);
      exit(1);
   }
   fclose(sortie);
}

/**
 * Écrit les statistiques dans un fichier.
 *
 * @param fichier Nom du fichier de sortie
 * @param stats Statistiques à écrire
 */
void ecrire_stats(char *fichier, donner_stats stats)
{
   FILE *sortie = fopen(fichier, "a");
   if (sortie == NULL)
   {
      printf("Impossible d'ouvrir le fichier '%s'\n", fichier);
      exit(1);
   }
   fprintf(sortie, "Total de coups : %d\n", stats.nb_total_coups);
   fprintf(sortie, "Nombre de lettres uniques dans le premier navire coulé : %d\n", stats.nb_lettres_uniques_premier_navire_coule);
   fprintf(sortie, "Total des ratés : %d\n", stats.nb_misses_total);
   fprintf(sortie, "Total des coups déjà joués : %d\n", stats.nb_deja_joues_total);
   fprintf(sortie, "Total des touches : %d\n", stats.nb_touches_total);
   fprintf(sortie, "Nom du dernier navire coulé : %s\n", stats.nom_dernier_navire_coule);
   fclose(sortie);
}

/**
 * Gère le fichier de statistiques en fonction des arguments de la ligne de commande.
 *
 * @param nom_fichier Nom du fichier de statistiques
 * @param stats Statistiques à écrire
 */
void gerer_fichier(char *nom_fichier, donner_stats stats)
{
   if (!est_txt(nom_fichier))
   {
      printf("Le fichier doit être un fichier .txt\n");
      exit(1);
   }
   creer_fichier(nom_fichier);
   ecrire_stats(nom_fichier, stats);
}

/**
 * Vérifie les arguments de la ligne de commande.
 *
 * @param argc Nombre d'arguments
 * @param argv Tableau d'arguments
 * @param stats Statistiques à écrire
 * @return Nom du fichier de statistiques
 */
char *verifier_args(int argc, char *argv[], donner_stats stats)
{
   char *nom_fichier = NULL;

   if (argc == 3)
   {
      verifier_option(argv[1]);
      nom_fichier = argv[2];
      gerer_fichier(nom_fichier, stats);
      printf("Commencer la partie !\n");
   }
   else if (argc == 2)
   {
      verifier_option(argv[1]);
      nom_fichier = "stats.txt";
      gerer_fichier(nom_fichier, stats);
      printf("Commencer la partie !\n");
   }
   else if (argc == 1)
   {
      // Jouer sans écrire de fichier txt
      printf("Commencer la partie !\n");
   }
   else
   {
      printf("Utilisation incorrecte. Exemple : ./bataille_navale -S stats.txt\n");
      exit(1);
   }

   return nom_fichier;
}

#endif
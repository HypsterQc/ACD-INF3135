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
   if (strcmp(option, "-S") != 0 && strcmp(option, "-s") != 0)
   {
      printf("Option non reconnue.\n");
      exit(1);
   }
}

/**
 * Vérifie si le fichier a une extension .txt.
 *
 * @param fichier Nom du fichier à vérifier
 */
void est_txt(char *fichier)
{
   char *extension = strrchr(fichier, '.');
   if (extension == NULL || strcmp(extension, ".txt") != 0)
   {
      printf("Le fichier doit avoir une extension .txt\n");
      exit(1);
   }
}


/**
 * Crée un fichier s'il n'existe pas ou l'écrase s'il existe déjà.
 *
 * @param fichier Nom du fichier à créer
 */
void creer_fichier(char *fichier)
{
   FILE *sortie = fopen(fichier, "w+");
   if (sortie == NULL)
   {
      printf("Impossible de créer le fichier '%s'\n", fichier);
      exit(1);
   }
   fclose(sortie);
}

/**
 * Écrit les nouvelles statistiques dans un fichier.
 *
 * @param fichier Nom du fichier de sortie
 * @param stats Nouvelles statistiques à écrire
 */
void ecrire_stats(char *fichier, donner_stats *stats) {
    FILE *newfichier = fopen(fichier, "w+");
    if (!newfichier) {
        printf("Erreur lors de la création/ouverture du fichier stats.txt\n");
        return;
    }

    fprintf(newfichier, "Nombre de lignes (recettes) du fichier : %d\n", stats->nb_lignes_fichier);
    fprintf(newfichier, "Nombre de mots uniques : %d\n", stats->nb_mots_uniques);
    fprintf(newfichier, "Nombre total de mots (avec doublons) : %d\n", stats->nb_mots_doublons);
    fprintf(newfichier, "Lettre la plus fréquente : %c\n", stats->lettre_plus_frequente);
    fprintf(newfichier, "Nombre de catégories : %d\n", stats->nb_categories);
    fprintf(newfichier, "Nombre total de recettes : %d\n", stats->nb_recettes);
    fprintf(newfichier, "Catégorie avec le plus de recettes : %s\n", stats->categorie_max_recettes);
    fprintf(newfichier, "Recette la plus longue : %s\n", stats->recette_plus_longue);

    fclose(newfichier);
    printf("Statistiques enregistrées dans stats.txt\n");
}

/**
 * Gère le fichier de statistiques en fonction des arguments de la ligne de commande.
 *
 * @param nom_fichier Nom du fichier de statistiques
 * @param stats Statistiques à écrire
 */
void gerer_fichier(char *nom_fichier, donner_stats *stats)
{
   est_txt(nom_fichier);
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
void verifier_args(int argc, char *argv[], donner_stats *stats, char **nom_fichier_entree, char **nom_fichier_stats)
{
   if (argc < 2)
   {
      printf("Utilisation incorrecte. Exemple : ./recherche liste.txt -S stats.txt\n");
      exit(1);
   }
   est_txt(argv[1]);
   *nom_fichier_entree = argv[1];

   if(argc == 3 || argc == 4)
   {
      verifier_option(argv[2]);
      *nom_fichier_stats = "stats.txt";
   }
   if (argc == 4)
   {
      est_txt(argv[3]);
      *nom_fichier_stats = argv[3];
   }
   if (*nom_fichier_stats != NULL) {
        creer_fichier(*nom_fichier_stats);
        ecrire_stats(*nom_fichier_stats, stats); 
    }

    printf("Début du programme !\n");
}

// Initialiser les statistiques à zéro ou des valeurs appropriées
void initialiserStats(donner_stats *stats) {
    stats->nb_lignes_fichier = 0;
    stats->nb_mots_uniques = 0;
    stats->nb_mots_doublons = 0;
    stats->lettre_plus_frequente = 0;
    stats->nb_categories = 0;
    stats->nb_recettes = 0;
    stats->categorie_max_recettes[0] = '\0';  
    stats->recette_plus_longue[0] = '\0';    
}


#endif
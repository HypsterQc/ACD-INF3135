#ifndef MAIN_C
#define MAIN_C

#include <stdio.h>
#include "../include/recherche.h"
#include "../include/stats.h"

int main(int argc, char *argv[])
{
   donner_stats stats;
   initialiserStats(&stats);

   char *nom_fichier_entree = NULL;
   char *nom_fichier_stats = NULL;

   verifier_args(argc, argv, &stats, &nom_fichier_entree, &nom_fichier_stats);

   Categorie *categories = NULL;

    lireFichier(argv[1], &categories, &stats);

    if (nom_fichier_stats != NULL) {
        ecrire_stats(nom_fichier_stats, &stats);
    }

    Categorie *categorieCourante = categories;
    while (categorieCourante) {
        printf("Recettes pour %s:\n", categorieCourante->nom);
        categorieCourante = categorieCourante->suivant;
    }

    convertirCategorieEnMinuscule(categories);

   barreRecherche(categories);

    libererListeCategorie(categories);

   return 0;
}

#endif

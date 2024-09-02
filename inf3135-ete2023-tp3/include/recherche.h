#ifndef RECHERCHE_H
#define RECHERCHE_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "../include/stats.h"

// Définition de la structure pour un nœud de la liste
typedef struct Recette {
    char titre[256];
    struct Recette *suivant;
} Recette;

typedef struct Categorie {
    char nom[256];
    struct Categorie *suivant;
    Recette *recettes;
    int nbRecettes;
} Categorie;

Categorie* chercherOuAjouterCategorie(Categorie **tete, const char *nom);
void ajouterRecette(Categorie *categorie, const char *titre);
void lireFichier(const char *nomFichier, Categorie **categories, donner_stats *stats);
void afficherRecettesDeCategorie(Categorie *categorie);
void libererListeRecette(Recette *tete);
void libererListeCategorie(Categorie *tete);
void convertirEnMinuscule(char *mot);
void convertirCategorieEnMinuscule(Categorie *categorie);
Categorie* chercherCategorie(Categorie *tete, const char *motRecherche);
void barreRecherche(Categorie *categories);

#endif
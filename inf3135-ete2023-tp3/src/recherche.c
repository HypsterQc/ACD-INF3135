#ifndef RECHERCHE_C
#define RECHERCHE_C

#include "../include/recherche.h"

//*******TEST********
void afficherArguments(int argc, char *argv[]) {
    printf("Nombre d'arguments : %d\n", argc);
    printf("Liste des arguments :\n");

    for (int i = 0; i < argc; i++) {
        printf("Argument %d : %s\n", i, argv[i]);
    }
}

// Fonction pour chercher ou ajouter une catégorie
Categorie* chercherOuAjouterCategorie(Categorie **tete, const char *nom) {
    Categorie *temp = *tete;

    while (temp) {
        if (strcmp(temp->nom, nom) == 0) {
            return temp; 
        }
        temp = temp->suivant;
    }

    Categorie *nouvelleCategorie = (Categorie *)malloc(sizeof(Categorie));
    strcpy(nouvelleCategorie->nom, nom);
    nouvelleCategorie->suivant = *tete;
    nouvelleCategorie->recettes = NULL;
    *tete = nouvelleCategorie;
    return nouvelleCategorie;
}

// Fonction pour ajouter une recette à une catégorie
void ajouterRecette(Categorie *categorie, const char *titre) {
    Recette *nouvelleRecette = (Recette *)malloc(sizeof(Recette));
    strcpy(nouvelleRecette->titre, titre);
    nouvelleRecette->suivant = categorie->recettes;
    categorie->recettes = nouvelleRecette;
}

// Fonction pour lire le fichier et peupler les listes chaînées
void lireFichier(const char *nomFichier, Categorie **categories, donner_stats *stats) {
    FILE *fichier = fopen(nomFichier, "r");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier %s\n", nomFichier);
        return;
    }

    char ligne[1024];
    int repetetion[256] = {0}; 

    while (fgets(ligne, sizeof(ligne), fichier)) {
        stats->nb_lignes_fichier++;
        stats->nb_recettes++; 
        
        for (unsigned char *ptr = (unsigned char *)ligne; *ptr; ptr++) {
            repetetion[tolower(*ptr)]++; 
        }
        
        char *titre = strtok(ligne, "[");
        size_t titreLength = strlen(titre);

        if (!stats->recette_plus_longue || titreLength > strlen(stats->recette_plus_longue)) {
            strncpy(stats->recette_plus_longue, titre, sizeof(stats->recette_plus_longue));
        }

        char *categorieText = strtok(NULL, "]");
        Categorie *prevCat = NULL;

        while (categorieText) {
            Categorie *categorie = chercherOuAjouterCategorie(categories, categorieText);
            
            if (!prevCat || (prevCat && strcmp(prevCat->nom, categorie->nom) != 0)) {
                stats->nb_mots_uniques++;
                prevCat = categorie;
            }

            stats->nb_mots_doublons++; 

            if (!stats->categorie_max_recettes[0] || categorie->nbRecettes > prevCat->nbRecettes) {
                strcpy(stats->categorie_max_recettes, categorie->nom);
            }


            ajouterRecette(categorie, titre);
            categorie->nbRecettes++; 

            categorieText = strtok(NULL, "[");
            if (categorieText) {
                categorieText = strtok(NULL, "]");
            }
        }
    }

    int maxRepetetion= 0;
    for (int i = 0; i < 256; i++) {
        if (repetetion[i] > maxRepetetion) {
            maxRepetetion = repetetion[i];
            stats->lettre_plus_frequente = (char)i;
        }
    }

    stats->nb_categories = stats->nb_mots_uniques;

    fclose(fichier);
}

void afficherRecettesDeCategorie(Categorie *categorie) {
    Recette *current = categorie->recettes;
    while (current) {
        printf("%s\n", current->titre);
        current = current->suivant;
    }
}

void libererListeRecette(Recette *tete) {
    Recette *courant = tete;
    while (courant) {
        Recette *temp = courant;
        courant = courant->suivant;
        free(temp);
    }
}

void libererListeCategorie(Categorie *tete) {
    Categorie *courant = tete;
    while (courant) {
        Categorie *temp = courant;
        libererListeRecette(courant->recettes); 
        courant = courant->suivant;
        free(temp);
    }
}

void convertirEnMinuscule(char *mot) {
    for (size_t i = 0; i < strlen(mot); i++) {
        mot[i] = tolower(mot[i]);
    }
}

void convertirCategorieEnMinuscule(Categorie *categorie) {
    while (categorie) {
        convertirEnMinuscule(categorie->nom);
        categorie = categorie->suivant;
    }
}

Categorie* chercherCategorie(Categorie *tete, const char *motRecherche) {
    while (tete) {
        if (strcmp(tete->nom, motRecherche) == 0) {
            return tete;
        }
        tete = tete->suivant;
    }
    return NULL;
}

void barreRecherche(Categorie *categories) {
    char input[1024];

    do {
        printf("Entrez votre recherche (ou 'quit' pour quitter): ");
        fgets(input, sizeof(input), stdin);

        char *newline = strchr(input, '\n');
        if (newline) {
            *newline = '\0';
        }

        convertirEnMinuscule(input);

        if (strcmp(input, "quit") != 0) {
            Categorie *catTrouvee = chercherCategorie(categories, input);
            if (catTrouvee) {
                printf("Recettes pour la catégorie %s:\n", input);
                afficherRecettesDeCategorie(catTrouvee);
            } else {
                printf("Aucune catégorie trouvée pour : %s\n", input);
            }
        }

    } while (strcmp(input, "quit") != 0);

    printf("Fin de la barre de recherche.\n");
}


#endif
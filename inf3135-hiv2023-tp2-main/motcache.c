#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Définition d'une structure pour la matrice
struct Matrice {
    char donnees[12][12];
    int nb_mots;
    char mots[100][13];
    int trouver[12][12];
};

/**
 * Initialise la matrice à partir d'un fichier texte.
 *
 * @param matrice un pointeur vers une structure Matrice à initialiser
 * @param fichier un pointeur vers le fichier contenant les données de la matrice
 */
void initialiser_Matrice(struct Matrice *matrice, FILE *fichier) {
    char c;

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if ((c = fgetc(fichier)) != '\n') {
                matrice->donnees[i][j] = c;
            } else {
                j--;
            }
        }
    }
}

// Fonction pour enregistre les mots dans la structure matrice aillant un
// maximum de mots de 100.

/**
 * Initialise la liste des mots à partir d'un fichier texte et les stocke dans
 * le tableau de chaînes de caractères pointé par 'matrice->mots'.
 *
 * @param matrice - pointeur vers une structure Matrice à initialiser
 * @param fichier - pointeur vers le fichier contenant la liste des mots (un mot par ligne)
 */
void initialiser_Mots(struct Matrice *matrice, FILE *fichier) {
    while (fgets(matrice->mots[matrice->nb_mots], 13, fichier) != NULL) {
        matrice->mots[matrice->nb_mots][strcspn(matrice->mots[matrice->nb_mots], "\n")] = '\0';
        matrice->nb_mots++;
    }
}

/**
 * Recherche un mot dans la matrice à partir d'une position et d'une direction données.
 *
 * @param matrice - pointeur vers une structure Matrice contenant les données de la matrice
 * @param lignes - la ligne de départ de la recherche
 * @param colonnes - la colonne de départ de la recherche
 * @param mots - le mot à rechercher
 * @param direction - la direction dans laquelle effectuer la recherche (0:bas, 1:haut, 2:droite, 3:gauche)
 * @return true si le mot est trouvé, sinon false.
 */
bool recherche_Mots(struct Matrice *matrice, int lignes, int colonnes, char *mots, int direction) {
    int extremiter_matrice[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    if (*mots == '\0') {
        return true;
    }
    if (lignes < 0 || lignes >= 12 || colonnes < 0 || colonnes >= 12) {
        return false;
    }
    if (matrice->donnees[lignes][colonnes] != *mots) {
        return false;
    }
    return recherche_Mots(matrice, lignes + extremiter_matrice[direction][0], colonnes + extremiter_matrice[direction][1], mots + 1, direction);
}

/**
* Marque les lettres correspondant à un mot trouvé dans la direction donnée.

* @param matrice un pointeur vers la matrice de jeu
* @param lignes la ligne de départ du mot
* @param colonnes la colonne de départ du mot
* @param mots le mot à trouver
* @param i la position courante dans le mot
*/
void lecture_GD(struct Matrice *matrice, int lignes, int colonnes, char *mots, unsigned int i){
    for (i = 0; i < strlen(mots); i++) {
        matrice->trouver[lignes + i][colonnes] = 1;
    }
}

void lecture_DG(struct Matrice *matrice, int lignes, int colonnes, char *mots, unsigned int i){
    for (i = 0; i < strlen(mots); i++) {
        matrice->trouver[lignes - i][colonnes] = 1;
    }
}

void lecture_HB(struct Matrice *matrice, int lignes, int colonnes, char *mots, unsigned int i){
    for (i = 0; i < strlen(mots); i++) {
        matrice->trouver[lignes][colonnes + i] = 1;
    }
}

void lecture_BH(struct Matrice *matrice, int lignes, int colonnes, char *mots, unsigned int i){
    for (i = 0; i < strlen(mots); i++) {
        matrice->trouver[lignes][colonnes - i] = 1;
    }
}


/**
 * Trouve un mot dans la matrice et marque ses lettres comme trouvées.
 * La direction indique la manière dont le mot est orienté dans la matrice :
 * - 0 pour gauche-droite
 * - 1 pour droite-gauche
 * - 2 pour haut-bas
 * - 3 pour bas-haut
 *
 * @param matrice un pointeur vers la matrice à parcourir
 * @param lignes la ligne de départ pour la recherche
 * @param colonnes la colonne de départ pour la recherche
 * @param mots un pointeur vers la chaîne de caractères à chercher
 * @param direction la direction dans laquelle chercher le mot
 */
void mots_Trouver(struct Matrice *matrice, int lignes, int colonnes, char *mots, int direction) {
    int i = 0;
    if (direction == 0) {
        lecture_GD(matrice, lignes, colonnes, mots, i);
    } else if (direction == 1) {
        lecture_DG(matrice, lignes, colonnes, mots, i);
    } else if (direction == 2) {
        lecture_HB(matrice, lignes, colonnes, mots, i);
    } else {
        lecture_BH(matrice, lignes, colonnes, mots, i);
    }
}

/**
 * Recherche les mots dans la matrice.
 *
 * @param matrice un pointeur vers la structure Matrice contenant les données
 */
void recherche(struct Matrice *matrice) {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            // Pour chaque case, on vérifie si chaque mot est présent dans chaque direction
            for (int k = 0; k < matrice->nb_mots; ++k) {
                for (int l = 0; l < 4; ++l) {
                    // Si le mot est trouvé dans cette direction, on marque les lettres dans la matrice
                    if (recherche_Mots(matrice, i, j, matrice->mots[k], l)) {
                        mots_Trouver(matrice, i, j, matrice->mots[k], l);
                        break;
                    }
                }
            }
        }
    }
}

/**
 * Affiche la matrice avec les lettres non trouvées.

 * @param matrice un pointeur vers une structure Matrice
 */
void tester_Affichage(struct Matrice *matrice) {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (matrice->trouver[i][j] == 0) {
                printf("%c", matrice->donnees[i][j]);
            }
        }
    }
    printf("\n");
}

/**
 * Affiche la matrice des lettres ce trouvant dans le fichier.

 * @param matrice un pointeur vers une structure Matrice
 */
void tester_Affichage_Matrice(struct Matrice *matrice) {
    printf("Matrice : \n");
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            printf("%c", matrice->donnees[i][j]);
        }
        printf("\n");
    }
}

/**
 * Affiche la matrice des mots ce trouvant dans le fichier.

 * @param matrice un pointeur vers une structure Matrice
 */
void tester_Affichage_Mots(struct Matrice *matrice) {
    printf("mots : \n");
    for (int i = 0; i < matrice->nb_mots; ++i) {
        printf("%s\n", matrice->mots[i]);
    }
    printf("\n");
}

/**
 * Fonction principale du programme
 *
 * @param argc nombre d'arguments passés en ligne de commande
 * @param argv tableau de chaînes de caractères contenant les arguments passés en ligne de commande
 * @return 0 si le programme s'est exécuté avec succès, une valeur différente de zéro sinon.
 */
int main(int argc, char *argv[]) {
    struct Matrice matrice;
    memset(&matrice, 0, sizeof(matrice));

    // Vérification que le nom du fichier est fourni en argument
    if (argc > 2) {
        printf("trop d'argument\n");
        return 1;
    }
    FILE *fichier = fopen(argv[1], "r");

    if(fichier == NULL){
        printf("fichier manquant\n");
        return 1;
    }
    initialiser_Matrice(&matrice, fichier);

    initialiser_Mots(&matrice, fichier);

    recherche(&matrice);

    tester_Affichage(&matrice);

    // tester_Affichage_Matrice(&matrice);

    // tester_Affichage_Mots(&matrice);

    fclose(fichier);

    return 0;
}

/*
    Projet : Travail pratique 1 "Chemin de Dyck"
    Objectif : permettre la saisie de mots de Dyck en entrée et de dessiner 
            le chemin correspondant. La lecture de l'entrée sera réalisée 
            depuis l'entrée standard (stdin), tandis que le résultat sera 
            affiché sur la sortie standard (stdout). 

    2023 Tous droits réservés, Kevin Da Silva (DASK30049905)
*/

/* Bibliothèque d'entrées/sorties standard */
#include <stdio.h>
/* Bibliothèque d'appels système et de gestion des processus */
#include <unistd.h>
/* Bibliothèque standard de fonctions générales */
#include <stdlib.h>
/* Bibliothèque de fonctions de manipulation de chaînes de caractères */
#include <string.h>
/* Bibliothèque de fonctions de manipulation de caractères */
#include <ctype.h>
/* Bibliothèque pour le type booléen */
#include <stdbool.h>

#define TAILLE_MOT 40
#define USAGE "\
Usage: %s [HEIGHT,AREA] <LETTER 1> <LETTER 2> <WORD>\n\
\n\
Draws on an ASCII path of dycks word. The dycks word is provided on stdin and\n\
the result is printed on stdout. The length of the word must not exceed 40 characters.\n\
\n\
If no argument is provided, the program prints this help and exit.\n\
\n\
Program parameters :\n\
  HEIGHT                    Optional parameter to calculate the height of the\n\
                            path under the word of dyck.\n\
  AREA                      Optional parameter to calculate the height of\n\
                            the path under the word of dyck.\n\
  LETTER 1, LETTER 2        Define the alphabet of the word.\n\
  WORD                      Word of dyck to draw.\n\
  "

/**
 * @struct motDeDyck
 * @brief Structure représentant un mot de Dyck
 */
struct motDeDyck {
    char mot[TAILLE_MOT];   //Le mot saisi
    char haut;              //Caractere ascendant
    char bas;               //Caractere descendant
};

/**
 * @enum error
 * @brief Énumération des messages d'erreurs
 */
enum error {
    OK                          = 0,
    ERREUR_ARGUMENTS_INVALIDES  = 1,
    ERREUR_DONNEES_INVALIDES    = 2,
    ERREUR_MOT_TROP_LONG        = 3,
    ERREUR_LETTRE_INTERDITE     = 4,
    ERREUR_MOT_NON_EQUILIBRE    = 5
};

/**
 * @brief Affiche un message d'erreur correspondant au code d'erreur spécifié, puis termine le programme.
 * @param numError Le code d'erreur à traiter.
 * 
 * Cette fonction affiche un message d'erreur sur la sortie d'erreur standard (stderr) en fonction du code d'erreur spécifié.
 * Ensuite, elle termine le programme en utilisant le code d'erreur comme code de sortie.
 */
void error_msg(enum error numError){
    switch (numError)
    {
    case ERREUR_ARGUMENTS_INVALIDES:
        fprintf(stderr, "argument invalide\n");
        break;
    case ERREUR_DONNEES_INVALIDES:
        fprintf(stderr, "donnees invalides\n");
        break;
    case ERREUR_MOT_TROP_LONG:
        fprintf(stderr, "mot trop long\n");
        break;
    case ERREUR_LETTRE_INTERDITE:
        fprintf(stderr, "lettre interdite\n");
        break;
    case ERREUR_MOT_NON_EQUILIBRE:
        fprintf(stderr, "mot non equilibre\n");
        break;
    default:
        fprintf(stderr, "erreur inconnue\n");
        break;
    }
    exit(numError);
}


/**
 * @brief Convertit une chaîne de caractères en minuscules.
 * @param mot Un pointeur vers un pointeur de caractères représentant la chaîne à convertir.
 * @return Un pointeur vers la chaîne convertie en minuscules.
 * 
 */
char* convert_Minuscule(char **mot){

    for (int i = 0; mot[0][i] != '\0'; i++) {
        mot[0][i] = tolower(mot[0][i]);
    }
    return mot[0];
}


/**
 * @brief Vérifie et retourne le caractère unique d'un mot.
 * @param mot La chaîne de caractères à vérifier.
 * @return Le caractère unique du mot.
 * @throws ERREUR_DONNEES_INVALIDES si la longueur du mot est différente de 1, ou si le mot est NULL ou vide.
 * 
 * Cette fonction vérifie la validité d'un mot en s'assurant qu'il contient un seul caractère. 
 * Si la longueur du mot n'est pas égale à 1, ou si le mot est NULL ou vide, une erreur ERREUR_DONNEES_INVALIDES est générée à l'aide de la fonction error_msg().
 * Sinon, elle retourne le caractère unique du mot.
 */
char verif_Haut_Bas(char* mot){
    size_t longueur = strlen(mot);
    if(longueur != 1 || mot == NULL || mot[0] == '\0'){
        error_msg(ERREUR_DONNEES_INVALIDES);
    }
    return mot[0];
}

/**
 * @brief Vérifie et stocke un mot dans une structure motDeDyck.
 * @param motDeDyck Un pointeur vers une structure motDeDyck.
 * @param verifM La chaîne de caractères à vérifier et stocker.
 * @param option Une option pour le traitement du mot (à adapter en fonction de votre utilisation).
 * @throws ERREUR_ARGUMENTS_INVALIDES si le dernier caractère de verifM n'est ni égal à motDeDyck->bas ni à motDeDyck->haut.
 * @throws ERREUR_MOT_TROP_LONG si le nombre total de caractères du mot dépasse la limite maxMot.
 * @throws ERREUR_ARGUMENTS_INVALIDES si le nombre total de caractères du mot et des arguments dépasse la limite maxTotal.
 * 
 * Cette fonction vérifie un mot et le stocke dans une structure motDeDyck. 
 * Elle effectue les vérifications suivantes :
 * - Compte le nombre d'occurrences des lettres bas et haut dans le mot.
 * - Stocke chaque caractère de verifM dans le tableau motDeDyck->mot.
 * - Calcule le nombre total de caractères du mot (compteLettre1 + compteLettre2).
 * - Ajoute l'option spécifiée au nombre d'arguments (nbArg + option).
 * - Calcule le nombre total de caractères du mot et des arguments (totalCaracMot + nbArg).
 */
void verif_Mot(struct motDeDyck *motDeDyck,char *verifM, int option){
    int longueur = strlen(verifM);
    int compteLettre1 = 0;
    int compteLettre2 = 0;
    int maxTotal = 100;
    int maxMot = 40;
    int nbArg = 2;
    int totalCaracMot = 0;
    int totalCaracArg = 0;

    for (int i = 0; i < longueur; i++) {
        if (verifM[i] == motDeDyck->bas) {
            compteLettre1++;
        } else if (verifM[i] == motDeDyck->haut) {
            compteLettre2++;
        }
        motDeDyck->mot[i] = verifM[i];
    }
    totalCaracMot = compteLettre1 + compteLettre2;
    nbArg = nbArg + option;
    totalCaracArg = totalCaracMot + nbArg;
    if(!(verifM[totalCaracMot - 1] == motDeDyck->bas || verifM[totalCaracMot - 1] == motDeDyck->haut)){
        error_msg(ERREUR_ARGUMENTS_INVALIDES);
    } else if (totalCaracMot > maxMot ){
        error_msg(ERREUR_MOT_TROP_LONG);
    } else if ( totalCaracArg > maxTotal ){
        error_msg(ERREUR_ARGUMENTS_INVALIDES);
    }
}

/**
 * @brief Calcule la hauteur maximale entre la position actuelle et la hauteur donnée.
 * @param position La position actuelle.
 * @param hauteur La hauteur donnée.
 * @return La hauteur maximale entre la position actuelle et la hauteur donnée.
 * 
 * Cette fonction compare la position actuelle avec la hauteur donnée et retourne la valeur la plus élevée.
 * Elle est utilisée pour déterminer la hauteur maximale atteinte lors du parcours d'une structure de données.
 */
int calcul_Hauteur(int position, int hauteur){
    if(position > hauteur){
        hauteur = position;
    }
    return hauteur;
}


/**
 * @brief Calcule et affiche le graphe correspondant au mot de Dyck donné.
 * @param motDeDyck Un pointeur vers une structure contenant le mot de Dyck et ses caractères haut et bas.
 * @param longueur La longueur du mot de Dyck.
 * @param option L'option de calcul du graphe : 0 pour normal, 4 pour l'aire, 7 pour la hauteur.
 * 
 * Cette fonction calcule le graphe correspondant au mot de Dyck donné et l'affiche. Le graphe est représenté
 * sous forme de caractères '/' et '\' pour les caractères haut et bas respectivement. Le graphe est affiché
 * selon l'option choisie : option 0 pour le graphe normal, option 4 pour afficher l'aire du graphe, et option 7
 * pour afficher la hauteur du graphe. En cas de mot de Dyck non équilibré ou de lettre interdite, une erreur est
 * affichée.
 */
void calcul_Graphe(struct motDeDyck *motDeDyck, int longueur, int option){
    int position = 0;
    int hauteur = 0;
    double aire = 0;
    int positionMax = 0;
    char canvasGraphe[40][20];

    memset(canvasGraphe,'*',sizeof(canvasGraphe));
    
    for (int i = 0; i < longueur; i++)
    {
        if(motDeDyck->haut == motDeDyck->mot[i]){
            canvasGraphe[i][position] = '/';
            position++;
            hauteur = calcul_Hauteur(position, hauteur);
            aire = aire + position - 0.5;
        } else if(motDeDyck->bas == motDeDyck->mot[i]){
            position--;
            canvasGraphe[i][position] = '\\';
            aire = aire + position + 0.5;
        }
        if (positionMax < position)
        {
            positionMax = position;
        }
        if(position < 0){
            error_msg(ERREUR_MOT_NON_EQUILIBRE);
        }
    }
    if (position != 0){
        error_msg(ERREUR_MOT_NON_EQUILIBRE);
    } else if (motDeDyck->mot[longueur-1] == ' ' || motDeDyck->mot[longueur-1] == '\t' ||motDeDyck->mot[longueur-1] == '\n'){
        if (motDeDyck->haut != motDeDyck->mot[longueur-2] && motDeDyck->bas != motDeDyck->mot[longueur-2]){
        
        error_msg(ERREUR_LETTRE_INTERDITE);
        }
    }else if (motDeDyck->haut != motDeDyck->mot[longueur-1] && motDeDyck->bas != motDeDyck->mot[longueur-1]){
        
        error_msg(ERREUR_LETTRE_INTERDITE);
    }
    if (option == 4 ){
        printf("%d\n", (int)aire);
        exit (0);
    } else if (option == 7){
        printf("%d\n", hauteur);
        exit (0);
    } else {
        for (int i = positionMax - 1; i > -1; i--){
            for (int j = 0; j < longueur; j++){
                printf("%c", canvasGraphe[j][i]);
            }
            printf("\n");
        }
    }
}

/**
 * @brief Effectue le choix de l'option et exécute les étapes correspondantes.
 * @param motDeDyck Un pointeur vers une structure contenant le mot de Dyck et ses caractères haut et bas.
 * @param mot Un tableau de chaînes de caractères contenant les arguments passés au programme.
 * 
 * Cette fonction effectue le choix de l'option en fonction du premier argument `mot[0]` et exécute les étapes
 * correspondantes. Si `mot[0]` est différent de "aire" et "hauteur", la fonction vérifie la validité des données
 * et exécute les étapes normales. Sinon, si `mot[0]` est "aire", l'option est définie à 4 et le graphe est calculé
 * et affiché avec l'aire du graphe. Si `mot[0]` est "hauteur", l'option est définie à 7 et le graphe est calculé
 * et affiché avec la hauteur du graphe. En cas de données invalides, une erreur est affichée.
 */
void choix_Option(struct motDeDyck *motDeDyck, char **mot){
    int option = 0;
    int tailleMot = strlen(mot[3]);

    
    
    if(!(strcmp(mot[0], " ") == 0)){
        int longueur = strlen(mot[0]);

        if(strcmp(mot[0], "aire") == 0){
            option = 4;
            motDeDyck->haut = verif_Haut_Bas(mot[1]);
            motDeDyck->bas = verif_Haut_Bas(mot[2]);

            verif_Mot(motDeDyck, mot[3], option);
            calcul_Graphe(motDeDyck, tailleMot, option);
        } else if (strcmp(mot[0], "hauteur") == 0){
            option = 7;
            motDeDyck->haut = verif_Haut_Bas(mot[1]);
            motDeDyck->bas = verif_Haut_Bas(mot[2]);

            verif_Mot(motDeDyck, mot[3], option);
            calcul_Graphe(motDeDyck, tailleMot, option);
        } else if ((longueur != 1) || (mot[3] != NULL)){
            error_msg(ERREUR_DONNEES_INVALIDES);
        }
    } else {
        motDeDyck->haut = verif_Haut_Bas(mot[1]);
        motDeDyck->bas = verif_Haut_Bas(mot[2]);
        
        verif_Mot(motDeDyck, mot[3], option);
        calcul_Graphe(motDeDyck, tailleMot, option);
    }
}

/**
 * @brief Supprime les espaces et les tabulations redondants dans une ligne donnée.
 * @param ligne La ligne de caractères à modifier.
 * 
 * Cette fonction supprime les espaces et les tabulations redondants dans la chaîne de caractères `ligne`.
 * Les espaces et les tabulations consécutifs sont remplacés par un seul espace. La fonction modifie directement
 * la chaîne `ligne` passée en paramètre.
 */
void supp_Espace_Tab(char *ligne) {
    int longueur = strlen(ligne);
    int i, j = 0;
    bool espacePrecedent = false;
    char verifLigne[longueur];

    for (i = 0; i < longueur; i++) {
        if (ligne[i] == ' ' || ligne[i] == '\t') {
            if (!espacePrecedent) {
                verifLigne[j] = ' ';
                j++;
                espacePrecedent = true;
            }
        } else {
            verifLigne[j] = ligne[i];
            j++;
            espacePrecedent = false;
        }
    }

    if (j > 0 && verifLigne[j - 1] == ' ') {
        verifLigne[j - 1] = '\0';
    } else {
        verifLigne[j] = '\0';
    }
    strcpy(ligne, verifLigne);
}

/**
 * @brief Lit un fichier et effectue une action en fonction des données extraites.
 * @param motDeDyck Pointeur vers la structure motDeDyck pour stocker les informations.
 * @param nom_fichier Le nom du fichier à lire.
 * @param action L'action à effectuer (4 pour l'aire, 7 pour la hauteur, autre pour normal).
 * 
 * Cette fonction lit le fichier spécifié par `nom_fichier` et effectue une action en fonction des données extraites.
 * Elle utilise la structure motDeDyck pour stocker les informations nécessaires. L'action à effectuer est déterminée
 * par le paramètre `action`, où 4 correspond à l'aire, 7 correspond à la hauteur et toute autre valeur correspond à une action normale.
 * Les mots extraits du fichier sont stockés dans le tableau `mot`, et la fonction `choix_Option` est appelée pour effectuer
 * l'action correspondante.
 */
void scan_fichier(struct motDeDyck *motDeDyck, const char *nom_fichier, int action) {
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        error_msg(ERREUR_DONNEES_INVALIDES);
    }

    char *mot[5]; 
    int nombre_mots = 0;
    char ligne[256];
    char* verif; 
    char* motConverti[2];

    fgets(ligne, sizeof(ligne), stdin);
    supp_Espace_Tab(&ligne);
    motConverti[0] = strtok(ligne, " ");
    motConverti[0] = convert_Minuscule(motConverti);
    if((strcmp(motConverti[0], "aire") == 0) || (strcmp(motConverti[0], "hauteur") == 0)){
        
        mot[nombre_mots++] = motConverti[0];
    } else if (action == 4){
        mot[nombre_mots++] = "aire";
        mot[nombre_mots++] = motConverti[0];
    } else if (action == 7){
        mot[nombre_mots++] = "hauteur";
        mot[nombre_mots++] = motConverti[0];
    } else {
        mot[nombre_mots++] = " ";
        mot[nombre_mots++] = motConverti[0];
    }
    
    for (nombre_mots = nombre_mots; nombre_mots < 4; nombre_mots++) {
        
        mot[nombre_mots] = strtok(NULL, " ");
        
        if(mot[nombre_mots] == NULL){
            error_msg(ERREUR_DONNEES_INVALIDES);
        }
    }

    if((verif = strtok(NULL, " ")) != NULL){
        error_msg(ERREUR_DONNEES_INVALIDES);
    }


    choix_Option(motDeDyck, mot);

    fclose(fichier);
}

/**
 * @brief Fonction principale du programme.
 * @param argc Le nombre d'arguments passés en ligne de commande.
 * @param argv Un tableau de pointeurs vers les arguments passés en ligne de commande.
 * @return 0 si le programme s'exécute avec succès.
 * 
 * Cette fonction est la fonction principale du programme. Elle traite les arguments passés en ligne de commande et
 * appelle les fonctions correspondantes pour effectuer les actions requises. La structure motDeDyck est utilisée pour
 * stocker les informations nécessaires. Les actions sont déterminées en fonction des arguments et des options spécifiées.
 * Le programme peut également lire les données à partir d'un fichier si la redirection d'entrée est utilisée.
 */
int main(int argc, char *argv[]) {

    struct motDeDyck motDeDyck;
    char *mot[5];
    
    for (int i = 0; i < argc; ++i) {

        if (!isatty(STDIN_FILENO)) {
            if (argc == 1){
                scan_fichier(&motDeDyck, argv[0], 0);
            } else if(argc == 2){
                if(strcmp(argv[1], "aire") == 0 ){
                    scan_fichier(&motDeDyck, argv[0], 4);
                }else if(strcmp(argv[1], "hauteur") == 0 ){
                    scan_fichier(&motDeDyck, argv[0], 7);
                } else {
                    error_msg(ERREUR_ARGUMENTS_INVALIDES);
                }
            } else {
                error_msg(ERREUR_ARGUMENTS_INVALIDES);
            }
        } else if (argc == 1){
            printf(USAGE, argv[0]);
        } else if (argc == 3){
            for (int i = 1; i <= 3; i++) {
                mot[i] = argv[i];
            }
            choix_Option(&motDeDyck, mot);

        } else if (argc == 4){
            for (int i = 0; i < 4; i++) {
                mot[i] = argv[i + 1];
            }
            choix_Option(&motDeDyck, mot);

        } else {
            error_msg(ERREUR_DONNEES_INVALIDES);
        }

    }

    return 0;
}

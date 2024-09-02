#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// voir explication motcache.c
struct Matrice {
   char donnees[12][12];
   int nb_mots;
   char mots[100][13];
   int trouver[12][12];
};

// voir explication motcache.c
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

// voir explication motcache.c
void initialiser_Mots(struct Matrice *matrice, FILE *fichier) {
   while (fgets(matrice->mots[matrice->nb_mots], 13, fichier) != NULL) {
      matrice->mots[matrice->nb_mots][strcspn(matrice->mots[matrice->nb_mots], "\n")] = '\0';
      matrice->nb_mots++;
   }
}

// voir explication motcache.c
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

// voir explication motcache.c
void lecture_GD(struct Matrice *matrice, int lignes, int colonnes, char *mots, unsigned int i) {
   for (i = 0; i < strlen(mots); i++) {
      matrice->trouver[lignes + i][colonnes] = 1;
   }
}

void lecture_DG(struct Matrice *matrice, int lignes, int colonnes, char *mots, unsigned int i) {
   for (i = 0; i < strlen(mots); i++) {
      matrice->trouver[lignes - i][colonnes] = 1;
   }
}

void lecture_HB(struct Matrice *matrice, int lignes, int colonnes, char *mots, unsigned int i) {
   for (i = 0; i < strlen(mots); i++) {
      matrice->trouver[lignes][colonnes + i] = 1;
   }
}

void lecture_BH(struct Matrice *matrice, int lignes, int colonnes, char *mots, unsigned int i) {
   for (i = 0; i < strlen(mots); i++) {
      matrice->trouver[lignes][colonnes - i] = 1;
   }
}

// voir explication motcache.c
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

// voir explication motcache.c
void recherche(struct Matrice *matrice) {
   for (int i = 0; i < 12; ++i) {
      for (int j = 0; j < 12; ++j) {
         for (int k = 0; k < matrice->nb_mots; ++k) {
            for (int l = 0; l < 4; ++l) {
               if (recherche_Mots(matrice, i, j, matrice->mots[k], l)) {
                  mots_Trouver(matrice, i, j, matrice->mots[k], l);
                  break;
               }
            }
         }
      }
   }
}



// Cunit
void test_initialiser_Matrice(void) {
   struct Matrice reponse_matrice;
   FILE *fichier = fopen(argv[1], "r");
   initialiser_Matrice(&matrice, fichier);

   char test_A_Cunit[12][12]{
       {'A', 'M', 'E', 'T', 'T', 'E', 'N', 'I', 'R', 'A', 'L', 'C'},
       {'C', 'G', 'U', 'I', 'T', 'A', 'R', 'E', 'X', 'I', 'O', 'V'},
       {'C', 'A', 'S', 'O', 'O', 'E', 'M', 'A', 'T', 'M', 'A', 'T'},
       {'O', 'M', 'A', 'R', 'J', 'D', 'C', 'B', 'H', 'N', 'B', 'E'},
       {'R', 'U', 'X', 'G', 'N', 'R', 'L', 'U', 'A', 'E', 'A', 'N'},
       {'D', 'I', 'O', 'U', 'A', 'A', 'A', 'T', 'R', 'L', 'T', 'O'},
       {'E', 'N', 'P', 'E', 'B', 'B', 'V', 'F', 'P', 'A', 'T', 'H'},
       {'O', 'O', 'H', 'O', 'E', 'M', 'I', 'L', 'E', 'B', 'E', 'P'},
       {'N', 'M', 'O', 'N', 'R', 'O', 'E', 'U', 'D', 'M', 'R', 'O'},
       {'L', 'R', 'N', 'A', 'Y', 'B', 'R', 'T', 'O', 'Y', 'I', 'L'},
       {'O', 'A', 'E', 'I', 'L', 'L', 'I', 'E', 'N', 'C', 'E', 'Y'},
       {'S', 'H', 'E', 'P', 'O', 'L', 'O', 'C', 'C', 'I', 'P', 'X'}};

   char test_B_Cunit[12][12]{
       {'A', 'M', 'E', 'T', 'T', 'E', 'N', 'I', 'R', 'A', 'L', 'C'},
       {'C', 'G', 'U', 'I', 'T', 'A', 'R', 'E', 'X', 'I', 'O', 'V'},
       {'C', 'A', 'S', 'O', 'O', 'E', 'M', 'A', 'T', 'M', 'A', 'T'},
       {'O', 'M', 'A', 'R', 'J', 'D', 'C', 'B', 'H', 'N', 'B', 'E'},
       {'R', 'U', 'X', 'G', 'N', 'R', 'L', 'U', 'A', 'E', 'A', 'N'},
       {'D', 'I', 'O', 'U', 'A', 'A', 'A', 'T', 'R', 'L', 'T', 'O'},
       {'E', 'N', 'P', 'E', 'B', 'B', 'V', 'F', 'P', 'A', 'T', 'H'},
       {'O', 'O', 'H', 'O', 'E', 'M', 'I', 'L', 'E', 'B', 'E', 'P'},
       {'N', 'M', 'O', 'N', 'R', 'O', 'E', 'U', 'D', 'M', 'R', 'O'},
       {'L', 'R', 'N', 'A', 'Y', 'B', 'R', 'T', 'O', 'Y', 'I', 'L'},
       {'O', 'A', 'E', 'I', 'L', 'L', 'I', 'E', 'N', 'C', 'E', 'Y'},
       {'S', 'H', 'E', 'P', 'O', 'L', 'O', 'C', 'C', 'I', 'P', 'X'}};

   char test_C_Cunit[12][12]{
       {'A', 'M', 'E', 'T', 'T', 'E', 'N', 'I', 'R', 'A', 'L', 'C'},
       {'C', 'G', 'U', 'I', 'T', 'A', 'R', 'E', 'X', 'I', 'O', 'V'},
       {'C', 'A', 'S', 'O', 'O', 'E', 'M', 'A', 'T', 'M', 'A', 'T'},
       {'O', 'M', 'A', 'R', 'J', 'D', 'C', 'B', 'H', 'N', 'B', 'E'},
       {'R', 'U', 'X', 'G', 'N', 'R', 'L', 'U', 'A', 'E', 'A', 'N'},
       {'D', 'I', 'O', 'U', 'A', 'A', 'A', 'T', 'R', 'L', 'T', 'O'},
       {'E', 'N', 'P', 'E', 'B', 'B', 'V', 'F', 'P', 'A', 'T', 'H'},
       {'O', 'O', 'H', 'O', 'E', 'M', 'I', 'L', 'E', 'B', 'E', 'P'},
       {'N', 'M', 'O', 'N', 'R', 'O', 'E', 'U', 'D', 'M', 'R', 'O'},
       {'L', 'R', 'N', 'A', 'Y', 'B', 'R', 'T', 'O', 'Y', 'I', 'L'},
       {'O', 'A', 'E', 'I', 'L', 'L', 'I', 'E', 'N', 'C', 'E', 'Y'},
       {'S', 'H', 'E', 'P', 'O', 'L', 'O', 'C', 'C', 'I', 'P', 'X'}};

   char test_D_Cunit[12][12]{
       {'A', 'M', 'E', 'T', 'T', 'E', 'N', 'I', 'R', 'A', 'L', 'C'},
       {'C', 'G', 'U', 'I', 'T', 'A', 'R', 'E', 'X', 'I', 'O', 'V'},
       {'C', 'A', 'S', 'O', 'O', 'E', 'M', 'A', 'T', 'M', 'A', 'T'},
       {'O', 'M', 'A', 'R', 'J', 'D', 'C', 'B', 'H', 'N', 'B', 'E'},
       {'R', 'U', 'X', 'G', 'N', 'R', 'L', 'U', 'A', 'E', 'A', 'N'},
       {'D', 'I', 'O', 'U', 'A', 'A', 'A', 'T', 'R', 'L', 'T', 'O'},
       {'E', 'N', 'P', 'E', 'B', 'B', 'V', 'F', 'P', 'A', 'T', 'H'},
       {'O', 'O', 'H', 'O', 'E', 'M', 'I', 'L', 'E', 'B', 'E', 'P'},
       {'N', 'M', 'O', 'N', 'R', 'O', 'E', 'U', 'D', 'M', 'R', 'O'},
       {'L', 'R', 'N', 'A', 'Y', 'B', 'R', 'T', 'O', 'Y', 'I', 'L'},
       {'O', 'A', 'E', 'I', 'L', 'L', 'I', 'E', 'N', 'C', 'E', 'Y'},
       {'S', 'H', 'E', 'P', 'O', 'L', 'O', 'C', 'C', 'I', 'P', 'X'}};

   char test_E_Cunit[12][12]{
       {'A', 'M', 'E', 'T', 'T', 'E', 'N', 'I', 'R', 'A', 'L', 'C'},
       {'C', 'G', 'U', 'I', 'T', 'A', 'R', 'E', 'X', 'I', 'O', 'V'},
       {'C', 'A', 'S', 'O', 'O', 'E', 'M', 'A', 'T', 'M', 'A', 'T'},
       {'O', 'M', 'A', 'R', 'J', 'D', 'C', 'B', 'H', 'N', 'B', 'E'},
       {'R', 'U', 'X', 'G', 'N', 'R', 'L', 'U', 'A', 'E', 'A', 'N'},
       {'D', 'I', 'O', 'U', 'A', 'A', 'A', 'T', 'R', 'L', 'T', 'O'},
       {'E', 'N', 'P', 'E', 'B', 'B', 'V', 'F', 'P', 'A', 'T', 'H'},
       {'O', 'O', 'H', 'O', 'E', 'M', 'I', 'L', 'E', 'B', 'E', 'P'},
       {'N', 'M', 'O', 'N', 'R', 'O', 'E', 'U', 'D', 'M', 'R', 'O'},
       {'L', 'R', 'N', 'A', 'Y', 'B', 'R', 'T', 'O', 'Y', 'I', 'L'},
       {'O', 'A', 'E', 'I', 'L', 'L', 'I', 'E', 'N', 'C', 'E', 'Y'},
       {'S', 'H', 'E', 'P', 'O', 'L', 'O', 'C', 'C', 'I', 'P', 'X'}};

   for (size_t i = 0; i < 12; i++) {
      for (size_t j = 0; j < 12; j++) {
         CU_ASSERT((reponse_matrice->donnees[i][j] == test_A_Cunit[i][j]) 
         || (reponse_matrice->donnees[i][j] == test_B_Cunit[i][j]) 
         || (reponse_matrice->donnees[i][j] == test_C_Cunit[i][j]) 
         || (reponse_matrice->donnees[i][j] == test_D_Cunit[i][j]) 
         || (reponse_matrice->donnees[i][j] == test_E_Cunit[i][j]));
      }
   }

   fclose(fichier);
}

void teste_Matrice_Numerique(void) {
   struct Matrice reponse_numerique;
   FILE *fichier = fopen(argv[1], "r");

   int test_A_Cunit[12][12]{
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

   int test_B_Cunit[12][12]{
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

   int test_C_Cunit[12][12]{
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

   int test_D_Cunit[12][12]{
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

   int test_E_Cunit[12][12]{
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

   for (int i = 0; i < 12; ++i) {
      for (int j = 0; j < 12; ++j) {
         CU_ASSERT((reponse_numerique->trouver[i][j] == test_A_Cunit[i][j]) 
         || (reponse_numerique->trouver[i][j] == test_B_Cunit[i][j]) 
         || (reponse_numerique->trouver[i][j] == test_C_Cunit[i][j]) 
         || (reponse_numerique->trouver[i][j] == test_D_Cunit[i][j]) 
         || (reponse_numerique->trouver[i][j] == test_E_Cunit[i][j]));
      }
   }
}

fclose(fichier);
}

void teste_mots(void) {
   struct Matrice reponse_mots;
   FILE *fichier = fopen(argv[1], "r");

   char test_A_Cunit[12]{
       {"ALBA"},
       {"ASSISE"},
       {"ASTI"},
       {"BARI"},
       {"BERGAME"},
       {"BRA"},
       {"COME"},
       {"FLORENCE"},
       {"GELA"},
       {"GENES"},
       {"IMOLA"},
       {"LASPEZIA"},
       {"LIVOURNE"},
       {"MILAN"},
       {"NAPLES"},
       {"PADOUE"},
       {"PALERME"},
       {"PARME"},
       {"PISE"},
       {"RHO"},
       {"RIMINI"},
       {"RIVOLI"},
       {"ROME"},
       {"SIENNE"},
       {"TERNI"},
       {"TURIN"}};

   char test_B_Cunit[12]{
       {"ASTRONAUTE"},
       {"EPERVIER"},
       {"ROMANESQUE"},
       {"TALENTUEUSES"},
       {"BOURREAUX"},
       {"OUVRIERE"},
       {"ARMEE"},
       {"LOISIRS"},
       {"PELLERIN"},
       {"SAUTE"},
       {"CADENAS"},
       {"CHAROGNE"},
       {"SOL"},
       {"EUCHARISTIE"},
       {"XENOPHILE"},
       {"RAMIFIER"},
       {"BINERIE"},
       {"ESCRIME"},
       {"RISTOURNE"},
       {"RUEE"}};

   char test_C_Cunit[12]{
       {"ACCORDEON"},
       {"BANJO"},
       {"BATTERIE"},
       {"BOMBARDE"},
       {"CLARINETTE"},
       {"CLAVIER"},
       {"CYMBALE"},
       {"FLUTE"},
       {"GUITARE"},
       {"HARMONIUM"},
       {"HARPE"},
       {"LYRE"},
       {"ORGUE"},
       {"PIANO"},
       {"PICCOLO"},
       {"SAXOPHONE"},
       {"SOL"},
       {"TAMTAM"},
       {"TUBA"},
       {"VOIX"},
       {"XYLOPHONE"}};

   char test_D_Cunit[12]{
       {"PLANTE"},
       {"MERCREDI"},
       {"PARCOURS"},
       {"MANGA"},
       {"LIT"},
       {"LA"},
       {"TEMPERATURE"},
       {"ELEPHANT"},
       {"CULTURE"},
       {"NOISIVER"},
       {"RIE"},
       {"APPORTER"},
       {"LONGTEMPS"},
       {"PLOMBIER"},
       {"ABANDONNER"},
       {"ACCIDENTELLE"},
       {"JOINTURE"}};

   char test_E_Cunit[12]{
       {"QUEBEC"},
       {"LIBRE"},
       {"SOUVERAIN"},
       {"TENTE"},
       {"RESOUT"},
       {"TRAVERSIER"},
       {"MONOCHROME"},
       {"ESTUAIRE"},
       {"QUESTIONS"},
       {"MOUTARDE"},
       {"VALVE"},
       {"TRADUIRE"},
       {"ACCIDENT"},
       {"EVACHEE"},
       {"SEINE"},
       {"IONS"},
       {"LUNE"},
       {"QUEL"},
       {"DICTION"},
       {"CHASSE"},
       {"TRUITE"},
       {"ARME"},
       {"REFERENT"},
       {"CRUEL"},
       {"IVROGNE"},
       {"REER"},
       {"REZ"},
       {"MUNI"}};

   for (int i = 0; i < matrice->nb_mots; ++i) {
      CU_ASSERT((reponse_mots->mots[i] == test_A_Cunit) 
      || (reponse_mots->mots[i] == test_B_Cunit) 
      || (reponse_mots->mots[i] == test_C_Cunit) 
      || (reponse_mots->mots[i] == test_D_Cunit) 
      || (reponse_mots->mots[i] == test_E_Cunit));
   }
   fclose(fichier);
}

int main(int argc, char const *argv[]) {
   CU_pSuite motcache = NULL;
   if (CUE_SUCCESS != CU_initialize_registry()) {
      return CU_get_error();
   }
   motcache = CU_add_suite("suite_test", NULL, NULL);
   if (motcache == NULL) {
      CU_cleanup_registry();
      return CU_get_error();
   }
   if (NULL == CU_add_test(motcache, "test_initialiser_Matrice", test_initialiser_Matrice)) {
      CU_cleanup_registry();
      return CU_get_error();
   }
   if (NULL == CU_add_test(motcache, "teste_Matrice_Numerique", teste_Matrice_Numerique)) {
      CU_cleanup_registry();
      return CU_get_error();
   }
   if (NULL == CU_add_test(motcache, "teste_mots", teste_mots)) {
      CU_cleanup_registry();
      return CU_get_error();
   }
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
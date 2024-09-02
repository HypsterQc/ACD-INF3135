#ifndef BATAILLE_NAVALE_C
#define BATAILLE_NAVALE_C

#include "../include/bataille_navale.h"

/**
 * Initialise le générateur de nombres aléatoires.
 */
void init_nb_aleatoire()
{
   srand(time(NULL));
}

/**
 * Génère un nombre aléatoire entre 0 et max.
 *
 * @param max Valeur maximale (non incluse)
 * @return Nombre aléatoire généré
 */
int nb_aleatoire(int max)
{
   return (rand() % max);
}

/**
 * Alloue de la mémoire en vérifiant les erreurs.
 *
 * @param taille Taille de la mémoire à allouer
 * @return Pointeur vers la mémoire allouée
 */
void *allouer_memoire(size_t taille)
{
   void *ptr = malloc(taille);
   if (ptr == NULL)
   {
      perror("Impossible d'allouer de la mémoire");
      exit(EXIT_FAILURE);
   }
   return ptr;
}

/**
 * Crée une grille de jeu avec une taille donnée et une valeur de remplissage.
 *
 * @param taille Taille de la grille
 * @param remplissage Valeur de remplissage
 * @return Pointeur vers la grille de jeu créée
 */
GrilleJeu *creer_grille(int taille, char remplissage)
{
   GrilleJeu *grille = allouer_memoire(sizeof(GrilleJeu));

   grille->taille_plateau = taille;
   grille->cases = allouer_memoire(taille * sizeof(Case *));
   grille->navires = allouer_memoire(5 * sizeof(Navire *)); 

   grille->nb_bateaux_non_coules = 0;

   for (int i = 0; i < taille; i++)
   {
      grille->cases[i] = allouer_memoire(taille * sizeof(Case));
      for (int j = 0; j < taille; j++)
      {
         grille->cases[i][j].x = i;
         grille->cases[i][j].y = j;
         grille->cases[i][j].valeur = remplissage;
      }
   }

   return grille;
}

/**
 * Crée un navire avec une taille donnée et un nom.
 *
 * @param taille Taille du navire
 * @param nom Nom du navire
 * @return Pointeur vers le navire créé
 */
Navire *creer_navire(int taille, char *nom)
{
   Navire *navire = (Navire *)allouer_memoire(sizeof(Navire));
   navire->taille = taille;
   navire->nom = nom;
   navire->sante = taille;
   return navire;
}

/**
 * Vérifie si un placement de navire est valide dans la grille.
 *
 * @param grille Grille de jeu
 * @param navire Navire à placer
 * @return 1 si le placement est valide, 0 sinon
 */
int est_placement_valide(GrilleJeu *grille, Navire *navire)
{
   int dx = 0;
   int dy = 0;
   int x = 0;
   int y = 0;
   switch (navire->sens)
   {
   case 0:
      dx = 1;
      break;
   case 1:
      dy = 1;
      break;
   case 2:
      dx = -1;
      break;
   case 3:
      dy = -1;
      break;
   }
   for (int i = 0; i < navire->taille; i++)
   {
      x = navire->premiere_case.x + i * dx;
      y = navire->premiere_case.y + i * dy;
      if (x < 0 || x >= grille->taille_plateau || y < 0 || y >= grille->taille_plateau || grille->cases[x][y].valeur != '.')
      {
         return 0;
      }
   }
   return 1;
}

/**
 * Valide les informations d'un navire pour une case donnée.
 *
 * @param navire Navire à valider
 * @param x Coordonnée x de la case
 * @param y Coordonnée y de la case
 * @return 1 si les informations du navire sont valides, 0 sinon
 */
int valider_info_navire(Navire *navire, int x, int y)
{
   int valide = 1;
   if (navire == NULL || navire->nom == NULL ||
       navire->sante <= 0 || x < navire->premiere_case.x || x >= navire->premiere_case.x + navire->taille ||
       y < navire->premiere_case.y || y >= navire->premiere_case.y + navire->taille)
   {
      valide = 0;
   }
   return valide;
}

/**
 * Génère des coordonnées aléatoires pour placer un navire dans la grille.
 *
 * @param grille Grille de jeu
 * @param navire Navire à placer
 * @param x Pointeur vers la coordonnée x générée
 * @param y Pointeur vers la coordonnée y générée
 */
void generer_coordonnees(GrilleJeu *grille, Navire *navire, int *x, int *y)
{
   if (navire->sens == 0)
   {
      *x = nb_aleatoire(grille->taille_plateau - navire->taille);
      *y = nb_aleatoire(grille->taille_plateau);
   }
   else if (navire->sens == 1)
   {
      *x = nb_aleatoire(grille->taille_plateau);
      *y = nb_aleatoire(grille->taille_plateau - navire->taille);
   }
   else
   {
      *x = nb_aleatoire(grille->taille_plateau);
      *y = nb_aleatoire(grille->taille_plateau);
   }
}

/**
 * Place un navire dans la grille.
 *
 * @param grille Grille de jeu
 * @param navire Navire à placer
 * @param c Valeur du navire dans la grille
 */
void placer_navire(GrilleJeu *grille, Navire *navire, char c)
{
   // On suppose que navire->sens est toujours compris entre 0 et 3
   int dx[4] = {1, 0, -1, 0};
   int dy[4] = {0, 1, 0, -1};
   int placement_reussi;

   do
   {
      placement_reussi = 1;
      navire->sens = nb_aleatoire(4);

      int x = 0;
      int y = 0;
      generer_coordonnees(grille, navire, &x, &y);

      navire->premiere_case.x = x;
      navire->premiere_case.y = y;

      for (int i = 0; i < navire->taille; i++)
      {
         // Vérifier s'il y a un chevauchement avec un autre navire
         if (grille->cases[x][y].valeur != '0')
         {
            placement_reussi = 0;
            break;
         }
         x += dx[navire->sens];
         y += dy[navire->sens];
      }
   } while (!placement_reussi);

   // réussi alors placer le navire
   int x = navire->premiere_case.x;
   int y = navire->premiere_case.y;
   for (int i = 0; i < navire->taille; i++)
   {
      grille->cases[x][y].valeur = c;
      x += dx[navire->sens];
      y += dy[navire->sens];
   }

   navire->sante = navire->taille;                  
   grille->nb_bateaux_non_coules += navire->taille; 
}

/**
 * Affiche la grille de jeu.
 *
 * @param grille Grille de jeu à afficher
 */
void afficher_grille(GrilleJeu *grille)
{
   for (int i = 0; i < grille->taille_plateau; i++)
   {
      for (int j = 0; j < grille->taille_plateau; j++)
      {
         printf("%c ", grille->cases[i][j].valeur);
      }
      printf("\n");
   }
}

/**
 * Joue une partie du jeu de bataille navale.
 *
 * @param grille1 Grille du joueur
 * @param grille2 Grille de l'adversaire
 * @param stats Statistiques de la partie
 * @param nom_fichier Nom du fichier de statistiques
 */
void jouer_partie(GrilleJeu *grille1, GrilleJeu *grille2, donner_stats stats, char *nom_fichier)
{
   afficher_grille(grille2);
   while (grille1->nb_bateaux_non_coules > 0)
   {
      printf("Entrez une case que vous souhaitez attaquer selon le format (x,y), la taille maximale est %d : ", grille1->taille_plateau);
      int x, y;
      scanf("%d,%d", &x, &y);

      if (x < 0 || x >= grille1->taille_plateau || y < 0 || y >= grille1->taille_plateau)
      {
         printf("Coordonnées invalides.\n");
         continue;
      }

      if (grille2->cases[x][y].valeur == 'O' || grille2->cases[x][y].valeur == 'X')
      {
         printf("Vous avez déjà joué ce coup.\n");
         stats.nb_deja_joues_total++;
         continue;
      }

      stats.nb_total_coups++;

      switch (grille1->cases[x][y].valeur)
      {
      case '0':
         grille2->cases[x][y].valeur = 'O';
         printf("À l'eau !\n");
         stats.nb_misses_total++;
         break;
      case '1':
         for (int i = 0; i < 5; i++)
         {
            Navire *navire = grille1->navires[i];
            if (valider_info_navire(navire, x, y))
            {
               if (navire->sante > 0 &&
                   x >= navire->premiere_case.x && x < navire->premiere_case.x + navire->taille &&
                   y >= navire->premiere_case.y && y < navire->premiere_case.y + navire->taille)
               {
                  grille2->cases[x][y].valeur = 'X';
                  navire->sante--;
                  printf("Touché !\n");
                  stats.nb_touches_total++;
                  if (navire->sante == 0)
                  {
                     printf("Coulé %s !\n", navire->nom);
                     grille1->nb_bateaux_non_coules -= navire->taille;
                     stats.nom_dernier_navire_coule = navire->nom;
                  }
                  break;
               }
            }
         }
         break;
      }

      afficher_grille(grille2);
   }

   printf("Bravo !! Vous avez gagné en %d coups.\n", stats.nb_total_coups);

   if (nom_fichier != NULL)
   {
      ecrire_stats(nom_fichier, stats);
   }
}

/**
 * Libère la mémoire allouée pour la grille de jeu.
 *
 * @param grille Grille de jeu à libérer
 */
void detruire_grille(GrilleJeu *grille)
{
   for (int i = 0; i < grille->taille_plateau; i++)
   {
      free(grille->cases[i]);
   }
   free(grille->cases);

   for (int i = 0; i < 5; i++)
   {
      free(grille->navires[i]);
   }
   free(grille->navires);

   free(grille);
}

#endif
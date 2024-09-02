# TP2: Résolution de mots cachés"

## Description

Il sagis d'un logiciel qui effectue des mots meler. Le logiciel fonctionne a la console. 
recois en parametre un nom de fichier qui contient la grille de lettres ainsi que les mots a trouver.
lorsque le logiciel a trouvez tous les mots, il affiche la solution. 
C'est a dire le mots trouver a partir des lettre restante non utiliser dans la grille.
Ce travail est accompli pour le cours de construction et maintenance de logiciels, INF3135,
Gnagnely Serge Dogny, a l'Universite du Quebec a Montreal.

## Auteur

© 2023 Tous droits réservés, Kevin Da Silva (DASK30049905)

## Fonctionnement

Un fichier d'entrée vous sera fourni pour vos tests. Les 12 premières lignes du fichier contiendront les 12
lignes de la grille. Ensuite, le fichier contiendra une ligne vide et finalement la liste de mots à trouver.
Chaque mot sera sur une ligne différente.

Les lettres d'un mot peuvent apparaître à l'envers dans la grille. En réalité, quatre directions sont
possibles :

• de gauche à droite;
• de droite à gauche;
• de haut en bas;
• de bas en haut.

Les diagonales ne sont pas prises en considération dans ce jeu de mots cachés. Il est possible d'utiliser une même lettre de la grille pour former plusieurs mots différents. Une fois que tous les mots ont été identifiés, la réponse au mot caché est obtenue en affichant à l'écran les lettres qui n'ont pas été utilisées, en parcourant de gauche à droite et de haut en bas.

Voici les exigences à appliquer à votre code source :

• L'indentation doit être de 3 espaces. Les tabulations ne sont pas autorisées pour l'indentation.
• Votre code doit être découpé en fonctions dont la longueur est acceptable, avec une limite de 10 lignes par fonction.
• Chaque fonction doit être documentée à l'aide d'un commentaire précisant son objectif, ses paramètres et sa valeur de retour (si applicable). Le nom de la fonction doit être significatif.
• Les variables globales ne doivent pas être utilisées, à l'exception de errno.
• Les erreurs système doivent être correctement gérées.
• Une approche de programmation modulaire doit être adoptée, en utilisant des fichiers d'en-tête (.h) pour représenter les interfaces et des fichiers (.c) pour cacher les implémentations. Les modules doivent suivre le standard enseigné en classe.
• Les identifiants de fonctions et variables doivent être en snake_case.
• Une attention particulière doit être accordée à la lisibilité du code source.
• Bats et Cunit doivent être utilisés comme cadres de test pour tester le logiciel, avec une couverture de 80% et un code de test propre.
• Une approche de développement par branches doit être adoptée, avec l'initiation d'une demande de fusion pour toutes les fusions dans la branche principale.
• Un GitLab-CI doit être ajouté au projet pour assurer l'intégration continue.
• Un Makefile doit être fourni pour exprimer les dépendances de façon complète.

## Tests

Lancer la suite de tests automatiques avec cette commande `make test`.

Ps: il est important de savoir que si vous souhaitez effectuer tous les teste du check.bats en retirant les skips. il est demander de retirer les symbole de commentaire dans le main, sois tester_Affichage_Mots(&matrice); ainsi que tester_Affichage_Matrice(&matrice);

Attention : j'ai mis en commentaire dans le makefile le Cunit etant donner que j'ai trop de warning. j'ai tous de meme esseiller de fournir une tentative, merci de votre comprehension.

A savoir dans le dossier Exemple ce trouve des exemple de fichier de grille de mots.
Voici la liste des testes qui on ete effectuer:

```sh
$ make test
gcc -Wall -Wextra -o motcache -std=c11 motcache.c
bats check.bats
check.bats
 ✓ Resultat final : MANDOLINE
 ✓ Verification matrice : MANDOLINE
 ✓ Verification des mots :  MANDOLINE
 ✓ Resultat final : CALISSE
 ✓ Verification matrice : CALISSE
 ✓ Verification des mots :  CALISSE
 ✓ Resultat final : PARESSEUX
 ✓ Verification matrice : PARESSEUX
 ✓ Verification des mots :  PARESSEUX
 ✓ Resultat final : VENISE
 ✓ Verification matrice : VENISE
 ✓ Verification des mots :  VENISE
 ✓ Resultat final : INTELLIGENT
 ✓ Verification matrice : INTELLIGENT
 ✓ Verification des mots :  INTELLIGENT
 ✓ Erreur : Demander entrer tous les fichier txt
 ✓ Erreur : Demande aucun fichier

17 tests, 0 failures
```

```sh
$ make test
	bats check.bats
```


## Dépendances

* [Bats](https://github.com/bats-core/bats-core)
* [GCC](https://gcc.gnu.org/install/)
* [Pandoc](https://pandoc.org/installing.html)
* [Make](https://linuxhint.com/install-make-ubuntu/)
* [Cunit](https://apolo-docs.readthedocs.io/en/latest/software/scientific_libraries/cunit/2.1-3/index.html)

## Références

* [Gitignore librairie complete](https://github.com/github/gitignore)
* [Markdown](https://learn.microsoft.com/en-us/contribute/markdown-reference)
* [Code in markdown](https://learn.microsoft.com/en-us/contribute/code-in-docs)
* [tutoriels C Programming](https://www.cprogramming.com/)
* [implementation de l'algorithme de recherche de motif Knuth-Morris-Pratt (KMP)](https://www.sciencedirect.com/science/article/pii/0022000077900362)
* [GeeksforGeeks](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)

## État du projet

Indiquez toutes les tâches qui ont été complétés en insérant un `X` entre les
crochets. Si une tâche n'a pas été complétée, expliquez pourquoi (lors de la
remise, vous pouvez supprimer ce paragraphe).

* [X] Votre dépôt doit se nommer exactement inf3135-hiv2023-tp2.
* [X] L'URL du dépôt GitLab est exactement (remplacer `utilisateur` par votre
      nom identifiant GitLab) `https://gitlab.info.uqam.ca/<utilisateur>/inf3135-hiv2023-tp2`.
* [X] Les usagers `dogny_g` et `correcteur` ont accès au projet en mode *Developer*.
* [X] Le dépôt GitLab est privé.
* [X] Le dépôt contient au moins un fichier `.gitignore`.
* [X] Le fichier `Makefile` permet de compiler le projet lorsqu'on entre `make`. 
      Il supporte les cibles `test` et `clean`.
* [X] Le nombre de tests qui réussissent/échouent avec la `make test` 
      est indiqué quelque part dans le fichier `README.md`.
* [X] Les sections incomplètes de ce fichier (`README.md`) ont été complétées.
* [X] L'en-tête du fichier est documentée.
* [X] Le programme ne contient pas de valeurs magiques.
* [X] Votre travail doit être rédigé en langage C et doit compiler sans erreur et sans avertissement.
* [X] Les modifications sont réparties en commits atomiques. Utilisation des branches. 
      Les messages de commit sont significatifs et uniformes. Les demandes d’intégration.
* [X] Les tests sont propres, avec une couverture de 80%.
* [X] Le Makefile doit supporter au moins les cibles compile,link et test. 
      L’appel à make doit compiler et construire l’exécutable.
* [X] Votre projet doit supporter le système d’intégration continue de GitLab 
      (GitLab-CI) qui construit et roule tous vos tests à chaque commit sur la branche master.

## Exigences du code source

* [X] L'indentation doit être de 3 espaces. Aucune tabulation n'est permise dans l'indentation.
* [X] Pas de fonctions de plus de 10 lignes.
* [X] Chaque fonction doit être documentée, Le nom de la fonction doit être significatif (refactoring).
* [X] N'utilisez pas de variables globales (sauf errno).
* [X] Les erreurs systèmes doivent être gérées correctement.
* [X] Utilisez de fichier d’en-tête (.h) pour représenter vos interfaces et cacher vos implémentations dans les fichiers (.c).
* [X] Les identifiants de fonctions et variables doivent être en snake_case.
* [X] Lisibilité du code source.
* [\] Utiliser bats et Cunit.
* [X] Adopter une approche de développement par branche et initier des merge request pour tous vos fusions dans la branche principale.
* [X] Ajouter une intégration continue (GitLab-CI) de votre projet.
* [X] Fournir un Makefile qui exprime les dépendances de façon complète.

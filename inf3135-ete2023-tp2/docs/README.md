# inf3135-ete2023-tp2

## Description

Il sagis d'un logiciel qui est une replique du jeux [Bataille navale](https://fr.wikipedia.org/wiki/Bataille_navale_(jeu)). "Bataille navale" est un jeu de société classique qui se déroule sur les mers. 
Chaque joueur place ses navires sur une grille, puis tente de les localiser en devinant les coordonnées de l'adversaire. 
L'objectif est de couler tous les navires ennemis en visant avec précision. 
Dans le cas de ce logiciel, il fonctionne a la console.

Ce travail est accompli pour le cours de construction et maintenance de logiciels, INF3135,
Gnagnely Serge Dogny, a l'Universite du Quebec a Montreal.

## Auteur

© 2023 Tous droits réservés, Kevin Da Silva (DASK30049905)

## Fonctionnement

L'objectif du projet consiste à développer un jeu de bataille navale. Dans ce jeu, le joueur commence par entrer la taille du plateau de jeu (entre 6 et 100 cases). Ensuite, le programme place aléatoirement cinq navires de différentes tailles sur ce plateau. Les navires sont les suivants :

- 1 Porte-avions (5 cases)
- 1 Croiseur (4 cases)
- 2 Contre-torpilleurs (3 cases)
- 1 Torpilleur (2 cases)

Ensuite, le joueur est invité à choisir une case sur laquelle il souhaite lancer une torpille. Le programme affiche ensuite les résultats comme suit :

- "Touché" si un navire est présent sur cette case.
- "À l'eau" si aucun navire n'est présent sur cette case.
- "Déjà joué" si cette case a déjà été jouée.

De plus, une grille de jeu de taille "taille_plateau" × "taille_plateau" est affichée, où chaque case est représentée par un symbole :

- "X" si la case a été jouée et qu'un navire est présent sur cette case.
- "O" si la case a été jouée et qu'aucun navire n'est présent sur cette case.
- "." si la case n'a pas encore été jouée.

Une fois que toutes les cases d'un navire ont été touchées, un message s'affiche pour indiquer que le navire (en précisant sa taille et son nom) a été coulé. Ce processus est répété jusqu'à ce qu'il ne reste plus de navires non coulés.

Lorsque tous les navires ont été coulés, un message de victoire s'affiche, accompagné du nombre de coups joués.

Si le logiciel est lancé avec l'option "-S", il accumule des statistiques sur les données du jeu et les écrit dans un fichier de sortie spécifié dans la console.

Si le fichier de sortie n'existe pas, il sera créé. S'il existe déjà, il sera écrasé.

## Tests

Attentions! les test non pas ete fait. il y a 2 serveur uqam l'un d'eux plante toujours car le serveur nest pas mise a jours. ce qui cause des probleme dans le code.

Lancer la suite de tests des fichier bats automatiques avec cette commande `make bats`.
et 
Lancer la suite de tests des fichier CUnit automatiques avec cette commande `make test`.

Voici la liste des testes qui on ete effectuer au bats:

```sh
$ make bats
bats tests/bats/checktest1.bats

0 tests, 0 failures
```

Voici la liste des testes qui on ete effectuer au CUnit:

```sh
$ make test

...

```

## Cible Makefile

Chaque cible a un objectif spécifique dans le processus de construction du projet, que ce soit la compilation du programme principal, l'exécution de tests unitaires, la génération de fichiers HTML ou le nettoyage des fichiers temporaires. Voici une explication de chaque cible présente dans le Makefile et de ce qu'elle fait :

- `all` : Cette cible est la cible par défaut. 
Lorsque vous exécutez simplement `make` sans spécifier de cible, cette cible sera exécutée. 
Dans ce `Makefile`, la cible `all` est définie pour exécuter la cible `compile`.

- `compile` : Cette cible est responsable de la compilation du programme principal. 
Elle dépend du fichier source principal `($(SRC_DIR)/$(main).c)` et génère un fichier objet `($(main))`. 
Le fichier objet est placé dans le répertoire `$(BUILD_DIR)`.

- `debug` : Cette cible permet de lancer le débogueur GDB pour le programme principal. 
Elle dépend de la cible `$(main)`, ce qui signifie que le programme principal doit être déjà compilé avant de pouvoir lancer le débogueur.

- `valgrind` : Cette cible utilise Valgrind pour lancer une analyse de la mémoire du programme principal. 
Elle dépend de la cible `$(main)`, ce qui signifie que le programme principal doit être déjà compilé avant de pouvoir exécuter Valgrind.

- `clean` : Cette cible est utilisée pour nettoyer les fichiers de compilation et l'exécutable généré. 
Elle supprime les fichiers objets et le répertoire `$(BUILD_DIR)`, ainsi que les fichiers HTML générés.

- `test` : Cette cible est utilisée pour exécuter les tests unitaires avec CUnit. 
Elle dépend des fichiers de tests CUnit `($(cunitTests))` et génère un exécutable `($(testCU))`. 
L'exécutable est ensuite exécuté pour exécuter les tests unitaires.

- `bats` : Cette cible est utilisée pour exécuter les tests unitaires avec Bats. 
Elle dépend des fichiers de tests Bats `($(batsTests))` et exécute la commande bats sur chaque fichier de test individuellement.

- `html` : Cette cible est utilisée pour générer un fichier HTML à partir du fichier `README.md` à l'aide de l'outil Pandoc. 
Elle dépend du fichier `README.md` et utilise la commande Pandoc pour effectuer la conversion.

- `link` : Cette cible est utilisée pour lier les fichiers objets générés. 
Elle dépend des fichiers objets du programme principal (`$(main)` et `$(testCU)`) et utilise la commande de liaison pour générer l'exécutable final.

## Dépendances

* [Bats](https://github.com/bats-core/bats-core)
* [GCC](https://gcc.gnu.org/install/)
* [Pandoc](https://pandoc.org/installing.html)
* [Make](https://linuxhint.com/install-make-ubuntu/)
* [Cunit](https://apolo-docs.readthedocs.io/en/latest/software/scientific_libraries/cunit/2.1-3/index.html)
* []()

## Références

* [Gitignore librairie complete](https://github.com/github/gitignore)
* [Markdown](https://learn.microsoft.com/en-us/contribute/markdown-reference)
* [Code in markdown](https://learn.microsoft.com/en-us/contribute/code-in-docs)
* [tutoriels C Programming](https://www.cprogramming.com/)
* []()

## État du projet

* [X] Votre dépôt doit se nommer exactement inf3135-ete2023-tp2.
* [X] L'URL du dépôt GitLab est exactement (remplacer `utilisateur` par votre
      nom identifiant GitLab) `https://gitlab.info.uqam.ca/<utilisateur>/inf3135-ete2023-tp2`.
* [X] Les usagers `dogny_g` et `correcteur` ont accès au projet en mode *Developer*.
* [X] Le dépôt GitLab est privé.
* [X] Le dépôt contient au moins un fichier `.gitignore`.
* [X] Le fichier `Makefile` permet de compiler le projet lorsqu'on entre `make`. 
      Il supporte les cibles `test`, `clean`, `compile`, `html` et `link`.
* [ ] Le nombre de tests qui réussissent/échouent avec la `make test` et le `make bats`
      est indiqué quelque part dans le fichier `README.md`.
* [ ] Les sections incomplètes de ce fichier (`README.md`) ont été complétées.
* [X] L'en-tête du fichier est documentée.
* [X] Le programme ne contient pas de valeurs magiques.
* [ ] Votre travail doit être rédigé en langage C et doit compiler sans erreur et sans avertissement.
* [X] Les modifications sont réparties en commits atomiques. Utilisation des branches. 
      Les messages de commit sont significatifs et uniformes. Les demandes d’intégration.
* [ ] Les tests sont propres, avec une couverture de 80%.
* [X] Le Makefile doit supporter au moins les cibles `test`, `clean`, `compile`, `html` et `link`.
      L’appel à make doit compiler et construire l’exécutable.
* [X] Votre projet doit supporter le système d’intégration continue de GitLab 
      (GitLab-CI) qui construit et roule tous vos tests à chaque commit sur la branche master.

## Exigences du code source

* [X] L'indentation doit être de 3 espaces. Aucune tabulation n'est permise dans l'indentation.
* [ ] Pas de fonctions de plus de 15 lignes.
* [X] Chaque fonction doit être documentée, Le nom de la fonction doit être significatif (refactoring).
* [X] N'utilisez pas de variables globales (sauf errno).
* [X] Les erreurs systèmes doivent être gérées correctement.
* [X] Utilisez de fichier d’en-tête (.h) pour représenter vos interfaces et cacher vos implémentations dans les fichiers (.c).
* [X] Les identifiants de fonctions et variables doivent être en snake_case.
* [X] Lisibilité du code source.
* [ ] Utiliser bats et Cunit.
* [X] Adopter une approche de développement par branche et initier des merge request pour tous vos fusions dans la branche principale.
* [X] Ajouter une intégration continue (GitLab-CI) de votre projet.
* [X] Fournir un Makefile qui exprime les dépendances de façon complète.

## Barème

- Fonctionnalité (30 points): Tous les programmes compilent et affichent les résultats attendus.

- Améliorations possibles (10 points): Implémentation des améliorations suggérées dans l’énoncé.

- Qualité du code (10 points): Les identifiants utilisés sont significatifs et ont une syntaxe uniforme, le code est bien indenté, il y a de l'aération autour des opérateurs et des parenthèses, le programme est simple et lisible. Pas de bout de code en commentaire ou de commentaires inutiles. Pas de valeur magique. Le code doit être bien factorisé (pas de redondance) et les erreurs bien gérées. La présentation doit être soignée.

- Documentation (5 points): Le fichier README.md est complet et respecte le format Markdown. Il explique comment compiler et exécuter vos programmes ainsi que toutes les autres cibles demandées.

- Utilisation de Git (10 points): Les modifications sont réparties en commits atomiques. Le fichier .gitignore est complet. Utilisation des branches. Les messages de commit sont significatifs et uniformes. Les demandes d’intégration.

- Tests (20 points): Le code de test est propre, avec une couverture de 80%. Cunit et Bats.

- Makefile (5 points): Le Makefile doit supporter au moins les cibles compile, link, test et une cible html permettant de créer une version html du README.md. L’appel à make doit compiler et construire l’exécutable.

- GitLab-CI (10 points): Votre projet doit supporter le système d’intégration continue de GitLab (GitLab-CI) qui construit et roule tous vos tests à chaque commit sur la branche master. 
---
title: "inf3135-ete2023-tp3"
---

# inf3135-ete2023-tp3

## Description

Il sagis d'un logiciel qui 

l'objectif est 

Ce travail est accompli pour le cours de construction et maintenance de logiciels, INF3135,
Gnagnely Serge Dogny, a l'Universite du Quebec a Montreal.

## Auteur

© 2023 Tous droits réservés, Kevin Da Silva (DASK30049905)

## Fonctionnement

L'objectif du projet consiste à développer un 

## Tests

Lancer la suite de tests des fichier CUnit automatiques avec cette commande `make test`.

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

- `html` : Cette cible est utilisée pour générer un fichier HTML à partir du fichier `README.md` à l'aide de l'outil Pandoc. 
Elle dépend du fichier `README.md` et utilise la commande Pandoc pour effectuer la conversion.

- `link` : Cette cible est utilisée pour lier les fichiers objets générés. 
Elle dépend des fichiers objets du programme principal (`$(main)` et `$(testCU)`) et utilise la commande de liaison pour générer l'exécutable final.

## Dépendances

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

* [X] Votre dépôt doit se nommer exactement inf3135-ete2023-tp3.
* [X] L'URL du dépôt GitLab est exactement (remplacer `utilisateur` par votre
      nom identifiant GitLab) `https://gitlab.info.uqam.ca/<utilisateur>/inf3135-ete2023-tp3`.
* [X] Les usagers `dogny_g` et `correcteur` ont accès au projet en mode *Developer*.
* [X] Le dépôt GitLab est privé.
* [ ] Le dépôt contient au moins un fichier `.gitignore`.
* [ ] Le fichier `Makefile` permet de compiler le projet lorsqu'on entre `make`. 
      Il supporte les cibles `test`, `clean`, `compile`, `html` et `link`.
* [ ] Le nombre de tests qui réussissent/échouent avec la `make test`
      est indiqué quelque part dans le fichier `README.md`.
* [ ] Les sections incomplètes de ce fichier (`README.md`) ont été complétées.
* [ ] L'en-tête du fichier est documentée.
* [ ] Votre travail doit être rédigé en langage C et doit compiler sans erreur et sans avertissement.
* [ ] Les modifications sont réparties en commits atomiques. Utilisation des branches. 
      Les messages de commit sont significatifs et uniformes. Les demandes d’intégration.
* [ ] Les tests sont propres, avec une couverture de 70%.
* [ ] Le Makefile doit supporter au moins les cibles `test`, `clean`, `compile`, `html` et `link`.
      L’appel à make doit compiler et construire l’exécutable.
* [ ] Votre projet doit supporter le système d’intégration continue de GitLab 
      (GitLab-CI) qui construit et roule tous vos tests à chaque commit sur la branche master.
* [ ] Votre système ne doit avoir aucune fuite de mémoire.
* [ ] Les paramètres reçus par le main (argc et argv) doivent toujours être validés.
* [ ] Vous devez adapter une approche de programmation modulaire.
* [ ] La structure de données principale doit être une liste chaînée contenant les catégories. La liste de catégories doit toujours être triée en ordre alphabétique.
* [ ] Chaque catégorie doit également contenir une liste chaînée de recettes. Les listes de recettes doivent également être triées en ordre alphabétique.
* [ ] Les structures de données utilisées pour accumuler les catégories et les recettes doivent être allouées dynamiquement.
* [ ] Date limite le 13 août 2023 à 23:59.

## Exigences du code source

* [ ] L'indentation doit être de 3 espaces. Aucune tabulation n'est permise dans l'indentation.
* [ ] Pas de fonctions de plus de 10 lignes.
* [ ] Chaque fonction doit être documentée, Le nom de la fonction doit être significatif (refactoring).
* [ ] Les erreurs systèmes doivent être gérées correctement (ouverture-fermeture de fichier).
* [ ] Utilisez de fichier d’en-tête (.h) pour représenter vos interfaces et cacher vos implémentations dans les fichiers (.c).
* [ ] Lisibilité du code source.
* [ ] Utiliser Cunit.
* [ ] Adopter une approche de développement par branche et initier des merge request pour tous vos fusions dans la branche principale.
* [ ] Ajouter une intégration continue (GitLab-CI) de votre projet.
* [ ] Fournir un Makefile qui exprime les dépendances de façon complète.

## Barème

- Fonctionnalité (40 points): Tous les programmes compilent et affichent les résultats attendus.

- Exigences de conception (15 points): Le respect des exigences de conception et des structures de données exigées. La modularité de la conception

- Utilisation de Git (5 points): Les modifications sont réparties en commits atomiques. Le fichier .gitignore est complet. Utilisation des branches et des requêtes d’intégration (merge request). Les messages de commit sont significatifs et uniformes.

- Tests (20 points): Bonne utilisation du cadre de test Cunit, Le code de test est propre avec une couverture de tests de 70 % sur le projet.

- Makefile, Documentation, GitLab-CI, Qualité du code (20 points) :

      - Documentation : Le fichier README.md est complet et respecte le format Markdown. Il explique comment compiler et exécuter vos programmes. Ce fichier doit avoir une section nommée « équipe », qui liste les membres de l’équipe (nom et prénoms, code permanant, courriel) et doit clairement identifier le chef de l’équipe.

      - Makefile : Le Makefile qui met en œuvre de façon adéquate, la construction de votre logiciel et qui génère la documentation en html.

      - GitLab-CI : Votre projet doit supporter le système d’intégration continue de GitLab (GitLab-CI) qui construit et roule tous vos tests à chaque commit sur la branche principale.

      - Qualité du code : Lisibilité, uniformité, testabilité 
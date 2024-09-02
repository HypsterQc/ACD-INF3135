# TP1: Chemins de Dyck"


## Description

Le projet intitulé "motdedyck" sera développé en langage C afin de permettre la saisie de mots de Dyck en entrée et de dessiner le chemin correspondant. La lecture de l'entrée sera réalisée depuis l'entrée standard (stdin), tandis que le résultat sera affiché sur la sortie standard (stdout). Si vous désirez obtenir des informations plus détaillées sur la théorie des mots de Dyck, je vous conseille de consulter le lien vers le sujet du travail ci-dessous.

Ce travail est accompli pour le cours de construction et maintenance de logiciels, INF3135,
pour l'enseignant Gnagnely Serge Dogny, a l'Université du Québec à Montréal.

Voici le lien vers le [sujet du travail](sujet.md).

Ainsi que la structure et l'utilisation du contenu du projet:

* `README.md`: ce fichier
* `Makefile`: permet d'automatiser la compilation
* etc.

## Auteur

© 2023 Tous droits réservés, Kevin Da Silva (DASK30049905)

## Fonctionnement

******
Expliquez d'abord en mots comment faire fonctionner le projet (imaginez que la
personne qui l'utilisera ne connaît pas C, ne connaît pas le projet et souhaite
seulement saisir une série de commandes pour l'exécuter). En particulier,
indiquez les commandes qui doivent être entrées pour la compilation et
l'exécution.
*******

## Tests

Le lancement de la suite de tests automatiser ce fait avec la commande
`make test` dans le terminal.

Les resultat opbtenue sont les suivantes:

```sh
$ make test
bats check.bats
 ✓ test0 : Sans aucune entree, afficher aide 
 ✓ test1 : Dessiner dyck ab 
 ✓ test2 : Dessiner dyck 01 
 ✓ test3 : mot non equilibre 
 ✓ test4 : mot trop long 
 ✓ test5 : mot non equilibre 
 ✓ test6 : lettre interdite 
 ✓ test7 : parametre hauteur 
 ✓ test8 : parametre aire 
 ✓ test9 : argument invalide 
 ✓ test10 : donnees invalides 

11 tests, 0 failures
```

[]()

## Dépendances

* [Bats](https://github.com/bats-core/bats-core).
* [Pandoc](https://pandoc.org/installing.html)
* [Make](https://linuxhint.com/install-make-ubuntu/)

## Références

* [Markdown](https://learn.microsoft.com/en-us/contribute/markdown-reference)
* [Pandoc User’s Guide](https://pandoc.org/MANUAL.html)
* [Gitignore librairie complete](https://github.com/github/gitignore)

## État du projet

* [X] Le nom du dépôt GitLab est exactement `e23-inf3135-tp1` (Pénalité de
  **50%**).
* [X] L'URL du dépôt GitLab est exactement (remplacer `utilisateur` par votre
  nom identifiant GitLab) `https://gitlab.info.uqam.ca/utilisateur/e23-inf3135-tp1`
  (Pénalité de **50%**).
* [X] L'utilisateur `dogny_g` a accès au projet en mode *Developer*
  (Pénalité de **50%**).
* [X] Les correcteurs ont accès au projet en mode *Developer* (`id`à venir)
* [X] Le dépôt GitLab est un *fork* de [ce
  dépôt](https://gitlab.info.uqam.ca/inf3135-sdo/motdedyck)
  (Pénalité de **50%**).
* [X] Le dépôt GitLab est privé (Pénalité de **50%**).
* [X] Le dépôt contient au moins un fichier `.gitignore`.
* [X] Le fichier `Makefile` permet de compiler le projet lorsqu'on entre
  `make`. Il supporte les cibles `html`, `test` et `clean`.
* [X] Le nombre de tests qui réussissent/échouent avec la `make test` est
  indiqué quelque part dans le fichier `README.md`.
* [X] Les sections incomplètes de ce fichier (`README.md`) ont été complétées.
* [X] L'en-tête du fichier est documentée.
* [X] L'en-tête des déclarations des fonctions est documentée (*docstring*).
* [X] Le programme ne contient pas de valeurs magiques.
* [X] `README.md` ne depasse pas 80 caractere par ligne.

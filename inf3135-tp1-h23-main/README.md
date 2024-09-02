---
title: "TP1: Dessiner sur un canevas ASCII"
author: "Kevin Da Silva (DASK30049905)"
date: "2023-02-12"
lang: "fr"
output:
html_notebook:
pandoc_args: [
"--number-offset=1,0"
]
fig_caption: true
number_sections: yes
toc: yes
toc_depth: 3
---

## Description

Il s'agit d'un programme C nommé `canvascii.c` qui permet de dessiner
sur un canevas ASCII. Le canevas peut être initialisé ou lu sur l'entrée
standard (`stdin`). Le résultat est ensuite affiché sur la sortie standard
(`stdout`).

Plus en détails, le canevas est représenté par un fichier texte contenant `h` lignes
et `w` longueur.

Les seuls caractères acceptés sont les suivants:
- `.` désigne un pixel non occupé
- `0`(), `1`(), `2`(), `3`(), `4`(), `5`(), `6`() et `7`() désignent respectivement un pixel de couleur.
  Il y a plusieurs options de commande possible afin deffectuer une action sur le canevas tels:

- `-n`: Permet la création d'un canevas.
- `-s`: Affiche le canevas.
- `-h`: Permet de tracé une ligne horizontale sur le canevas.
- `-v`: Permet de tracé une ligne verticale sur le canevas.
- `-r`: Permet de tracé un rectangle sur le canevas.
- `-l`: Permet de tracé un segment sur le canevas.
- `-c`: Permet de tracé un cercle sur le canevas.
- `-p`: Sélection du crayon qui change la couleur du canvas a l'utilisation.
  Par defaut, le crayon est sur la pixel de couleur `7`.
- `-k`: Permet la colorisation du canevas.

pour finir, ce programme détecte des erreurs d'utilisation tels:
- `1`: Wrong pixel value in canvas
- `2`: Le canevas est trop haut.
- `3`: Le canevas est trop large.
- `4`: Le canevas n'est pas rectangulaire.
- `5`: L'option n'existe pas.
- `6`: L'option a des erreur de variable.
- `7`: Il y a un probleme avec les valeurs.

Ce travail est accompli pour le cours de construction et maintenance de logiciels, INF3135, 
pour l'enseignant Gnagnely Serge Dogny, a l'Université du Québec à Montréal.

Voici le lien vers le [sujet du travail](sujet.md).

## Auteur

© 2023 Tous droits réservés, Kevin Da Silva (DASK30049905)

## Fonctionnement
Afin de faire fonctionner le programme il faut utiliser la ligne de commande de votre terminal
(par exemple cmd, powershell ou encore wsl). Vous ajouter `./canvascii` afin dexecuter le programme. 
A savoir que seul `./canvascii` vas rafficher l'aide d'usage , alors que acompagner des option vue plus haut le programme 
peut faire les actions de chaqu'unes d'elles.


- `-n`: il faut ajouter un nombre de ligne et de colonne
- `-s`: seul.
- `-h`: il faut ajouter la ligne horizontal quon souhait modifier.
- `-v`: il faut rajouter la ligne verticale quon veux modifier.
- `-r`: vas tracer le rectangle en fonction des 4 indicateur de point repere.
- `-l`: Permet de tracé un segment sur le canevas.
- `-c`: Permet de tracé un cercle sur le canevas.
- `-p`: Sélection du crayon qui change la couleur du canvas a l'utilisation.
  Par defaut, le crayon est sur la pixel de couleur `7`.
- `-k`: Permet la colorisation du canevas.

Si vous souhaitez voir des exemples de commande vous pouvez vous referez au lien suivant du[sujet du travail](sujet.md) qui contient quel que exemple d'entrer sortie et d'avantage d'information sur le sujet.


## Tests

* `make test`: Lancer la suite de tests automatiques avec cette commande.
* etc.

```sh
$ make test
	bats check.bats
  
  34 tests, 15 failures
```

## Dépendances

* [Bats](https://github.com/bats-core/bats-core)
* [GCC](https://gcc.gnu.org/install/)
* [Pandoc](https://pandoc.org/installing.html)
* [Make](https://linuxhint.com/install-make-ubuntu/)
* []()

## Références

* [Pandoc User’s Guide](https://pandoc.org/MANUAL.html)
* [Gitignore librairie complete](https://github.com/github/gitignore)
* [Forum de discution](https://community.rstudio.com/t/rmarkdown-document-format-requires-a-nonempty-title-element/36774)
* [Markdown](https://learn.microsoft.com/en-us/contribute/markdown-reference)
* [Code in markdown](https://learn.microsoft.com/en-us/contribute/code-in-docs)
* [code cercle](http://rosettacode.org/wiki/Bitmap/Midpoint_circle_algorithm#C)
* [code segment](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm?section=7#All_cases)


## État du projet

Indiquez toutes les tâches qui ont été complétés en insérant un `X` entre les
crochets. Si une tâche n'a pas été complétée, expliquez pourquoi (lors de la
remise, vous pouvez supprimer ce paragraphe).

* [X] Le nom du dépôt GitLab est exactement `inf3135-tp1-h23` (Pénalité de
  **50%**).
* [X] L'URL du dépôt GitLab est exactement (remplacer `utilisateur` par votre
  nom identifiant GitLab) `https://gitlab.info.uqam.ca/utilisateur/inf3135-tp1-h23`
  (Pénalité de **50%**).
* [X] Les usagers `dogny_g` et `correcteur` ont accès au projet en mode *Developer*
  (Pénalité de **50%**).
* [X] Le dépôt GitLab est un *fork* de [ce
  dépôt](https://gitlab.info.uqam.ca/inf3135-sdo/canvascii)
  (Pénalité de **50%**).
* [X] Le dépôt GitLab est privé (Pénalité de **50%**).
* [X] Le dépôt contient au moins un fichier `.gitignore`.
* [X] Le fichier `Makefile` permet de compiler le projet lorsqu'on entre
  `make`. Il supporte les cibles `html`, `test` et `clean`.
* [X] Le nombre de tests qui réussissent/échouent avec la `make test` est
  indiqué quelque part dans le fichier `README.md`.
* [ ] Les sections incomplètes de ce fichier (`README.md`) ont été complétées.
* [ ] L'en-tête du fichier est documentée.
* [ ] L'en-tête des déclarations des fonctions est documentée (*docstring*).
* [ ] Le programme ne contient pas de valeurs magiques.

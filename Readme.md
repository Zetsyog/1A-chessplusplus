# Chessplusplus

Object-oriented programming project.
1A/S2

## Usage

To compile use

```bash
    make
```

To cleanup compilation files

```bash
    make clean
```

To run the programm simply execute `bin/echecs`
*Tested on Ubuntu 18 and WSL1*

## Documentation

See in `doc/html/` folder

## Conception (fr)

Pour la conception j'ai utilisé les grandes lignes des consignes de
modélisation.
J'ai donc une classe Piece qui représente une pièce quelconque de l'échiquier
avec toutes les classes des pièces de l'échiquier en hérite, sauf la reine qui
hérite du fou et de la tour.
Ensuite on a une classe globale du jeu, et un classe qui modélise le plateau,
où on retrouve la grille de jeu etc...
J'ai eu quelques difficultés notamment au niveau de la gestion de la mémoire
lors des déplacements.

En effet j'ai d'abord codé des déplacements naïfs, mais lorsqu'il a fallu testé
si après son déplacement, le joueur se mettait en échec (et donc interdire ce
genre de déplacement) cela s'est rapidement complexifié. C'est devenu plus
complexe puisque je devais simuler un déplacement sur un plateau fictif et voir
le conséquences qu'il apportait.
Le problème est que lorsque je clone un Board, les Pieces ne sont pas clonées
puisqu'elles sont enregistrées dans le tas, là où le reste des variables sont
dans la pile.
Donc mes pièces sont communes à toutes mes instances de Board, seul leur
position dans la grille change.
Et du coup comme lorsque qu'une piece prenait une autre au cours d'un
déplacement je libérait sa mémoire, si ce mouvement était fictif, je me
retrouvait avec des pièces quand même supprimées sur le vrai plateaux. C'est
pour cela qu'il y a un bool en argument sur les fonctions de mouvement pour
savoir si ce movement est fictif ou non, est donc si on doit libérer la mémoire
ou non. De plus lors d'un mouvement fictif, je changeait la position de la piece
(l'attribut de classe), ainsi que sur la grille, ce qui faisait que lorsque je
changeait de Board, la position de la piece dans la grille était corrigée, mais
pas son attribut de classe. C'est pour cela qu'au début de la méthode
Board::move() je met à jour la position de la piece avec sa vraie position dans
la grille. Et c'est également ce que fait la méthode Board::update_position(),
cette dernière a été nécessaire pour l'échec et mat.
Pour l'échec et mat, je l'ai implémenté de manière brutale : si le roi est en
échec, pour chaque pièce on regarde si chaque case de l'échiquier est un
mouvement légal, et s'il l'est, si ce mouvement permet d'empecher l'échec.
C'est pas très élégant, mais ça marche.

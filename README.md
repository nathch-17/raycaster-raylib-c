# RayCasting in c with raylib

Bienvenue sur le dépôt de mon **petit projet personnel** ! 
Il s'agit d'un mini-jeu (moteur de type raycaster) développé en C pour m'entraîner, m'amuser et expérimenter. Le rendu graphique s'appuie sur la bibliothèque [raylib](https://www.raylib.com/).

## Prérequis

Pour compiler ce projet, vous aurez besoin de :
- Un compilateur C comme `gcc`
- L'outil `make`
- La bibliothèque **raylib** installée sur votre système.

## Comment lancer le test

Le projet est configuré pour compiler un exécutable nommé `test`. 

Voici les étapes pour le compiler et le lancer :

1. Ouvrez votre terminal à la racine du projet.
2. Compilez le code en utilisant la commande `make` :
   ```bash
   make
   ```
3. Une fois la compilation terminée, lancez l'exécutable `test` :
   ```bash
   ./test
   ```

## Commandes utiles (Makefile)

- `make` : compile le projet et génère l'exécutable `test`.
- `make clean` : supprime les fichiers objets (`.o`).
- `make fclean` : supprime les fichiers objets et l'exécutable.
- `make re` : recompile entièrement le projet (équivalent de `make fclean` puis `make`).

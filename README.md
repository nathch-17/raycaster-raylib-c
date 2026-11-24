# RayCasting in c with raylib

Bienvenue sur le dépôt de mon **petit projet personnel** ! 
Il s'agit d'un mini-jeu (moteur de type raycaster) développé en C pour m'entraîner, m'amuser et expérimenter. Le rendu graphique s'appuie sur la bibliothèque [raylib](https://www.raylib.com/).

## Prérequis

Pour compiler la **version native**, vous aurez besoin de :
- Un compilateur C comme `gcc`
- L'outil `make`
- La bibliothèque **raylib** installée sur votre système.

Pour compiler la **version Web (HTML5 / WebAssembly)**, vous aurez en plus besoin de :
- **Emscripten** (`emcc` dans le `PATH`, via `emsdk`)
- Les sources de **raylib** compilées pour le web (`make PLATFORM=PLATFORM_WEB -B` dans `~/raylib/src`, qui génère `libraylib.web.a`).

## Contrôles

- `W` / `S` : avancer / reculer
- `A` / `D` : tourner à gauche / à droite
- `Espace` ou **Clic gauche** : tirer

## Comment lancer la version native

Le projet est configuré pour compiler un exécutable nommé `test`.

1. Ouvrez votre terminal à la racine du projet.
2. Compilez le code en utilisant la commande `make` :
   ```bash
   make
   ```
3. Lancez l'exécutable `test` :
   ```bash
   ./test
   ```

## Comment lancer la version Web (WebAssembly)

1. Compilez le projet avec Emscripten :
   ```bash
   make web
   ```
   *(Génère `index.html`, `index.js` et `index.wasm`.)*
2. Lancez un serveur HTTP local (nécessaire pour charger le fichier `.wasm` sans blocage CORS) :
   ```bash
   python3 -m http.server 8000
   ```
3. Ouvrez `http://localhost:8000/index.html` dans votre navigateur et cliquez sur le canvas pour activer les contrôles clavier.

## Commandes utiles (Makefile)

- `make` : compile le projet en natif et génère l'exécutable `test`.
- `make web` : compile le projet pour le Web (`index.html`, `index.js`, `index.wasm`).
- `make clean` : supprime les fichiers objets (`.o`).
- `make fclean` : supprime les fichiers objets, l'exécutable `test` et les fichiers générés pour le Web (`index.*`).
- `make re` : recompile entièrement la version native (`make fclean` puis `make`).

# TP2 - Ingénierie des modèles

## Plan

## Architecture 

Vous retrouverez dans ce projet 
- Un dossier **build** pour tous les fichiers .o générés à la compilation
- Un dossier **data** contenant 
    - **data.c** : Le tableau de nombre aléatoires créer avant l'éxecution du programme principale
    - **mt19937ar_output.c** : Les 1000 premiers nombres générés par le générateur aléatoire
    - **mappedFile.txt** : Le fichier binaire que l'on veut mapper pour la questioon 7
- Un dossier **exe** pour les 2 executables
    - **generator** pour la generation des nombres aléatoire et l'inscription de ces derniers dans un fichier. Usage : `./generator XXX` avec XXX le nombre de nombres à générer.
    - **monte_carlo** pour l'utilisation de l'algorithme de monte carlo
- Un dossier **header** contenant les fichiers d'en-tête .h
- Un dossier **html** avec la documentation du programme au format .html
- Un dossier **main** contenant les 2 mains pour les 2 différents programmes
- Un dossier **src** pour les fichiers sources .c
- Un fichier **cppcheck.txt** pour les améliorations possibles du code détecter par l'outil Cpp Check
- Un fichier **Dockerfile** pour la configuration de docker (optionnel)
- Un fichier **doxyfile** pour la configuration de la génération de la documentation
- Un fichier **makefile** pour la génération des executables
- Un script bash **subject.sh** pour répondre au questions de l'enoncé


## Le Makefile

Le Makefile permet de générer 2 executables comme énoncé précédemment. Quelques commandes utiles pour la génération des éxécutables. Toutefois, je vous conseille d'utiliser uniquement la dernière pour la génération du programme.

### Génération du code

- **make exe/generator** : Génération de l'executable pour la generation des nombres aleatoires
- **make exe/monte_carlo** : Génération de l'executable pour l'algorithme de Monte Carlo. Il faut avoir créer l'executable generator auparavant. On peut rajouter un argument `'y'` ou `'n'` si on veut uniquement générer ou lire XXX nombres dans le fichier
- **make run n=XXX** : Génération des deux executables avec le nombre de nombres aléatoires à générer. Remplacer le XXX par la vrai valeur. Usage : `make run n=1000`

### Autres

- **make** : Affiche de l'aide pour l'utilisation des différentes commandes
- **make clean** : Nettoyer le repository
- **make check** : Lance l'outil Cpp Check pour améliorer le code.

## Outils 

### Markdown

Pour la création de ce README, j'ai utilisé l'extension de fichier .md. On peut par la suite exporter ceci sous format .pdf ou .html.

### Cpp Check

L'outil Cpp Check permet d'observer des warnings plus poussé et des améliorations possibles de notre code

### Docker

Docker permet de créer une image, et par la suite un container de mon projet. Il permet donc de connaître les caractéristiques de mon environment. L'application fonctionnera très bien sans installer Docker, je vous donne juste mon Dockerfile si vous voulez regarder.

### Doxygen

J'ai généré une documentation pour le programme avec l'outil doxygen. Pour la génération de la documentation, vous devez lancer la commande **doxygen doxyfile**. Sinon vous pouvez consulter directement le dossier html

## Le sujet

Pour répondre au sujet, j'ai écrit un script qui permet de répondre au différentes questions du sujet. Pour le lancer, il suffit uniquement de lancer la commande **./subject.sh**.   
Toutefois, si il ne se lance pas, essayer la commande **chmod 700 ./subject.sh** pour obtenir le droit de l'executer

### Question 1 

Je retrouve bien les mêmes nombres que l'output de MT, si on observe les premiers nombres générer dans data.c

### Question 2 

Après lancement de l'executable `generator`, le fichier data.c contient bien la structure que vous demandez. J'ai rajouté en plus le nombre de double à l'interieur de ce dernier

### Question 3 

J'ai repris le code de Monte Carlo [sur ce site](https://www.dartmouth.edu/~rc/classes/soft_dev/C_simple_ex.html). Je l'ai ensuite adapté pour notre programme.

Pour effectuer 10 réplications séquentielles avec 1 million de points, il faut donc générér 20 millions de nombres avec le générateur de Mercenne Twister (10 * 1M * 2 (car x et y à générer pour créer un point)). 

Ensuite il suffit de lancer la commande (les arguments après <<< sont facultatifs, j'utilise des sscanf à l'intérieur du programme):   
**make run n=1 && time ./exe/monte_carlo <<< $'1000000\n10\nn\n'**

On observe le résultat suivant en moyenne : 
- Ecart Moyen : 0.001079
- Temps Moyen d'execution : 0.096 secondes

### Question 4

Dorénavant on doit utiliser les nombres générés dans le tableau. On vérifie bien que le nombre d'iteration * le nombre d'expérience est possible suivant la taille du tableau.

Ensuite il suffit de lancer la commande (les arguments après <<< sont facultatifs, j'utilise des sscanf à l'intérieur du programme):   
**time (make run n=20000000 ; ./exe/monte_carlo <<< $'1000000\n10\ny\n')**

On observe le résultat suivant suivant : 
- Ecart Moyen : 0.001127
- Temps Moyen d'execution : 7.363 secondes

Le temps de compilation est beaucoup plus long car on doit compiler le fichier pour obtenir le tableau. En revanche le temps d'execution uniquement de monte carlo est de 0.038 secondes, ce qui veut dire que si on veut réutiliser plusieurs fois le même programme il est préférable d'avoir générer le tableau auparavant

### Question 5 

Ici on regarde le temps d'execution pour générer XXX nombres ou bien les lires 

|Nombres de tirages|Lecture du tableau (en s)|Génération des nombres (en s)|
|:-|:-|:-|
|1 000 000|0.002|0.0048|
|10 000 000|0.002|0.040|
|20 000 000|0.002|0.084|
|50 000 000|0.002|0.199|
|100 000 000|0.002|0.463|

Le parcours du tableau est très très rapide (toujours 0.002 secondes), peut importe sa taille. En revanche, le temps de génération des nombres augmente avec le temps

### Question 6

Grâce à cette question, on comprend qu'il faut faire un choix entre la compléxité d'une application, et la mémoire qu'elle nécessite. En effet, j'ai essayé de générer un fichier avec 20 milliards de nombres. Après 350 Go, le serveur Turing de l'ISIMA a coupé ma connection SSH car il n'y avait plus assez de mémoire disponible. Je ne sais pas combien de nombre on pu être généré exactement.

Par conséquent j'ai fait le test ici uniquement en utilisant le générateur

On observe le résultat suivant suivant : 
- Ecart Moyen : 0.000065 (le résultat est donc mieux qu'avec 1 Millions de points)
- Temps Moyen d'execution : 1min 23sec

### Question 7 

Je ne suis pas arrivé à récupérer les nombres. En revanche, vous pouvez regarder la fonction appellé `void Question7()` dans le fichier `monte_carlo.c` pour voir mon raisonnement

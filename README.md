# Induct-O-Goal
Programme utilisé par l'Arduino dans le cadre du projet  de deuxième quadrimestre des premières année Ingénieur Civil de L'UCL.



# Le projet

Dans le cadre du cours de projet, nous avons du adapter un circuit de détection métallique à un kicker. Pour ce faire, nous avons décidé de coupler un Arduino à notre circuit afin de pouvoir implémenter un compteur de score et d'afficher celui-ci. 

## Le circuit 

Afin de pouvoir comprendre au mieux le code ci-joint, voici le fonctionnement du circuit électronique couplé à l'Arduino. 

Celui-ci est doté d'une inductance dans laquelle les balles de kicker
- préalablement métallisées à l'aide d'une bille métallique en leur centre - vont passer. Cela va créer une différence de potentiel à la sortie du circuit. Pour pouvoir compter les goals marqués par les deux joueurs et leurs score respectif, deux circuit sont nécessaires. Le premier, placé dans le goal du Joueur 1 et le deuxième dans celui du joueur 2.


## L'Arduino
L'Arduino est branché à la sortie des deux circuits décrits ci-dessus. Grâce à la commande ```analogRead()```, il détecte un changement de potentiel. Suivant la Pin sur laquelle la différence est observée, il rajoute un point au joueur ayant marqué et l'affiche sur un écran LCD venant du kit Arduino et relié à celui-ci. Lorsqu'un des deux joueurs atteint un score de 10 point, il efface toute l'interface de l'écran et affiche le joueur gagnant.

**Le code:**  Vous pouvez consulter le code [ici](https://github.com/thombaldwin/Projet-Q2-/blob/master/stable/Code%20Arduino%20Induct-O-goal.ino)

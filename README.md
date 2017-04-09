# PLD Compilateur - H4214
  _____                     _   _ _  __ 
 |  __ \                   | | ( |_)/ _|
 | |__) |___  ___ ___ _ __ | |_|/ _| |_ 
 |  _  // _ \/ __/ _ \ '_ \| __| | |  _|
 | | \ \  __/ (_|  __/ |_) | |_  | | |  
 |_|  \_\___|\___\___| .__/ \__| |_|_|  
                     | |                
                     |_|                
Arcel, Baux, Benrighi, Hammel, Sorin, Thibault, Vicente.




  __     _    _                 _______    
 /_ |   | |  | |               |__   __|   
  | |   | |__| | _____      __    | | ___  
  | |   |  __  |/ _ \ \ /\ / /    | |/ _ \ 
  | |_  | |  | | (_) \ V  V /     | | (_) |
  |_(_) |_|  |_|\___/ \_/\_/      |_|\___/ 
                                           
                                           
  <<1. How To>>

Le PLD a été divisé en quatres "parties".
----
La première concerne le Bison/Flex, présent dans le dossier ./Bison/
Le Bison/Flex possède un Makefile à exécuter afin de générer le code nécessaire à la suite du projet.
----

----
La deuxième partie correspond au programme transformant notre language en assembleur.
Présent dans le dossier racine, il possède un makefile également (vérifier de bien make le bison avant de make cette solution).
Le fichier éxécutable généré (ReceptifCalc_WIN.exe sous Windows / ReceptifCalc_UNIX sous Mac/Linux) est le programme en lui même.

Il récupère via l'entrée standard le code qui sera traîté et transformé en assembleur.
En sortie standard sur le terminal, en prettyPrint vous retrouverez la structure détecté (cela permet de voir d'eventuelles erreures de portée de variables etc)
ainsi que le code généré.

Le code généré est également enregistré dans le fichier "generatedAss.s".
----

----
La troisième partie, nommée Assemblif, est un bout de code permetant d'assembler le fichier .s et de spécifier le nom de l'executable.
Il possède son propre dossier (./Assemblif/) ainsi que son propre makefile, qui génèrera l'exécutable "Assemblif" sous Linux/Mac et "Assemblif.exe" sous Windows.
Il prend en paramètre le fichier .s à assembler puis le nom de l'exécutable qui sera généré si tout se passe bien.
(Exemple : Assemblif.exe input.s output.exe)

Ce petit logiciel a été développé dans le but de pouvoir lire l'assembleur afin d'essayer de l'optimiser une dernière fois avant
de l'assembler. Cependant le manque de temps a fait qu'Assemblif se contente de simplifier l'assemblage.
----

----
La dernière partie concerne le framwork de test...............
----


  ___      _   _       _            
 |__ \    | \ | |     | |           
    ) |   |  \| | ___ | |_ ___  ___ 
   / /    | . ` |/ _ \| __/ _ \/ __|
  / /_ _  | |\  | (_) | ||  __/\__ \
 |____(_) |_| \_|\___/ \__\___||___/
                                    

Le bison, le programme principal et Assemblif peuvent tout les trois être compilés sous Windows, Linux et Mac (en supposant que certains outils tels que make soient disponibles).
Leurs makefiles sont facilement éditable pour Windows par exemple, pour pouvoir essayer d'utiliser un autre compilateur ou changer des options.
Cependant, l'assembleur généré est conçu pour un noyau Linux.

Le C++11 est utilisé et doit être géré par le compilateur.

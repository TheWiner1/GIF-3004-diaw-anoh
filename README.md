# GIF-3004-diaw-anoh
Dépôt pour le cours Systèmes Embarqués Temps Réel.

Tuto pour procédure de compilation

- créer un dossier projects/laboratoire5 sur le rpi
- changer l'adresser ip dans:
	- syncfile.sh du projet pi_clavier_module
	- ./vscode/launch.json du projet serveur
	- ./vscode/task.json du projet serveur
- remplacer "su setr" par "su nom_d_utilisateur" ou "sudo" sur une machine autre que fedora 
Compiler ET déboguer le projet serveur avec les touches  F7+F5(confirmer le mot de passe au cas echeant dans la ligne de commandes) dans visual studio
Compiler les modules du projet pi_module_clavier
- dans la palette de commande:
	-  aller dans Tâches: Exécuter la tâche , puis sélectionnez Compilation; puis
- lancer la tâche Tâches: Exécuter la tâche , puis sélectionnez toutsychroniser;
- dans le dossier laboratoire5 sur raspberryPI faire: sudo insmod setr_driver_polling.ko
Dans le projet client:
 lancer le script client en ligne de commande ./makeclient.sh
Dans le projet pc_module_clavier
su
mot de passe de su
make
insmod peripherique.ko 
Pour lancer le tout:
Brancher le keypad selon l’ordre prescrit dans les fichiers setr_driver_polling.c/setr_driver_irq.c
Dans le dossier laboratoire5 raspberry PI lancer le script:
sudo ./SETR_LABO_SERVEUR numeroDePort
Dans le dossier client sur le PC Linux lancer les commande en s’assurant d'être su:		
sur Fedora		
su
mot de passe de su
./client AdresseDeVotreRPI numeroPort /dev/Labo5_setr_driver
ou sur une autre machine linux
sudo ./client AdresseDeVotreRPI numeroPort /dev/Labo5_setr_driver
Appuyer les touches du clavier et observer les résultats sur la console client




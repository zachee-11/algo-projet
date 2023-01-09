#ifndef MOTEUR_TOOLS_H
#include <stdlib.h>
#define MOTEUR_TOOLS_H
#include <dirent.h>
#include <stdio.h>

//NOUS CLASSERONS NOS FONCTIONS DEFINIES DANS L'ORDRE D'EXECUTION DU PROGRAMME 

  void base_data(char *folder);              

  void lire_fichier(char *nom_fichier) ;

  int convertisseur(int argc, char *argv[]);

  int occurrences_str(const char *str, const char *word);

  int occurrences_file(FILE* file, const char *word);

  void ecrire_fichier_binaire(char *mot, int nb_occ);
  
  //à compléter...






#endif


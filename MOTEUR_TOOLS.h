#ifndef MOTEUR_TOOLS_H

#define MOTEUR_TOOLS_H

#include <stdio.h>



int occurrences_str(const char *str, const char *word);



int occurrences_file(FILE* file, const char *word);



int convertisseur(int argc, char *argv[]);



#endif


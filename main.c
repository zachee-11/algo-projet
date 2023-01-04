#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include "MOTEUR_TOOLS.h"

#define DEBUG_MODE

#include "DEBUG_TOOLS.h"





int main(int argc, char* argv[]) {



// Vérifiez qu'un argument a été passé au programme afin d'éviter une erreur de segmentation

if (argc < 2) {

printf("Usage : %s fichier %s mot \n", argv[0],argv[1]);

return 1;

}



// Ouvrez le fichier en lecture

FILE* file = fopen(argv[1], "r");

if (file == NULL) {

printf("Erreur lors de l'ouverture du fichier");

return 1;

}



// Explicite le nombre d'occurence du mot choisi

{

    const char *word = argv[2];

    FILE* file = fopen(argv[1], "r");

    int count = occurrences_file(file, word);

    printf("'%s' occurence %d fois dans le fichier \n", word, count);

    fclose(file);

    return 0;

}





}

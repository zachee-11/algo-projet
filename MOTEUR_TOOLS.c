#include "MOTEUR_TOOLS.h"

#define DEBUG_MODE

#include "DEBUG_TOOLS.h"

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>



int occurrences_str(const char *str, const char *word) {

    int count = 0;

    const char *p = str;

    int word_len = strlen(word);



    while ((p = strstr(p, word)) != NULL) {

        count++;

        p += word_len;

    }



    return count;

}





int occurrences_file(FILE* file, const char *word) {

    int count = 0;

    char buffer[1024];



    while (fgets(buffer, sizeof(buffer), file) != NULL) {

        count += occurrences_str(buffer, word);

    }

    return count;

}







int convertisseur(int argc, char *argv[]) {

    FILE *file;

    FILE *clean_file;

    int c;

    

// Vérifiez qu'un argument a été passé au programme afin d'éviter une erreur de segmentation

    if (argc != 2) {

        fprintf(stderr, "Usage: %s file\n", argv[0]);

        return 1;

    }

    

// Ouverture des fichier normal et clean

    clean_file = fopen ("clean_file.txt","a");

    file = fopen(argv[1], "r");

    

// Verifier si le fichier n'est pas NULL sinon affiche une erreur

    if (file == NULL) {

        perror(argv[1]);

        return 1;

    }

    

// Convertir le fichier en minuscule ainsi que trier les caracteres sans signe de ponctuations

    while ((c = fgetc(file)) != EOF) {

    if (!ispunct(c)) {

    	    fputc(c,clean_file);

            putchar(tolower(c));

        }

    }

   

    fclose(file);

    fclose(clean_file);

    return 0;

}

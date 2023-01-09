#include "MOTEUR_TOOLS.h"
#define DEBUG_MODE
#include "DEBUG_TOOLS.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//....................ouvrir un dossier....................................

void base_data(char *folder)

 {

	DIR *d;

	struct dirent *dir;

	d = opendir(folder);

	if (d) {

	while ((dir = readdir(d)) != NULL) {



	if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)    // J'ignore les fichiers "." et ".."

		    continue;

	if(dir->d_type==DT_DIR)                                              // on ignore les dossiers : 

		    continue;                                     

	printf("Nom du fichier: %s\n", dir->d_name);

	 lire_fichier(dir->d_name); 

	}

	closedir(d);

	

	}

	return;

 }

//---------------------------------lier un fichier----------------------------------------

void lire_fichier(char *nom_fichier) 

 {
	                                              // On ouvre le fichier en lecture
	FILE *fichier = fopen(nom_fichier, "r");
	                                               // On vérifie que le fichier a bien été ouvert
	if (fichier == NULL) {

	    printf("Erreur d'ouverture du fichier %s\n", nom_fichier);

	    exit(EXIT_FAILURE);

	}                                               // On lit le contenu du fichier ligne par ligne

	char ligne[256];

	while (fgets(ligne, sizeof(ligne), fichier) != NULL) {

	    printf("%s", ligne);

	}
	                                                   // On ferme le fichier

	fclose(fichier);
    
	return ;

 }

//.......................compter occurrence mot........................................

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
//--------------------------------compter nombre de mot du fichier------------------------------------------

int occurrences_file(FILE* file, const char *word) {

    int count = 0;

    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {

        count += occurrences_str(buffer, word);

    }

    return count;

}

//-------------------rendre uniforme la casse---------------------------------

/*int convertisseur(int argc, char *argv[]) {

    FILE *file;

    FILE *clean_file;

    int c;
// Vérifiez qu'un argument a été passé au programme afin d'éviter une erreur de segmentation

    if (argc != 2) {

        fprintf(stderr, "Usage: %s file\n", argv[0]);

        return 1;

    }

// Ouverture des fichier normal et clean

    clean_file = fopen (clean_file,a");

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
}  *****************************CE PROGRAMME EST à REVOIR CAR IL EST TROP LONG***********************************************************
*/

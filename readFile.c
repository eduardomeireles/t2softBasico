#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AUTHORS 
    proper_name ("Eduardo Meireles"), 
    proper_name ("Eduardo Godoi"), 

char **readFileToArray(FILE *file) {
    
    fseek (file, 0, SEEK_END);
    length = ftell (file);
    fseek (file, 0, SEEK_SET);

    string = malloc (length);
    if (string) {
        fread (string, 1, length, file);
    }
    fclose(file);
    
    
}

/* Índice Remissivo

Programação de Software Basico at PUCRS, Junho 2022.
Eduardo Meireles, Eduardo Godoi */

#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readFile.h"

/* The official name of this program.s */
#define PROGRAM_NAME "ir"

#define AUTHORS 
    proper_name ("Eduardo Meireles"), 
    proper_name ("Eduardo Godoi"), 

static struct option const long_options[] =
{
  {"ir", required_argument, NULL, 0},
  {GETOPT_HELP_OPTION_DECL},
  {GETOPT_VERSION_OPTION_DECL},
  {NULL, 0, NULL, 0}
};


void usage (int status) {
    if (status != EXIT_SUCCESS) {
      emit_try_help ();
    } else {
        printf (_("\
            Usage: %s [FILE]\n\
        "), program_name, program_name);
        fputs (_("\
            Cria um arquivo csv com uma lista de palavras e em qual paragrado aparece.\n\
        "), stdout);
    }
}

void getParagrafos(char text, FILE *output) {
    
    if(!text) return;


    char palavra[200] = '';

    int i = 0;
    int paragrafo = 1;

    for(i = 0; i < strlen(text); i++) {

        if ((text[i]>= 65 || text[i]<= 90) && (text[i]>= 97 || text[i]<= 122)) {
            palavra[i] = text[i];
        }

        if(text[i]<=32 || text[i]>=47) { 
           
            fprintf(output, "%s %s %s %d", "Palavra", palavra, " - Paragrafo: ", paragrafo);
            memset(palavra, 0, LENGTH);

        }

        if(text[i] == '\n') {
            paragrafo++;
        }
        
    }
   
}   
    

int main(int argc, char argv) {
    FILE *output = fopen("novoIr.csv", "w");
    if (!output) {
        printf("Não foi possível criar o arquivo\n");
        return 1;
    }

    FILE *file = fopen(argv, "r");
    char text = readFileToArray(file);

    getParagrafos(text, output);
    fclose(output);

    return 0;
}




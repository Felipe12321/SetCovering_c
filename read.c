#include <stdlib.h>
#include <string.h>
#include "read.h"

void read_params(const char *argv, int *params){

    //Abre archivos con datos.
    printf("Start reading\n");

    FILE *fp;
    fp = fopen(argv, "r");

    if (!fp)
    {
        printf("File not found...\n");
        exit (1);
    }

    for (int i = 0; i < 3; i++)
    {
        fscanf(fp, "%d", &params[i]);
    }
    fclose(fp);
}

void read_transmisores(int n, Transmisor *transmisores)
{
    printf("Reading transmisor file - %d\n", n);
    FILE *fp;
    fp = fopen("Input/transmisores.txt", "r");

    if (!fp)
    {
        printf("File not found...\n");
        exit(1);
    }
    
    for (int i = 0; i < n; i++)
    {
        transmisores[i].id = i;
        transmisores[i].on = 0;
        fscanf(fp, "%d %d", &transmisores[i].pos_x, &transmisores[i].pos_y);
    }
    fclose(fp);
}

void read_receptores(int n, int t, Receptor **receptores)
{
    printf("Reading receptor file - %d\n", n);
    FILE *fpReceptor, *fpFrecuencia;

    //Abre cada archivo de receptor con cada informacion de tiempo
    for (int i = 0; i < t; i++){

        //archivo de receptores
        char *name = "Input/receptores_";
        char *name_with_extension = malloc(strlen(name) + 10);
        char *buffer = malloc(sizeof(char) * sizeof(int) * 4 + 1);
        sprintf(buffer, "%d", i);

        strcpy(name_with_extension, name);
        strcat(name_with_extension, buffer);
        strcat(name_with_extension, ".txt");
        fpReceptor = fopen(name_with_extension, "r");

        //archivo de frecuencias

        name = "Input/frecuencia_";
        strcpy(name_with_extension, name);
        strcat(name_with_extension, buffer);
        strcat(name_with_extension, ".txt");
        fpFrecuencia = fopen(name_with_extension, "r");

        if (!fpReceptor|| !fpFrecuencia)
        {
            printf("File not found...\n");
            exit(1);
        }

        //Se guarda la información de cada receptor
        for (int j = 0; j < n; j++){
            receptores[i][j].id = j+n;
            fscanf(fpReceptor, "%d %d", &receptores[i][j].pos_x, &receptores[i][j].pos_y);
            fscanf(fpFrecuencia, "%s", &receptores[i][j].frecuencia);
            
        }

        fclose(fpReceptor);
        fclose(fpFrecuencia);
    }
}
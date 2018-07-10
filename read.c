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
        int c = fscanf(fp, "%d", &params[i]);
        if (c != 1)
            printf("Problem reading file\n");
    }
    fclose(fp);
}

void read_transmisores(int n, Transmisor *transmisores)
{
    printf("Reading Transmiter File - %d\n", n);
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
        int c = fscanf(fp, "%d %d", &transmisores[i].pos_x, &transmisores[i].pos_y);
        if (c != 2)
            printf("Problem reading file\n");
        
    }
    fclose(fp);
}

void read_receptores(int n, int t, Receptor **receptores)
{
    printf("Reading Reciver File - %d\n", n);
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
            int c = fscanf(fpReceptor, "%d %d", &receptores[i][j].pos_x, &receptores[i][j].pos_y);
            if (c != 2)
                printf("Problem reading file\n");
            c = fscanf(fpFrecuencia, "%s", &receptores[i][j].frecuencia);
            if (c != 1)
                printf("Problem reading file\n");
        }

        fclose(fpReceptor);
        fclose(fpFrecuencia);
    }
}

set_data read_in_set_data(int n, int m , int t){

    FILE *conexion;

    //abrir archivo conexion_
    char *name = "Input/conexion_";
    char *name_with_extension = malloc(strlen(name) + 10);
    char *buffer = malloc(sizeof(char) * sizeof(int) * 4 + 1);
    sprintf(buffer, "%d", t);

    strcpy(name_with_extension, name);
    strcat(name_with_extension, buffer);
    strcat(name_with_extension, ".txt");
    conexion = fopen(name_with_extension, "r");
        
    if (!conexion){
        printf("File not found...\n");
        exit(1);
    }

    set_data ret_struct;
    ret_struct.set_count = m;
    ret_struct.uniqu_element_count = n;

    unsigned int * element_buffer = (unsigned int *)malloc(n * sizeof(unsigned int));
    unsigned int * element_size   = (unsigned int *)malloc((n+2) * sizeof(unsigned int));
    memset(&element_size[0], 0, sizeof(unsigned int) * (n + 2));
    ret_struct.element_size_lookup = element_size;
    unsigned int *set_size = (unsigned int *)malloc(m * sizeof(unsigned int));
    ret_struct.set_sizes = set_size;
    unsigned int **sets = (unsigned int **)malloc(m * sizeof(unsigned int));
    ret_struct.sets = sets;
    unsigned short **weights = (unsigned short **)malloc(m * sizeof(unsigned short));
    ret_struct.weights = weights;
    ret_struct.max_weight = 0;
    ret_struct.all_element_count = 0;

    char str[n*2];
    char *pch;
    int i=0;
    while (fgets(str, n*2, conexion) != NULL){
        //printf("%s", str);
        pch = strtok(str, " ,.-");
        int element_counter = 0;
        while (pch != NULL)
        {
            int curr_element = atoi(pch);
            pch = strtok(NULL, " ,.-");
            if (curr_element == 0)
                continue;
            element_buffer[element_counter++] = curr_element;
            element_size[curr_element]++;
            ret_struct.all_element_count++;
            //printf("curr: %d\n", curr_element);
        }

        if(ret_struct.max_weight < element_counter){
            ret_struct.max_weight = element_counter;
        }
        unsigned int *elements = (unsigned int *)malloc(element_counter * sizeof(unsigned int));
        memcpy(elements,element_buffer,sizeof(int)*element_counter);
        unsigned short *weight = (unsigned short *)malloc(element_counter * sizeof(unsigned short));
        for (int j = 0; j < element_counter; j++){
            weight[j] = 1;
        }

        weights[i] = weight;
        sets[i] = elements;
        set_size[i] = element_counter;
        i++;
    }
    

    return ret_struct;
}
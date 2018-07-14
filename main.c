#include <stdio.h>
#include <stdlib.h>
#include "read.h"
#include "receptor.h"
#include "transmisor.h"
#include "set_data.h"
#include "set_cover.h"

int main(int argc, char const *argv[])
{
    
    //Se guardan los parametros del archivo ingresado con los parámetros
    // nro de receptores, nro de transmisores, periodos.
    int *params = malloc(3 * sizeof(int));
    read_params(argv[1], params);
    //Obtiene los nodos transmisores
    Transmisor *transmisores = malloc(params[1] * sizeof(Transmisor));
    read_transmisores(params[1], transmisores);
    //Obtiene los nodos receptores
    Receptor **receptores = malloc(params[2]);

    for(int i = 0; i < params[2]; i++)
        receptores[i] = malloc(params[0] * sizeof(Receptor));   
    
    read_receptores(params[0], params[2], receptores);

    printf("Reading Data File...\n");
    for (int t = 0; t < params[2]; t++){
        set_data set_data = read_in_set_data(params[0], params[1], t);

        set_cover setcover = new_setCover(set_data.set_count,           //cantidad de transmisores
                           set_data.uniqu_element_count, //cantidad de receptores
                           set_data.max_weight,          //cantidad maxima de receptores en todos los transmisores
                           set_data.all_element_count,   //total de conexiones
                           set_data.element_size_lookup);

        printf("Init Set Covering...\n");
        printf("Done.\n");
    }

    return 0;
}

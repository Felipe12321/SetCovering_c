#include <stdio.h>
#include <stdlib.h>
#include "read.h"
#include "receptor.h"
#include "transmisor.h"

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


    for (int i = 0; i < params[2]; i++)
    {
        for (int j = 0; j < params[0]; j++)
        {
            //printf("%d - (%d, %d) - %c\n", receptores[i][j].id, receptores[i][j].pos_x, receptores[i][j].pos_y, receptores[i][j].frecuencia);
        }
    }
        return 0;
}

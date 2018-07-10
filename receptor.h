#ifndef RECEPTOR
#define RECEPTOR

typedef struct _Receptor{
    int id;
    int pos_x;
    int pos_y;
    int id_transmisor;
    float distancia;
    int id_transmisor1;
    float distancia1;
    int id_transmisor2;
    float distancia2;
    char frecuencia;
} Receptor;

#endif
#ifndef READ
#define READ

#include <stdio.h>
#include "transmisor.h"
#include "receptor.h"
#include "set_data.h"

void read_params(const char *argv, int *params);
void read_transmisores(int n, Transmisor *transmisores);
void read_receptores(int n, int t, Receptor **receptores);
set_data read_in_set_data();

#endif
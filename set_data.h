#ifndef SETDATA
#define SETDATA

typedef struct set_data
{
    unsigned int **sets;
    unsigned short **weights;
    unsigned int *set_sizes;
    unsigned int *element_size_lookup;
    unsigned int set_count;
    unsigned int uniqu_element_count;
    unsigned int all_element_count;
    unsigned int max_weight;
} set_data;

#endif
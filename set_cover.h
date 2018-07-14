#ifndef __graphcluster__SetCover__
#define __graphcluster__SetCover__

#include <stdio.h>
#include "set_element.h"
#include "LinearMultiArray.h"

typedef struct set_cover{
    unsigned int add_position;
    int element_size;
    int set_size;
    int weight_range;
    set** ordered_by_score_set;
    element* set_elements;
    set * sets;
} set_cover;

set_cover new_setCover(unsigned int set_size,
                       unsigned int uniqu_element_size,
                       unsigned int weight_range,
                       unsigned int all_element_count,
                       unsigned int *element_size_lookup);
void destuctor_set_cover(set_cover set_cover);
void add_set(const int set_id, 
             const int set_weight,
             const unsigned int *element_ids,
             const unsigned short *weights,
             const int element_size);

#endif
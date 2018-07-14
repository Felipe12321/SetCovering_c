#ifndef __graphcluster__element__
#define __graphcluster__element__

#include <stdio.h>

struct element_meta_data{
    int element_id;
    int count;
};

typedef struct element {
    unsigned int element_id;
    unsigned short weight;
    
    struct set * parent_set;
    struct element * last;
    struct element * next;
}element;

typedef struct set{
    int set_id;
    unsigned short weight;

    struct element * elements;
    struct set * last;
    struct set * next;
}set;

element new_element(unsigned int element_id,unsigned short weight);
 
#endif
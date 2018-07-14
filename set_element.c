#include "set_element.h"

element new_element(unsigned int element_id,unsigned short weight){
    element e;
    e.element_id=element_id;
    e.weight=weight;
    return e;
}
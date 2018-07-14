#include <stdio.h>
#include "LinearMultiArray.h"


linear_multi_array* New_LMA(unsigned int * element_size_lookup,
                       unsigned int element_size,
                       unsigned int size) {
                       		linear_multi_array* LMA;
                       		LMA->size = max((unsigned int)1,size); //at least one
                       		LMA->multi_array = (linear_multi_array*)malloc(sizeof(*LMA)*size);
                       		LMA->next_pos_to_write=(linear_multi_array**) malloc( sizeof(*LMA)*(element_size+1));
                       		int last_element=0;
							for(unsigned int i = 0; i <= element_size; i++){
            					xorSwap(&element_size_lookup[0], &element_size_lookup[i+1]);
            					element_size_lookup[i+1] = last_element+element_size_lookup[i+1];
            					last_element = element_size_lookup[i+1];
        					}
							LMA->element_offset = element_size_lookup;
        					for(unsigned int i = 0; i <= element_size; i++){
            					LMA->next_pos_to_write[i] = &LMA->multi_array[LMA->element_offset[i]];
        					}
							return LMA; 
					   }

void destroy_multi_array(linear_multi_array *LMA){
	free(LMA->multi_array); 
	free(LMA->next_pos_to_write);	
}

void xorSwap (unsigned int * x, unsigned int * y){
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

pair* get_array(unsigned int *element_offset, int i, linear_multi_array *multi_array)
{
    pair *ret_value;
    int from = element_offset[i];
    int to   = element_offset[i+1];
    int size = to - from;
    ret_value->i = size;
    ret_value->LMA  = &multi_array[from];
    return ret_value;
}

void add_value_at(int i,linear_multi_array ** next_pos_to_write, linear_multi_array *LMA)
{
    *(next_pos_to_write[i]) = *
	LMA;
    next_pos_to_write[i]++;
}	
#ifndef __graphcluster__LinearMultiArray__
#define __graphcluster__LinearMultiArray__

#include <stdio.h>
#include <stdlib.h>

 #define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })


typedef struct linear_multi_array{
	unsigned int * element_size_lookup;
	unsigned int element_size;
	unsigned int size;
	unsigned int *element_offset;
	struct linear_multi_array ** next_pos_to_write;
	struct linear_multi_array * multi_array;
	
	
}linear_multi_array;

typedef struct{
	linear_multi_array* LMA;
	int i;
}pair;

linear_multi_array* New_LMA(unsigned int * element_size_lookup,
                       unsigned int element_size,
                       unsigned int size);
void xorSwap (unsigned int * x, unsigned int * y);
pair* get_array(unsigned int *element_offset, int i, linear_multi_array *multi_array);
void add_value_at(int i,linear_multi_array ** next_pos_to_write, linear_multi_array *LMA);

linear_multi_array* New_LMA(unsigned int * element_size_lookup,
                       unsigned int element_size,
                       unsigned int size);
void destroy_multi_array(linear_multi_array *LMA);

void xorSwap (unsigned int * x, unsigned int * y);

pair* get_array(unsigned int *element_offset, int i, linear_multi_array *multi_array);

void add_value_at(int i,linear_multi_array ** next_pos_to_write, linear_multi_array *LMA);				   
					   
#endif

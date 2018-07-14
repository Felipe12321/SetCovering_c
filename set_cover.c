#include <string.h>
#include "set_cover.h"
set_cover new_setCover(unsigned int set_size,
                       unsigned int uniqu_element_size,
                       unsigned int weight_range,
                       unsigned int all_element_count,
                       unsigned int *element_size_lookup)
{


    printf("New set cover... %d %d %d %d %d \n", set_size, uniqu_element_size,
                        weight_range,
                        all_element_count,
                        *element_size_lookup);
    set_cover sc;
    sc.set_size  = set_size;
    sc.element_size = uniqu_element_size;
    sc.weight_range = weight_range;
    sc.ordered_by_score_set = (set **)malloc((weight_range+1) * sizeof(set));
    memset(sc.ordered_by_score_set, 0, sizeof(set *)*(weight_range+1)); // init with 0 (no element is set)
    
    sc.set_elements = (element *) malloc(sizeof(element)*all_element_count);
    sc.sets = (set *) malloc(sizeof(set)*(set_size+1));
    sc.add_position = 0;
    return sc;
}
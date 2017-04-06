#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP


#include "array.hpp"

 int choose_division(stru::array<int>& , int ,  int );
void swap_array(stru::array<int>& original, int index_1,  int right);
 int divide_array(stru::array<int>& original, int left,  int right);
void quick_sort(stru::array<int>& original, int left,  int right);





#endif

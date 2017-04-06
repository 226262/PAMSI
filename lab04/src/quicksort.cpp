
#include "../inc/quicksort.hpp"








  void quick_sort(stru::array<int>& original, int left,  int right){

  int i=(left+right)/2;
  int j=0;
  int pivot=original[i];
  original[i]=original[right];

  for(j=i =left;i<right;i++){
  if(original[i]<pivot){
  swap_array(original,i, j);
  j++;
  }
  original[right]=original[j];
  original[j]=pivot;
    
  if(left<j-1) quick_sort(original,left, j-1);
  if(j+1<right) quick_sort(original,j+1, right);
    
  }
 
  }
  void swap_array(stru::array<int>& original, int index_1,  int index_2){

  int temp= original[index_1];
  original[index_1]=original[index_2];
  original[index_2]=temp;

  }

/*
void quick_sort(stru::array<int>& original,int left,  int right){

  if(left<right){

    int divided= divide_array(original,left,right);
    quick_sort(original,left,divided-1);
    quick_sort(original,divided+1,right);
    
  }
  
}

int divide_array(stru::array<int>& original,int left,  int right){

  int division_index = choose_division(original,left,right);
  int element= original[division_index];
  swap_array(original,division_index,right);
  int actual_position=left;

  for( int i=0; i<right-1;i++){

    if(original[i]<element){
      swap_array(original, i, actual_position);
      actual_position++;
    }    
  }

  swap_array(original,actual_position,right);
  return actual_position;
 
}

void swap_array(stru::array<int>& original, int index_1,  int index_2){

  int temp= original[index_1];
  original[index_1]=original[index_2];
  original[index_2]=temp;

}

int choose_division(stru::array<int>& original, int left,  int right){

  
  return left + ((right-left)/2);

}
*/

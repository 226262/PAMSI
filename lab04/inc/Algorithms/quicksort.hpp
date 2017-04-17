/*
  This class sorts user defined class (interface iquicksortable), and uses implementation of quicksort algorithm.

*/


#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include<cstdlib>
#include<iostream>
#include"../Interfaces/iquicksortable.hpp"
#include"../Interfaces/irunnable.hpp"

class quicksort: public stru::irunnable{

private:
  //iquicksortable object to sort
  stru::iquicksortable<int>& object;
  
public:

  //Methods specific for quicksort algorithm:
  quicksort(stru::iquicksortable<int>& starter);
  ~quicksort();
  inline void swap(int index_1, int index_2);
  void sort(int left, int right, int option);
  void fill_random(unsigned int howmany);
  bool is_sorted();
  
  //Methods from irunnable interface:
  virtual void perform_run(unsigned int size, char option);
  virtual void reset();
  virtual void prepare(unsigned int size,char option);
  
  
};


//DEFINITIONS OF METHODS ABOVE:


bool quicksort::is_sorted(){

  int first;
  int second;
  
  for (int i=0;i<object.get_last_index()-1;i++){

    first=object[i];
    second=object[i+1];
    
    if(first>second){
      return false;
    }
  }
  
  return true;
  
}

quicksort::quicksort(stru::iquicksortable<int>& starter)
  :object(starter){
}

quicksort::~quicksort(){
  
}


void quicksort::sort(int left,int right, int option){

  //Default option for pivot:
  int i=(right+left)/2;

  //Choose option for pivot:
  if(option==0){
    i=left;
  }else if(option==1){
    i=right;
  }
  
  
  int pivot=object[i];
  object[i]=object[right];
  int j=left;
  i=left;

  //PARTITION:
  while(i<right){

    if(object[i]<pivot){
      swap(i,j);
      j++;
    }
    i++;
  }
  object[right]=object[j];
  object[j]=pivot;

  //continue:
  if(left<j-1) sort(left,j-1,option);
  if(j+1<right) sort(j+1,right,option);  
}

inline void quicksort::swap(int index_1, int index_2){

  int temp=object[index_1];
  object[index_1]=object[index_2];
  object[index_2]=temp;
  
}

void quicksort::fill_random(unsigned int howmany){
  
  for(unsigned int i=0;i<howmany;i++){
    int random_number=(std::rand()%howmany)+0;
    object.set_element(random_number);
  }
}


void quicksort::perform_run(unsigned int size, char option){

  //Options: f- pivot is always first
  //         l- pivot is always last
  //       any- pivot is in the middle
  
  if(option=='f'){
    sort(0,size-1, 0);    
  }else if(option=='l'){
    sort(0,size-1,1 );
  }else {
    sort(0,size-1, 2);
  }

  
  if(!this->is_sorted()){
    std::cerr<< "ERR: NOT  SORTED AFTER SORT!\n";
  }
  
}

void quicksort::reset(){

  object.reset();
  
}


void quicksort::prepare(unsigned int size,char option){

  //Options: r- fill with random numbers
  //         i- prepare with increasing array
  //         d- prepare with decreasing array

  switch(option){

  case 'r':
    fill_random(size);
    break;

  case'i':
    fill_random(size);
    sort(0,size-1,2);
    break;

  case'd':
    fill_random(size);
    sort(0,size-1,2);
    for (unsigned int i=0;i<(size-1)/2;i++){
      swap(i,(size-1)-i);
    }
    break;

  default:
    fill_random(size);
    break;

  }
  
  
}
  
#endif

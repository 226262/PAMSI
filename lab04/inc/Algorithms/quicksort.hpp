
#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP


#include<cstdlib>
#include<iostream>
#include"../Interfaces/iquicksortable.hpp"
#include"../Interfaces/irunnable.hpp"

class quicksort: public stru::irunnable{

private:
  
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
  :object(starter)
{
}

quicksort::~quicksort(){
  
}

void quicksort::sort(int left,int right, int option){

  int i=(left+right)/2;
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

  sort(0,size-1, 2);
  
  if(!this->is_sorted()){
    std::cerr<< "ERR: NOT  SORTED AFTER SORT!\n";
  }

}

void quicksort::reset(){

  object.reset();
}

void quicksort::prepare(unsigned int size,char option){

  fill_random(size);
}
  

/*
  inline void swap(stru::iquicksortable<int>& object, int index_1, int index_2){

  int temp=object[index_1];
  object[index_1]=object[index_2];
  object[index_2]=temp;
  }


  void quicksort(stru::iquicksortable<int>& object, int left, int right, int option){

  int i=(left+right)/2;
  int pivot=object[i];
  object[i]=object[right];
  int j=left;
  i=left;

  //PARTITION:
  while(i<right){

  if(object[i]<pivot){
  swap(object,i,j);
  j++;
  }
  i++;
  }
  object[right]=object[j];
  object[j]=pivot;

  //continue:
  if(left<j-1) quicksort(object, left,j-1,option);
  if(j+1<right) quicksort(object, j+1,right,option);
  
  }
*/
#endif

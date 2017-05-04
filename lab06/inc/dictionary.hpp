#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <iostream>

#include "couple.hpp"
#include "array.hpp"
#include "list.hpp"
#include "IContainers/idictionary.hpp"
#include "Interfaces/irunnable.hpp"

template <typename KEY_TYPE, typename DATA_TYPE>
class dictionary : idictionary<KEY_TYPE,DATA_TYPE>, public irunnable {//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
private:

  unsigned int length;
  //Main array of lists of couples... (strange i know)
  list<couple<KEY_TYPE,DATA_TYPE>>* T; 

public:     //PUBLIC SPECIFICATOR           
  
  //Constructors and destructor:
  dictionary(unsigned int  space);
  virtual ~dictionary();

  //THESE METHODS WILL BE IN PRIVATE SPECIFICATOR! ONLY FOR TESTNG
  unsigned int hash(std::string tohash,char option='e');
    
  //Methods from idictionary interface
  virtual DATA_TYPE& lookup(KEY_TYPE key) const;
  virtual void delete_couple(KEY_TYPE key);
  virtual void add_couple(KEY_TYPE key, DATA_TYPE data);
  virtual void reassign(KEY_TYPE key, DATA_TYPE data);
  virtual DATA_TYPE& operator[](KEY_TYPE key);

  //Methods from irunnable interface
  virtual void perform_run(unsigned int size, char option);
  virtual void reset();
  virtual void prepare(unsigned int size,char option);
  
  
  //Temporary methods for debugging:
  void print();

  
        
};//~~~~~~~~~~~~~~~~~~~END OF DICTIONARY CLASS ~~~~~~~~~~~~~~~~~~~~~~~~~


//DEFINITIONS OF METHODS ABOVE:


//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
dictionary<KEY_TYPE,DATA_TYPE>::dictionary(unsigned int  space)
  : length(space)
{
  T=new list<couple<KEY_TYPE,DATA_TYPE>>[length];
}


//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
unsigned int dictionary<KEY_TYPE,DATA_TYPE>::hash(std::string tohash, char option){

  //Glorius return motherland
  unsigned int ZSRR=0;   
  
  //Swap string to unsigned int!
  for(int KOMUNIZM=0; KOMUNIZM<tohash.size();KOMUNIZM++){
    char Lenin=tohash.at(KOMUNIZM);
    ZSRR+=(unsigned int)Lenin;                      //Casting char to ASCII table 
  }
  
  if (option =='s'){   //SIMPLE HASH 
    ZSRR=ZSRR%length;
    return ZSRR;  
  }else {  //Any other is great hash function ;>
    ZSRR=ZSRR%length;
    return ZSRR;
  }
}


//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
dictionary<KEY_TYPE,DATA_TYPE>:: ~dictionary(){

  delete [] T;
}

//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
DATA_TYPE&  dictionary<KEY_TYPE,DATA_TYPE>::lookup(KEY_TYPE key) const{
  
}


//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
void dictionary<KEY_TYPE,DATA_TYPE>::delete_couple(KEY_TYPE key){
  
}



//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
void dictionary<KEY_TYPE,DATA_TYPE>::add_couple(KEY_TYPE key, DATA_TYPE data){

  unsigned int index=hash(key);
  couple<KEY_TYPE,DATA_TYPE> to_add(key,data);
  T[index].push_front(to_add);
  
}


//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
void dictionary<KEY_TYPE,DATA_TYPE>::reassign(KEY_TYPE key, DATA_TYPE data){
  
}



//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
DATA_TYPE& dictionary<KEY_TYPE,DATA_TYPE>::operator[](KEY_TYPE key){
  
}


//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
void dictionary<KEY_TYPE,DATA_TYPE>:: perform_run(unsigned int size, char option){
  
}


//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
void dictionary<KEY_TYPE,DATA_TYPE>::reset(){
  
}


//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
void dictionary<KEY_TYPE,DATA_TYPE>::prepare(unsigned int size,char option){
  
}


//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
void dictionary<KEY_TYPE,DATA_TYPE>::print(){

  std::cout << length<<"<-dlugosc tabliy haszujacej\n";
  for(int i=0;i<length ;i++){

    std::cout << i<<" ";
    T[i].print();
    std::cout<<"\n";
    }
}

#endif

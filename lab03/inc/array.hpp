/*
  Made by  226262 Wrocław University of Technology

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA


  This header contains dynamic array template.
  Interface:
  -push_back(element) -creates element on the end of array. If there
  is no space it calls allocate_to(2x capacity) for space for additional elements   
  -pop_back()         -deletes last element. If number of elements is less than 1/4 of 
  capacity it calls allocate_to(capacity/2) to not wasting space 
  -insert(index, element) -inserts in index new element
  -operator[index]- returning pointer for element in index
  Private:
  -n              - number of elements
  -capacity       -current memory capacity in array
  -tab            -actual pointer to array
  -allocate_to(number)   - allocates new array with capacity=number. Can delete elements!

  WARNING: this implementation contains printing out some messages (mainly for debugging)
  Additional information: this implementation is inspired by the book: "Introduction to Algorithms" Cormen, Leiserson, Stein and Rivest 
*/
#ifndef ARRAY_HPP
#define ARRAY_HPP


#include<iostream>
#include"irunnable.hpp"

namespace stru                        //my namespace "STRUctures"
{
  template <typename TYP>
  class array : public stru::irunnable{//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        
  private:   //DEFAULT PRIVATE SPECIFICATOR

    unsigned int capacity;
    unsigned int n;
    TYP* tab;

    //Private method fo allocation:
    void allocate_to(unsigned int howmany);

        
  public:     //PUBLIC SPECIFICATOR           

    //Constructors and destructor:
    array();
    array(TYP value);
    virtual ~array();
      
    //Interface from Irunnable:
    virtual void perform_run(unsigned int size, unsigned short int option);
    virtual void reset();
    virtual void prepare(unsigned int size);
      
    //specific methods for array:
    void push_back(TYP value,unsigned short int option=2);
    void pop_back();
    void insert(unsigned int where,TYP what);
    void print()const;

    //Getters:
    const unsigned int get_capacity() const;
    const unsigned int get_size() const;

    //Overloaded operators:
    TYP& operator[](unsigned int indeks) const;
        
  };//END OF CLASS ARRAY//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




    //DEFINITIONS OF METHODS ABOVE:


  template <typename TYP>
  void array<TYP>::allocate_to(unsigned int howmany){

    //std::cout<<"Bylo: "<<this->capacity<<" Alokuje: "<<howmany<<std::endl;
    if(n>howmany){          //Cutting  off if You want to allocate less memory than numbers
      n=howmany;
    }
    capacity=howmany;
    TYP* newtab=new TYP[capacity];

    for(unsigned int i=0;i<n;i++){
      newtab[i]=tab[i];
    }    
    delete[] tab;
    tab=newtab;
  }

  //*************************************************//
  template <typename TYP>
  array<TYP>::array()                       //default  constructor 
    :capacity(0)
    ,n(0)
    ,tab(nullptr)
  {
  }


  //*************************************************//
  template <typename TYP>
  void array<TYP>::perform_run(unsigned int size, unsigned short int option){
    for(unsigned int i=0;i<size;i++){
      this->push_back(TYP(0),option);
    }
  }


  //*************************************************//
  template <typename TYP>
  void array<TYP>::reset(){
    allocate_to(0);
  }


  //*************************************************//
  template <typename TYP>
  array<TYP>::array(TYP value)       //constructor creates first Type 
    :capacity(1)
    ,n(1)
  {
    tab=new TYP[capacity];
    tab[0]=value;
  }


  //*************************************************//
  template <typename TYP>
  void array<TYP>::print()const {      //This method is only for testing!
    std::cout<<"Zawartosc tablicy: \n";
    for (unsigned int i=0;i<n;i++){
      std::cout<<"EL:"<<i<<" "<<this->tab[i]<<"\n";
    }
    std::cout<<"\n";
  }


  //*************************************************//
  template <typename TYP>
  void array<TYP>::push_back(TYP value,unsigned short int option){
    if(!capacity){                       //If capacity equals 0
      allocate_to(1);
    }
    if(capacity==n){
      if(option==1){
	allocate_to(capacity+1);
      }else{
	allocate_to(option*capacity);
      }
    }
    tab[n]=value;
    n++;
  }


  //*************************************************//
  template <typename TYP>
  void array<TYP>::insert(unsigned int where,TYP what){
    if(n<where){
      std::cerr<<"~~~~~~~~~~~~~~~\nBad using INSERT method. Out of avalible space!\n~~~~~~~~~~~~~~~\n";
      return;
    }
    if(capacity<=n){         //If not enough space for insertion:
      //   std::cout<<"Bylo: "<<this->capacity<<" Alokuje 2x wiecej!\n";
      capacity=2*capacity;
      TYP* newtab=new TYP[capacity];
        
      for(unsigned int i=0;i<where;i++){
	newtab[i]=tab[i];
      }
      newtab[where]=what;
      for(unsigned int i=where;i<n;i++){
	newtab[i+1]=tab[i];
      }  
      delete[] tab;
      tab=newtab;
      n++;

    }else{                                        //If avalible space is ok
      TYP* newtab=new TYP[capacity];
        
      for(unsigned int i=0;i<where;i++){
	newtab[i]=tab[i];
      }
      newtab[where]=what;
      for(unsigned int i=where;i<n;i++){
	newtab[i+1]=tab[i];
      }    
      delete[] tab;
      tab=newtab;
      n++;
    }
  }


  //*************************************************//
  template <typename TYP>
  void array<TYP>::pop_back(){
    if(!n || n==1){
      allocate_to(0);            //Idiotoodpornosc here
      return;
    }else{  //If number of elements is not 0 or 1 

      if(n<0){ 
	std::cerr<<"NIE POWINNO BYC UJEMNYCH ELEMENTOW :O \n"; 
	return;

      }
      if(n>0){
	n--;
      }
      if(n<=capacity/4){
	allocate_to(capacity/2);
      }else{
	allocate_to(capacity);
      }
    }
  }


  //*************************************************//
  template <typename TYP>
  const unsigned int array<TYP>::get_size() const{
    return n;
  }


  //*************************************************//
  template <typename TYP>
  const unsigned int array<TYP>::get_capacity() const{
    return capacity;
  }


  //*************************************************//
  template <typename TYP>
  TYP& array<TYP>::operator[](unsigned int indeks) const{
    if(indeks<n){
      return this->tab[indeks];
    }else
      exit(0);
  }

  //*************************************************//
  template <typename TYP>
  void array<TYP>::prepare(unsigned int size){
        
  }


  //*************************************************//
  template <typename TYP>
  array<TYP>::~array(){                        //Destructor
    delete[] tab;
  }

}//END OF stru NAMESPACE
#endif

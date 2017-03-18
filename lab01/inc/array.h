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
#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>

namespace stru                        //my namespace "STRUctures"
{
    template <typename TYP>
    class array{                     //Simple array  (USING COUT FOR TESTING!)
            
        unsigned int capacity,n;
        TYP* tab;
        
        //*************************************************//
        void allocate_to(unsigned int howmany){

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

        public:           
        //*************************************************//
        array()                       //default  constructor 
            :capacity(0)
            ,n(0)
            ,tab(nullptr)
        {
        }

        //*************************************************//
        array(TYP value)       //constructor creates first Type 
            :capacity(1)
            ,n(1)
        {
            tab=new TYP[capacity];
            tab[0]=value;
        }

        //*************************************************//
        void print()const {      //This method is only for testing!
            std::cout<<"Zawartosc tablicy: \n";
            for (unsigned int i=0;i<n;i++){
                std::cout<<"EL:"<<i<<" "<<this->tab[i]<<"\n";
            }
            std::cout<<"\n";
        }

        //*************************************************//
        void push_back(TYP value,unsigned short int option=2){
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
        void insert(unsigned int where,TYP what){

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
        void pop_back(){
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
        const unsigned int get_size() const{
            return n;
        }
        //*************************************************//
        const unsigned int get_capacity() const{
            return capacity;
        }

        //*************************************************//
        TYP& operator[](unsigned int indeks) const{
            if(indeks<n){
                return this->tab[indeks];
            }else
                exit(0);
        }

        //*************************************************//
        ~array(){                        //Destructor
        
            delete[] tab;
        }


    };


}
#endif
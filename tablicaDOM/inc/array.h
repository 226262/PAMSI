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
*/
#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>

namespace stru                        //my namespace "STRuctures"
{
    template <typename TYP>
    class array{                     //Simple array (i don't know yet what will this do)
            
        unsigned int capacity,n;
        TYP* tab;
        
        
        //*************************************************//
        void allocate_to(unsigned int howmany){

            std::cout<<"Bylo: "<<this->capacity<<" Alokuje: "<<howmany<<std::endl;
            if(n>howmany){
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
<<<<<<< HEAD
        array()                       //default  constructor (THANKS AREK ZEMA <3)
=======
        array()                       //basic constructor
>>>>>>> b12f174c4f1ec2f657e56369bdc683a4ab984024
            :capacity(0)
            ,n(0)
            ,tab(nullptr)
        {
            std::cout<<"Array Constructor\n";
        }

        //*************************************************//
        array(TYP value)       //constructor creates first Type 
            :capacity(1)
            ,n(1)
        {
            tab=new TYP[capacity];
            tab[0]=value;
            std::cout<<"Array Constructor"<<value<<"\n";
        }

        //*************************************************//
        void print()const {
            std::cout<<"Zawartosc tablicy: \n";
            for (unsigned int i=0;i<n;i++){
                std::cout<<"EL:"<<i<<" "<<this->tab[i]<<"\n";
            }
            std::cout<<"\n";
        }
        


        //*************************************************//
        void push_back(TYP value){
            if(!capacity){                       //If capacity equals 0
                allocate_to(1);
            }
            if(capacity==n){
                allocate_to(2*capacity);
                
            }
            tab[n]=value;
            n++;
        }
        //*************************************************//
        int insert(unsigned int where,TYP what){
            if(n<where){
                std::cerr<<"~~~~~~~~~~~~~~~\nBad using INSERT method. Out of avalible space!\n~~~~~~~~~~~~~~~\n";
                return 0;
            }
            if(capacity==n){
                allocate_to(2*capacity);
            }

            return 1;
        }
        //*************************************************//
        void pop_back(){
            if(!n){
                allocate_to(0);            //Idiotoodpornosc here
                return;
            }else 
            if(n<0){ std::cerr<<"NIE POWINNO BYC UJEMNYCH ELEMENTOW :O \n"; return;
            }else
            if(n>0){
                n--;
            }
            if(!n){
                allocate_to(0);
                return;
            }else
            if(n<=capacity/4){
                allocate_to(capacity/2);
            }else{
                allocate_to(capacity);
            }

        }
        //*************************************************//
        TYP *search(TYP value){                
            for (unsigned int i=0;i<n;i++){
                if(tab[i]==value) {
                    return &tab[i];
                }
            }
            return nullptr;                      
        }
        //*************************************************//
        unsigned int get_size() const{
            return n;
        }
        //*************************************************//
        unsigned int get_capacity() const{
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
        ~array()                        //Destructor
        {
            delete[] tab;
            std::cout<<"Array Destructor\n";}


    };


}
#endif
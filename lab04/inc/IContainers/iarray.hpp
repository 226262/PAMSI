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
#ifndef IARRAY_HPP
#define IARRAY_HPP


namespace stru                        //my namespace "STRUctures"
{
  template <typename TYP>
  class iarray {//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        
  public:     //PUBLIC SPECIFICATOR           

    //Constructors and destructor:
    iarray(){}
    virtual ~iarray(){}
      

    //specific methods for array:
    virtual void push_back(TYP value,unsigned short int option=2)=0;
    virtual void pop_back()=0;
    virtual void insert(unsigned int where,TYP what)=0;
    virtual void print()const=0;

    //Getters:
    virtual const unsigned int get_capacity() const=0;
    virtual const unsigned int get_size() const=0;

    //Overloaded operators:
    virtual TYP& operator[](unsigned int indeks) const=0;
        
  };

}//END OF stru NAMESPACE
#endif

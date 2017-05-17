/************************************************************************************    
 *    Made by  226262 Wroclaw University of Technology                               *                
 *                                                                                   *                        
 *    This program is free software; you can redistribute it and/or modify           *            
 *    it under the terms of the GNU General Public License as published by           *        
 *    the Free Software Foundation; either version 2 of the License, or              *            
 *    (at your option) any later version.                                            *            
 *                                                                                   *
 *    This program is distributed in the hope that it will be useful,                *            
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of                 *            
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                  *        
 *    GNU General Public License for more details.                                   *        
 *                                                                                   *        
 *    You should have received a copy of the GNU General Public License              *                    
 *    along with this program; if not, write to the Free Software                    *        
 *    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA     *    
 *                                                                                   *        
 *************************************************************************************/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  This program contains multiple interfaces with implementation.
  Basic usage is for measuring time of some classes which derive
  from irunnable interface 
  

  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include <string>

#include"../inc/array.hpp"
#include"../inc/timer.hpp"
#include"../inc/stack.hpp" 
#include "../inc/queue.hpp"
#include"../inc/list.hpp"
#include"../inc/Algorithms/quicksort.hpp"
#include "../inc/dictionary.hpp"
#include "../inc/couple.hpp"

//*********************************************************//
int main(int argc, char *argv[]){


  unsigned int size= atoi(argv[1]);         
  unsigned int elements= atoi(argv[2]);     
  //Set time for random numbers 
  srand(time(NULL));
  timer timerek;
  dictionary<std::string,int> dict(size);

  
  

  std::cout <<"simple: "<<timerek.measure_time(dict,10,elements,'s','s')<<"\n";
  std::cout <<"good: "<<timerek.measure_time(dict,10,elements,'e','e')<<"\n";

  
  /*
  dict.add_couple("1",666);
  dict.add_couple("dupa",666);
  dict.add_couple("zzzzzzzz",823);
  dict.add_couple("ksnd",666);
  dict.add_couple("sadf",666);
  dict.add_couple("dfds",666);
  dict.add_couple("dsad",666);
  dict.add_couple("zuap",666);
  dict.print();

  
  dict.lookup("zupa");
  */

  //  dict.prepare(1000,'s');
  //dict.print();

  

  
  return 0;
    
}



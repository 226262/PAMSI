


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
 *    along with this program; if not, write to the Free Software                   *        
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

#include"../inc/array.hpp"
#include"../inc/timer.hpp"
#include"../inc/stack.hpp" 
#include "../inc/queue.hpp"
#include"../inc/list.hpp"
#include"../inc/Algorithms/quicksort.hpp"

//*********************************************************//
int main(int argc, char *argv[]){

  
  //  std::cout << STOPEREK.measure_time(stosik,1, 10, 1)<<"\n";
  srand(time(NULL));

  timer STOPEREK;
  
  stru::array<int> tablica;

  quicksort sortownik(tablica);

  
  //  sortownik.sort(0, 19, 1);
  std::cout<<STOPEREK.measure_time(sortownik,100, 10, 'c')<<"\n";


  //std::cout << "jestem\n";
      
  return 0;
    
}



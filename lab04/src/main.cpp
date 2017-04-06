


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
#include<iostream>
#include<fstream>
#include<cstdlib>

#include"../inc/array.hpp"
#include"../inc/timer.hpp"
#include"../inc/stack.hpp"
#include "../inc/queue.hpp"
#include"../inc/list.hpp"
#include"../inc/quicksort.hpp"


//*********************************************************//
int main(int argc, char *argv[]){

  
  //  std::cout << STOPEREK.measure_time(stosik,1, 10, 1)<<"\n";



  stru::array<int> tablica;

  tablica.push_back(2);
  tablica.push_back(1);
  tablica.push_back(4);
  tablica.push_back(2);
  tablica.push_back(3);
  tablica.print();
  

  //std::cout  << "jestem\n";
  quick_sort(tablica,0,4);

  
  tablica.print();

  
  return 0;
    
}



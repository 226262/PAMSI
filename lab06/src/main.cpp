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

  //Set time for random numbers 
  srand(time(NULL));

  dictionary<std::string,int> dict(20);

  dict.add_couple("dupa",666);
  dict.add_couple("zupa",666);
  dict.add_couple("grzybeczki",666);
  dict.add_couple("zenit_chempion",666);
  dict.add_couple("ALLAHU AKHBAR!",666);
  dict.add_couple("Wrestling_wrestler_fucking_sucker",666);
  dict.print();

    

      
  return 0;
    
}



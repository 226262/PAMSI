


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

#include"../inc/array.hpp"
#include"../inc/timer.hpp"
#include"../inc/stack.hpp" 
#include "../inc/queue.hpp"
#include"../inc/list.hpp"
#include"../inc/Algorithms/quicksort.hpp"

//*********************************************************//
int main(int argc, char *argv[]){

  
  srand(time(NULL));

  if(argc<3){
    std::cerr<<"USE THIS PROGRAM:\n ./engine <FILENAME> <HOW MANY ELEMENTS> <OPTIONS>\n";
    exit(0);
  }
  
  std::ofstream datafile;                         //File stream declaration
  unsigned int elements= atoi(argv[2]);         //Number of elements
  char  options=atoi(argv[3]);       //options for allocation
  char options_run=*argv[4];

  timer STOPEREK;
  
  stru::array<int> tablica;

  quicksort sortownik(tablica);


  //Open file with name of first argument
  datafile.open(argv[1]);                        

  if(datafile.is_open()){

    datafile<<"RANDOM:\n";
    datafile<<STOPEREK.measure_time(sortownik, 1, elements, 'r','f')<<" Pivot first\n";    
    datafile<<STOPEREK.measure_time(sortownik, 1, elements, 'r','l')<<" Pivot last\n";
    datafile<<STOPEREK.measure_time(sortownik, 1, elements, 'r','m')<<" Pivot middle\n";
    
    datafile<<"INCREASING:\n";
    datafile<<STOPEREK.measure_time(sortownik, 1, elements, 'i','f')<<" Pivot first\n";    
    datafile<<STOPEREK.measure_time(sortownik, 1, elements, 'i','l')<<" Pivot last\n";
    datafile<<STOPEREK.measure_time(sortownik, 1, elements, 'i','m')<<" Pivot middle\n";

    datafile<<"DECREASING:\n";
    datafile<<STOPEREK.measure_time(sortownik, 1, elements, 'd','f')<<" Pivot first\n";    
    datafile<<STOPEREK.measure_time(sortownik, 1, elements, 'd','l')<<" Pivot last\n";
    datafile<<STOPEREK.measure_time(sortownik, 1, elements, 'd','m')<<" Pivot middle\n";
           
  } 
      
  return 0;
    
}



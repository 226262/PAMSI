
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

//*********************************************************//
int main(int argc, char *argv[]){

  if(argc<3){
    std::cerr<<"USE THIS PROGRAM:\n ./engine <FILENAME> <HOW MANY ELEMENTS> <OPTIONS>\n";
    exit(0);
  }

  
  std::ofstream datafile;                         //File stream declaration
  unsigned int elements= atoi(argv[2]);         //Number of elements
  unsigned short int options=atoi(argv[3]);       //options for allocation

  
  timer STOPEREK;
  stru::array<int> tablica;
  stru::stack<int> stosik;
  stru::queue<int> kolejka;
  stru::list<int>  lista;

  
  
  datafile.open(argv[1]);                         //Open file with name of first argument

  if(datafile.is_open()){

    datafile<<"stos, elements:"<<elements<<"\n";
    datafile<<STOPEREK.measure_time(stosik, 20, elements, options)<<"\n";
    datafile<<"kolejka, elements:"<<elements<<"\n";
    datafile<<STOPEREK.measure_time(kolejka, 20, elements, options)<<"\n";
    datafile<<"lista, elements:"<<elements<<"\n";
    datafile<<STOPEREK.measure_time(lista, 20, elements, options)<<"\n";

    
  }                  //If opened succesfully 

  //  std::cout << STOPEREK.measure_time(stosik,1, 10, 1)<<"\n";
  
  return 0;
    
}



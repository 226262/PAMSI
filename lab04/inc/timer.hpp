/*
  This class is just like stopwatch. 
  It measures time of run of any irunnable object.
  WARNING: object which is measured is reset after run! 
*/
#ifndef TIMER_HPP
#define TIMER_HPP

#include<chrono>
#include"Interfaces/irunnable.hpp"
#include"array.hpp"


typedef std::chrono::high_resolution_clock Clock;   

class timer{
    
  //Private methods:
  unsigned int measure_one(stru::irunnable& ToMeasure, unsigned int size
			   ,char option,char option_perform);
    
public:

  //Constructor and destructor:
  timer();
  ~timer();

  //Public methods:
  unsigned int measure_time(stru::irunnable& ToMeasure, unsigned int HowManyTimes
			    ,unsigned int size,char option,char option_perform);

};

#endif

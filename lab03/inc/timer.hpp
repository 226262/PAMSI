/*
This class is just like stopwatch. 
It measures time of run of any irunnable object.
WARNING: object which is measured is reset after run! 
*/
#ifndef TIMER_HPP
#define TIMER_HPP

#include<chrono>

#include"irunnable.hpp"
#include"array.hpp"


typedef std::chrono::high_resolution_clock Clock;   

class timer{
    
    //Private methods:
    unsigned int measure_one(stru::irunnable& ToMeasure, unsigned int size,unsigned short int option);
    
    public:

    //Constructor and destructor:
    timer();
    ~timer();

    //Public methods:
    unsigned int measure_time(stru::irunnable& ToMeasure, unsigned int HowManyTimes, unsigned int size,unsigned short int option);

};

#endif

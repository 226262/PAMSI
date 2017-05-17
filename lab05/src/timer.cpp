#include"../inc/timer.hpp"


timer::timer(){}

timer::~timer(){}


unsigned int timer::measure_one(stru::irunnable& ToMeasure, unsigned int size
				,char option,char option_perform){

  //Reset object to measurement
  ToMeasure.reset();  
  //Prepare object for measurement
  ToMeasure.prepare(size,option);
  //START CLOCK
  auto start_time= Clock::now();    
  //Calculate!
  ToMeasure.perform_run(size,option_perform);   
  //END CLOCK
  auto end_time=Clock::now();         
  //again reset object
  ToMeasure.reset();       
  //Print measured time:
  return std::chrono::duration_cast<std::chrono::microseconds>(end_time-start_time).count();

}

unsigned int timer::measure_time(stru::irunnable& ToMeasure, unsigned int HowManyTimes,
				 unsigned int size,char option,char option_perform){


  if(HowManyTimes<=0){
    std::cerr<<"MEASUREMENT TIMES <= 0 ! \n";
    return 0;

  }else if(HowManyTimes==1){

    return measure_one(ToMeasure,size,option,option_perform);

  }else{

    unsigned int sum=0;
    unsigned int*  tablition= new unsigned int[HowManyTimes];  //Create array for measurement times

    for(unsigned int i=0;i<HowManyTimes;i++){
      tablition[i]=measure_one(ToMeasure,size,option, option_perform );  //Write measurement to array
      sum+=tablition[i];                                 //increase sum
    }
        
    delete [] tablition;          
    return sum/HowManyTimes;    //Liczen srednien
  }
}


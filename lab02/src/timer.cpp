#include"../inc/timer.h"


timer::timer(){}

timer::~timer(){}

unsigned int timer::measure_one(stru::irunnable& ToMeasure, unsigned int size,unsigned short int option){

    ToMeasure.reset();   //Reset object to measurement

    auto start_time= Clock::now();      //START CLOCK

    ToMeasure.perform_run(size,option);   //Calculate!

    auto end_time=Clock::now();          //END CLOCK

    ToMeasure.reset();         //again reset object

    return std::chrono::duration_cast<std::chrono::microseconds>(end_time-start_time).count();
}

unsigned int timer::measure_time(stru::irunnable& ToMeasure, unsigned int HowManyTimes, unsigned int size,unsigned short int option){

    if(HowManyTimes<=0){
        return 0;

    }else if(HowManyTimes==1){
        return measure_one(ToMeasure,size,option);

    }else{
        unsigned int sum=0;
        unsigned int*  tablition= new unsigned int[HowManyTimes];  //Create array for measurement times

        for(unsigned int i=0;i<HowManyTimes;i++){
            tablition[i]=measure_one(ToMeasure,size,option);  //Write measurement to array
            sum+=tablition[i];                                 //increase sum
        }
        
        delete [] tablition;          
        return sum/HowManyTimes;    //Liczen srednien
    }
}


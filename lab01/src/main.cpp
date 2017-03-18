/*
USING THIS PROGRAM:

    ./engine <FILENAME> <HOW MANY ITERATION> <OPTION FOR ALLOCATION>


*/
#include<iostream>
#include<chrono>
#include<fstream>
#include<cstdlib>
#include"../inc/array.h"

typedef std::chrono::high_resolution_clock Clock;   

//*********************************************************//
void run_pushing(stru::array<int>& tablition, unsigned int howmany, unsigned short int argument){

    for(unsigned int i=0;i<howmany;i++){
        tablition.push_back(2,argument);
    }
}

//*********************************************************//
int main(int argc, char *argv[]){

    std::ofstream datafile;                         //File stream declaration
    unsigned int elements= atoi(argv[2]);         //Number of elements
    unsigned short int options=atoi(argv[3]);       //options for allocation

    if(argc<3){
        std::cerr<<"USE THIS PROGRAM:\n ./engine <FILENAME> <HOW MANY ELEMENTS> <OPTION FOR ALLOCATION>\n";
        exit(0);
    }


    datafile.open(argv[1]);                         //Open file with name of first argument

    if(datafile.is_open()){             //If opened succesfully 
        
        datafile<<"Elements: "<<elements<<" Options: "<<options<<" \n \n";

        for(int j=0;j<1;j++){                  //20 times run pushing and save time
            
            stru::array<int> hesz;              //Declaration of array
            
            auto start_time= Clock::now();      //START CLOCK

            run_pushing(hesz,elements,options);

            auto end_time=Clock::now();          //END CLOCK

            datafile<<std::chrono::duration_cast<std::chrono::microseconds>(end_time-start_time).count()<<std::endl;  
        }
        datafile.close();
        
    }
}

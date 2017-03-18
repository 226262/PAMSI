/*
This class is simple interface for irunnable objects 
which derive from this class

*/
#ifndef IRUNNABLE_H
#define IRUNNABLE_H


namespace stru{

    class irunnable{

        public:

        irunnable(){}
        virtual void perform_run(unsigned int size, unsigned short int option)=0;
        virtual void reset()=0;
        virtual ~irunnable(){}



    };

}




#endif
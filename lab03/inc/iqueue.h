/*
This is QUEUE interface 

*/
#ifndef IQUEUE_H
#define IQUEUE_H


namespace stru{

    template <typename TYP>
    class iqueue {//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        public://PUBLIC SPECIFICATOR

        //Constructors and destructor:
        iqueue(){}
        virtual ~iqueue(){}

        //General methods from bigger interface?
        virtual const unsigned int size() const=0;
        virtual TYP top()=0;                          //Show what is in the front of queue

        //Specific methods for stack:
        virtual void enqueue(TYP what)=0;             //Put on end of queue
        virtual TYP dequeue()=0;                      //Remove from front of queue


    };//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


}


#endif
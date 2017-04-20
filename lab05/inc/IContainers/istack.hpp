/*
This is stack interface

*/
#ifndef ISTACK_HPP
#define ISTACK_HPP


namespace stru{

  template <typename TYP>
    class istack { //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


        public://PUBLIC SPECIFICATOR

        //Constructors and destructor:
        istack(){}
        virtual ~istack(){}

        //General methods from bigger interface?
        virtual const unsigned int size() const=0;
        virtual TYP top()=0;

        //Specific methods for stack:
        virtual void push(TYP what)=0;                //Put "what" on top of stack
        virtual TYP pop()=0;                          //Remove element from top of stack


    };//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



}


#endif

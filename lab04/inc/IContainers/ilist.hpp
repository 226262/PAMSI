/*
This is list interface

*/
#ifndef ILIST_HPP
#define ILIST_HPP


namespace stru{

    template <typename TYP>
    class ilist {//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


        public:  //PUBLIC SPECIFICATOR

        //Constructors and destructor:
        ilist(){}
        virtual ~ilist(){}

        //General methods from bigger interface?
        virtual const unsigned int size() const=0;
        virtual TYP top()=0;

        //Specific methods for list:
        virtual void push_front(TYP what)=0;
        virtual TYP pop_front()=0;
        virtual TYP get_next()=0;
        

    };//END OF LIST CLASS//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




}//END OF stru NAMESPACE
#endif
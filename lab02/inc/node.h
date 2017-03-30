/*
Node is class that is used in linked list and
should be used only there!

*/

#ifndef NODE_H
#define NODE_H


namespace stru{

    template <typename TYP>
    class node{
        TYP element;
        node<TYP>* next;

        public:
        node():next(nullptr){};                           //constructor
        TYP get_element(){return element;}                //element geter
        node* get_next(){return next;}                    //next getter
        void set_element(TYP setter){element=setter;}     //element setter
        void set_next(node<TYP>* setter){next=setter;}    //next setter
        ~node(){};

    };

}

#endif
/*
Node is class that is used in linked list, stack or queue and
should be used only there!

*/

#ifndef NODE_HPP
#define NODE_HPP


namespace stru{

    template <typename TYP>
    class node{
        TYP element;
        node<TYP>* next;

        public:
        node():next(nullptr){};
        TYP get_element(){return element;}
        node* get_next(){return next;}
        void set_element(TYP setter){element=setter;}
        void set_next(node<TYP>* setter){next=setter;}
        ~node(){};

    };

}

#endif

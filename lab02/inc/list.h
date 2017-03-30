/*
This is implementation of linked list which uses NODE class


*/
#ifndef LIST_H
#define LIST_H

#include<iostream>
#include "irunnable.h"
#include"node.h"

namespace stru{

    template <typename TYP>
    class list: public irunnable{//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        private: //DEFAULT PRIVATE SPECIFICATOR

        stru::node<TYP>* head;

        public:  //PUBLIC SPECIFICATOR

        //Constructors and destructor:
        list();
        virtual ~list();

        //Irunnable interface:
        virtual void perform_run(unsigned int size, unsigned short int option);
        virtual void reset();

        //Specific methods for list:  TODO
        void push_front(TYP what);
        void pop_front();
        bool empty();

        //METDODS FO DEBUGGING:
        void print();


    };//END OF LIST CLASS//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    //DEFINITIONS OF METHODS ABOVE: 



    template<typename TYP>
    void list<TYP>::print(){


        stru::node<TYP>* tempnode= head;

        while(tempnode!=nullptr){

            std::cout<<tempnode->get_element()<<"\n";

            tempnode=tempnode->get_next();
        }
        delete tempnode;
    
    }





    //*************************************************//    
    template <typename TYP>
    list<TYP>::~list(){

        while(head!=nullptr){

            stru::node<TYP>* oldnode= head;
            head=oldnode->get_next();
            delete oldnode;
        }
    }

    //*************************************************//
    template <typename TYP>
    list<TYP>::list()
        :head(nullptr)
    {
    }

    //*************************************************//
    template <typename TYP>
    void list<TYP>::push_front(TYP what){

        if(head==nullptr){
            head= new stru::node<TYP>;
            head->set_element(what);

        }else{

            stru::node<TYP>* newnode= new stru::node<TYP>;
            newnode->set_element(what);
            newnode->set_next(head);
            head=newnode;
        }
    }


    //*************************************************//
    template <typename TYP>
    void list<TYP>::pop_front(){

        if(head!=nullptr){

            node<TYP>* temp=head;

            head=temp->get_next();
            delete temp;

        }else{
            exit(1);
        }
    }

    //*************************************************//
    template <typename TYP>
    void list<TYP>::reset(){
        
    }    


    //*************************************************//
    template <typename TYP>
    void list<TYP>::perform_run(unsigned int size, unsigned short int option){
        
    }



}//END OF stru NAMESPACE
#endif
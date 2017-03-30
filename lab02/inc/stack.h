/*

*/
#ifndef STACK_H
#define STACK_H

#include"irunnable.h"
#include"list.h"

namespace stru{

    template <typename TYP>
    class stack : public irunnable{ //DO ZMIANY I PRZEMYŚLENIA

        private:

        stru::node<TYP>* head;

        public:

        //Constructors and destructor:
        stack();
        virtual ~stack();

        //Specific methods for stack:
        bool empty() const;
        void push(TYP what);
        bool pop();
        TYP top();

        //Irunnable interface:
        virtual void perform_run(unsigned int size, unsigned short int option);
        virtual void reset();

        //METDODS FO DEBUGGING:
        void print() const;


    };

    template <typename TYP>
    stack<TYP>::stack()
    :head(nullptr)
    {
    }

    template <typename TYP>
    stack<TYP>::~stack(){

        while(head!=nullptr){

            stru::node<TYP>* oldnode= head;
            head=oldnode->get_next();
            delete oldnode;
        }

    }

    template <typename TYP>
    void stack<TYP>::push(TYP what){

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
    template <typename TYP>
    bool stack<TYP>::pop(){

        if(head!=nullptr){

            node<TYP>* temp=head;

            head=temp->get_next();
            delete temp;
            return true;
        }else{
            return false;
        }

    }

    template <typename TYP>
    TYP stack<TYP>::top(){

        if(head!=nullptr){
            return head->get_element();
        }else{
            exit(1);
        }
    }

    template <typename TYP>
    bool stack<TYP>::empty() const{
        
        if (head==nullptr){
            return true;
        }else{
            return false;
        }
    }

    template <typename TYP>
    void stack<TYP>::reset(){

    }



    template <typename TYP>
    void stack<TYP>::perform_run(unsigned int size, unsigned short int option){

    }    

    template <typename TYP>
    void stack<TYP>::print()const {
        
            stru::node<TYP>* tempnode= head;

            while(tempnode!=nullptr){

            std::cout<<tempnode->get_element()<<"\n";
            tempnode=tempnode->get_next();

        }

    }

}


#endif
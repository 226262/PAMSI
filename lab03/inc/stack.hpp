/*

 */
#ifndef STACK_HPP
#define STACK_HPP

#include<iostream>
#include"irunnable.hpp"
#include"node.hpp"
#include"istack.hpp"
#include"isearchable.hpp"

namespace stru{

  template <typename TYP>
  class stack : public irunnable, public istack<TYP>,public isearchable<TYP>{ //~~~~~~~~~~~~~

  private:

    stru::node<TYP>* head;
    unsigned int capacity;
      
  public:

    //Constructors and destructor:
    stack();
    virtual ~stack();


    //Istack interface:
    virtual const unsigned int size() const;
    virtual TYP top();
    virtual void push(TYP what);                //Put "what" on top of stack
    virtual TYP pop();                          //Remove element from top of stack


    //Isearchable interface:
    virtual TYP search(TYP what);

    //Irunnable interface:
    virtual void perform_run(unsigned int size, unsigned short int option);
    virtual void reset();
    virtual void prepare(unsigned int size);
    //METDODS FO DEBUGGING:
    void print() const;


  };//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //DEFINITIONS OF METHODS ABOVE:



  template <typename TYP>
  stack<TYP>::stack()
    :head(nullptr)
    ,capacity(0)
  {
  }

  template <typename TYP>
  TYP stack<TYP>::search(TYP what){
      

    if (head!=nullptr) {

      stru::node<TYP>* newnode =head;

      while(newnode != nullptr){

	if(newnode->get_element()==what){
	  return newnode->get_element();
	}
	newnode=newnode->get_next();

      }
      return TYP(0);
	
    }else{
      std::cerr<<"NO ELEMENTS IN THE STACK\n";
      return TYP(0);

    }
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
    capacity++;
  }

  template <typename TYP>
  TYP stack<TYP>::top(){

    if(head!=nullptr){
      return head->get_element();
    }else{
      std::cerr<<"NO ELEMENTS IN THE STACK\n";
      return TYP(0);
    }
  }
  
  template <typename TYP>
  TYP stack<TYP>::pop(){
      
    if(head!=nullptr){

      stru::node<TYP>* oldnode= head;
      TYP to_return=head->get_element();

      head=oldnode->get_next();
      delete oldnode;

      capacity--;
	    
      return to_return;
	    
    }else{
      std::cerr<<"NO ELEMENTS IN THE STACK\n";

      return TYP(0);
    }

  }


  template <typename TYP>
  void stack<TYP>::reset(){

    while(head!=nullptr){

      stru::node<TYP>* oldnode= head;
      head=oldnode->get_next();
      delete oldnode;
    }


  }


  template <typename TYP>
  const unsigned int stack<TYP>::size()const {
    return capacity;
  }

  template <typename TYP>
  void stack<TYP>::prepare(unsigned int size){
      
    this->push(666);

    for (unsigned int i=0; i < (size-1); i++) {
      this->push(2);
	
    }
  }

  template <typename TYP>
  void stack<TYP>::perform_run(unsigned int size, unsigned short int option){

    this->search(666);
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

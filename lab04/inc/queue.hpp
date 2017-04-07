#ifndef QUEUE_HPP
#define QUEUE_HPP

#include<iostream>
#include"Interfaces/irunnable.hpp"
#include"Interfaces/isearchable.hpp"
#include "IContainers/iqueue.hpp"
#include"node.hpp"

namespace stru{

  template<typename TYP>
  class queue: public iqueue<TYP>, public irunnable, public isearchable<TYP>{
    
    private:
    
    stru::node<TYP>* end;
    stru::node<TYP>* front;
    unsigned int capacity;
    
    public:

    //constructors and destructors
    queue();
    virtual ~queue();

    //Methods from iqueue interface:
    virtual const unsigned int size()const;
    virtual TYP first();
    virtual void enqueue(TYP what);
    virtual TYP dequeue();
    
    //Metods from irunnable interface:
    virtual void perform_run(unsigned int size, char option);
    virtual void reset();
    virtual void prepare(unsigned int size, char option);
    
    //methods from isearchable interface:
    virtual TYP search(TYP what);

    //METHODS FOR DEBUGGING
    void print()const;
  };


  template<typename TYP>
  queue<TYP>::queue()
    :end(nullptr)
    ,front(nullptr)
    ,capacity(0)
  {  
  }

  template<typename TYP>
  queue<TYP>::~queue(){

    while(front!=nullptr ){
      stru::node<TYP>* oldnode= front;
      front=oldnode->get_next();
      delete oldnode;
    }

  }

  template<typename TYP>
  void queue<TYP>::enqueue(TYP what){

    if(front==nullptr){
      front= new stru::node<TYP>;
      front->set_element(what);
      end=front;
      
    }else{

      stru::node<TYP>* newnode= new stru::node<TYP>;
      newnode->set_element(what);
      newnode->set_next(nullptr);
      end->set_next(newnode);
      end=newnode;
    }
    capacity++;

  }

  template<typename TYP>
  TYP queue<TYP>::dequeue(){

    if(front!=nullptr){

      stru::node<TYP>* oldnode=front ;
      TYP to_return=front->get_element();

      front=oldnode->get_next();
      delete oldnode;

      capacity--;
	    
      return to_return;
	    
    }else{
      std::cerr<<"NO ELEMENTS IN THE QUEUE!\n";

      return TYP(0);
    }

  }

  template<typename TYP>
  void queue<TYP>::perform_run(unsigned int size,char option){

    this->search(666);
  }

  template<typename TYP>
  void queue<TYP>::prepare(unsigned int size, char option){

    for (unsigned int i=0; i < (size-1); i++) {
      this->enqueue(2);
	
    }
    this->enqueue(666);
  }

  template<typename TYP>
  void queue<TYP>::reset(){

    while(front!=nullptr ){
      stru::node<TYP>* oldnode= front;
      front=oldnode->get_next();
      delete oldnode;
    }
    
  }

  template<typename TYP>
  TYP queue<TYP>::search(TYP what){

    if (front!=nullptr ) {

      stru::node<TYP>* newnode =front;

      while(newnode != nullptr){

	if(newnode->get_element()==what){
	  return newnode->get_element();
	}
	newnode=newnode->get_next();

      }
      return TYP(0);
	
    }else{
      std::cerr<<"NO ELEMENTS IN THE QUEUE\n";
      return TYP(0);

    }

  }

  template<typename TYP>
  const unsigned int queue<TYP>::size()const {
    return capacity;
  }

  template<typename TYP>
  TYP queue<TYP>::first(){
    return front->get_element();
  }

  template<typename TYP>
  void queue<TYP>::print()const {

    stru::node<TYP>* tempnode= front;

    while(tempnode!=nullptr){

      std::cout<<tempnode->get_element()<<"\n";
      tempnode=tempnode->get_next();

    }
  }

}

#endif

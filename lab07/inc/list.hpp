
/*

 */
#ifndef LIST_HPP
#define LIST_HPP

#include<iostream>
#include"Interfaces/irunnable.hpp"
#include"node.hpp"
#include"IContainers/ilist.hpp"
#include"Interfaces/isearchable.hpp"


template <typename TYP>
class list : public irunnable, public ilist<TYP>,public isearchable<TYP>{ //~~~~~~~~~~~~~

private:

  node<TYP>* head;
  node<TYP>* iterator;
  unsigned int capacity;
      
public:
    
  //Constructors and destructor:
  list();
  virtual ~list();


  //Ilist interface:
  virtual const unsigned int size() const;
  virtual TYP top();
  virtual void push_front(TYP what);                //Put "what" on top of list
  virtual TYP pop_front();                          //Remove element from top of list
  virtual TYP get_next();
  //Isearchable interface:
  virtual TYP search(TYP what);

  //Irunnable interface:
  virtual void perform_run(unsigned int size, char option);
  virtual void reset();
  virtual void prepare(unsigned int size,char option);
  //METDODS FO DEBUGGING:
  void print() const;


};//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//DEFINITIONS OF METHODS ABOVE:



template <typename TYP>
list<TYP>::list()
  :head(nullptr)
  ,iterator(nullptr)
  ,capacity(0)
{
}

template <typename TYP>
TYP list<TYP>::search(TYP what){
      

  if (head!=nullptr) {

    node<TYP>* newnode =head;

    while(newnode != nullptr){

      if(newnode->get_element()==what){
	return newnode->get_element();
      }
      newnode=newnode->get_next();

    }
    return TYP(0);
	
  }else{
    std::cerr<<"NO ELEMENTS IN THE LIST\n";
    return TYP(0);

  }
}
    
template <typename TYP>
list<TYP>::~list(){

  while(head!=nullptr){

    node<TYP>* oldnode= head;
    head=oldnode->get_next();
    delete oldnode;
  }

}

template <typename TYP>
void list<TYP>::push_front(TYP what){

  if(head==nullptr){
    head= new node<TYP>;
    head->set_element(what);
    iterator=head;

  }else{

    node<TYP>* newnode= new node<TYP>;
    newnode->set_element(what);
    newnode->set_next(head);
    head=newnode;
  }
  capacity++;
}

template <typename TYP>
TYP list<TYP>::top(){
  
  iterator=head;
  
  if(iterator!=nullptr){
    return iterator->get_element();
  }else{
    std::cerr<<"NO ELEMENTS IN THE LIST TOP\n";
    return TYP(0);
  }
}
  
template <typename TYP>
TYP list<TYP>::get_next(){

  node<TYP>* tempptr;

  tempptr=iterator;
  
  if(iterator!=nullptr){

    if(iterator->get_next()!=nullptr){
      
      iterator=tempptr->get_next();
      return  tempptr->get_next()->get_element();
    }else{
      return iterator->get_element();
    }
  }else{
    std::cerr<<"NO ELEMENTS IN THE LIST FOR ITERATOR\n";
    return TYP(0);
  }
}
    
template <typename TYP>
TYP list<TYP>::pop_front(){
      
  if(head!=nullptr){

    node<TYP>* oldnode= head;
    TYP to_return=head->get_element();

    head=oldnode->get_next();
    delete oldnode;

    capacity--;

    iterator=head;
    
    return to_return;
	    
  }else{
    std::cerr<<"NO ELEMENTS IN THE LIST\n";

    return TYP(0);
  }

}


template <typename TYP>
void list<TYP>::reset(){

  while(head!=nullptr){

    node<TYP>* oldnode= head;
    head=oldnode->get_next();
    iterator=head;
    delete oldnode;
  }


}


template <typename TYP>
const unsigned int list<TYP>::size()const {
  return capacity;
}

template <typename TYP>
void list<TYP>::prepare(unsigned int size, char option){
      
  this->push_front(666);

  for (unsigned int i=0; i < (size-1); i++) {
    this->push_front(2);
	
  }
}

template <typename TYP>
void list<TYP>::perform_run(unsigned int size,char option){

  this->search(666);
}    

template <typename TYP>
void list<TYP>::print()const {
        
  node<TYP>* tempnode= head;

  while(tempnode!=nullptr){

    std::cout<<tempnode->get_element()<<" ";
    tempnode=tempnode->get_next();

  }

}




#endif

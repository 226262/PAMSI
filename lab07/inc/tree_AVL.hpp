#ifndef TREE_AVL_HPP
#define TREE_AVL_HPP

#include <string>
#include<iostream>

#include "IContainers/itree.hpp"
#include "Interfaces/irunnable.hpp"
#include "Interfaces/isearchable.hpp"
#include "leaf.hpp"

template <typename TYP> class tree_AVL : public itree<TYP>, public irunnable , public isearchable<TYP>{
private:

  leaf<TYP> *root;
  
  //Private methods:
  void release_subtree(leaf<TYP> * to_release);
  void LL(leaf<TYP> *  A);
  void RR(leaf<TYP> *  A);
  void LR(leaf<TYP> *  A);
  void RL(leaf<TYP> *  A);
  void display(leaf<TYP> * to_display,int level);

public:
  // Constructors and destructor:
  tree_AVL();
  ~tree_AVL();

  // Methods from itree interface:
  bool is_empty() const;
  void insert(TYP what);
  void remove(TYP what);

  //Methods from isearchable interface
  TYP search(TYP what);
  
  //Methods from irunnable interface
  void perform_run(unsigned int size, char option);
  void reset();
  void prepare(unsigned int size,char option);

  //Methods for debugging
  void print();

  
};


//Definitions of methods above:

//##############################################//
template <typename TYP>
void tree_AVL<TYP>::release_subtree(leaf<TYP> * to_release){

  //If to_release- is not nullptr
  if(to_release){
    release_subtree(to_release->get_left());
    release_subtree(to_release->get_right());
    delete to_release;
  }
}

//##############################################//
template <typename TYP>
void tree_AVL<TYP>::display(leaf<TYP> *to_display, int level) {

  int i;
  if (to_display) {
    display(to_display->get_right(), level + 1);
    printf("\n");
    if (to_display == root)
      std::cout << "Root -> ";
    for (i = 0; i < level && to_display != root; i++)
      std::cout << "        ";
    std::cout << to_display->get_data();
    display(to_display->get_left(), level + 1);
  }
}

//##############################################//
template <typename TYP> void tree_AVL<TYP>::LL(leaf<TYP> *A) {

  leaf<TYP> *B = A->get_left();
  leaf<TYP> *p = A->get_parent();

  A->set_left(B->get_right());

  if (A->get_left()) {
    A->get_left()->set_parent(A);
  }
  B->set_right(A);
  B->set_parent(p);
  A->set_parent(B);

  if (p) {
    if (p->get_left() == A) {
      p->set_left(B);
    } else {
      p->set_right(B);
    }
  } else {
    root = B;
  }

  if (B->get_balance_factor() == 1) {
    A->set_balance_factor(0);
    B->set_balance_factor(0);
  } else {
    A->set_balance_factor(1);
    B->set_balance_factor(-1);
  }
}

//##############################################//
template <typename TYP> void tree_AVL<TYP>::RR(leaf<TYP> *A) {
  leaf<TYP> *B = A->get_right();
  leaf<TYP> *p = A->get_parent();

  A->set_right(B->get_left());

  if (A->get_right()) {
    A->get_right()->set_parent(A);
  }
  B->set_left(A);
  B->set_parent(p);
  A->set_parent(B);

  if (p) {
    if (p->get_left() == A) {
      p->set_left(B);
    } else {
      p->set_right(B);
    }
  } else {
    root = B;
  }

  if (B->get_balance_factor() == -1) {
    A->set_balance_factor(0);
    B->set_balance_factor(0);
  } else {
    A->set_balance_factor(-1);
    B->set_balance_factor(1);
  }
}

//##############################################//
template <typename TYP> void tree_AVL<TYP>::LR(leaf<TYP> *A) {
  leaf<TYP> *B = A->get_left();
  leaf<TYP> *C = B->get_right();
  leaf<TYP> *p = A->get_parent();

  B->set_right(C->get_left());

  if (B->get_right()) {
    B->get_right()->set_parent(B);
  }

  A->set_left(C->get_right());

  if (A->get_left()) {
    A->get_left()->set_parent(A);
  }

  C->set_right(A);
  C->set_left(B);
  A->set_parent(C);
  B->set_parent(C);
  C->set_parent(p);

  if (p) {
    if (p->get_left() == A) {
      p->set_left(C);
    } else {
      p->set_right(C);
    }
  } else {
    root = C;
  }

  if (C->get_balance_factor() == 1) {
    A->set_balance_factor(-1);
  } else {
    A->set_balance_factor(0);
  }

  if (C->get_balance_factor() == -1) {
    B->set_balance_factor(1);
  } else {
    B->set_balance_factor(0);
  }

  C->set_balance_factor(0);
}

//##############################################//
template <typename TYP> void tree_AVL<TYP>::RL(leaf<TYP> *A) {
  leaf<TYP> *B = A->get_right();
  leaf<TYP> *C = B->get_left();
  leaf<TYP> *p = A->get_parent();

  B->set_left(C->get_right());

  if (B->get_left()) {
    B->get_left()->set_parent(B);
  }

  A->set_right(C->get_left());

  if (A->get_right()) {
    A->get_right()->set_parent(A);
  }

  C->set_left(A);
  C->set_right(B);
  A->set_parent(C);
  B->set_parent(C);
  C->set_parent(p);

  if (p) {
    if (p->get_left() == A) {
      p->set_left(C);
    } else {
      p->set_right(C);
    }
  } else {
    root = C;
  }

  if (C->get_balance_factor() == -1) {
    A->set_balance_factor(1);
  } else {
    A->set_balance_factor(0);
  }

  if (C->get_balance_factor() == 1) {
    B->set_balance_factor(-1);
  } else {
    B->set_balance_factor(0);
  }

  C->set_balance_factor(0);
}

//##############################################//
template <typename TYP>
void tree_AVL<TYP>::insert(TYP what) {

  leaf<TYP> *w;
  leaf<TYP> *p;
  leaf<TYP> *r;
  bool t;

  w = new leaf<TYP>(what);

  // 1 ----- Adding leaf to TREE
  p = root;
  // if tree is empty-> insert in root and go out
  if (!p)
    root = w;
  else { // search space for "w"
    while (true)
      // compare keys
      if (what < p->get_data()) {
        // if p doesn't have left son
        if (!p->get_left()) {
          p->set_left(w);
          break;
        }
        // else go to left son
        p = p->get_left();
      } else {
        if (!p->get_right()) {
          p->set_right(w);
          break;
        }
        p = p->get_right();
      }

    w->set_parent(p);

    // 2----- balancing tree ;>
    if (p->get_balance_factor()) {

      p->set_balance_factor(0);
    } else {

      if (p->get_left() == w) {

        p->set_balance_factor(1);
      } else {

        p->set_balance_factor(-1);
      }
      r = p->get_parent();
      t = false;
      while (r) {
        if (r->get_balance_factor()) {
          t = true;
          break;
        };

        if (r->get_left() == p) {
          r->set_balance_factor(1);
        } else {
          r->set_balance_factor(-1);
        }

        p = r;
        r = r->get_parent();
      }

      if (t) {

        if (r->get_balance_factor() == 1) {
          if (r->get_right() == p)
            r->set_balance_factor(0);
          else if (p->get_balance_factor() == -1)
            LR(r);
          else
            LL(r);
        } else {
          if (r->get_left() == p)
            r->set_balance_factor(0);
          else if (p->get_balance_factor() == 1)
            RL(r);
          else
            RR(r);
        }
      }
    }
  }
}

//##############################################//
template <typename TYP>
tree_AVL<TYP>::tree_AVL():
  root(nullptr) {}

//##############################################//
template <typename TYP>
tree_AVL<TYP>::~tree_AVL(){
  release_subtree(root);
  root=nullptr;
}

//##############################################//
template <typename TYP>
bool tree_AVL<TYP>::is_empty() const{

  if(root) return false;
  else return true;
}


//##############################################//
template <typename TYP>
TYP tree_AVL<TYP>::search(TYP what){

  leaf<TYP>* p =root;
  
  while(p && p->get_data() !=what)
    //If true () ?  do true : do if false 
    p=(what < p->get_data()) ? p->get_left() : p->get_right();


  if(p)  return p->get_data();
  else   return TYP(0);
    
}

//##############################################//
template <typename TYP>
void tree_AVL<TYP>::remove(TYP what){

  
  
}

//##############################################//
template <typename TYP>
void tree_AVL<TYP>::perform_run(unsigned int size, char option){

  if(!search(1)) {
    std::cout << "NIE ZNALEZIONO\n";
  }
  
}

//##############################################//
template <typename TYP>
void tree_AVL<TYP>::reset(){

  if(root){
    
    release_subtree(root);
    root=nullptr;
  }
}

//##############################################//
template <typename TYP>
void tree_AVL<TYP>::prepare(unsigned int size,char option){

  for(unsigned int i=1;i<size+1;i++){
    insert(i);
  }
}

//##############################################//
template <typename TYP>
void tree_AVL<TYP>::print(){
  display(root, 1);
  
}




#endif

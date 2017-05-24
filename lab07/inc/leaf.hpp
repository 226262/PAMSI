#ifndef LEAF_HPP
#define LEAF_HPP

#include<iostream>



template <typename TYP> class leaf {

private:
  TYP data;
  leaf *left_ptr;
  leaf *right_ptr;
  leaf *parent;
  int balance_factor;

public:
  // constructors and destructor:
  leaf(TYP starter)
      : data(starter), left_ptr(nullptr), right_ptr(nullptr),
        parent(nullptr), balance_factor(0) {}
  leaf():data(0), left_ptr(nullptr), right_ptr(nullptr),
        parent(nullptr), balance_factor(0)  {}
  ~leaf() {}

  // Getters, setters:
  int get_balance_factor() { return balance_factor; }
  TYP get_data() const { return data; }
  leaf *get_right() { return right_ptr; }
  leaf *get_left() { return left_ptr; }
  leaf *get_parent(){return parent;}
  void set_balance_factor(int to_set) { balance_factor = to_set; }
  void set_data(TYP &to_set) { data = to_set; }
  void set_parent(leaf &to_set) { parent = to_set; }
  void set_left(leaf &to_set) { left_ptr = &to_set; }
  void set_right(leaf &to_set) { right_ptr = &to_set; }
  void set_data(TYP *to_set) { data = to_set; }
  void set_parent(leaf *to_set) { parent = to_set; }
  void set_left(leaf *to_set) { left_ptr = to_set; }
  void set_right(leaf *to_set) { right_ptr = to_set; }
  bool has_left();
  bool has_right();
  bool has_parent();
  bool is_external();
 };


template <typename TYP> bool leaf<TYP>::has_left() {
  if (left_ptr == nullptr)
    return false;
  else
    return true;
}

template <typename TYP> bool leaf<TYP>::has_right() {
  if (right_ptr == nullptr)
    return false;
  else
    return true;
}

template <typename TYP> bool leaf<TYP>::has_parent() {
  if (parent == nullptr)
    return false;
  else
    return true;
}

template <typename TYP> bool leaf<TYP>::is_external() {
  if (!has_left() && !has_right())
    return true;
  else
    return false;
}

#endif

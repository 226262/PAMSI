#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>

#include "IContainers/idictionary.hpp"
#include "Interfaces/irunnable.hpp"
#include "Interfaces/isearchable.hpp"
#include "array.hpp"
#include "couple.hpp"
#include "list.hpp"

const std::string default_chars =
    "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";


template <typename KEY_TYPE, typename DATA_TYPE>
class dictionary : idictionary<KEY_TYPE, DATA_TYPE>,
                   public irunnable { //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

private:
  unsigned int length;
  // Main array of lists of couples... (strange i know)
  list<couple<KEY_TYPE, DATA_TYPE>> *T;

  // Private methods
  unsigned int hash(std::string tohash, char option = 'e') const;
  std::string generate_key(const size_t how_long) const;

public: // PUBLIC SPECIFICATOR
  // Constructors and destructor:
  dictionary(unsigned int space);
  virtual ~dictionary();

  // Methods from idictionary interface
  virtual DATA_TYPE lookup(KEY_TYPE key,char option ='e') const;
  virtual void delete_couple(KEY_TYPE key);
  virtual void add_couple(KEY_TYPE key, DATA_TYPE data,char option ='e');
  virtual void reassign(KEY_TYPE key, DATA_TYPE data);
  virtual DATA_TYPE operator[](KEY_TYPE key);

  // Methods from irunnable interface
  virtual void perform_run(unsigned int size, char option);
  virtual void reset();
  virtual void prepare(unsigned int size, char option);

  // Temporary methods for debugging:
  void print();

}; //~~~~~~~~~~~~~~~~~~~END OF DICTIONARY CLASS ~~~~~~~~~~~~~~~~~~~~~~~~~

// DEFINITIONS OF METHODS ABOVE:

//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
dictionary<KEY_TYPE, DATA_TYPE>::dictionary(unsigned int space)
    : length(space) {
  T = new list<couple<KEY_TYPE, DATA_TYPE>>[length];
}

//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
unsigned int dictionary<KEY_TYPE, DATA_TYPE>::hash(std::string tohash,
                                                   char option) const {

  // first letter multiple by 128
  unsigned long long int numbered_key = 128 * (unsigned int)tohash.at(0);

  // And add rest
  for (unsigned int i = 0; i < tohash.size(); i++) {
    char letter = tohash.at(i);
    numbered_key += (unsigned int)letter; // Casting char to ASCII table
  }

  if (option == 's') { // SIMPLE HASH- modulo hashing (not so good)
    return numbered_key % length;
  } else { // Any other is great hash function ;>
    // Casting integer index to floating number
    double A = (sqrt(5.0) - 1.0) / 2.0;
    A = (A * numbered_key);
    A = A - floor(A);
    A = length * A;
    return floor(A);
  }
}

//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
dictionary<KEY_TYPE, DATA_TYPE>::~dictionary() {

  delete[] T;
}

//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
DATA_TYPE dictionary<KEY_TYPE, DATA_TYPE>::lookup(KEY_TYPE key,char option) const {

  unsigned int index = hash(key,option);

  if (T[index].size() == 0) {

    std::cout << "Key not found in hash table\n";
    return DATA_TYPE(0);
  }

  if (T[index].top().get_key() == key) {
    return T[index].top().get_data();
  }

  for (unsigned int i = 0; i < T[index].size() - 1; i++) {

    KEY_TYPE tempkey = T[index].get_next().get_key();

    if (tempkey == key) {
      return T[index].get_next().get_data();
    }
  }
  std::cout << "Key not found in hash table\n";
  return DATA_TYPE(0);
}

//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
std::string
dictionary<KEY_TYPE, DATA_TYPE>::generate_key(const size_t how_long) const {

  std::mt19937_64 gen{std::random_device()()};
  std::uniform_int_distribution<size_t> dist{0, default_chars.length() - 1};

  std::string ret;

  std::generate_n(std::back_inserter(ret), how_long,
                  [&] { return default_chars[dist(gen)]; });

  return ret;
}

//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
void dictionary<KEY_TYPE, DATA_TYPE>::delete_couple(KEY_TYPE key) {}

//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
void dictionary<KEY_TYPE, DATA_TYPE>::add_couple(KEY_TYPE key, DATA_TYPE data,char option) {

  unsigned int index = hash(key,option);
  couple<KEY_TYPE, DATA_TYPE> to_add(key, data);

  T[index].push_front(to_add);
}

//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
void dictionary<KEY_TYPE, DATA_TYPE>::reassign(KEY_TYPE key, DATA_TYPE data) {}

//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
DATA_TYPE dictionary<KEY_TYPE, DATA_TYPE>::operator[](KEY_TYPE key) {
  return this->lookup(key);
}

//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
void dictionary<KEY_TYPE, DATA_TYPE>::perform_run(unsigned int size,
                                                  char option) {
  lookup("SZATAN",option);

  
}

//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
void dictionary<KEY_TYPE, DATA_TYPE>::reset() {

  for (unsigned int i = 0; i < length; i++) {
    T[i].reset();
  }
}

//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
void dictionary<KEY_TYPE, DATA_TYPE>::prepare(unsigned int size, char option) {

  add_couple("SZATAN", 666,option);
  for (unsigned int i = 0; i < size; i++) {
    add_couple(generate_key(6), 64,option);
  }
}

//################################################
template <typename KEY_TYPE, typename DATA_TYPE>
void dictionary<KEY_TYPE, DATA_TYPE>::print() {

  std::cout << length << "<-dlugosc tabliy haszujacej\n";
  for (unsigned int i = 0; i < length; i++) {

    std::cout << i << " ";
    T[i].print();
    std::cout << "\n";
  }
}

#endif

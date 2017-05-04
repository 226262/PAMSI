#ifndef IDICTIONARY_HPP
#define IDICTIONARY_HPP

#include <string>

template <typename KEY_TYPE, typename DATA_TYPE>
class idictionary {//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
private:
public:     //PUBLIC SPECIFICATOR           

  //Constructors and destructor:
  idictionary(){}
  virtual ~idictionary(){}
     

  //specific methods for dictionary
  virtual DATA_TYPE& lookup(KEY_TYPE key)const =0;
  virtual void delete_couple(KEY_TYPE key)=0;
  virtual void add_couple(KEY_TYPE key, DATA_TYPE data)=0;
  virtual void reassign(KEY_TYPE key, DATA_TYPE data)=0;
  virtual DATA_TYPE& operator[](KEY_TYPE key)=0;
  
  //Getters:

  //Overloaded operators:

        
};


#endif

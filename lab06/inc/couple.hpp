#ifndef COUPLE_HPP
#define COUPLE_HPP


#include <string>
#include <iostream>

template <typename KEY_TYPE, typename DATA_TYPE>
class couple{
  
private:
  KEY_TYPE key;
  DATA_TYPE data;
  
public:
  couple(){}
  couple(int x){std::cerr<<"NO SUCH COUPLE!\n";}    //For list " TYP(0) error (to change)"
  couple(KEY_TYPE klucz, DATA_TYPE wartosc) : key(klucz), data(wartosc){}
  ~couple(){}
  void set_data(DATA_TYPE which ){data=which;}
  void set_key(KEY_TYPE which ){key=which;}
  KEY_TYPE get_key(){return key;}
  DATA_TYPE get_data(){return data;}

  bool operator==(couple& second)const {
    if(key==second.get_key()){
      return true;
    }else
      return false;
  }
 
  void print(){
    std::cout << "K: "<<key<<" W: "<<data<<"\n";
  }
  
  friend std::ostream& operator <<(std::ostream& os , const couple& coup ){
    os<<"{K:"<<coup.key<<" W:"<<coup.data<<"}";
    return os;
  }
};

#endif

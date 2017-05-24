#ifndef ITREE_HPP
#define ITREE_HPP

template<typename TYP>
class itree {

public:

  itree (){};
  ~itree(){};
  
  virtual bool is_empty()const=0;
  virtual void insert(TYP what)=0;
  virtual void remove(TYP what)=0;
  
};

#endif

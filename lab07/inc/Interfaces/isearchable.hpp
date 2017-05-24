#ifndef ISEARCHABLE_HPP
#define ISEARCHABLE_HPP


template<typename TYP>
class isearchable{

public:
  isearchable(){}
  virtual ~isearchable(){}
  virtual TYP search(TYP what)=0;
    
};

 

#endif

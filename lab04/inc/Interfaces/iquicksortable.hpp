#ifndef IQUICKSORTABLE_HPP
#define IQUICKSORTABLE_HPP


namespace stru{

  template <typename TYP>
  class iquicksortable {
    
  public:

    iquicksortable(){}
    virtual TYP& operator[](unsigned int indeks) const=0;
    virtual void set_element(TYP what)=0;
    virtual void reset()=0;
    virtual int get_last_index()=0;
    virtual ~iquicksortable(){}
    
  };
}

#endif

#include<iostream>
#include"../inc/array.h"


int main(){
    stru::array<int> hesz(888);
    hesz.push_back(777);
    hesz.insert(2,111);
    hesz.insert(0,999);
    hesz.insert(4,123);
    hesz.print();

    int * SEARCHED=hesz.search(45);
    if(SEARCHED){
             std::cout<<"Znalazlem "<<*SEARCHED<<"\n";             //cos rob z 72
    }
    std::cout<<"cout! "<<hesz.get_size()<<" "<<hesz.get_capacity()<<"\n";

}

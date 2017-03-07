#include<iostream>
#include"../inc/array.h"


int main(){
    stru::array<int> hesz(888);
    hesz.push_back(777);
    hesz.push_back(666);
    hesz.push_back(666);
    hesz.push_back(666);
    hesz.print();
    hesz.pop_back();
    hesz.pop_back();
    hesz.pop_back();
    hesz.pop_back();
    hesz.print();
    hesz.pop_back();
    hesz.pop_back();
    hesz.print();
    hesz.push_back(45);
    hesz.push_back(45);
    hesz.pop_back();
    hesz.pop_back();
    hesz.push_back(65);
    hesz.push_back(45);
    hesz.print();
    std::cout<<hesz[0]<<std::endl;
    std::cout<<hesz[1]<<std::endl;

    int * SEARCHED=hesz.search(45);
    if(SEARCHED){
             std::cout<<"Znalazlem "<<*SEARCHED<<"\n";             //cos rob z 72
    }
    std::cout<<"cout! "<<hesz.get_size()<<" "<<hesz.get_capacity()<<"\n";
}
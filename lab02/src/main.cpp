/*
USING THIS PROGRAM:

    ./engine <FILENAME> <HOW MANY ITERATION> <OPTION FOR ALLOCATION> <HOWMANYTIMES>

*/ 
#include<iostream>
#include<fstream>
#include<cstdlib>
#include"../inc/array.h"
#include"../inc/irunnable.h"
#include"../inc/timer.h"
#include"../inc/list.h"

//*********************************************************//
int main(int argc, char *argv[]){



    timer STOPEREK;
    stru::array<int> tablica;
    
    stru::list<int> lista;

    lista.push_front(1);
    lista.push_front(2);
    lista.print();
    lista.pop_front();
    lista.push_front(666);
    lista.print();
    lista.pop_front();
    lista.print();
    
    return 0;
}

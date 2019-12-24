#include "Guard.h"
#include <iostream>
#include "MyMatrix.h"

void print(){
    Guard guard(std::cout);

    std::cout.fill('y');
    std::cout.width(10);
    std::cout<<"test"<<std::endl;

    std::cout<<std::hex<<10<<"  "<<std::dec<<10<<std::endl;
}

int main(){

    std::cout<<"test"<<std::endl;

    std::cout.width(10);
    std::cout<<"test"<<std::endl;

    std::cout.fill('x');
    std::cout.width(10);
    std::cout<<"test"<<std::endl;

    print();

    std::cout<<"test"<<std::endl;
    std::cout.width(10);
    std::cout<<"test"<<std::endl;

    return 0;
}
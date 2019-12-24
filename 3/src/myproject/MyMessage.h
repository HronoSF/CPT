#include <iostream>
#include <fstream>
#include <string>

template<class Head>
void printOut(std::ostream& STR, const char* String, Head head){
    while(*String != '%'){
        STR<<*String;
        String++;
    }
    STR<<head;
    String++;

    while(*String != '\0' ){
        STR<<*String;
        String++;
    }
}

template<class Head, class ... Tail>
void printOut(std::ostream& STR, const char* String, Head head, Tail ... tail){
    while(*String != '%'){
        STR<<*String;
        String++;
    }
    STR<<head;
    String++;
    printOut(STR, String, tail...);
}

template<class ... Param>
bool message(std::ostream& STR, const char* String, Param ... args){
    int sumStringArg = 0;
    const char* str = String;
    while(*str != '\0' ){
        if(*str == '%')
            sumStringArg = sumStringArg + 1;
        str++;
    }
    std::cout<<*String;
    int sumArg = sizeof...(args);

    if(sumArg != sumStringArg){
        std::cout<<("Number of StringArgs and Params not equal")<<std::endl;
        return false;
    }

    printOut(STR, String, args...);
    return true;
}
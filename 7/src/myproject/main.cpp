#include "startBuffer.h"
#include <string>
#include <iostream>

int main(){
    std::streambuf* oldbuf = std::cin.rdbuf();
    stat_buffer stb(oldbuf);
    std::cin.rdbuf(&stb);

    std::cout<<std::cin.rdbuf();
    std::cout<<stb.getStrCount()<<" "<<stb.getWordCount()<<" "
             <<stb.getCharCount()<<std::endl;

    std::cin.rdbuf(oldbuf);
    return 0;
}
#include <iostream>
#include <string>

class ln80c_buffer: public std::streambuf{
private:
    int n;
    int size;
    std::streambuf* buf;
    bool newStr;
public:
    explicit ln80c_buffer(std::streambuf* b):buf(b) {n=1; newStr=true; size=0;}

protected:
    int_type overflow(int_type c) override{
        if(newStr){
            std::string str = std::to_string(n);
            if(str.length()<8){
                str += std::string(8-str.length(), ' ');
            }
            buf->sputn(str.data(), 8);
            newStr = false;
            n++;
            size=0;
        }
        if((char)c=='\n'){
            newStr=true;
            buf->sputc(c);
        } else if (size==71){
            newStr=true;
            buf->sputc(c);
            buf->sputc('\n');
        } else {
            buf->sputc(c);
        }
        size++;
        return c;
    }
};
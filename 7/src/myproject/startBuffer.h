#include <iostream>
#include <string>
#include <cctype>

class stat_buffer: public std::streambuf{
private:
    std::streambuf* buf;
    int strCount;
    int wordCount;
    int charCount;
    bool prevCharIsAlpha;
public:
    explicit stat_buffer(std::streambuf* b):buf(b) { strCount=0; wordCount=0;
        charCount=0; prevCharIsAlpha=false;}

    int getStrCount(){
        return strCount;
    }

    int getWordCount(){
        return wordCount;
    }

    int getCharCount(){
        return charCount;
    }
protected:
    int_type underflow() override{
        int_type c = buf->sbumpc();

        if(c != traits_type::eof()){
            if(std::isalpha(c)){
                if(!prevCharIsAlpha){
                    wordCount++;
                    prevCharIsAlpha=true;
                }
            } else{
                prevCharIsAlpha=false;
            }

            if(c=='\n'){
                strCount++;
            }

            charCount++;

            char ch = traits_type::to_char_type(c);
            setg(&ch, &ch, &ch+1);
        }

        return c;
    }

};
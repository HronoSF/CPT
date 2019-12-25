#include <iostream>

struct Guard {
    std::ostream& stream;
    std::ios::fmtflags stream_flags;
    char stream_fill;

    Guard(std::ostream& str): stream(str){
        stream_flags = stream.flags();
        stream_fill = stream.fill();
    }

    ~Guard(){
        stream.flags(stream_flags);
        stream.fill(stream_fill);
    }
};
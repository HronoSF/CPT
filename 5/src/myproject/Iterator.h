#include <ostream>

template<class T>
class my_iterator{
private:
    std::ostream* pointer;
    int N;
    int n;
public:
    my_iterator(std::ostream& str, int N): pointer(&str), N(N){
        n = 1;
    }

    my_iterator& operator*(){
        return *this;
    }

    my_iterator& operator=(T p){
        if(n == N){
            n = 1;
            *pointer<<p;
        }
        else{
            n++;
        }
        return *this;
    }

    my_iterator& operator++(int i){
        return *this;
    }

    ~my_iterator() = default;

};
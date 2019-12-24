#include <vector>

namespace turnOn{
    template <typename T>
    void turnOn90dClockwise(std::vector<T>& vec, int n){
        for(int i = 0; i<n; i++){
            T a = vec[1];
            vec[1] = -vec[0];
            vec[0] = a;
        }
    }

    template <typename T>
    void turnOn90dCounterClockwise(std::vector<T>& vec, int n){
        for(int i = 0; i<n; i++){
            T a = vec[0];
            vec[0] = -vec[1];
            vec[1] = a;
        }
    }
}

template <typename T>
bool turnOn90deg(std::vector<T>& vec, int deg){
    if (vec.size()>2)
        return false;

    if (deg%90>0)
        return false;

    int n = deg/90;
    if(n>0)
        turnOn::turnOn90dClockwise(vec, n);
    else
        turnOn::turnOn90dCounterClockwise(vec, -1 * n);

    return true;
}
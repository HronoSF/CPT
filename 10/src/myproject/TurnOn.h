#include <vector>
#include <unordered_set>

namespace turnOn {

    template<typename T>
    void CounterClockwise(std::vector<T> &vec, int n) {
        vec[1] = -vec[1];
        std::swap(vec[0], vec[1]);
    }

    template<typename T>
    void Clockwise(std::vector<T> &vec, int n) {
        vec[0] = -vec[0];
        std::swap(vec[0], vec[1]);
    }
}

template<typename T>
bool turnOnVector(std::vector<T> &vec, int angle) {
    if (vec.size() > 2 || angle % 90 > 0) {
        return false;
    }

    int n = angle / 90;

    n > 0 ? turnOn::Clockwise(vec, n) : turnOn::CounterClockwise(vec, -1 * n);

    return true;
}
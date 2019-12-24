#include <array>

template <class T, int N, int M>
struct Tie {
    std::array<T*, M> data;

    Tie(std::array<T*, M> arr) {
        data = arr;
    }

    void operator=(const std::array<T, N*M>& rhs){
        for(int i = 0; i<M; i++){
            for(int j = 0; j<N; j++){
                data[i][j] = *(rhs.begin() + i*N + j);
            }
        }
    }
};

template <class T, size_t N, class... Args>
auto myTie(std::array<T, N>& head, Args&... tail) -> Tie<T, N, sizeof...(tail)+1> {
    std::array<T*, sizeof...(tail)+1> arrays {head.begin(), (tail).begin()...};
    return Tie<T, N, sizeof...(tail)+1>(arrays);
}
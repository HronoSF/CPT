#include <array>

template<class T, std::size_t N, std::size_t M>
std::array<T, N+M> funInner(std::array<T, N> arr1, std::array<T, M> arr2) {

    std::array<T, N+M> retArray;

    std::copy(arr1.cbegin(), arr1.cend(), retArray.begin());
    std::copy(arr2.cbegin(), arr2.cend(), retArray.begin()+N);

    return retArray;
}

template<class Head>
Head fun(Head head){
    return head;
}

template<class Head, class Tail>
auto fun(Head head, Tail tail) -> decltype(funInner(head, tail)){
    return funInner(head, tail);
}

template<class Head, class ... Tail>
auto fun(Head head, Tail ... tail)-> decltype(fun(head, fun(tail...))){
    return fun(head, fun(tail...));
}

template<class ... Arrays>
auto myCat(Arrays ... arrays) -> decltype(fun(arrays...)){
    return fun(arrays...);
}
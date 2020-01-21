#include <complex>
#include <memory>

template<class T>
class Polynomial {
private:
    std::unique_ptr<T[]> array; // array[0] = a(n), array[size-1] = a(0)
    int size;

    template<class Arg>
    void setArgs(int place, Arg head) {
        array[place] = head;
    }

    template<class Arg>
    void setArgs(int place, Arg head, Arg tail) {
        array[place] = head;
        array[place + 1] = tail;
    }

    template<class Head, class ... Args>
    void setArgs(int place, Head head, Args ... tail) {
        array[place] = head;
        voidSetArgs(place + 1, tail...);
    }

public:
    explicit Polynomial() = delete;

    Polynomial(const Polynomial &) = delete;

    Polynomial(Polynomial &&data) : array(std::move(data.array)) {
        size = data.size;
    }

    Polynomial &operator=(Polynomial &&data) {
        size = std::move(data.size);
        array = std::move(data.array);
        return *this;
    }

    ~Polynomial() = default;

    template<class ... Args>
    Polynomial(T head, Args ... args):  array(new T[sizeof...(args) + 1]{std::forward<Args>(args)...}) {
        size = sizeof...(args) + 1;
        array[0] = head;
        setArgs(1, args...);
    }

    Polynomial(T *arr, int size) {
        array.reset(arr);
        std::swap(this->size, size);
    }

    int getSize() const {
        return size;
    }

    void multiply(T x) {
        for (int i = 0; i < size; i++) {
            array[i] = array[i] * x;
        }
    }

    T getArg(int place) const {
        return array[place];
    }

};

template<typename T>
struct is_complex_t : public std::false_type {
};

template<typename T>
struct is_complex_t<std::complex<T>> : public std::true_type {
};

template<typename T>
constexpr bool is_complex() { return is_complex_t<T>::value; }

template<class T>
typename std::enable_if<std::is_arithmetic<T>::value, Polynomial<T>>::type
schurTransform(Polynomial<T> p) {

    int size = p.getSize();
    T *array = new T[size];
    for (int i = 0; i < size; i++) {
        array[i] = p.getArg(size - 1 - i);
    }

    Polynomial<T> reciprocal = std::move(Polynomial<T>(array, size));

    reciprocal.multiply(p.getArg(0));
    p.multiply(p.getArg(p.getSize() - 1));

    T *schurArray = new T[size];
    for (int k = 0; k < size; k++) {
        schurArray[k] = p.getArg(k) - reciprocal.getArg(k);
    }

    return std::move(Polynomial<T>(schurArray, size));
}

template<class T>
typename std::enable_if<is_complex_t<T>::value, Polynomial<T>>::type
schurTransform(Polynomial<T> &p) {

    int size = p.getSize();
    T *array = new T[size];
    for (int i = 0; i < size; i++) {
        array[i] = std::conj(p.getArg(size - 1 - i));
    }

    Polynomial<T> reciprocal(Polynomial<T>(array, size));

    reciprocal.multiply(p.getArg(0));
    p.multiply(std::conj(p.getArg(p.getSize() - 1)));

    T *schurArray = new T[size];
    for (int k = 0; k < size; k++) {
        schurArray[k] = p.getArg(k) - reciprocal.getArg(k);
    }

    return Polynomial<T>(schurArray, size);
}
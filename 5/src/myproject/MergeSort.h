#include <iostream>
#include <typeinfo>

template<typename T>
void merge_sort(T first, T last){
    if (first==last)
        return;

    T f = first;
    int size = 0;
    while(f!=last){
        f++;
        size++;
    }

    if (size==1)
        return;

    T center = first + (size/2);

    merge_sort(first, center);
    merge_sort(center, last);


    T n1 = first;
    T n2 = center;

    typename std::iterator_traits<T>::value_type* list =
            new typename std::iterator_traits<T>::value_type[size];

    size = 0;
    while( n1 != center || n2 != last)
        if( n1 == center)
            while(n2!= last)
            {
                list[size] = *n2;
                n2++;
                size++;
            }
        else
        if(n2 == last)
            while(n1!= center)
            {
                list[size] = *n1;
                n1++;
                size++;
            }
        else
        if(*n1<*n2){
            list[size] = *n1;
            n1++;
            size++;
        }
        else{
            list[size] = *n2;
            n2++;
            size++;
        }

    f = first;
    size = 0;
    while(f!=last){
        *f = list[size];
        size++;
        f++;
    }
    delete[] list;
}
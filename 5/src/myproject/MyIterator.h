#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <utility>

template <class T, unsigned int N = 1>
class MyIterator : public std::iterator<std::input_iterator_tag, T>
{
public:
    MyIterator & operator++()
    {
        return *this;
    }
    MyIterator & operator++(int)
    {
        return *this;
    }
    MyIterator & operator*()
    {
        return *this;
    }
    MyIterator & operator=(T const &val)
    {
        if ( ( i + 1 ) % N == 0)
        {
            if (!first)
                (*stream) << separator;
            else
                first = !first;
            (*stream) << val;
        }
        i++;
        return *this;
    }
    explicit MyIterator(std::ostream & str, std::string sep = " ")
            : stream(&str), separator(std::move(sep)), i(0) {}

private:
    bool first = true;
    std::ostream* stream;
    std::string separator;
    unsigned int i;
};
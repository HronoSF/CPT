#include <string>

namespace My{
    struct Person{
        int id;
        std::string first_name, last_name;

        bool operator==(const Person& p) const{
            return id == p.id;
        }

        bool operator<(Person const & other) const {
            return to_string() < other.to_string();
        }

        std::string to_string() const {
            return first_name + " " + last_name;
        }

        int getId() const {
            return id;
        }
    };
}

namespace std{

    template<>
    struct hash<My::Person>{
        typedef size_t result_type;
        typedef My::Person argument_type;
        result_type operator()(const argument_type& x) const{
            return static_cast<result_type>(x.getId());
        }
    };
}
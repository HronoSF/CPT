#include <string>

/*! \mainpage Welcome,Please Navigate to Namespaces to see my doc
 */
/**
*namespace Person
*@brief Custom namespace to use Account structure
*@author HronoSF
*/
namespace Person {
/**
*@brief Structure in Person namespace representing a person account
*@detailed Has fields id,name.Can be used as key in std::unordered_map,std::map and
*as element in std::unordered_set,std::set.
*/
    struct Account {
        int id;
        std::string first_name, last_name;

/**
*@brief overloaded comparison operator
*@detailed nessesary for std::unordered_map
*@param p Account structure to compare
*@return is same or not
*/
        bool operator==(const Account &p) const {
            return id == p.id;
        }

/**
*@brief overloaded less operator
*@detailed nessesary for std::set
*@param other Account structure to compare
*@return is less or not
*/
        bool operator<(Account const &other) const {
            return to_string() < other.to_string();
        }

/**
*@brief cast Account Structure to string
*/
        std::string to_string() const {
            return first_name + " " + last_name;
        }

/**
@brief getter of id field
@return id of Person Account
*/
        int getId() const {
            return id;
        }
    };
}


/**
*@brief implementation of std::hash for Account structure
*/
template<>
struct std::hash<Person::Account> {
    typedef size_t result_type;
    typedef Person::Account argument_type;

/**
*@brief overloaded operator () to compute hash-function
*@param x argument key of type Key
*@return returns a value of type size_t that represents the hash value of key
*/
    result_type operator()(const argument_type &x) const {
        return static_cast<result_type>(x.getId());
    }
};

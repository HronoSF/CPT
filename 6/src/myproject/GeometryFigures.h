#include <string>
#include <cmath>

class Circle
{
private:
    float radius;

public:
    explicit Circle(float R){
        this->radius = R;
    }

    void setRadius(float R){
        this->radius = R;
    }

    float getRadius() const {
        return this->radius;
    }

    float square() const {
        return M_PI*pow(radius, 2);
    }
};

class Rectangle
{
private:
    float a, b;

public:
    Rectangle(float a, float b){
        this->a = a;
        this->b = b;
    }

    void setA(float a){
        this->a = a;
    }

    float getA() const{
        return a;
    }

    void setB(float b){
        this->b = b;
    }

    float getB() const{
        return b;
    }

    float square(){
        return a*b;
    }
};

namespace std
{
    template<class T>
    struct Trait;

    template<>
    struct Trait<Circle> {
        static int size(const Circle& c){
            return sizeof(c.getRadius());
        }
    };

    template<>
    struct Trait<Rectangle> {
        static int size(const Rectangle& r){
            return sizeof(r.getA()) + sizeof(r.getB());
        }
    };
} 
#ifndef __UNITS_OF_ANGLE_HPP__
#define __UNITS_OF_ANGLE_HPP__
#include<ostream>
#include"Constants.hpp"
class Radian;
class Degree {
    int degree;
public:
    Degree() : degree(0) {}
    Degree(int value) : degree(value){}
    Degree(const Degree& value) : degree(value.degree){}
    int GetValue() const { return degree; }
    Radian ToRadian() const;
    friend std::ostream& operator<<(std::ostream& out, const Degree& value){
        return out << value.degree << " deg";
    }
};
class Radian {
    double radian;
public:
    Radian() : radian(0) {}
    Radian(double value) : radian(value){}
    Radian(const Radian& value) : radian(value.radian) {}
    double GetValue() const { return radian; }
    Degree ToDegree() const {
        return Degree(radian * (180 / Pi));
    }
    friend std::ostream& operator<<(std::ostream& out, const Radian& value){
        return out << value.radian << " rad";
    }
};
Radian Degree::ToRadian() const {
    return Radian(degree * (Pi / 180));
}
#endif
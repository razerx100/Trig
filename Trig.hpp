#ifndef __TRIG_HPP__
#define __TRIG_HPP__
#include<string>
#include"TrigRatios.hpp"
#include<iostream>
namespace Trig {
    struct Side {
        std::string name;
        double value;
    };
    struct Angle {
        char name;
        Radian value;
    };
    std::ostream& operator<<(std::ostream& out, const Side& value){
        return out << value.name << " = " << value.value << " ";
    }
    std::ostream& operator<<(std::ostream& out, const Angle& value){
        return out << value.name << " = " << value.value.ToDegree() << " ";
    }
    class RightTriangle {
        std::string rightAngle;
        Angle first, second;
        Side hypotenuse, adjacent, opposite;
        std::pair<std::string, std::string> GetValueFromString(std::string str){
            std::pair<std::string, std::string> value;
            for(int i = 0; i < str.length(); i++){
                if(str[i] == '='){
                    value.first = str.substr(0, i + 1);
                    value.second = str.substr(i + 1, str.length() - i + 1);
                    break;
                }
            }
            return value;
        }
    public:
        RightTriangle(const char* name) : rightAngle(std::move(name)) {
            hypotenuse.name = std::string(1, rightAngle[0]) + std::string(1, rightAngle[2]);
            first.name = rightAngle[0];
            second.name = rightAngle[2];
        }
        RightTriangle(const RightTriangle& trig) : rightAngle(trig.rightAngle) {
            hypotenuse.name = "" + rightAngle[0] + rightAngle[2];
            first.name = rightAngle[0];
            second.name = rightAngle[2];
        }
        void Calculate(std::string side, std::string angle){
            std::pair<std::string, std::string> value = GetValueFromString(angle);
            if(value.first.length() > 1){
                value.first = "" + value.first[1];
            }
            if(value.first[0] == first.name){   //FIRST ANGLE'S VALUE IS GIVEN
                first.value = Degree(std::stod(value.second)).ToRadian();
                second.value = (Pi / 2) - first.value.GetValue();
                adjacent.name = rightAngle.substr(0, 2);
                opposite.name = rightAngle.substr(1, 2);

                // SET SIDES
                std::pair<std::string, std::string> side_var = GetValueFromString(side);
                if(side_var.first == adjacent.name){
                    adjacent.value = std::stod(side_var.second);
                    hypotenuse.value = Sec(first.value) * adjacent.value;
                    opposite.value = Sin(first.value) * hypotenuse.value;
                }
                else {
                    opposite.value = std::stod(side_var.second);
                    hypotenuse.value = Cosec(first.value) * opposite.value;
                    adjacent.value = Cos(first.value) * hypotenuse.value;
                }
            }
            else {                              //SECOND ANGLE'S VALUE IS GIVEN
                second.value = Degree(std::stod(value.second)).ToRadian();
                first.value = (Pi / 2) - second.value.GetValue();
                opposite.name = rightAngle.substr(0, 2);
                adjacent.name = rightAngle.substr(1, 2);

                // SET SIDES
                std::pair<std::string, std::string> side_var = GetValueFromString(side);
                if(side_var.first == adjacent.name){
                    adjacent.value = std::stod(side_var.second);
                    hypotenuse.value = Sec(second.value) * adjacent.value;
                    opposite.value = Sin(second.value) * hypotenuse.value;
                }
                else {
                    opposite.value = std::stod(side_var.second);
                    hypotenuse.value = Cosec(second.value) * opposite.value;
                    adjacent.value = Cos(second.value) * hypotenuse.value;
                }
            }
        }
        friend std::ostream& operator<<(std::ostream& out, const RightTriangle& trig){
            return out << trig.rightAngle + " = 90 deg " << trig.first <<
            trig.second << trig.hypotenuse << trig.adjacent << trig.opposite;
        }
    };
}
#endif
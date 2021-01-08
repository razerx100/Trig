#ifndef __TRIG_RATIOS__
#define __TRIG_RATIOS__
#include"UnitsOfAngle.hpp"
#include<cmath>
namespace Trig{
    double Sin(const Radian& value){
        return std::sin(value.GetValue());
    }
    double Sin(const Degree& value){
        return Sin(value.ToRadian());
    }
    double Cos(const Radian& value){
        return std::cos(value.GetValue());
    }
    double Cos(const Degree& value){
        return Cos(value.ToRadian());
    }
    double Tan(const Radian& value){
        return std::tan(value.GetValue());
    }
    double Tan(const Degree& value){
        return Tan(value.ToRadian());
    }
    double Sec(const Radian& value){
        return 1 / std::cos(value.GetValue());
    }
    double Sec(const Degree& value){
        return Sec(value.ToRadian());
    }
    double Cosec(const Radian& value){
        return 1 / std::sin(value.GetValue());
    }
    double Cosec(const Degree& value){
        return Cosec(value.ToRadian());
    }
    double Cot(const Radian& value){
        return 1 / std::tan(value.GetValue());
    }
    double Cot(const Degree& value){
        return Cot(value.ToRadian());
    }
}
#endif
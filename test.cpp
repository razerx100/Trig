#include<iostream>
#include"Trig.hpp"
int main(){
    // Degree a = 30, b = 60;
    // std::cout << Trig::Cosec(a) << " " << Trig::Sec(b);
    Trig::RightTriangle abc = "ACB";
    abc.Calculate("AC=5", "B=30");
    std::cout << abc;
    return 0;
}
#include <Objects.hpp>
#include <iostream>

Objects earth("Earth", 10.f, 12.f, 1234.f, 1200.f, 100.f);

int main(){
    earth.setAcceleration(1021.f);
    std::cout << earth.getPositionX() << earth.getName()<< std::endl;
    std::cout << earth.getAcceleration() << std::endl;
    return 0;
}


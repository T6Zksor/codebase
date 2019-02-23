#include "StrategyPattern.h"
#include <iostream>

using namespace DesignPattern::StrategyPattern;

void FlyWithWings::fly() {
    std::cout << "I'am flying with wings!!" << std::endl;
}

void FlyNoWay::fly() {
    std::cout << "I just CAN'T fly!!" << std::endl;
}

void Quack::quack() {
    std::cout << "Quack!!" << std::endl;
}

void Squeak::quack() {
    std::cout << "Squeak!!" << std::endl;
}

void MuteQuack::quack() {
    std::cout << "MuteQuack!!" << std::endl;
}

void Duck::Execute() {
    PerformFly();
    PerformQuack();
}

MallardDuck::MallardDuck() {
    _fly = new FlyWithWings;
    _quack = new Quack;
}
void MallardDuck::PerformDisplay() {
    std::cout << "I looked like a MallardDuck!" << std::endl;
}

RubberDuck::RubberDuck() {
    _fly = new FlyNoWay;
    _quack = new MuteQuack;
}
void RubberDuck::PerformDisplay() {
    std::cout << "I looked like a RubberDuck!" << std::endl;
}

void Instance::Execute() {
#define _fuck_duck(_type)   _duck = new _type;\
                            _duck->Execute();\
                            delete _duck;
    Duck *_duck;
    _fuck_duck(MallardDuck)
    _fuck_duck(RubberDuck)
}
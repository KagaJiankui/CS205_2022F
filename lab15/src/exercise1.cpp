#include "exercise1.h"
#include <iostream>
void Car::showinfo() const {
  const char *str_ison = nullptr;
  if (this->mode==Car::Off)
  {
    str_ison="Off";
  }else if (this->mode==Car::On)
  {
    str_ison="On";
  }
  std::cout<<"The information of car: mode is "<<str_ison<<", velocity is "<<this->velocity<<std::endl;
}

int Car::getvel() const { return this->velocity; }

bool Car::ison() const { return this->mode == Car::On; }

bool Car::veldown(int v) {
  if (this->velocity-v<(int)Car::Minvel)
  {
    std::cout << "The velocity is " << this->velocity - v << ". It it out of Minvel." << std::endl;
    return false;
  }else
  {
    this->velocity-=v;
    std::cout << "The velocity is " << this->velocity << std::endl;
    return true;
  }
}

bool Car::velup(int v) {
  if (this->velocity+v>(int)Car::Maxvel)
  {
    std::cout << "The velocity is " << this->velocity + v << ". It it out of Maxvel." << std::endl;
    return false;
  }else
  {
    this->velocity+=v;
    std::cout << "The velocity is " << this->velocity << std::endl;
    return true;
  }
}

void Driver::setmode(Car &car) {
  if (car.mode==Car::On)
  {
    car.mode=Car::Off;
  }else
  {
    car.mode=Car::On;
  }
}

bool Driver::ison(Car& car) const { return car.mode == Car::On; }

bool Driver::velup(Car &car, int v) {
  if (car.velocity + v > (int)Car::Maxvel) {
    std::cout << "The velocity is " << car.velocity + v << ". It it out of Maxvel." << std::endl;
  } else {
    std::cout << "The velocity is " << car.velocity << std::endl;
  }
    car.velocity += v;
    return true;
}

bool Driver::veldown(Car &car, int v) {
  if (car.velocity - v < (int)Car::Minvel) {
    std::cout << "The velocity is " << car.velocity - v << ". It it out of Minvel." << std::endl;
  } else {
    std::cout << "The velocity is " << car.velocity << std::endl;
  }
    car.velocity -= v;
    return true;
}

int main(int argc, char const *argv[])
{
    Car car_sample;
    Driver driver_sample;
    car_sample.showinfo();
    std::cout<<"Increase velocity by car, its mode is"<<(car_sample.ison()?"Off":"On")<<" ";
    car_sample.velup(120);
    std::cout << "Set the mode of car by driver" << std::endl;
    driver_sample.setmode(car_sample);
    car_sample.showinfo();
    std::cout<<"Decrease velocity by driver:";
    driver_sample.veldown(car_sample, 100);
    std::cout<<"Increase velocity by driver:";
    driver_sample.velup(car_sample, 150);
    car_sample.showinfo();
  return 0;
}

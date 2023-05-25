#ifndef EXERCISE1_H
#define EXERCISE1_H

class Car {
private:
  enum {
    Off = 0,
    On = 1
  }; // Off- non automatically drive, On-automatically drive
  enum {
    Minvel,
    Maxvel = 200
  };        // range of velocity from 0 to 200
  int mode; // mode of car, Off or On
  int velocity;

public:
  friend class Driver;
  Car(int m = On, int v = 50) : mode(m), velocity(v) {}
  bool velup(int v);     // increase velocity by v
  bool veldown(int v);   // decrease velocity by v
  bool ison() const;     // Check whether the mode is on
  int  getvel() const;   // get the velocity
  void showinfo() const; // show the mode and velocity of car
};

class Driver {
public:
  bool velup(Car &car, int v);   // increase velocity by v
  bool veldown(Car &car, int v); // decrease velocity by v
  void setmode(Car &car);        // If the mode is On, set it to Off,otherwise set it to Off
  bool ison(Car &car) const;     // Check whether the mode is on
};

#endif // EXERCISE1_H
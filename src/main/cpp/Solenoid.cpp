#include "Solenoid.h"

Solenoid::Solenoid(){

}; //consturcter - lets the class be called in this file
    
void Solenoid::Release(bool on)  {
    if(on) {
        exampleDouble.Set(frc::DoubleSolenoid::Value::kForward);
    }
    else {
        exampleDouble.Set(frc::DoubleSolenoid::Value::kOff);
    }

};

void Solenoid::originPos(){

    Release(0);

}; // Notservo is the class that the function is in
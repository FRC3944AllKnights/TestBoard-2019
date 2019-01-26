#ifndef SOLENOID_H
#define SOLENOID_H

#include <frc/Servo.h>

class Solenoid{
    
    public: 
        
        Solenoid(); //constructor - when called it builds the class, creates instance 

        void Release(bool on); //lifterlock variable for turning it on off
        void originPos();

    private:

};

#endif

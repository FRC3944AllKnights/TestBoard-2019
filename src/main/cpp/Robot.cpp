/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/TimedRobot.h>
#include <frc/Joystick.h>
#include "Solenoid.h"
#include <ctre/Phoenix.h>

TalonSRX srx = {0};

/** This is a test
 * This is a demo program showing how to use Mecanum control with the
 * MecanumDrive class.
 */
class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override {
    srx.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,0,0);
    srx.SetInverted(true);
    int AbsolutePosition=srx.GetSelectedSensorPosition(0)&0xFFF;
    srx.SetSelectedSensorPosition(AbsolutePosition,0,0);
    //srx.Set(ControlMode::PercentOutput,0);
    // Invert the left side motors. You may need to change or remove this to
    // match your robot.
    solenoid.originPos();
    
  }

  void TeleopPeriodic() override {
    /* Use the joystick X axis for lateral movement, Y axis for forward
     * movement, and Z axis for rotation.
     */
    
    if (m_stick.GetRawButton(6)){
        solenoid.Release(false);
    }
    else{
        solenoid.Release(true);
    }
    
    if (m_stick.GetRawButton(5)){
        // srx.SetSelectedSensorPosition(-10,0,0);
        // double TargetPosition=m_stick.GetY()*10*4096;
        // srx.Set(ControlMode::Position,TargetPosition);
        // std::string Output;
        // Output.append(std::to_string(TargetPosition));
    }
    double TargetPosition=m_stick.GetY()*10*4096;
    srx.Set(ControlMode::Position,4096);
    // srx.Set(ControlMode::PercentOutput, -1*m_stick.GetY());
    // double stick=m_stick.GetRawAxis(1)*-1;
    // srx.Set(ControlMode::PercentOutput,stick);
  }

 private:
 //this is where to change variables
  static constexpr int kJoystickChannel = 0;
  Solenoid solenoid; //names the class notServo - servo, also creates an instance of servo
  frc::Joystick m_stick{kJoystickChannel};
 
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>();}
#endif
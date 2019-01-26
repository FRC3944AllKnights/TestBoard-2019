/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/TimedRobot.h>
#include <frc/Joystick.h>
#include "Solenoid.h"

/** This is a test
 * This is a demo program showing how to use Mecanum control with the
 * MecanumDrive class.
 */
class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override {
    // Invert the left side motors. You may need to change or remove this to
    // match your robot.
  }

  void TeleopPeriodic() override {
    /* Use the joystick X axis for lateral movement, Y axis for forward
     * movement, and Z axis for rotation.
     */
    if (m_stick.GetRawButton(6)){
      
    }
    else{
      
    }

  }

 private:
 //this is where to change variables
  static constexpr int kJoystickChannel = 0;
  Solenoid servo; //names the class notServo - servo, also creates an instance of servo
  frc::Joystick m_stick{kJoystickChannel};
};

START_ROBOT_CLASS(Robot)
#include "DriveCommand.h"
#include "../Subsystems/DriveTrain.h"
#include "../OI.h"

DriveCommand::DriveCommand() : frc::Command("DriveCommand") {
	// Use Requires() here to declare subsystem dependencies
	Requires(DriveTrain::Get().get());
}

// Called just before this Command runs the first time
void DriveCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute() {
	auto& joystick = OI::Get()->GetJoystick();
	DriveTrain::Get()->Drive(-joystick.GetY(frc::GenericHID::JoystickHand::kLeftHand), joystick.GetZ());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveCommand::End() {
	DriveTrain::Get()->Drive(0.0,0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCommand::Interrupted() {

}

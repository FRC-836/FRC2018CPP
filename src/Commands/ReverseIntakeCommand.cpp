#include "ReverseIntakeCommand.h"
#include "../Subsystems/Intake.h"
#include "SmartDashboard/SmartDashboard.h"

ReverseIntakeCommand::ReverseIntakeCommand() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Intake::Get().get());
}

// Called just before this Command runs the first time
void ReverseIntakeCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ReverseIntakeCommand::Execute() {
	Intake::Get()->SetIntakeSpeed(frc::SmartDashboard::GetNumber("IntakeSpeed", 1.0)*-1);
}

// Make this return true when this Command no longer needs to run execute()
bool ReverseIntakeCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ReverseIntakeCommand::End() {
	Intake::Get()->SetIntakeSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReverseIntakeCommand::Interrupted() {
	End();
}

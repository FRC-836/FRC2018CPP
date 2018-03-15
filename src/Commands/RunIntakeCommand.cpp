#include <Commands/RunIntakeCommand.h>
#include "../SubSystems/Intake.h"
#include "SmartDashboard/SmartDashboard.h"

RunIntakeCommand::RunIntakeCommand() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Intake::Get().get());
}

// Called just before this Command runs the first time
void RunIntakeCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RunIntakeCommand::Execute() {
	Intake::Get()->SetIntakeSpeed(frc::SmartDashboard::GetNumber("IntakeSpeed", 1.0));
}

// Make this return true when this Command no longer needs to run execute()
bool RunIntakeCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void RunIntakeCommand::End() {
	Intake::Get()->SetIntakeSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunIntakeCommand::Interrupted() {
	End();
}

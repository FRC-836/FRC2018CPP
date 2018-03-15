#include "Intake.h"
#include "../RobotMap.h"
#include <Talon.h>

static std::shared_ptr<Intake> intake_singleton = nullptr;

std::shared_ptr<Intake> Intake::Get() {
	if (intake_singleton == nullptr)
		intake_singleton = std::make_shared<Intake>();
	return intake_singleton;
}

Intake::Intake() : frc::Subsystem("Intake") {
	m_IntakeMotor = std::make_shared<frc::Talon>(kIntakeMotor);

}

void Intake::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Intake::SetIntakeSpeed(double speed) {
	m_IntakeMotor->Set(speed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

#ifndef Intake_H
#define Intake_H

#include <Commands/Subsystem.h>
#include <SpeedController.h>

class Intake : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	std::shared_ptr<frc::SpeedController> m_IntakeMotor;

public:
	Intake();
	void InitDefaultCommand();

	void SetIntakeSpeed(double speed);

	static std::shared_ptr<Intake> Get();
};

#endif  // Intake_H

#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <SpeedController.h>
#include <SpeedControllerGroup.h>
#include <memory>
#include <Encoder.h>
#include "../RobotMap.h"

class DriveTrain : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<frc::DifferentialDrive> m_Drive;
	std::shared_ptr<frc::SpeedController> m_LeftControllers[kNumMotorsPerSide];
	std::shared_ptr<frc::SpeedController> m_RightControllers[kNumMotorsPerSide];
	std::shared_ptr<frc::SpeedControllerGroup> m_LeftGroup;
	std::shared_ptr<frc::SpeedControllerGroup> m_RightGroup;

	frc::Encoder m_leftEnc{kLeftEnc1, kLeftEnc2};
	frc::Encoder m_rightEnc{kRightEnc1, kRightEnc2};

public:
	DriveTrain();
	void InitDefaultCommand();
	void Log();
	void Drive(double speed, double rotation);
	void Reset();

	double GetDistance();

	static std::shared_ptr<DriveTrain> Get();
};

#endif  // DriveTrain_H

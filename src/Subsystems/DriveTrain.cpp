#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/DriveCommand.h"
#include <SmartDashboard/SmartDashboard.h>

#include <Talon.h>

static std::shared_ptr<DriveTrain> drive_singleton = nullptr;


std::shared_ptr<DriveTrain> DriveTrain::Get() {
	if (drive_singleton == nullptr)
		drive_singleton = std::make_shared<DriveTrain>();
	return drive_singleton;
}

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain") {

	for (int i = 0; i < kNumMotorsPerSide; i++) {
		m_LeftControllers[i] = std::make_shared<frc::Talon>(kLeftMotor[i]);
		m_LeftControllers[i]->SetInverted(kLeftMotorInv[i]);
		m_RightControllers[i] = std::make_shared<frc::Talon>(kRightMotor[i]);
		m_RightControllers[i]->SetInverted(kRightMotorInv[i]);
	}

	m_LeftGroup = std::make_shared<frc::SpeedControllerGroup>(*(m_LeftControllers[0]), *(m_LeftControllers[1])); //, *(m_LeftControllers[2]));
	m_RightGroup = std::make_shared<frc::SpeedControllerGroup>(*(m_RightControllers[0]), *(m_RightControllers[1])); //, *(m_RightControllers[2]));
	//m_LeftGroup->SetInverted(true);

	m_Drive = std::make_unique<frc::DifferentialDrive>(*m_LeftGroup, *m_RightGroup);
	m_Drive->SetSubsystem("DriveTrain");
	m_Drive->SetMaxOutput(0.85);

#ifndef SIMULATION
	m_leftEnc.SetDistancePerPulse(kDistPerEncPulseDrive);
	m_rightEnc.SetDistancePerPulse(kDistPerEncPulseDrive);
#else
	// Circumference in ft = 4in/12(in/ft)*PI
	m_leftEnc.SetDistancePerPulse(
			static_cast<double>(4.0 / 12.0 * M_PI) / 360.0);
	m_rightEnc.SetDistancePerPulse(
			static_cast<double>(4.0 / 12.0 * M_PI) / 360.0);
#endif

	AddChild("Left Encoder", m_leftEnc);
	AddChild("Right Encoder", m_rightEnc);

}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	 SetDefaultCommand(new DriveCommand());
}

void DriveTrain::Log() {
	frc::SmartDashboard::PutNumber(
			"Left Distance", m_leftEnc.GetDistance());
	frc::SmartDashboard::PutNumber(
			"Right Distance", m_rightEnc.GetDistance());
	frc::SmartDashboard::PutNumber("Left Speed", m_leftEnc.GetRate());
	frc::SmartDashboard::PutNumber("Right Speed", m_rightEnc.GetRate());
	//frc::SmartDashboard::PutNumber("Gyro", m_gyro.GetAngle());
}

void DriveTrain::Drive(double speed, double rotation) {
	m_Drive->CurvatureDrive(speed, rotation, speed < 0.05);
}

void DriveTrain::Reset() {
	m_leftEnc.Reset();
	m_rightEnc.Reset();
}

double DriveTrain::GetDistance() {
	return (m_leftEnc.GetDistance() + m_rightEnc.GetDistance())
	       / 2.0;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

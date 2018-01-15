/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>

static std::shared_ptr<OI> oi_singleton = nullptr;

std::shared_ptr<OI> OI::Get() {
	if (oi_singleton == nullptr)
		oi_singleton = std::make_shared<OI>();
	return oi_singleton;
}

OI::OI() {
	// Process operator interface input here.
}

frc::Joystick& OI::GetJoystick() {
	return m_joy;
}

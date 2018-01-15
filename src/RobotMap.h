/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

constexpr int kNumMotorsPerSide = 2;

constexpr int kLeftMotor[kNumMotorsPerSide] = {1, 0};
constexpr bool kLeftMotorInv[kNumMotorsPerSide] = { false, false};

constexpr int kRightMotor[kNumMotorsPerSide] = {2, 3};
constexpr bool kRightMotorInv[kNumMotorsPerSide] = { false, true};

constexpr int kLeftEnc1 = 9;
constexpr int kLeftEnc2 = 8;
constexpr int kRightEnc1 = 7;
constexpr int kRightEnc2 = 6;


constexpr double kDistPerEncPulseDrive = 0.042;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;

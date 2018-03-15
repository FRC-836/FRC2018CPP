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

constexpr int kIntakeButton = 5;
constexpr int kIntakeRevButton = 7;



//CAN Motors:
//Left Rear(0), Middle(2), Front(4) -
//Right Rear(1), Middle(3), Front(5) - invert all
constexpr int kNumMotorsPerSide = 3;

constexpr int kLeftMotor[kNumMotorsPerSide] = {0, 2, 4};
constexpr bool kLeftMotorInv[kNumMotorsPerSide] = { false, false, false};

constexpr int kRightMotor[kNumMotorsPerSide] = {1, 3, 5};
constexpr bool kRightMotorInv[kNumMotorsPerSide] = { true, true, true};

constexpr int kLeftEnc1 = 0;
constexpr int kLeftEnc2 = 1;
constexpr int kRightEnc1 = 2;
constexpr int kRightEnc2 = 3;

constexpr int kLeftEncReverse = true;
constexpr int kRightEncReverse = true;

//CAN Lift Vertical(6), Rotation(7) Talon SRX

constexpr double kDistPerEncPulseDrive = 0.14719;

constexpr int kIntakeMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;

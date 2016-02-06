#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

struct RobotMap
{
	const static u_int32_t
		DRIVE_LEFT_ENCODER_A = 0,
		DRIVE_LEFT_ENCODER_B = 1,
		DRIVE_RIGHT_ENCODER_A = 2,
		DRIVE_RIGHT_ENCODER_B = 3,
		ARM_ENCODER_A = 4,
		ARM_ENCODER_B = 5,
		DRIVE_FRONT_LEFT_MOTOR = 0,
		DRIVE_REAR_LEFT_MOTOR = 1,
		DRIVE_FRONT_RIGHT_MOTOR = 2,
		DRIVE_REAR_RIGHT_MOTOR = 3,
		LIFT_MOTOR = 4,
		ARM_LIFT_MOTOR = 5,
		ARM_COLLECT_MOTOR = 6;
};

#endif

#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

struct RobotMap
{
	const static u_int32_t
		DRIVE_LEFT_ENCODER_A = 22,
		DRIVE_LEFT_ENCODER_B = 21,
		DRIVE_RIGHT_ENCODER_A = 11,
		DRIVE_RIGHT_ENCODER_B = 10,
		ARM_ENCODER_A = 5,
		ARM_ENCODER_B = 6,
		DRIVE_FRONT_LEFT_MOTOR = 1,
		DRIVE_REAR_LEFT_MOTOR = 2,
		DRIVE_FRONT_RIGHT_MOTOR = 3,
		DRIVE_REAR_RIGHT_MOTOR = 4,
		ARM_LIFT_MOTOR = 5,
		ARM_COLLECT_MOTOR = 8,
		SHOOT_LEFT_MOTOR = 6,
		SHOOT_RIGHT_MOTOR = 7,
		LIFT_TAPE_MOTOR = 0,
		LIFT_ROPE_MOTOR = 1;
};

#endif

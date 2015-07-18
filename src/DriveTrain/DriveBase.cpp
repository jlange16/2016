/*
 * DriveBase.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: nlele
 */

#include <DriveTrain/DriveBase.h>

#include "Motor.h"

#include <iterator>

DriveBase::DriveBase(int motor_a, int motor_b, int motor_c, int motor_d) {
	all_motors[motor_a] = std::shared_ptr<Motor> (new Motor (motor_a) );
	all_motors[motor_b] = std::shared_ptr<Motor> (new Motor (motor_b) );
	all_motors[motor_c] = std::shared_ptr<Motor> (new Motor (motor_c) );
	all_motors[motor_d] = std::shared_ptr<Motor> (new Motor (motor_d) );

	motors_side[all_motors[motor_a] ] = Side::RIGHT;
	motors_side[all_motors[motor_b] ] = Side::RIGHT;
	motors_side[all_motors[motor_c] ] = Side::LEFT;
	motors_side[all_motors[motor_d] ] = Side::LEFT;
}

DriveBase& DriveBase::getInstance(int motor_a, int motor_b, int motor_c, int motor_d)
{
	static bool initialized = false;

	if( (motor_a == -1 || motor_b == -1 || motor_c == -1 || motor_d == -1) && !initialized)
	{
		initialized = true;
	}

	if(initialized)
	{
		static DriveBase db = DriveBase(motor_a, motor_b, motor_c, motor_d);
		return db;
	}
}

void DriveBase::setAll(double speed)
{
	for (std::map<int, std::shared_ptr<Motor> >::iterator it = all_motors.begin(); it != all_motors.end(); it++)
	{
		it->second->setSpeed(speed);
	}
}

void DriveBase::setIndividual(int port, double speed)
{
	all_motors[port]->setSpeed(speed);
}

void DriveBase::setDouble(Side side, double speed)
{
	for(std::map<std::shared_ptr<Motor>, Side>::iterator it = motors_side.begin(); it != motors_side.end(); it++)
	{
		if(it->second == side)
		{
			it->first->setSpeed(speed);
		}
	}
}

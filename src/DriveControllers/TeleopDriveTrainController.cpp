/*
 * TeleopDriveTrainController.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: nlele
 */

#include <DriveControllers/TeleopDriveTrainController.h>

#include "User Controls/UserController.h"

const double MAX_THROTTLE = 0.5;

TeleopDriveTrainController::TeleopDriveTrainController(UserController* controller, DriveBase* drivebase, DriveType drivetype) : current_type(drivetype)
{
	p_user_controller.reset(controller);
	p_drive_base.reset(drivebase);
}

void TeleopDriveTrainController::update()
{
	double turn = p_user_controller->getRightXAxis();
	double throttle = p_user_controller->getLeftYAxis();

	double r_speed, l_speed;

	if(turn > 0 && throttle != 0)
	{
		r_speed = throttle * MAX_THROTTLE;
		l_speed = findWheelSpeeds(throttle, turn) * MAX_THROTTLE;
		setTurn(l_speed, r_speed);
	}
	if(turn < 0 && throttle != 0)
	{
		r_speed = findWheelSpeeds(throttle, turn) * MAX_THROTTLE;
		l_speed = throttle * MAX_THROTTLE;
		setTurn(l_speed, r_speed);
	}

	if(turn == 0 && throttle != 0)
	{
		setStraight(throttle);
	}
	if(turn != 0 && throttle == 0)
	{
		turnInPlace(turn);
	}


}

void TeleopDriveTrainController::setStraight(double speed)
{
	if(current_type == TANK)
	{
		p_drive_base->setAll(speed);
	}
}

void TeleopDriveTrainController::turnInPlace(double speed)
{
	if(current_type == TANK)
	{
		p_drive_base->setDouble(LEFT, speed);
		p_drive_base->setDouble(RIGHT, -speed);
	}
}

void TeleopDriveTrainController::setTurn(double l_speed, double r_speed)
{
	if(current_type == TANK)
	{
		p_drive_base->setDouble(LEFT, l_speed);
		p_drive_base->setDouble(RIGHT, r_speed);
	}
}

double TeleopDriveTrainController::findWheelSpeeds(double throttle, double turn)
{
	return throttle - (throttle * turn);
}

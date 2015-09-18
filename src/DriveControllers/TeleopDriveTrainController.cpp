/*
 * TeleopDriveTrainController.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: nlele
 */

#include <DriveControllers/TeleopDriveTrainController.h>

#include "User Controls/UserController.h"
#include "Configs/Configs.h"

#include <ctime>
#include <cmath>

TeleopDriveTrainController::TeleopDriveTrainController(UserController* controller, DriveBase* drivebase, DriveType drivetype) :
		p_user_controller(controller), p_drive_base(drivebase), current_type(drivetype)
{
}

TeleopDriveTrainController::~TeleopDriveTrainController() = default;

void TeleopDriveTrainController::update()
{
	double controller_turn = p_user_controller->getRightXAxis();
	double controller_throttle = p_user_controller->getLeftYAxis();

	double throttle = findThrottle(controller_throttle * Configs::THROTTLE_MULTIPLIER);
	double turn = findThrottle(controller_turn * Configs::THROTTLE_MULTIPLIER);

	if(throttle != 0 && turn != 0)
	{
		setTurn(throttle, turn);
	}
	else if(throttle != 0 && turn == 0)
	{
		setStraight(throttle);
	}
	else if(throttle == 0 && turn != 0)
	{
		turnInPlace(turn);
	}
	else
	{
		const double STOP = 0.0;
		setStraight(STOP);
	}
}

void TeleopDriveTrainController::setStraight(double speed)
{
	if(current_type == DriveType::TANK)
	{
		p_drive_base->setAll(speed);
	}
}

void TeleopDriveTrainController::turnInPlace(double speed)
{
	if(current_type == DriveType::TANK)
	{
		p_drive_base->setSide(LEFT, speed);
		p_drive_base->setSide(RIGHT, -speed);
	}
}

void TeleopDriveTrainController::setTurn(double throttle, double turn)
{
	auto calcInsideWheelSpeed = [](double outside_speed, double turn_steepness)
		{
			double turn_radius = Configs::MAX_TURN_RADIUS - (Configs::MAX_TURN_RADIUS * turn_steepness);

			return outside_speed * (turn_radius / (turn_radius - Configs::ROBOT_WIDTH) );
		};
	if(current_type == DriveType::TANK)
	{
		double l_side = throttle;
		double r_side = calcInsideWheelSpeed(throttle, turn);

		//TODO: IMPLEMENT REVERSE TURNING

		p_drive_base->setSide(LEFT, l_side);
		p_drive_base->setSide(RIGHT, r_side);
	}
}

double TeleopDriveTrainController::findThrottle(double throttle)
{
	//stores last throttle!
	static float prev_throttle = 0.0f;

	//clock returns clock ticks since epoch
	static float prev_time = clock();
	float current_time = clock();

	if(Configs::ACCEL_TIME != 0)
	{
		double accel = (throttle - prev_throttle) / Configs::ACCEL_TIME;
		float delta_time = current_time - prev_time;

		double delta_throttle = delta_time * accel;

		throttle = prev_throttle + delta_throttle;
	}

	//sets prev time to current one
	prev_time = current_time;

	//sets prev throttle to current one
	prev_throttle = throttle;

	return (abs(throttle) < Configs::ZERO_THROTTLE_THRESHOLD) ? 0.0 : throttle;
}

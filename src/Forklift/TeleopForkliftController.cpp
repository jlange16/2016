/*
 * TeleopForkliftController.cpp
 *
 *  Created on: Sep 5, 2015
 *      Author: norayu
 */

#include <Forklift/TeleopForkliftController.h>

#include "Forklift/Forklift.h"
#include "User Controls/UserController.h"
#include "Configs/Configs.h"

#include <Joystick.h>

TeleopForkliftController::TeleopForkliftController(Forklift* fl, UserController* uc) :
	forklift(fl), controller(uc)
{
}

void TeleopForkliftController::update()
{
	//gets input from controllers
	double throttle = controller->getJoystickYAxis();

	bool fork_toggle = controller->getRawJoystick()->GetRawButton(Configs::FORK_TOGGLE_BIND);

	//updates elevator
	forklift->setEleSpeed(throttle * Configs::ELEVATOR_MULTIPLIER);

	//makes solenoid only switch if button has been released first
	static bool prev_toggle = false;
	if(fork_toggle && !prev_toggle)
	{
		//switches solenoid to other state
		forklift->altSolndState();
		prev_toggle = true;
	}
	else
	{
		prev_toggle = fork_toggle;
	}

}

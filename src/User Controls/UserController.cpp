/*
 * UserController.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: nlele
 */

#include <User Controls/UserController.h>

#include <Joystick.h>

UserController::UserController(int port) {
	p_joystick.reset(new Joystick(port) );

}

double UserController::getLeftXAxis()
{
	return p_joystick->GetRawAxis(F310_AXIS::LEFT_X_AXIS);

}

double UserController::getLeftYAxis()
{
	return p_joystick->GetRawAxis(F310_AXIS::LEFT_Y_AXIS);
}

double UserController::getRightXAxis()
{
	return p_joystick->GetRawAxis(F310_AXIS::RIGHT_X_AXIS);
}

double UserController::getRightYAxis()
{
	return p_joystick->GetRawAxis(F310_AXIS::RIGHT_Y_AXIS);
}

/*
 * UserController.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: nlele
 */

#include <User Controls/UserController.h>

#include <Joystick.h>
#include <Configs/Configs.h>

#include <cmath>

UserController::UserController(int port)
{
	p_joystick = std::make_unique<Joystick>(port);
}

UserController::~UserController()
{
}

double UserController::getLeftXAxis() const
{
	return p_joystick->GetRawAxis(F310_AXIS::LEFT_X_AXIS);

}

double UserController::getLeftYAxis() const
{
	if(abs(p_joystick->GetRawAxis(F310_AXIS::LEFT_Y_AXIS) ) < Configs::ZERO_THROTTLE_THRESHOLD)
		{
			return 0.0;
		}
	return p_joystick->GetRawAxis(F310_AXIS::LEFT_Y_AXIS);
}

double UserController::getRightXAxis() const
{
	if(abs(p_joystick->GetRawAxis(F310_AXIS::RIGHT_X_AXIS) ) < Configs::ZERO_THROTTLE_THRESHOLD)
	{
		return 0.0;
	}
	return p_joystick->GetRawAxis(F310_AXIS::RIGHT_X_AXIS);
}

double UserController::getRightYAxis() const
{
	if(abs(p_joystick->GetRawAxis(F310_AXIS::RIGHT_Y_AXIS) ) < Configs::ZERO_THROTTLE_THRESHOLD)
	{
		return 0.0;
	}
	return p_joystick->GetRawAxis(F310_AXIS::RIGHT_Y_AXIS);
}

double UserController::getJoystickYAxis() const
{
	return p_joystick->GetY();
}

Joystick* UserController::getRawJoystick() const
{
	return p_joystick.get();
}

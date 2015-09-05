/*
 * Motor.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: nlele
 */

#include <DriveTrain/Motor.h>
#include <TalonSRX.h>

Motor::Motor(int channel) {
	// TODO Auto-generated constructor stub
	talon = std::make_unique<TalonSRX>(channel);
}

Motor::~Motor() = default;

void Motor::setSpeed(float speed)
{
	talon->Set(speed);
}

void Motor::disable()
{
	talon->Disable();
}

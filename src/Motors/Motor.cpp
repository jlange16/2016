/*
 * Motor.cpp
 *
 *  Created on: Jan 22, 2016
 *      Author: norayu
 */

#include <Motors/Motor.h>

#include <TalonSRX.h>

#include <cassert>

Motor::Motor(unsigned int channel)
{
	_motor = std::make_unique<TalonSRX>(channel);
}

Motor::~Motor()
{
	kill();
}

void Motor::setSpeed(double speed)
{
	assert(-1 <= speed && speed <= 1);
	_motor->Set(speed);
}

void Motor::kill()
{
	_motor->Disable();
}

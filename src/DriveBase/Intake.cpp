/*
 * Intake.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: user
 */

#include <DriveBase/Intake.h>

#include <Motors/Motor.h>

Intake::Intake(unsigned int port)
{
	_motor = std::make_unique<Motor>(port);
}

Intake::~Intake() = default;

void Intake::setSpeed(double speed)
{
	_motor->setSpeed(speed);
}

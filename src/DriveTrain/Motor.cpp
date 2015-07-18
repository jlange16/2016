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
	talon.reset(new TalonSRX(channel) );
}

void Motor::setSpeed(float speed)
{
	talon->Set(speed);
}

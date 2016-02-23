/*
 * IntakeControl.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: user
 */

#include <ExtraControllers/IntakeControl.h>

#include "Motors/Motor.h"
#include "Controllers/Gamepad.h"
#include "Configs/Configs.h"
#include "Sensors/LimitSwitch.h"
#include "DriveBase/Intake.h"

IntakeControl::IntakeControl(Intake* in, LimitSwitch* lw, Gamepad* gp) : _in(in), _lw(lw), _gp(gp)
{

}

IntakeControl::~IntakeControl() = default;

void IntakeControl::toggle()
{
	//can't use a while loop because we want the execution to continue
	static bool should_turn = true;
	//right now dummy
	//spins until limit switch is hit
	//defaults .5
	constexpr double DEF_SPEED = .5;

	if(_lw->pressed() == true)
	{
		should_turn = false;
	}

	if(should_turn)
	{
		force(DEF_SPEED);
	}
	else
	{
		constexpr char DEAD = 0;
		force(DEAD);
	}

}

void IntakeControl::force(double speed)
{
	_in->setSpeed(speed);
}

void IntakeControl::update()
{
	auto rt = _gp->getRawAxis(CONFIGS::RT_BIND);
	auto rb = _gp->getRawButton(CONFIGS::RB_BIND);

	//force gets priority of both force and toggle pressed
	//force speed depends on how much button is pressed
	if(rt > CONFIGS::RT_COMP)
	{
		force(rt * CONFIGS::MOTOR_SCALE);
		return;
	}

	if(rb != false)
	{
		toggle();
		return;
	}

	//set the motor speed to 0
	constexpr unsigned char DEAD = 0; //stupid magic numbers
	force(DEAD);
}


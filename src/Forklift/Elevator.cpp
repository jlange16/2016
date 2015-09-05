/*
 * Elevator.cpp
 *
 *  Created on: Sep 5, 2015
 *      Author: norayu
 */

#include <Forklift/Elevator.h>

#include "DriveTrain/Motor.h"
#include "Switch/LimitSwitch.h"

#include <cassert>
#include <iostream>

Elevator::Elevator(int port, int channela, SWITCHPOS posa, int channelb, SWITCHPOS posb)
{
	ele_motor = std::make_unique<Motor>(port);

	//make sure different enums are entered
	assert(posa != posb);
	//inserts channels into boundary
	boundary[posa] = std::make_unique<LimitSwitch>(channela);
	boundary[posb] = std::make_unique<LimitSwitch>(channelb);
}

Elevator::~Elevator() = default;

void Elevator::setEleSpeed(double speed)
{
	ele_motor->setSpeed(speed);
}

void Elevator::checkSafety()
{
	//sets switches
	auto& top = *boundary[SWITCHPOS::TOP];
	auto& bottom = *boundary[SWITCHPOS::BOTTOM];

	//updates switches
	top.update();
	bottom.update();

	//checks top
	if(top.isSwitched() )
	{
		top_in_prog = true;
	}
	else if(top_in_prog)
	{
		is_above = !is_above;
		top_in_prog = false;
	}

	//same for bottom
	if(bottom.isSwitched() )
	{
		bttm_in_prg = true;
	}
	else if(bttm_in_prg)
	{
		is_below = true;
		bttm_in_prg = false;
	}
}

void Elevator::reset()
{
	std::cout << "RESET CALLED!\n";

	//clears limit switches
	boundary[SWITCHPOS::TOP].reset();
	boundary[SWITCHPOS::BOTTOM].reset();

	//sets carriage pos in middle
	is_above = true;
	is_below = true;

	//assumes carriage is not on switch
	top_in_prog = false;
	bttm_in_prg = false;
}

void Elevator::kill()
{
	ele_motor->disable();
}

/*
 * LimitSwitch.cpp
 *
 *  Created on: Sep 5, 2015
 *      Author: norayu
 */

#include <Switch/LimitSwitch.h>

#include "Configs/Configs.h"

#include <Counter.h>
#include <DigitalInput.h>

LimitSwitch::LimitSwitch(int channel)
{
	dig_inpt = std::make_unique<DigitalInput>(channel);
	counter = std::make_unique<Counter>(*dig_inpt);
}

LimitSwitch::~LimitSwitch() = default;

void LimitSwitch::update()
{
	//sets prev to current
	prev_count = curr_count;
	//sets current to counted val
	curr_count = counter->Get();
}

bool LimitSwitch::isSwitched()
{
	return curr_count - prev_count > Configs::SWITCH_SENSITIVITY;
}

void LimitSwitch::reset()
{
	curr_count = 0;
	prev_count = 0;
}

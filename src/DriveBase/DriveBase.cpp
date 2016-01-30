/*
 * DriveBase.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: norayu
 */

#include <DriveBase/DriveBase.h>

void DriveBase::setSide(double speed, Side side)
{
	for(auto& it : _motors)
	{
		if(it.second == side)
		{
			it.first->setSpeed(speed);
		}
	}
}

void DriveBase::setAll(double speed)
{
	for(auto& it : _motors)
	{
		it.first->setSpeed(speed);
	}
}

void DriveBase::setIndividual(double speed, MotorInterface* mw)
{
	mw->setSpeed(speed);
}

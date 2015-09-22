/*
 * DriveBase.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: nlele
 */

#include <DriveTrain/DriveBase.h>

#include <iterator>

DriveBase::~DriveBase() = default;

bool whlTypSdCmprsn(WheelTypes wt, Side sd)
{
	if((wt == RIGHT_FOR || wt == RIGHT_BCK) && sd == RIGHT)
	{
		return true;
	}

	if((wt == LEFT_FOR || wt == LEFT_BCK) && sd == LEFT)
	{
		return true;
	}

	return false;
}

void DriveBase::setAll(double speed)
{
	for (auto& it: all_motors)
	{
		it.second->setSpeed(speed);
	}
}

void DriveBase::setIndividual(int port, double speed)
{
	all_motors[port]->setSpeed(speed);
}

void DriveBase::setSide(Side side, double speed)
{
	for(auto& it : all_motors)
	{
		if(it.first >= WHEEL_TYPES_MAX)
		{
			continue;
		}

		if(whlTypSdCmprsn(static_cast<WheelTypes>(it.first), side) )
		{
			it.second->setSpeed(speed);
		}
	}
}

void DriveBase::kill()
{
	//never starts again
	//like when you kill something
	for(auto& it : all_motors)
	{
		it.second->disable();
	}
}

/*
 * Motor.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: nlele
 */

#include <DriveTrain/Motor.h>
#include <TalonSRX.h>

#include <algorithm>

std::vector<int> Motor::all_ports;

Motor::Motor(int channel) : _channel(channel)
{
	if(std::find(all_ports.begin(), all_ports.end(), channel) != all_ports.end() )
	{
		throw PortExists(channel);
	}

	talon = std::make_unique<TalonSRX>(channel);
	all_ports.push_back(channel);
}

Motor::~Motor() = default;

void Motor::setSpeed(float speed)
{
	std::cout << "Motor " << static_cast<int>(_channel) << "Speed " << speed << std::endl;
	talon->Set(speed);
}

void Motor::disable()
{
	talon->Disable();
}

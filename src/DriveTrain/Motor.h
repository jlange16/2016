/*
 * Motor.h
 *
 *  Created on: Jul 18, 2015
 *      Author: nlele
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include <memory>
#include <vector>

#include <stdexcept>
#include <string>

class TalonSRX;

class PortExists : public std::runtime_error
{
public:
	PortExists(int channel) : std::runtime_error("Port " + std::to_string(channel) + "exists already!"){};
};

class Motor {
private:
	std::unique_ptr<TalonSRX> talon;
	static std::vector<int> all_ports;
public:
	Motor(int channel);
	~Motor();
	Motor(Motor& m) = delete;
	Motor& operator=(Motor& m) = delete;
	Motor(Motor&&m) = delete;
	Motor& operator=(Motor&& m) = delete;
	void setSpeed(float speed);
	void disable();
};

#endif /* MOTOR_H_ */

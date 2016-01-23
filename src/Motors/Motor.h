/*
 * Motor.h
 *
 *  Created on: Jan 22, 2016
 *      Author: norayu
 */

#ifndef SRC_MOTORS_MOTOR_H_
#define SRC_MOTORS_MOTOR_H_

#include "MotorInterface.h"

#include <memory>

class TalonSRX;

class Motor : public MotorInterface
{
private:
	std::unique_ptr<TalonSRX> _motor;
public:
	Motor(unsigned int channel);
	~Motor();
	void setSpeed(double speed) override;
	void kill() override;
};

#endif /* SRC_MOTORS_MOTOR_H_ */
